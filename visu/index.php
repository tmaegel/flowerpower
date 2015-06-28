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

<div id="container" style="padding:25px">

	<canvas id="graph" width="800" height="800"></canvas>

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

		getData();

		/**
		 * Event for resize the window
		 */
		$(window).resize(function() {
			chart.resize();
		});

		/**
 		 * Get data
		 */
		function getData() {
			$.ajax({
				type: 'POST',
				url: 'php/get.php',
				data: {
					type: 'data'
				},
				async: false,
				success: function(request) {
					chart.draw(jQuery.parseJSON(request));
				}
			});
		}

	});
</script>

<?php

/**
 * FOOTER
 */
include "footer.php";

?>
