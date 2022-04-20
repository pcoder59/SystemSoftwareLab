#include<stdio.h>
#include<string.h>
int main() {
    char address[50], label[50], opcode[50], operand[50], 
    symaddr[50], symbol[50], opaddr[50], startaddr[50], opname[50];
    int count = 0;
    FILE *input, *listing, *output, *symtab, *optab;
    input = fopen("input_pass2.txt", "r");
    listing = fopen("listing_pass2.txt", "w");
    output = fopen("output_pass2.txt", "w");
    symtab = fopen("symtab_pass2.txt", "r");
    optab = fopen("optab_pass2.txt", "r");
    fscanf(input, "%s %s %s %s", address, label, opcode, operand);
    strcpy(startaddr, address);
    if(strcmp("START", opcode) == 0) {
        fprintf(listing, "%s %s\n", address, opcode);
    }
    fprintf(output, "H^%s^%s^25\n", label, address);
    fprintf(output, "T^00%s^1E", address);
    fscanf(input, "%s %s %s %s", address, label, opcode, operand);
    while(strcmp("END", opcode) != 0) {
        if(strcmp("BYTE", opcode) == 0 || strcmp("WORD", opcode) == 0 || 
        strcmp("RESW", opcode) == 0 || strcmp("RESB", opcode) == 0) {
            if(count < 10) {
                fprintf(output, "^00000%s", operand);
                count = count + 1;
            } else {
                count = 1;
                fprintf(output, "\nT^00%s^1E",address);
                fprintf(output, "^00000%s", operand);
            }
        } else {
            if(strcmp("**", operand) != 0) {
                fscanf(symtab, "%s %s", symaddr, symbol);
                strcpy(operand, symaddr);
                if(count < 10) {
                    fprintf(output, "^00%s", operand);
                    count = count + 1;
                } else {
                    count = 1;
                    fprintf(output, "\nT^00%s^1E",address);
                    fprintf(output, "^00%s", operand);
                }
            } else {
                fscanf(optab, "%s %s", opname, opaddr);
                if(count < 10) {
                    fprintf(output, "^0000%s", opaddr);
                    count = count + 1;
                } else {
                    count = 1;
                    fprintf(output, "\nT^00%s^1E",address);
                    fprintf(output, "^0000%s", opaddr);
                }
            }
        }
        fprintf(listing, "%s %s\n", address, opcode);
        fscanf(input, "%s %s %s %s", address, label, opcode, operand);
    }
    fprintf(output, "\nE^00%s", startaddr);
    fprintf(listing, "%s %s", startaddr, opcode);
    return 0;
}