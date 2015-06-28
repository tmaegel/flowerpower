/**
 * format string to timestamp
 */
function getTimestamp(ts) {
	var date;
	var time;
	var tmp = ts.split(" ");
	for (var i = 0; i < tmp.length; i++) {
		if(tmp[i].match('-')) {
			date = tmp[i].split("-");
		} else if(tmp[i].match(':')) {
			time = tmp[i].split(":");
		}
	}

	var timestamp = new Date(date[1]+" "+date[2]+","+date[0]+" "+time[0]+":"+time[1]+":"+time[2]);
	return timestamp;
}

/**
 * compare timestamp, ignore seconds
 */
function compareTimestamp(ts1, ts2) {
	var timestamp1 = getTimestamp(ts1);
	var timestamp2 = getTimestamp(ts2);

	if(timestamp1.getFullYear() != timestamp2.getFullYear()) {
		return -1;
	}

	if(timestamp1.getMonth() != timestamp2.getMonth()) {
		return -1
	}

	if(timestamp1.getDate() != timestamp2.getDate()) {
		return -1
	}

	if(timestamp1.getHours() != timestamp2.getHours()) {
		return -1;
	}

	if(timestamp1.getMinutes() != timestamp2.getMinutes()) {
		return -1;
	}

	return 1;
}

/**
 * pad given value to the left with "0"
 */
function addZero(num) {
    return (num >= 0 && num < 10) ? "0" + num : num + "";
}
