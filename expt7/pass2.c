#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void main()
{
    char opcode[10], mnemonic[10], operand[10], operand1[10], label[10], code[10], address[10], sizeAddress[10], Motlabel[10];
    int locctr = 0, start, length, flag = 0;
    FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6, *fp411;
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("st.txt", "r");
    fp3 = fopen("out.txt", "r");
    fp4 = fopen("mot.txt", "r");
    fp411 = fopen("mot.txt", "r");
    fp5 = fopen("bt.txt", "w");
    fp6 = fopen("outTable.txt", "w");
 
    fscanf(fp1, "%s %s %s", label, opcode, operand1);
 
    if (strcmp(opcode, "START") == 0)
    {
        fscanf(fp1, "%s %s %s", label, opcode, operand1);
    }
    else
        locctr = 0;
    while (strcmp(opcode, "END") != 0)
    {
        fscanf(fp4, "%s", mnemonic);
        fscanf(fp411, "%s", Motlabel);
        while (strcmp(Motlabel, opcode) != 0 && strcmp(Motlabel, "END") != 0)
        {
            fscanf(fp411, "%s", Motlabel);
        }
 
        fscanf(fp411, "%s", Motlabel);
        if (strcmp(Motlabel, "END") != 0)
        {
            char sub = operand1[0];
            char substring[4];
            int j = 0;
            for (int i = 2; i < 6; i++)
            {
                substring[j++] = operand1[i];
            }
            fprintf(fp6, "%s %c, ", Motlabel, operand1[0]);
            for (int i = 0; i < 4; i++)
            {
                fprintf(fp6, "%c", substring[i]);
            }
            fprintf(fp6, "\n");
        }
        rewind(fp411);
        if (strcmp(opcode, "DC") == 0)
        {
            if (operand1[0] == 'F')
            {
                locctr += 4;
            }
            else
            {
                locctr += 2;
            }
            fprintf(fp6, "%d %c\n", locctr, operand1[2]);
        }
        else if (strcmp(opcode, "DS") == 0)
        {
            if (operand1[1] == 'F')
            {
                locctr += 4;
            }
            else
            {
                locctr += 2;
            }
            fprintf(fp6, "%d _\n", locctr);
        }
        else if (strcmp(opcode, "USING") == 0)
        {
            locctr += 0;
            fprintf(fp5, "%c%c", operand1[2], operand1[3]);
            printf("\nusing\n");
        }
        while (strcmp(mnemonic, "END") != 0)
        {
            printf("%s\t%s\n", opcode, mnemonic);
            if (strcmp(opcode, mnemonic) == 0)
            {
                printf("\ninside the loop\n");
                locctr += 4;
                flag = 1;
                break;
            }
            fscanf(fp4, "%s", mnemonic);
        }
        printf("%d\n", flag);
        flag = 0;
        fscanf(fp1, "%s %s %s", label, opcode, operand1);
        rewind(fp4);
    }
    printf("\nThe length of the program is %d", length);
}
