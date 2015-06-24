#ifndef CONTROLLER_H

#define CONTROLLER_H

int init_ctl(void);
void loop(void);
void setup(void);
int str_to_struct(char *, struct measurement *);

#endif
