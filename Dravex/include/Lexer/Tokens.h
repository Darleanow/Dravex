#ifndef TOKENS_H
#define TOKENS_H

enum Tokens
{
    NUMBER_LITERAL, // 42, 3.14, etc
    CHAR_LITERAL,   // 'a', 'b', '\n'
    BOOL_LITERAL,   // true, false
    STRING_LITERAL, // "hello", "world"

    TYPE_INT,    // int
    TYPE_FLOAT,  // float
    TYPE_CHAR,   // char
    TYPE_STRING, // string
    TYPE_BOOL,   // boolean
    TYPE_VOID,   // no return functions

    NULL_KEYWORD,   // null
    STATIC_KEYWORD, // static

    PANIC_OPERATOR,  // ! (ex: x+!)
    WRAP_OPERATOR, // % (ex: x+%)

    IDENTIFIER, // variable names, function names

    FUNCTION,      // fn
    RETURN,        // return
    RETURN_TYPE,   // ->
    FUNCTION_TYPE, // <T>
    T_PARAM,       // T in generic types

    POINTER,   // *
    REFERENCE, // @

    READONLY, // readonly

    INITIALIZATION, // =

    BRACE_OPEN,  // {
    BRACE_CLOSE, // }

    PARENTHESIS_OPEN,  // (
    PARENTHESIS_CLOSE, // )

    BRACKET_OPEN,  // [
    BRACKET_CLOSE, // ]

    IF_KEYWORD,     // if
    MODULE_KEYWORD, // module
    PUB_KEYWORD,    // pub

    SCOPE_OPERATOR, // ::

    UNSAFE_KEYWORD, // unsafe

    REG32, // reg32 (32-bit register)
    REG64, // reg64 (64-bit register)

    PORT16, // port16 (16-bit I/O port)

    STRUCTURE,           // struct
    NEW_KEYWORD,         // new
    OPERATION_DELIMITER, // ;
    SELF_KEYWORD,        // self

    PLUS_OP,         // +
    MINUS_OP,        // -
    DIVIDE_OP,       // /
    MULT_OP,         // *
    EQUALS_OP,       // ==
    GREATER_THAN_OP, // >
    LESS_THAN_OP,    //
    ASSIGMENENT_OP,  // =
    ARROW_OP,        // ->

    ANNOTATION, // @something (ex: @positive)

    IMPORT_KEYWORD,    // import
    SCOPE_DOUBLE_DOTS, // ::

    ARRAY_KEYWORD,    // array
    LIST_KEYWORD,     // List
    DYNARRAY_KEYWORD, // DynArray

    ATOMIC_KEYWORD, // atomic
    RESULT_KEYWORD, // Result

    COMMENT_LINE,   // //
    COMMA_SEPARATOR // ,
};

#endif