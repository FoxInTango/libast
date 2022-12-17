#ifndef _AST_TOKEN_H_
#define _AST_TOKEN_H_
typedef enum _ASTTokenType{

}ASTTokenType;
typedef struct _ASTToken {
    ASTTokenType type;
    wchar_t* name;
    wchar_t* value;
    wchar_t* documentURL;
    unsigned int lineIndex;
    unsigned int charIndex;
}ASTToken;
 #endif