#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
    int startaddress, locctr;
    char label[10], opcode[10], operand[10], optabopcode[10], address[10];
    FILE *input, *output, *symtab, *optab;
    input = fopen("input_pass1.txt", "r");
    optab = fopen("optab_pass1.txt", "r");
    symtab = fopen("symtab_pass1.txt", "w");
    output = fopen("output_pass1.txt", "w");
    fscanf(input, "%s %s %s", label, opcode, operand);
    fscanf(optab, "%s %s", optabopcode, address);
    if(strcmp(opcode, "START") == 0) {
        startaddress = atoi(operand);
        locctr = startaddress;
        fprintf(output, "%d START %d\n", startaddress, startaddress);
        fscanf(input, "%s %s %s", label, opcode, operand);
    } else {
        startaddress = 0;
        locctr = 0;
        fprintf(output, "%d ** START %d\n", startaddress, startaddress);
    }
    while(strcmp(opcode, "END") != 0) {
        if(strcmp(label, "**") == 0) {
            fscanf(optab, "%s %s", optabopcode, address);
            fprintf(output, "%d ** %s %s\n", locctr, opcode, operand);
            fscanf(input, "%s %s %s", label, opcode, operand);
            locctr += 3;
        } else {
            fprintf(symtab, "%s %d\n", label, locctr);
            fprintf(output, "%d %s %s %s\n", locctr, label, opcode, operand);
            if(strcmp(opcode, "WORD") == 0) {
                locctr += 3;
            } else if(strcmp(opcode, "RESW") == 0) {
                locctr = locctr + (3 * atoi(operand));
            } else if(strcmp(opcode, "RESB") == 0) {
                locctr += atoi(operand);
            } else {
                locctr += 1;
            }
            fscanf(input, "%s %s %s", label, opcode, operand);
        }
    }
    fprintf(output, "%d ** END %d", locctr, startaddress);
    printf("Program Length: %d\n", locctr-startaddress);
    return 0;
}