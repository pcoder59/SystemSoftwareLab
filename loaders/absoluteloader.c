#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
    char read[50], name[50], objname[50], address[50];
    int i, j, addr;
    FILE *input;
    input = fopen("absolute_input.txt", "r");
    fscanf(input, "%s", read);
    printf("Enter Program Name: ");
    scanf("%s", name);
    for(i = 2, j = 0; i < 10; i++, j++) {
        if(read[i] == '^') {
            break;
        }
        objname[j] = read[i];
    }
    objname[j] = '\0';
    if(strcmp(objname, name) == 0) {
        fscanf(input, "%s", read);
        while(read[0] != 'E') {
            for(i=0, j=4; j < 8; i++, j++) {
                address[i] = read[j];
            }
            address[i] = '\0';
            addr = atoi(address);
            for(i = 12; read[i] != '$'; i=i+2, addr++) {
                if(read[i] == '^') {
                    i = i - 1;
                    addr = addr - 1;
                } else {
                    printf("%d %c%c\n", addr, read[i], read[i+1]);
                }
            }
            fscanf(input, "%s", read);
        }
    } else {
        printf("Error! Program Name From OBJ: %s", objname);
    }
    return 0;
}