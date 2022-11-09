#ifndef TUTORAT_PROJET_SYS22_MIME_H
#define TUTORAT_PROJET_SYS22_MIME_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum
{
    EXTENSION_POS,
    MIME_TYPE,
    ARRAY_SIZE,
};

extern char *Mime_types[][ARRAY_SIZE];

char *get_mime_type(char *filename);

#endif // TUTORAT_PROJET_SYS22_MIME_H
