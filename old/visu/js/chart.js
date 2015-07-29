/**
 * Curve Object
 */
function Curve(count) {
	this.yCount = count;
	this.data = new Array();
}

/**
 * Curve item object
 */
function CurveItem(datetime) {
	this.x = datetime;
	this.xShort;
	this.y = new Array();
}

/**
 * Chart object
 */
function Chart(id) {
	var self = this;
	var chart = id;
	var c = chart[0].getContext('2d');

	// curve data
	var curveTmp;

	var colors = new Array("#FF0000", "#0000FF", "#009600", "#FF7D00", "#FF00FF", "#7D4B00");
	var red = new Array(255, 0, 0, 255, 255, 125);
	var green = new Array(0, 0, 150, 125, 0, 75);
	var blue = new Array(0, 255, 0, 0, 255, 0);

	var width ;
	var height;

	var size;
	var secsSize;

	var yMaxArr = new Array();
	var stepArr = new Array();
	var xStep = 0;

	var yGraphOffset = 10;
	var xOffset = 15;
	var yOffset = 30;

	var graphNames = new Array();

	var takt = 10;						/**< 10 minutes takt */

	var yGrid = false;
	var yAxis = false;
	var yAxisLabel = false;
	var xGrid = false;
	var xAxis = false;
	var xAxisMarks = false;
	var xAxisLabel = false;

	var border = false;
	var points = false;

	var lineThickness = 1;

	this.init = function(curve) {
		self.update();

		// curve temp
		curveTmp = new Curve(curve.yCount);
		curveTmp.data = curve.data;

		var minDate = getTimestamp(curve.data[0].x);
		var maxDate = getTimestamp(curve.data[curve.data.length - 1].x);
		secsSize = (maxDate.getTime() - minDate.getTime()) / 1000;

		size = curveTmp.data.length;
		xStep = Math.floor(size / 10);

		/**
		 * calculate the max value for each graph
		 */
		for(var i = 0; i < curveTmp.yCount; i++) {
			yMaxArr.push(getMaxY(curveTmp.data, i));
			stepArr.push(getStepWidth(i));
		}
	}

	this.update = function() {
		c.clearRect(0, 0, $(chart).attr("width"), $(chart).attr("height"));

		$(chart).attr("width", $(id).parent().width());

		width = $(chart).attr("width");
		height = $(chart).attr("height");
	}

	this.draw = function() {
		var xPixelZero = getXPixel(0);

		/**
		 * limits
		 */
		c.lineWidth = 1;

		var minLimit = new Array(35, 13, 500);
		var maxLimit = new Array(55, 30, 2000);
		for(var y = 0; y < curveTmp.yCount; y++) {
			var yPixelMin = getYPixel(minLimit[y], y);
			var yPixelMax = getYPixel(maxLimit[y], y);
			c.globalAlpha = 0.2;
			c.beginPath();
			c.rect(xPixelZero, yPixelMin, getGraphWidth(), yPixelMax - yPixelMin);
			c.fillStyle = colors[y];
			c.fill();
		}

		c.globalAlpha = 1.0;
		c.fillStyle = "#000";

		/**
		 * y-axis
		 */
		if(yAxis) {
			c.strokeStyle = "#DDD";
			c.lineWidth = 3;
			c.beginPath();
			c.moveTo(xPixelZero, getGraphHeight() + yGraphOffset);
			c.lineTo(xPixelZero, + yGraphOffset);
			c.stroke();
		}

		/**
		 * x-axis
		 */
		c.strokeStyle = "#DDD";
		c.textAlign = "center";
		c.textBaseline = "top";
		c.font = "8pt Sans";
		for(var xaxis = 0; xaxis < curveTmp.data.length; xaxis += xStep) {
			var xPixel = getXPixelAxis(xaxis);
			// x-Grid
			if(xGrid) {
				c.lineWidth = 1;
				c.beginPath();
				c.moveTo(xPixel, getGraphHeight() + yGraphOffset);
				c.lineTo(xPixel, + yGraphOffset);
				c.stroke();
			}
			// x-Axis marks
			if(xAxisMarks) {
				c.lineWidth = 1;
				c.beginPath();
				c.moveTo(xPixel, getGraphHeight() + yGraphOffset);
				c.lineTo(xPixel, getGraphHeight() + yGraphOffset + 5);
				c.stroke();
			}
			// x-Axis labels
			if(xAxisLabel) {
				var dt = getTimestamp(curveTmp.data[xaxis].x);
				c.fillText(addZero(dt.getHours())+':'+addZero(dt.getMinutes()), xPixel, getGraphHeight() + yGraphOffset + 15);
			}
		}

		/**
		 * y-axis
		 */
		c.strokeStyle = "#DDD";
		c.lineWidth = 1;
		for(var y = 0; y < curveTmp.yCount; y++) {
			for (var yaxis = 0; yaxis <= yMaxArr[y]; yaxis += stepArr[y]) {
				var yPixel = getYPixel(yaxis, y);
				if(yGrid) {
					// if zero line set lineWidth = 3
					if(yaxis == 0) {
						// bold x-axis
						if(xAxis) {
							c.lineWidth = 3;
						}
						// draw graph names
						c.textBaseline = "bottom";
						c.textAlign = "left";
						c.font = "13pt Sans";
						c.fillText(graphNames[y], xOffset + 10, yPixel - 10);
					} else {
						c.lineWidth = 1;
					}

					c.beginPath();
					c.moveTo(xOffset, yPixel);
					c.lineTo(getGraphWidth() + xOffset, yPixel);
					c.stroke();
				}

				// y-axis labels
				if(yAxisLabel) {
					// don't draw the last y-axis label = first y-axis label from next chart
					if(yaxis < yMaxArr[y] || y == (curveTmp.yCount - 1)) {
						c.textBaseline = "middle";
						c.textAlign = "right";
						c.font = "8pt Sans";
						c.fillText(yaxis, xOffset / 2, yPixel);
					}
				}
			}
		}

		/**
		 * Graph
		 */
		c.lineWidth = lineThickness;
		for(var iY = 0; iY < curveTmp.yCount; iY++) {
			c.strokeStyle = colors[iY];
			c.beginPath();
			for(var iData in curveTmp.data) {
				var yPixel = getYPixel(curveTmp.data[iData].y[iY], iY);
				// draw line
				if(curveTmp.data[iData].y[iY] != null) {
					if(iY == 2) {
						var yPixelTmp = getYPixel(yMaxArr[2] - curveTmp.data[iData].y[iY], iY);
						c.lineTo(getXPixel(iData), yPixelTmp);
					} else {
						c.lineTo(getXPixel(iData), yPixel);
					}
					// draw points
					if(points) {
						c.fillStyle = colors[iY];
						c.arc(getXPixel(iData)+2, yPixel, 4, 0, Math.PI * 2, true);
					}
				}
			}
			c.stroke();
		}

		/**
		 * border
		 */
		if(border) {
			c.strokeStyle = "#DDD";
			c.lineWidth = 3;
			c.strokeRect(xPixelZero, yGraphOffset, getGraphWidth(), getGraphHeight());

			// c.strokeRect(0, 0, width, height);
		}
	}

	/**
	 * set border visible
	 */
	this.setBorder = function(state) {
		border = state;
	}

	/**
	 * set points visible
	 */
	this.setPoints = function(state) {
		points = state;
	}

	/**
	 * set x grid visible
	 */
	this.setXGrid = function(state) {
		xGrid = state;
	}

	/**
	 * set x axis visible
	 */
	this.setXAxis = function(state) {
		xAxis = state;
	}

	/**
	 * set x axis marks visible
	 */
	this.setXAxisMarks = function(state) {
		xAxisMarks = state;
	}

	/**
	 * set x axis labels visible
	 */
	this.setXAxisLabel = function(state) {
		xAxisLabel = state;
	}

	/**
	 * set y grid visible
	 */
	this.setYGrid = function(state) {
		yGrid = state;
	}

	/**
	 * set y axis visible
	 */
	this.setYAxis = function(state) {
		yAxis = state;
	}

	/**
	 * set y axis label visible
	 */
	this.setYAxisLabel = function(state) {
		yAxisLabel = state;
		if(state) {
			xOffset = 75;
		} else {
			xOffset = 15;
		}
	}

	/**
	 * set line width (graph)
	 */
	this.setLineWidth = function(width) {
		lineThickness = width;
	}

	/**
	 * set graph names
	 */
	this.setGraphNames = function(names) {
		graphNames = names;
	}

	/**
	 * real width of graph
	 */
	function getGraphWidth() {
		return width - xOffset * 2;
	}

	/**
	 * real height of graph
	 */
	function getGraphHeight() {
		return (height - yOffset - yGraphOffset);
	}

	/**
	 * get x pixel for graph
	 */
	function getXPixel(val) {
		var minDateTmp = getTimestamp(curveTmp.data[0].x);
		var maxDateTmp = getTimestamp(curveTmp.data[val].x);
		var secsTmp = (maxDateTmp.getTime() - minDateTmp.getTime()) / 1000;
		return (getGraphWidth() / secsSize * secsTmp) + ((width - xOffset) / secsSize) / 2 + xOffset;
	}

	/**
	 * get x pixel for x axis
	 */
	function getXPixelAxis(val) {
		return (getGraphWidth() / size * val) + ((width - xOffset) / size) / 2 + xOffset;
	}

	function getYPixel(val, index) {
		return (height - getGraphHeight() / yMaxArr.length / yMaxArr[index] * val - yOffset) - (index) * getGraphHeight() / yMaxArr.length;
	}

	function getMaxY(data, index) {
		var max = 15;
		for (var i = 0; i < data.length; i++) {
			if (parseInt(data[i].y[index]) > max) {
				max = data[i].y[index];
			}
		}

		max = parseInt(max);
		max += 20 - max % 10;

		return max;
	}

	function getStepWidth(index) {
		var step = 0;
		// var max = yMax;
		var max = yMaxArr[index];
		for (var i = 1; i < max; i++) {
			if (max % i == 0 && i > step) {
				step = i;
			}
		}

		return step / 2;
	}
}
