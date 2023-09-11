#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
 
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
			return(strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}
// function that handel the command from the user 
char *get_command(char *command)
	{
		char *path = _getenv("PATH");
		// varibal check the directly 
		char *token ;
		// varibal where we can stock all the path 
		char *cmd_full ;
		// checking if the function exite or not 
		struct stat st;

		token = strlen(path, ": ");
		while (token)
		{
			cmd_full = malloc(strlen(token) + strlen(command) + 2);
		    strcpy(cmd_full , token);
		    strcat(cmd_full ,"/");
		    strcat(cmd_full, command);
		if (stat(cmd_full , &st) == 0)
			return (cmd_full);
		free(cmd_full);
		token =strtok(NULL, ":");
		}
		return (NULL);
	}
	// function that split the string 
	char **split_string(char *buffer, char *del)
	{
		char **tokens;
		char *token;
		int i = 0 ;
		tokens = malloc(sizeof(char *)* 1024);
		token = strtok(buffer, del);
		 while(token)
		 {
			tokens[i] = token ;
			i++;
		 }
		 tokens[i] = NULL;
		 return(tokens);	
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
		args = split_string(buffer, "\t\n");
		if (strcmp(args[0], "exit")== 0)
		exit(0);
		pid = fork();
		if ( pid == 0)
		{
			cmd = get_command(args[0]);
			if (cmd)
				execve(cmd, args, env);
			else
				printf(" command not found");
				exit(0);
			}
		else
			wait(&status);
		}
		return(0);
	}