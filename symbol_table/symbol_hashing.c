#include<stdio.h>
#include<string.h>
struct symtab {
    char symbol[30];
    char address[30];
    int flag;
}s[97];

int hash(char symbol[]) {
    int i, h, sum = 0;
    for(i = 0; i < strlen(symbol); i++) {
        sum += (int)symbol[i];
    }
    h = sum % 97;
    return h;
}

void Insert() {
    int h, i, repeat = 0;
    char symbol[30], address[30];
    printf("Enter Symbol to Insert: ");
    scanf("%s", symbol);
    h = hash(symbol);
    printf("Enter Address of Symbol: ");
    scanf("%s", address);
    if(s[h].flag == 0) {
        strcpy(s[h].symbol, symbol);
        strcpy(s[h].address, address);
        s[h].flag = 1;
    } else {
        i = h + 1;
        while(s[i].flag != 0) {
            if(i == h) {
                repeat = 1;
                break;
            }
            i = (i+1)%97;
        }
        if(repeat == 1) {
            printf("No Space to Insert Symbol!\n");
        } else {
            strcpy(s[i].symbol, symbol);
            strcpy(s[i].address, address);
            s[i].flag = 1;
        }
    }
}

void Search() {
    int h, i, repeat = 1;
    char symbol[30];
    printf("Enter Symbol to Search For: ");
    scanf("%s", symbol);
    h = hash(symbol);
    if((s[h].flag == 1) && (strcmp(s[h].symbol, symbol) == 0)) {
        printf("Symbol %s found at Address %s!\n", symbol, s[h].address);
    } else {
        i = h + 1;
        while((s[i].flag != 0) && (strcmp(s[i].symbol, symbol) != 0)) {
            if(i == h) {
                repeat = 1;
                break;
            }
            i = (i+1)%97;
        }
        if(repeat == 1) {
            printf("Symbol Not Found!\n");
        } else {
            printf("Symbol %s found at Address %s!\n", symbol, s[i].address);
        }
    }
}

void Display() {
    int i;
    printf("Symbol Table:\n");
    for(i = 0; i < 97; i++) {
        if(s[i].flag != 0) {
            printf("%s\t%s\n", s[i].symbol, s[i].address);
        }
    }
}

int main() {
    int ch = 0, i;
    for(i = 0; i < 97; i++) {
        s[i].flag = 0;
    }
    while(ch != 4) {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1 : Insert();
            break;
            case 2 : Search();
            break;
            case 3 : Display();
            break;
            case 4 :
            break;
            default : printf("Invalid Choice!\n");
        }

    }
    return 0;
}