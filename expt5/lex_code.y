%{
#include<stdio.h>
%}
%token NUMBER ID
// setting the precedence
// and associativity of operators
%left '+' '-'
%left '*' '/'

%%
E : T {printf("Result = %d\n", $$);return 0;}
T : T '+' T { $$ = $1 + $3; }
| T '-' T { $$ = $1 - $3; }
| T '*' T { $$ = $1 * $3; }
| T '/' T { $$ = $1 / $3; }
| NUMBER { $$ = $1; }
%%

int main()
{
    printf("Enter the expression\n");
    yyparse();
}

int yyerror(char* s)
{
    printf("\nExpression is invalid\n");
}