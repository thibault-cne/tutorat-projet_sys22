#ifndef TUTORAT_PROJET_SYS22_STAT_H
#define TUTORAT_PROJET_SYS22_STAT_H

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

off_t get_file_size(const char *path);
double get_seconds_from_last_modification(const char *path);

#endif // TUTORAT_PROJET_SYS22_STAT_H
