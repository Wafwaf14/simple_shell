#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int _setenv(const char *name, const char *value, int overwrite);
{
	extern char **environ;
	int i = 0; len = 0;
	char new_var;

	if(!name || !value)
		return (-1);
	while(environ[i])
	{
		len = strlen(name);
	       if (strncmp(environ[i], name, len )==0)
	       {
		       if (overwrite)
		       {
			       new_var = malloc(strlen(name) + 1 + strlen(value) + 2);
		strcpy(new_var,name);
		strcat(new_var, "_");
		strcat(new_var, value);
		environ[i] = new_var;
		return(0);
		       }
		       return(0);
	       }
	}
	i++;
}
new_var = malloc(strlen(name) + strlen(value) +2);
 strcpy(new_var,name);
                strcat(new_var, "_");
                strcat(new_var, value);
		
environ[i] = new_var;
environ[i+1] = NULL;
return (0);

