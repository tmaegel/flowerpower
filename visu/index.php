<?php

/**
 * HEADER
 */
include "header.php";

/**
 * DATABASE
 */
include "php/inc_database.php";

?>

<nav class="navbar navbar-default navbar-static-top">
	<div class="container-fluid">
		<div class="navbar-header">
	  		<a class="navbar-brand" href="#">
	    		<img alt="flowerpower" src="...">
	  		</a>
		</div>
		<form class="navbar-form navbar-right" role="search">
			<div class="form-group">
				<select id="select-hw-id" class="form-control" name="hw-id" size="1">
					<option value="0">dummy</option>
				</select>
			</div>
		</form>
	</div>
</nav>

<div id="container" style="padding:25px">

	<div class="row">
		<div class="col-lg-12 col-md-12 col-sm-12">
			<canvas id="graph" width="800" height="800"></canvas>
		</div>
	</div>

</div>

<?php

/**
 * JavaScript
 */
include "js.php";

?>

<script src="js/chart.js"></script>
<script>
	$(document).ready(function() {

		var chart = new Chart($('#graph'));

		chart.setPoints(false);
		chart.setBorder(true);

		chart.setYGrid(true);
		chart.setYAxisLabel(true);

		chart.setXGrid(false);
		chart.setXAxisMarks(true);
		chart.setXAxisLabel(true);

		chart.setLineWidth(2);
		chart.setPoints(false);
		chart.setGraphNames(new Array("Temperatur", "Helligkeit", "Feuchtigkeit"));
		chart.init();

		getData(1);

		getHwIds();

		/**
		 * Event for resize the window
		 */
		$(window).resize(function() {
			chart.resize();
		});

		/**
 		 * Get data
		 */
		function getData(id) {
			$.ajax({
				type: 'POST',
				url: 'php/get.php',
				data: {
					type: 'data',
					id: id
				},
				async: false,
				success: function(request) {
					chart.draw(jQuery.parseJSON(request));
				}
			});
		}

		/**
 		 * Get data
		 */
		function getHwIds() {
			$.ajax({
				type: 'POST',
				url: 'php/get.php',
				data: {
					type: 'hw-ids'
				},
				async: false,
				success: function(request) {
					$('#select-hw-id').empty();
					var hwIds = jQuery.parseJSON(request)
					for (var i in hwIds) {
						$('#select-hw-id').append('<option value="' + hwIds[i] + '">Hardware ID ' + hwIds[i] + '</option>');
					}
				}
			});
		}

		/**
		 * change graph
		 */
		$('#select-hw-id').change(function() {
			chart.clear();
			getData($('#select-hw-id').val());
		});

	});
</script>

<?php

/**
 * FOOTER
 */
include "footer.php";

?>
