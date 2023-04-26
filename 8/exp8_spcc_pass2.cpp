#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
int checkIfPresent(char inputOpcode[]) // this function will return position of macroname in mnt if present
{ 
    char macroname[10], mdtpointer[10]; char label[10], opcode[10], operand[10]; 
    FILE *mnptr;
    mnptr = fopen("mnt.txt", "r");
    fscanf(mnptr, "%s%s", macroname, mdtpointer);
    int i = 0;
    while (strcmp(macroname, "END") != 0)
{ 
    if (strcmp(inputOpcode, macroname) == 0)
{ 
    return i; 
} 
    fscanf(mnptr, "%s%s", macroname, mdtpointer); 
    i++; 
} 
    return -1; 
}
int main()
{
char opcode[10], mnemonic[10], operand[10], label[10], code[10],macroname[10], opcodemdt[10], operandmdt[10];
int mdtline[10],locctr = 0, start, length, flag= 0; 
FILE *fp1, *fp2, *fp3, *fp4;
fp1 = fopen("Input.txt", "r"); 
fp2 = fopen("mnt.txt", "r"); 
fp3 = fopen("mdt.txt", "r"); 
fp4 = fopen("expsrc.txt", "w"); // Ignoring macro definition lines 
while (strcmp(opcode,"Start") != 0)
{ 
    fscanf(fp1, "%s%s%s", label, opcode, operand); 
} 
fprintf(fp4, "%s %s %s\n", label, opcode, operand);
while (strcmp(opcode, "END") != 0)
{ 
    fscanf(fp1, "%s%s%s", label, opcode, operand);
    int x = checkIfPresent(opcode);
    if (x != -1) 
    { 
     fscanf(fp2, "%s%d", macroname, mdtline);
     for (int i = 0; i < x; i++)
    {
     fscanf(fp2, "%s%d", macroname, mdtline);
    }
    for (int i = 0; i < *mdtline; i++)
    { 
     fscanf(fp3, "%s%s", opcodemdt, operandmdt);
    }
    while (strcmp(opcodemdt, "MEND") != 0)
    { 
     fprintf(fp4, "%s %s %s\n", "**", opcodemdt, operandmdt); 
     fscanf(fp3, "%s%s", opcodemdt, operandmdt);
    }
    rewind(fp3); 
    rewind(fp2); 
    continue;
    } 
    fprintf(fp4,"%s %s %s\n", label, opcode, operand);
}
printf("Expanded Source Code generated successfully!\n");
fclose(fp1); 
fclose(fp2); 
fclose(fp3); 
fclose(fp4);

return 0;
}


