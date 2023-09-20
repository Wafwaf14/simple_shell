#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>  

#define MAX_LINE_LENGTH 100

int gitline(char *line) {
    int c;
    int i = 0;

    while (1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            line[i] = '\0';
            return 1;
        } else if (i < MAX_LINE_LENGTH - 1) {
            line[i] = (char)c;
            i++;
        } else {
            line[MAX_LINE_LENGTH - 1] = '\0';
            while ((c = getchar()) != '\n' && c != EOF);
            return 0;
        }
    }
}

int main(int argc, char **argv) {
    (void)argc;
    char line[MAX_LINE_LENGTH];

    write(1, "$ ", 2);

    if (gitline(line)) {
        printf("%s\n", line);
    } else {
        printf("Line was too long and got truncated: %s\n", line);
    }

    return 0;
}

