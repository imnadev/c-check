#include "database.h"
#include <stdio.h>
#include <stdlib.h>

FILE *file;

void database_insert(char *entry) {
    file = fopen("../database/database.db", "a");

    fprintf(file, "%s", entry);

    fclose(file);
}

char *database_read() {
    file = fopen("../database/database.db", "r");

    char *contents = (char *) malloc(10240 * sizeof(char));

    fread(contents, 102400 * sizeof(char), 1, file);

    fclose(file);

    return contents;
}