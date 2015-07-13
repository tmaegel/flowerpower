#ifndef DATABASE_H

#define DATABASE_H

int get_option(const char *arg, const char *opt);
void check_error(void);
void show_help();
int get_last_timestamp(const char *table, char *timestamp);
int read_from_database(const char *table, struct measurement *data, const char *datetime);
void write_to_database(const char *table, struct measurement *data);
void create_database(const char *database);
void create_Table(const char *table);
void insert_sim_data(const char *table, int num);
void init_database(const char *database, const char *table, bool simulate);
void close_database();

#endif
