#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// environ vs env 
int main(int ac , char **av, char **env)
{
//to do array 
	 int i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++ ;
	}
	// global varibal 
	extern char **environ ;
	// print the adress for env 
	printf("%p\n" ,env);
	// printing the adreess for environ for commpaire if are the same or not 
	printf("%p\n",environ);
}
