#ifndef TOKEN_H
#define TOKEN_H
#include "Tokens.h"
#include <stdlib.h>
#include <string.h>

struct Token
{
    Tokens type;
    char *value;
    size_t line;
    size_t column;
    size_t length;
};

Token *create_token(enum Tokens type, const char *value, size_t line, size_t column)
{
    if (!value)
        return NULL;

    Token *token = (Token *)malloc(sizeof(Token));
    if (!token)
        return NULL;

    size_t length = strlen(value);
    token->value = (char *)malloc(length + 1);
    if (!token->value)
    {
        free(token);
        return NULL;
    }
    strcpy(token->value, value);

    token->type = type;
    token->line = line;
    token->column = column;
    token->length = length;

    return token;
}

void destroy_token(Token *token)
{
    if (!token)
        return;
    free(token->value);
    free(token);
}

#endif