#include "main.h"

int main(void)
{
int status;

status = remove("bash_alias");
if (status == -1)
	perror("remove");

return (0);
}
