#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *isInMot(const char *symbol)
{
    FILE *fp;
    char line[255];

    fp = fopen("mot.txt", "r");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        const char *val1 = strtok(line, " ");

        if (strcmp(val1, symbol) != 0)
            continue;

        const char *val2 = strtok(NULL, " ");

        // printf("Found in MOT %s - %s\n", val1, val2);
        return val2;
    }

    return NULL;
}

int pass1()
{
    FILE *fp, *fw;
    char line[255];
    int line_no = 0;

    fw = fopen("symbol_table.txt", "w");
    fp = fopen("input.txt", "r");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        const char *val1 = strtok(line, " ");
        const char *val2 = strtok(NULL, " ");
        const char *val3 = strtok(NULL, " ");

        if (val2 == NULL)
        {
            // One token
            printf("%d\t%s\n", line_no, val1);
        }
        else if (val3 == NULL)
        {
            // Two tokens
            printf("%d\t%s|%s", line_no, val1, val2);

            if (strcmp(val2, "START\n") == 0 || strcmp(val1, "USING") == 0)
            {
                // printf("Skip iteration\n");
                continue;
            }

            const char *opcode = isInMot(val1);
            if (opcode == NULL)
                printf("Char not found. %s\n", val1);

            line_no += 4;
        }
        else
        {
            // Three Tokens
            if (isInMot(val1) == NULL)
            {
                switch (*val3)
                {
                case 'F':
                    line_no += 4;
                    break;
                case 'H':
                    line_no += 2;
                    break;
                default:
                    line_no += 2;
                    break;
                }
                fprintf(fw, "%s %d\n", val1, line_no);
            }

            printf("%d\t%s|%s|%s", line_no, val1, val2, val3);
        }
    }

    fclose(fp);
    fclose(fw);
    return 0;
}

int main(void)
{
    printf("=== Pass 1 ===\n");
    int status = pass1();

    if (status != 0)
    {
        printf("Failed to parse in pass 1\n");
        return 1;
    }
    
    return 0;
}