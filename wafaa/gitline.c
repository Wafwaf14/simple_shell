#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
	(void)ac;
	char *buffer = NULL;
	size_t size_buffer = 0;
	int num_char = 0;

	write(1, "$ ",2);
	num_char = getlie(&buffer, &size_buffer, stdin);
	if (num_char == EOF)
		perror("getline");
	printf("%s\n", buffer);

	return (0);
}

