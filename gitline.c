#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *gitline(const char *command) {
    FILE *fp;
    char buffer[128];
    char *result = NULL;
    size_t result_size = 0;

    fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run Git command");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        size_t line_length = strlen(buffer);
        result = realloc(result, result_size + line_length + 1);
        if (result == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        strcpy(result + result_size, buffer);
        result_size += line_length;
    }

     pclose(fp);
    return result;
}
int main(int ac, char **av)
{
	(void)ac;
	char *buffer = NULL;
	size_t size_buffer = 0;
	int num_char = 0;

	write(1, "$ ",2);
	num_char = getline(&buffer, &size_buffer, stdin);
	if (num_char == EOF)
		perror("getline");
	printf("%s\n", buffer);

	return (0);
}

