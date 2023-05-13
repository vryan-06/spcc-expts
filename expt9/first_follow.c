#include <stdio.h>
#include <string.h>
int n, l = 0, m = 0, i = 0, j = 0;
char a[10][10], followResult[10], firstResult[10];
void follow(char c);
char first(char c);
int main()
{
    int i, z, opt;
    char c, ch;
    printf("Enter the no.of productions:");
    scanf("%d", &n);
    printf("Enter the productions(epsilon=~):\n");
    for (i = 0; i < n; i++)
        scanf("%s%c", a[i], &ch);
    do
    {
        printf("Do you wish to find FIRST(1) or FOLLOW(2):\n");
        scanf("%d", &opt);
        if (opt == 1)
        {
            l = 0;
            printf("Enter the element whose FIRST you want to find:\n");
            scanf(" %c", &c);
            first(c);
            int num = 10;
            for (int v1 = 0; v1 < num; v1++)
            {
                for (int v2 = v1 + 1; v2 < num; v2++)
                {
                    if (firstResult[v1] == firstResult[v2])
                    {
                        for (int v3 = v2; v3 < num; v3++)
                        {
                            firstResult[v3] = firstResult[v3 + 1];
                        }
                        v2--;
                        num--;
                    }
                }
            }
            printf("FIRST(%c) = { ", c);
            for (i = 0; i < num - 1; i++)
                printf("%c ", firstResult[i]);
            printf(" }\n");
        }
        else if (opt == 2)
        {
            m = 0;
            printf("Enter the element whose FOLLOW you want to find:\n");
            scanf(" %c", &c);
            follow(c);
            printf("FOLLOW(%c) = { ", c);
            for (i = 0; i < m; i++)
                printf("%c ", followResult[i]);
            printf(" }\n");
        }
        else
        {
            printf("Wrong option entered!!");
        }
        printf("Do you want to continue(0/1)?");
        scanf("%d%c", &z, &ch);
    } while (z == 1);
    printf("Exit");
}
void follow(char c)
{
    // checking if Start variable
    if (a[0][0] == c)
        followResult[m++] = '$';
    for (i = 0; i < n; i++)
    {
        for (j = 2; j < strlen(a[i]); j++)
        {
            if (a[i][j] == c)
            {
                if (a[i][j + 1] != '\0')
                    first(a[i][j + 1]);
                if (a[i][j + 1] == '\0' && c != a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}
char first(char c)
{
    int k;
    int foundEpsilon = 0;
    if (!(isupper(c)))
    {
        followResult[m++] = c;
        firstResult[l++] = c;
    }
    else
    {
        for (k = 0; k < n; k++)
        {
            if (a[k][0] == c)
            {
                if (a[k][2] == '~')
                {
                    foundEpsilon = 1;
                }
                else if (islower(a[k][2]))
                {
                    followResult[m++] = a[k][2];
                    firstResult[l++] = a[k][2];
                }
                else
                {
                    int j = 2;
                    do
                    {
                        foundEpsilon = 0;
                        if (first(a[k][j]) == '~')
                        {
                            j++;
                            foundEpsilon = 1;
                        }
                        else
                        {
                            foundEpsilon = 0;
                            break;
                        }
                    } while (foundEpsilon);
                }
            }
        }
    }
    if (foundEpsilon)
    {
        firstResult[l++] = '~';
        return '~';
    }
    return '\0';
}