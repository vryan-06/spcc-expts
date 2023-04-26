#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
int main()
{
char opcode[10], mnemonic[10], operand[10], label[10], code[10]; 
int locctr = 0, start, length, flag = 0; 
FILE *fp1, *fp2,*fp3;
fp1 = fopen("Input.txt", "r"); 
fp2 = fopen("mnt.txt", "w"); 
fp3 = fopen("mdt.txt", "w");
fscanf(fp1, "%s%s%s", label, opcode, operand);
int count = 1; 
while(strcmp(opcode, "Start") != 0)
{ 
    if (strcmp(opcode, "MACRO") == 0)
{ 
    fscanf(fp1, "%s%s%s", label, opcode, operand); 
    fprintf(fp2, "%s %d \n", opcode, count);
    fscanf(fp1, "%s%s%s", label, opcode, operand);

while (strcmp(opcode, "MEND") != 0)
{ 
    count++; 
    fprintf(fp3, "%s %s\n", opcode, operand); 
    fscanf(fp1, "%s%s%s", label, opcode, operand); 
} 
count++; 
fprintf(fp3, "%s %s\n", opcode, "**");
}
fscanf(fp1, "%s%s%s", label, opcode, operand);
} 
fprintf(fp2, "%s %s\n", "END","**");
printf("Tables Updated Successfully!\n");
fclose(fp1); 
fclose(fp2); 
fclose(fp3);
return 0;
}




