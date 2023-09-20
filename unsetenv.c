#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int _unsetenv(const char *name) {
    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL) {
        printf(stderr, "Invalid variable name\n");
        return -1;
    }

    if (unsetenv(name) == 0) {
        return 0;
    } else {
        perror("unsetenv");
        return -1;
    }
