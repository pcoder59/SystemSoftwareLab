#include<stdio.h>
#include<string.h>
int main() {
    int i = 1, j, address, flag = -1;
    FILE *input, *output, *namtab, *deftab;
    char label[25], opcode[25], operand[25], name[25], defl[25], defop[25], defand[25];
    input = fopen("macroin.txt", "r");
    output = fopen("macroout.txt", "w");
    namtab = fopen("namtab.txt", "w+");
    deftab = fopen("deftab.txt", "w+");
    fscanf(input, "%s %s %s", label, opcode, operand);
    while(strcmp(opcode, "END") != 0) {
        if(strcmp(opcode, "MACRO") == 0) {
            fprintf(namtab, "%s %d\n", label, i);
            while(strcmp(opcode, "MEND") != 0) {
                fscanf(input, "%s %s %s", label, opcode, operand);
                fprintf(deftab, "%s %s %s\n", label, opcode, operand);
                i += 1;
            }
            fscanf(input, "%s %s %s", label, opcode, operand);
        } else if(strcmp(opcode, "START") == 0) {
            fprintf(output, "%s %s %s\n", label, opcode, operand);
            fscanf(input, "%s %s %s", label, opcode, operand);
        } else {
            flag = 0;
            fseek(namtab, 0, SEEK_SET);
            fseek(deftab, 0, SEEK_SET);
            while(!feof(namtab)) {
                fscanf(namtab, "%s %d", name, &address);
                if(strcmp(name, opcode) == 0) {
                    flag = 1;
                    i = address;
                    for(j = 0; j < i; j++) {
                        fscanf(deftab, "%s %s %s", defl, defop, defand);
                    }
                    while(strcmp(defop, "MEND") != 0) {
                        fprintf(output, "%s %s %s\n", defl, defop, defand);
                        fscanf(deftab, "%s %s %s", defl, defop, defand);
                    }
                    break;
                }
            }
            fscanf(input, "%s %s %s", label, opcode, operand);
        }
        if(flag == 0) {
            fprintf(output, "%s %s %s\n", label, opcode, operand);
            fscanf(input, "%s %s %s", label, opcode, operand);
        }
    }
    fprintf(output, "%s %s %s\n", label, opcode, operand);
    return 0;
}