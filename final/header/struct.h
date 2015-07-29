#ifndef STRUCT_H

#define STRUCT_H

/**< struct to manage the measurements */
struct measurement {
	int hw_id;
	double temperature;
	double humidity;
	double brightness;
	char timestamp[20];
};

#endif
