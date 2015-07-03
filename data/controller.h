#ifndef CONTROLLER_H

#define CONTROLLER_H

int init_ctl(const char *table);
int loop(const char *table);
void setup(void);
int str_to_struct(char *, const char *table);

#endif
