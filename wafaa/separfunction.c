#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*
 *
 *
 *
 */

int main(int ac, char **av)
{
	(void)ac ;
	int i = 0;
	char *buffer = NULL;
	size_t size_buffer = 0;
	int num_char =0;

	while (av[i])
	{
		printf("%s \n" , av[i]);
		i++;
	}
	printf("$ ");
	num_char = getline(&buffer, &size_buffer, stdin);
	 if (num_char == EOF)
		 perror("getline");
	 printf("%s\n",buffer);
	  return (0);
}

