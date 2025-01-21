#ifndef CLI_H
#define CLI_H

typedef struct
{
    char *input_file;
} config_t;

bool cli_parse_arguments(int argc, char **argv, config_t *config);

void cli_print_help(void);

#endif