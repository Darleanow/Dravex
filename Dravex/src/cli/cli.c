#include <stdio.h>
#include <stdbool.h>

#include "cli/cli.h"

void cli_print_help(void)
{
    printf("Usage: dravex [options]\n"
           "Options:\n"
           " -i <input>         The file to compile"
           " -h                 Display this help\n");
}

static bool handle_option_with_arg(const char opt, int *i, int argc,
                                   char **argv, config_t *config)
{
    if (++(*i) >= argc)
    {
        fprintf(stderr, "Error: Missing argument for -%c\n", opt);
    }

    switch (opt)
    {
    case 'i':
        config->input_file = argv[*i];
        break;
    default:
        fprintf(stderr, "Error, Unrecognized argument for -%c\n", opt);
        return false;
    }

    return true;
}

static bool handle_flag_option(const char opt, config_t *config)
{
    switch (opt)
    {
    case 'h':
        cli_print_help();
        break;
    default:
        fprintf(stderr, "Error: Unknown option for '-%c'\n", opt);
        return false;
    }

    return true;
}

bool cli_parse_arguments(int argc, char **argv, config_t *config)
{
    for (int i = 1; i < argc; i++)
    {
        const char *arg = argv[i];

        if (arg[0] != '-' || argv[1] == '\0')
        {
            fprintf(stderr, "Error: Invalid argument format: %s\n", arg);
            return false;
        }

        if (strchr("i", arg[1]))
        {
            if (!handle_option_with_arg(arg[1], &i, argc, argv, config))
            {
                return false;
            }
        }
        else if (!handle_flag_option(arg[1], config))
        {
            return false;
        }
    }

    return true;
}