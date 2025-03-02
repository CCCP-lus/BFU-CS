#ifndef exp_scanner_h
#define exp_scanner_h

typedef enum
{
    // A subset of C language

    // Single character
    TOKEN_LEFT_PAREN,    // '('
    TOKEN_RIGHT_PAREN,   // ')'
    TOKEN_LEFT_BRACE,    // '{'
    TOKEN_RIGHT_BRACE,   // '}'
    TOKEN_LEFT_BRACKET,  // '['
    TOKEN_RIGHT_BRACKET, // ']'
    TOKEN_COMMA,         // ','
    TOKEN_DOT,           // '.'
    TOKEN_HASH,          // '#'
    TOKEN_COLON,         // ':'
    TOKEN_SEMICOLON,     // ';'
    TOKEN_PLUS,          // '+'
    TOKEN_MINUS,         // '-'
    TOKEN_SLASH,         // '/'
    TOKEN_STAR,          // '*'

    // One or two character
    TOKEN_BANG,          // '!'
    TOKEN_BANG_EQUAL,    // '!='
    TOKEN_EQUAL,         // '='
    TOKEN_EQUAL_EQUAL,   // '=='
    TOKEN_GREATER,       // '>'
    TOKEN_GREATER_EQUAL, // '>='
    TOKEN_LESS,          // '<'
    TOKEN_LESS_EQUAL,    // '<='

    // Literals
    TOKEN_IDENTIFIER,
    TOKEN_STRING,
    TOKEN_NUMBER,

    // Keywords
    /*
     * The following keywords are not supported:
     * auto, struct, break, switch, case, enum, register
     * typedef, extern, union, const, unsigned, continue
     * signed, default, goto, sizeof, volatile, do, static
     */
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_FOR,
    TOKEN_RETURN,
    TOKEN_WHILE,
    TOKEN_INT,
    TOKEN_SHORT,
    TOKEN_FLOAT,
    TOKEN_DOUBLE,
    TOKEN_LONG,
    TOKEN_VOID,
    TOKEN_CHAR,

    TOKEN_ERROR, // report an error to the compiler
    TOKEN_EOF    // End of file
} TokenType;

typedef struct
{
    TokenType type;
    const char *start;
    int length;
    int line;
} Token;

void initScanner(const char *source);
void listTokens(const char *dest);

#endif