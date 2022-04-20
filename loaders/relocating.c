#include<stdio.h>
#include<string.h>

char bit[12];

void convert(char mask[3]) {
    int i;
    strcpy(bit, "");
    for(i = 0; i < 3; i++) {
        switch(mask[i]) {
            case '0' : strcat(bit, "0");
            break;
            case '1' : strcat(bit, "1");
            break;
            case '2' : strcat(bit, "10");
            break;
            case '3' : strcat(bit, "11");
            break;
            case '4' : strcat(bit, "100");
            break;
            case '5' : strcat(bit, "101");
            break;
            case '6' : strcat(bit, "110");
            break;
            case '7' : strcat(bit, "111");
            break;
            case '8' : strcat(bit, "1000");
            break;
            case '9' : strcat(bit, "1001");
            break;
            case 'A' : strcat(bit, "1010");
            break;
            case 'B' : strcat(bit, "1011");
            break;
            case 'C' : strcat(bit, "1100");
            break;
            case 'D' : strcat(bit, "1101");
            break;
            case 'E' : strcat(bit, "1110");
            break;
            case 'F' : strcat(bit, "1111");
            break;
        }
    }
}

int main() {
    FILE *input, *output;
    char type[10], name[8], mask[3], opcode[2], temp;
    int address, length, addr, len, i, operand, enter = 0;
    printf("Enter Actual Starting Address: ");
    scanf("%x", &addr);
    input = fopen("relocating_input.txt", "r");
    output = fopen("relocating_output.txt", "w");
    fscanf(input, "%s", type);
    while(strcmp(type, "E") != 0) {
        if(strcmp(type, "H") == 0) {
            fscanf(input, "%s", name);
            fscanf(input, "%x", &address);
            fscanf(input, "%x", &length);
            fscanf(input, "%s", type);
        }
        if(strcmp(type, "T") == 0) {
            fscanf(input, "%x", &address);
            fscanf(input, "%x", &length);
            fscanf(input, "%s", mask);
            address = address + addr;
            convert(mask);
            len = strlen(bit);
            if(len > 10) {
                len = 10;
            }
            for(i = 0; i < len; i++) {
                fscanf(input, "%s", opcode);
                fscanf(input, "%x", &operand);
                if(bit[i] == '1') {
                    operand = operand + addr;
                }
                fprintf(output, "%x %s%x\n", address, opcode, operand);
                address = address + 3;
            }
            fscanf(input, "%s", type);
        }
    }
    return 0;
}