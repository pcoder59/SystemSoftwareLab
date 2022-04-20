#include<stdio.h>
#include<string.h>
 char bitmask[12];

void convert(char bit[]) {
    int i;
    strcpy(bitmask, "");
    for(i = 0; i < 3; i++) {
        switch(bit[i]) {
            case '0' : strcat(bitmask, "0");
            break;
            case '1' : strcat(bitmask, "1");
            break;
            case '2' : strcat(bitmask, "10");
            break;
            case '3' : strcat(bitmask, "11");
            break;
            case '4' : strcat(bitmask, "100");
            break;
            case '5' : strcat(bitmask, "101");
            break;
            case '6' : strcat(bitmask, "110");
            break;
            case '7' : strcat(bitmask, "111");
            break;
            case '8' : strcat(bitmask, "1000");
            break;
            case '9' : strcat(bitmask, "1001");
            break;
            case 'A' : strcat(bitmask, "1010");
            break;
            case 'B' : strcat(bitmask, "1011");
            break;
            case 'C' : strcat(bitmask, "1100");
            break;
            case 'D' : strcat(bitmask, "1101");
            break;
            case 'E' : strcat(bitmask, "1110");
            break;
            case 'F' : strcat(bitmask, "1111");
            break;
        }
    }
}

int main() {
    int address, len, i, actual, operand;
    FILE *input, *output;
    char type[1], name[8], size[8], bit[3];
    input = fopen("relocating_input.txt", "r");
    output = fopen("relocating_output.txt", "w");
    fscanf(input, "%c %s %x %s", &type, name, &address, size);
    printf("Enter Actual Starting Address: ");
    scanf("%x", &actual);
    fscanf(input, "%s", &type);
    while(type[0] != 'E') {
        fscanf(input, "%x %s %s", &address, size, bit);
        address = address + actual;
        convert(bit);
        len = strlen(bitmask);
        if(len > 10) {
            len = 10;
        }
        for(i = 0; i < len; i++) {
            fscanf(input, "%s %x", bit, &operand);
            if(bitmask[i] == '1') {
                operand = operand + actual;
            }
            fprintf(output, "%x %s%x\n", address, bit, operand);
            address = address+3;
        }
        fscanf(input, "%s", &type);
    }
    return 0;
}