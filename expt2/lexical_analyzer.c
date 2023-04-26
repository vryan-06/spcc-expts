#include <stdio.h>
#include <string.h>
int IDflag;
void checkKeywords(char _token[])
{
    char keys[23][30] = {"if", "else", "while", "do", "break", "continue",
                         "int", "double", "float", "return", "char", "case",
                         "long", "sizeof", "typeof", "short", "typedef",
                         "unsigned", "switch", "void", "static", "struct", "goto"};
    int keyflag = 0;
    for (int i = 0; i < 23; i++)
    {
        if (strcmp(_token, keys[i]) == 0)
        {
            printf("keyword: ");
            printf("%s\n", _token);
            keyflag += 1;
        }
    }
    if (keyflag <= 0)
        IDflag += 1;
}
void checkLit(char _token[])
{
    char c = _token[0];
    if (c == '\'' || c == '\"')
    {
        printf("literal: ");
        printf("%s\n", _token);
    }
    else
        IDflag += 1;
}
void checkOp(char _token[])
{
    if (strcmp(_token, "+") == 0 || strcmp(_token, "++") == 0 || strcmp(_token, "-") == 0 || strcmp(_token, "--") == 0 || strcmp(_token, "*") == 0 || strcmp(_token, "/") == 0 || strcmp(_token, "=") == 0 || strcmp(_token, "==") == 0)
    {
        printf("operator: ");
        printf("%s\n", _token);
    }
    else
        IDflag += 1;
}
void checkConst(char _token[])
{
    if (isdigit(_token[0]) || (_token[0] == '-' && isdigit(_token[1])))
    {
        printf("const: ");
        printf("%s\n", _token);
    }
    else
        IDflag += 1;
}
void checkSymbol(char _token[])
{
    if (strcmp(_token, ";") == 0 || strcmp(_token, ",") == 0)
    {
        printf("special symbol: ");
        printf("%s\n", _token);
    }
    else
        IDflag += 1;
}
void checkID(char _token[])
{
    if (IDflag == 5)
    {
        printf("identifier: ");
        printf("%s\n", _token);
    }
    else
        IDflag += 1;
}

void main()
{
    char inpString[256];
    char ch; 
    // printf("The code\n");
    FILE *ptr = fopen("expt2_input.txt", "r");
    int count = 0;
    do
    {
        inpString[count] = fgetc(ptr); 
        // printf("%c", ch);
        count++;
    } while (inpString[count - 1] != EOF); 
    // printf("\n\nInput String \n%s\n",inpString);
    printf("\n-------BEGIN--------\n\n");
    char *token = strtok(inpString, " ");
    while (token != NULL)
    {
        if (token[0] == 'E' && token[1] == 'N' && token[2] == 'D')
        {
            printf("\n--------END---------\n");
            break;
        } 
        // printf( "token is %s\n", token);
        IDflag = 0;
        checkKeywords(token);
        checkLit(token);
        checkOp(token);
        checkConst(token);
        checkSymbol(token);
        checkID(token);
        token = strtok(NULL, " \n");
    }
}