#include <stdio.h>

#include "cli/cli.h"

int main(int argc, char **argv)
{
    config_t config;

    if (!cli_parse_arguments(argc, argv, &config))
    {
        fprintf(stderr, "Error: Failed to parse arguments\n");
        return -1;
    }

    return 0;
}
