#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int ac , char **av, char **env)
{
	int i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++ ;
	}
	extern char **environ ;
	printf("%p\n" ,env);
	printf("%p\n",environ);
}
