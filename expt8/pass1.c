#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char opcode[10], mnemonic[10], operand[10], label[10], code[10], address[10], sizeAddress[10],
        Motlabel[10];
    int locctr = 0, start, length, flag = 0, mntc = 1, mdtp = 1;
    FILE *fp1, *fp2, *fp3, *fp4;
    fp1 = fopen("Input.txt", "r");
    fp2 = fopen("MNT.txt", "w");
    fp3 = fopen("MDT.txt", "w");
    fp4 = fopen("Copyfile.txt", "w");
    fscanf(fp1, "%s %s %s", label, opcode, operand);
    while (strcmp(opcode, "END") != 0)
    {
        if (strcmp(opcode, "MACRO") == 0)
        {
            while (strcmp(opcode, "MEND") != 0)
            {
                fscanf(fp1, "%s %s %s", label, opcode, operand);
                if (strcmp(operand, "**") == 0 && strcmp(opcode, "MEND") != 0)
                {
                    fprintf(fp2, "%d %s %d\n", mntc, opcode, mdtp);
                    mntc++;
                }
                fprintf(fp3, "%d %s %s %s\n", mdtp, label, opcode, operand);
                mdtp++;
            }
        }
        fscanf(fp1, "%s %s %s", label, opcode, operand);
        if (strcmp(opcode, "MACRO") != 0)
            fprintf(fp4, "%s %s %s\n", label, opcode, operand);
    }
    return 0;
}