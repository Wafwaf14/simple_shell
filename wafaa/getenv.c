#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// function can return the envairment element
char *_getenv(const char *env_var)
{
	extern char **environ;
	int i = 0;
	char *key;
	// in this loop we will check every environ , when we get the string that we need we will print the value of it 
	while (environ[i])
	{
		key = strtok(environ[i] , "=");
		if (strcmp(env_var,key) == 0 )
			return(strtok(NULL, "="));
		i++;
	}
	return (NULL);
}
int main()
{// return the path 
	printf("%s\n",_getenv("PATH"));
	return(0);
}
