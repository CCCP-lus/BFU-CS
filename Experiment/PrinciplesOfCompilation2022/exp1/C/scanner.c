#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "common.h"
#include "scanner.h"

typedef struct
{
    const char *start;
    const char *current;
    int line;
} Scanner;

Scanner scanner;

static bool isAtEnd()
{
    return *scanner.current == '\0';
}

static char advance()
{
    return *scanner.current++;
}

static char peek()
{
    return *scanner.current;
}

static char peekNext()
{
    if (isAtEnd())
        return '\0';
    return *(scanner.current + 1);
}

static bool match(char expect)
{
    if (isAtEnd())
        return false;
    if (peek() != expect)
        return false;
    advance();
    return true;
}

static bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

static bool isAlpha(char c)
{
    return c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

static void skipWhiteSpace()
{
    while (!isAtEnd())
    {
        switch (peek())
        {
        // White spaces
        case ' ':
        case '\t':
        case '\r':
            advance();
            break;

        // New line
        case '\n':
            scanner.line++;
            advance();
            break;

        // Comments
        case '/':
        {
            if (peekNext() == '/')
            {
                while (!isAtEnd() && peek() != '\n')
                    advance();
            }
            else if (peekNext() == '*')
            {
                advance(); // skip the initial '*'
                do
                {
                    advance();

                    if (peek() == '\n')
                        scanner.line++;

                    if (peek() == '*')
                    {
                        advance();
                        if (peek() == '/')
                        {
                            advance();
                            break;
                        }
                    }
                } while (!isAtEnd());
            }
            else
                return;
            break;
        }

        default:
            return;
        }
    }
}

static Token makeToken(TokenType type)
{
    Token token;

    token.type = type;
    token.line = scanner.line;
    token.start = scanner.start;
    token.length = (scanner.current - scanner.start);

    return token;
}

static Token errorToken(const char *msg)
{
    Token token;

    token.start = msg;
    token.length = strlen(msg);
    token.type = TOKEN_ERROR;
    token.line = scanner.line;

    return token;
}

static Token number()
{
    while (!isAtEnd() && isDigit(peek()))
        advance();

    if (peek() == '.' && isDigit(peekNext()))
        do
        {
            advance();
        } while (!isAtEnd() && isDigit(peek()));

    if ((peek() == 'E' || peek() == 'e'))
    {
        advance();
        char next = peek();
        if (isDigit(next) || next == '+' || next == '-')
            do
            {
                advance();
            } while (!isAtEnd() && isDigit(peek()));
    }

    return makeToken(TOKEN_NUMBER);
}

static Token chars()
{
    while (!isAtEnd() && peek() != '\'')
    {
        if (peek() == '\n')
            return errorToken("Multiline char");
        advance();
    }

    if (peek() != '\'')
        return errorToken("Unterminated char");

    advance();
    if (scanner.current - scanner.start == 2)
        return errorToken("Empty char is not allowed");
    if (scanner.current - scanner.start > 3)
        return errorToken("Only a character is allowed in char declaration");

    return makeToken(TOKEN_CHAR);
}

static Token string()
{
    while (!isAtEnd() && peek() != '"')
    {
        if (peek() == '\n')
            scanner.line++;
        advance();
    }

    if (peek() != '"')
        return errorToken("Unterminated string");

    advance();
    return makeToken(TOKEN_STRING);
}

static TokenType checkKeyword(int start, int length, const char *rest, TokenType type)
{
    if (length == 0)
        return scanner.current - scanner.start == (start + length);

    if (scanner.current - scanner.start == (start + length) && memcmp(scanner.start + start, rest, length) == 0)
        return type;
    return TOKEN_IDENTIFIER;
}

static TokenType identifierType()
{
    switch (*scanner.start)
    {
    case 'e':
        return checkKeyword(1, 3, "lse", TOKEN_ELSE);
    case 'r':
        return checkKeyword(1, 5, "eturn", TOKEN_RETURN);
    case 'w':
        return checkKeyword(1, 4, "hile", TOKEN_WHILE);
    case 's':
        return checkKeyword(1, 4, "hort", TOKEN_SHORT);
    case 'd':
        return checkKeyword(1, 5, "ouble", TOKEN_DOUBLE);
    case 'l':
        return checkKeyword(1, 3, "ong", TOKEN_LONG);
    case 'v':
        return checkKeyword(1, 3, "oid", TOKEN_VOID);
    case 'c':
        return checkKeyword(1, 3, "har", TOKEN_CHAR);
    case 'i':
    {
        if (scanner.current - scanner.start > 1)
        {
            switch (*(scanner.start + 1))
            {
            case 'f':
                return checkKeyword(2, 0, "", TOKEN_FOR);
            case 'n':
                return checkKeyword(2, 1, "t", TOKEN_INT);
            }
        }
        break;
    }
    case 'f':
    {
        if (scanner.current - scanner.start > 1)
        {
            switch (*(scanner.start + 1))
            {
            case 'o':
                return checkKeyword(2, 1, "r", TOKEN_FOR);
            case 'l':
                return checkKeyword(2, 3, "oat", TOKEN_FLOAT);
            }
        }
        break;
    }
    }

    return TOKEN_IDENTIFIER;
}

static Token identifier()
{
    while (isAlpha(peek()) || isDigit(peek()))
        advance();
    return makeToken(identifierType());
}

static Token scanToken()
{
    skipWhiteSpace();
    scanner.start = scanner.current;

    if (isAtEnd())
        return makeToken(TOKEN_EOF);

    char c = advance();

    if (isDigit(c))
        return number();
    if (isAlpha(c))
        return identifier();

    switch (c)
    {
    // Single character
    case '(':
        return makeToken(TOKEN_LEFT_PAREN);
    case ')':
        return makeToken(TOKEN_RIGHT_PAREN);
    case '{':
        return makeToken(TOKEN_LEFT_BRACE);
    case '}':
        return makeToken(TOKEN_RIGHT_BRACE);
    case '[':
        return makeToken(TOKEN_LEFT_BRACKET);
    case ']':
        return makeToken(TOKEN_RIGHT_BRACKET);
    case ',':
        return makeToken(TOKEN_COMMA);
    case '+':
        return makeToken(TOKEN_PLUS);
    case '-':
        return makeToken(TOKEN_MINUS);
    case '*':
        return makeToken(TOKEN_STAR);
    case '#':
        return makeToken(TOKEN_HASH);
    case '.':
        return makeToken(TOKEN_DOT);
    case ';':
        return makeToken(TOKEN_SEMICOLON);
    case ':':
        return makeToken(TOKEN_COLON);
    case '/':
        return makeToken(TOKEN_SLASH);

    // One or two characters
    case '=':
        return makeToken(match('=') ? TOKEN_EQUAL_EQUAL : TOKEN_EQUAL);
    case '!':
        return makeToken(match('=') ? TOKEN_BANG_EQUAL : TOKEN_BANG);
    case '>':
        return makeToken(match('=') ? TOKEN_GREATER_EQUAL : TOKEN_GREATER);
    case '<':
        return makeToken(match('=') ? TOKEN_LESS_EQUAL : TOKEN_LESS);

    case '"':
        return string();
    case '\'':
        return chars();
    }

    return errorToken("Unexpected character");
}

static int getTokenOutputType(TokenType type)
{
    if (type == TOKEN_IDENTIFIER)
        return 2;
    if (type >= TOKEN_IF && type <= TOKEN_CHAR)
        return 1;
    if (type == TOKEN_NUMBER || type == TOKEN_STRING)
        return 3;
    if (type >= TOKEN_PLUS && type <= TOKEN_LESS_EQUAL)
        return 4;
    return 5;
}

void initScanner(const char *source)
{
    scanner.start = source;
    scanner.current = source;
    scanner.line = 1;
}

void listTokens(const char *dst)
{
    FILE *file = fopen(dst, "w");
    if (file == NULL)
    {
        fprintf(stderr, "Cannot open destination file: %s", dst);
        exit(74);
    }

    for (;;)
    {
        Token token = scanToken();
        if (token.type == TOKEN_EOF)
            break;

        if (token.type == TOKEN_ERROR)
        {
#ifdef DEBUG_CONSOLE
            printf("[line %d]: %.*s\n", token.line, token.length, token.start);
#endif
            fprintf(file, "[line %d]: %.*s\n", token.line, token.length, token.start);
        }
        else
        {
#ifdef DEBUG_CONSOLE
            printf("%-8d %.*s\n", getTokenOutputType(token.type), token.length, token.start);
#endif
            fprintf(file, "%-8d %.*s\n", getTokenOutputType(token.type), token.length, token.start);
        }
    }

    fclose(file);
}

int main(int argc, const char **argv)
{
    char *source = readFile(argv[1]);
    initScanner(source);
    listTokens(argv[2]);
    free(source);
}