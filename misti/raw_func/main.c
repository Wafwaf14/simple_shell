#include "main.h"


int main(int argc, char **argv) // use argc and argv parameters
{
    if (argc != 2) // check if there is exactly one argument
    {
        printf("Usage: %s filename\n", argv[0]);
        return (-1);
    }

    handle_file(argv[1]); // pass the argument as file name
    return (0);
}
