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

<!-- Always shows a header, even in smaller screens. -->
<div class="mdl-layout mdl-js-layout mdl-layout--fixed-header">
	<header class="mdl-layout__header">
		<div class="mdl-layout__header-row">
		<!-- Title -->
		<span class="mdl-layout-title">flowerpower</span>
		<!-- Add spacer, to align navigation to the right -->
		<div class="mdl-layout-spacer"></div>
		<!-- Navigation. We hide it in small screens. -->
		<nav class="mdl-navigation mdl-layout--large-screen-only">
			<!-- <a class="mdl-navigation__link" href="">Link</a>
			<a class="mdl-navigation__link" href="">Link</a>
			<a class="mdl-navigation__link" href="">Link</a>
			<a class="mdl-navigation__link" href="">Link</a> -->
		</nav>
		</div>
	</header>
	<div class="mdl-layout__drawer">
		<span class="mdl-layout-title">flowerpower</span>
		<nav class="mdl-navigation">
			<!-- <a class="mdl-navigation__link" href="">Link</a>
			<a class="mdl-navigation__link" href="">Link</a>
			<a class="mdl-navigation__link" href="">Link</a> -->
		</nav>
	</div>

	<main class="mdl-layout__content mdl-color--grey-100">
		<div class="mdl-grid mdl-cell mdl-cell--12-col mdl-cell--12-col-tablet">
			<div class="mdl-cell mdl-cell--12-col mdl-cell--12-col-desktop mdl-cell--12-col-tablet mdl-cell--12-col-phone">
				<div class="mdl-card mdl-shadow--2dp">
					<div class="mdl-card__title">Grafische Darstellung</div>
					<div class="mdl-card__supporting-text div-canvas" style="text-align: center">
						<canvas id="graph" width="800" height="600"></canvas>
					</div>
					<div class="mdl-card__actions mdl-card--border">
						<label  for="select-hw-id">Hardware ID:</label>
						<select id="select-hw-id" name="hw-id" size="1">
							<option value="0">dummy</option>
						</select>
					</div>
				</div>
			</div>
		</div>
	</main>

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

		getData(1);

		getHwIds();

		/**
		 * Event for resize the window
		 */
		$(window).resize(function() {
			chart.update();
			chart.draw();
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
					chart.init(jQuery.parseJSON(request));
					chart.draw();
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
			chart.update();
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
