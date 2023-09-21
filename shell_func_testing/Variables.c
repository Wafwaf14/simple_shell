#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char input[max_input];
	char* varibles[max_input / 2];

	while(1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		
		if (strchr(input, '='))
		{
			char* var = strtok(input, "=");
			char* val = strtok(NULL,"");
			if (var != NULL && val != NULL)
			{
				variables[strlen(var)] = strdup(val);
			}
			else
			{
				printf("invalid variable ");
			}
		}
		else if (strstr(input, "$?"))
		{
			char* var = strtok(input, " ");
			while (var != NULL)
			{
				if (var[0] == '$' && var[1] != '$')
				{
					char* var_name = var + 1;
					int fount = 0;

