#ifndef CONTROLLER_H

#define CONTROLLER_H

int loop(const char *table);
void init_ctl(void* ptr_ic);
void setup_ctl(void);
void str_to_struct(char *, const char *table);

#endif
