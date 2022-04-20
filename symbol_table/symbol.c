#include<stdio.h>
#include<string.h>
#define MAX 100;
struct symbol {
    char symbol[30];
    char address[30];
}s[100];
int top = 0;

void insert() {
    if(top == 100) {
        printf("No Space for More Symbols!\n");
    } else {
        printf("Enter Symbol to Insert: ");
        scanf("%s", s[top].symbol);
        printf("Enter Address of Symbol: ");
        scanf("%s", s[top].address);
        top++;
    }
}

void search() {
    int i, flag = 0;
    char symbol[30];
    printf("Enter Symbol to Search For: ");
    scanf("%s", symbol);
    for(i = 0; i < top; i++) {
        if(strcmp(s[i].symbol, symbol) == 0) {
            flag = 1;
            printf("Symbol %s found at address %s!\n", symbol, s[i].address);
            break;
        }
    }
    if(flag == 0) {
        printf("Symbol Not Found!\n");
    }
}

void modify() {
    int i, flag = 0;
    char symbol[30];
    printf("Enter Symbol to Modify: ");
    scanf("%s", symbol);
    for(i = 0; i < top; i++) {
        if(strcmp(s[i].symbol, symbol) == 0) {
            flag = 1;
            printf("Enter New Address: ");
            scanf("%s", s[i].address);
            break;
        }
    }
    if(flag == 0) {
        printf("Symbol Not Found!\n");
    }
}

void delete() {
    int i, flag = 0;
    char symbol[30];
    if(top == 0) {
        printf("No Symbols in Symbol Table!\n");
    } else {
        printf("Enter Symbol to Delete: ");
        scanf("%s", symbol);
        for(i = 0; i < top; i++) {
            if(strcmp(s[i].symbol, symbol) == 0) {
                flag = 1;
                strcpy(s[i].symbol, s[top-1].symbol);
                strcpy(s[i].address, s[top-1].address);
                top--;
                break;
            }
        }
        if(flag == 0) {
            printf("Symbol Not Found!\n");
        }
    }
}

int main() {
    int ch;
    do {
        printf("Menu:\n");
        printf("1. Insert Symbol\n");
        printf("2. Search Symbol\n");
        printf("3. Modify Symbol\n");
        printf("4. Delete Symbol\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1 : insert();
            break;
            case 2 : search();
            break;
            case 3 : modify();
            break;
            case 4 : delete();
            break;
            case 5 :
            break;
            default : printf("Invalid Choice!\n");
        }
    } while(ch != 5);
    return 0;
}