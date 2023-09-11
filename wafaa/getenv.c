#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// function can 
char *_getenv(const char *env_var)
{
	extern char **environ;
	int i = 0;
	char *key;
	while (environ[i])
	{
		key = strtok(environ[i] , "=");
		if (strcmp(env_var,key) == 0 )
			return(strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}
	char *get_command(char *command)
	{
		char *path = _getenv("PATH");
		char *token ;
		char *cmd_full ;
		struct stat st;

		token = strlen(pat, ":");
		while (token)
		{
			cmd_full = malloc(strlen(token) + strlen(command) + 2)
			       strcpy(cmd_full , token );
		strcat(cmd_full , '/');
		strcat(cmd_full, command);
		if (stat(cmd_full , &st) == 0)
			return (cmd_full);
		free(cmd_full);
		token =strtok(NULL, ":");
		}
		return (NULL);
	}

int main(int ac , char **av, char **env)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	char *cmd;
	char **args;
	pid_t pid ;
	int status, nchars;

	while (1);
	{
		write(1,"$ ", 2);
		nchars = getline(&buffer, &buffer_size, stdin);
		if(nchars == -1)
		{
			write(1,"\n",1);
			exit(1);
		}
	}
}
