#include<stdio.h>
#include<string.h>

struct file {
    char filename[100][25];
    char dirname[25];
    int fcnt;
}dir;

void insertFile() {
    printf("Enter File Name: ");
    scanf("%s", dir.filename[dir.fcnt]);
    dir.fcnt++;
}

int searchFile() {
    char name[25];
    int i, flag = 0;
    printf("Enter File Name: ");
    scanf("%s", name);
    for(i = 0; i < dir.fcnt; i++) {
        if(strcmp(dir.filename[i], name) == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        printf("File Found at position %d\n", i);
        return i;
    } else {
        printf("File Not Found!\n");
        return -1;
    }
}

void deleteFile() {
    int pos;
    pos = searchFile();
    if(pos != -1) {
        strcpy(dir.filename[pos], dir.filename[dir.fcnt-1]);
        dir.fcnt--;
        printf("File Deleted!\n");
    } else {
        printf("File Not Found!\n");
    }
}

void displayFile() {
    int i;
    printf("DIRECTORY %s\n", dir.dirname);
    for(i = 0; i < dir.fcnt; i++) {
        printf("File %d - %s\n", i+1, dir.filename[i]);
    }
}

int main() {
    int choice;
    dir.fcnt = 0;
    printf("Enter Directory Name: ");
    scanf("%s", dir.dirname);
    do {
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1 : insertFile();
            break;
            case 2: searchFile();
            break;
            case 3: deleteFile();
            break;
            case 4: displayFile();
            break;
            default: printf("Invalid Choice!\n");
        }
    } while(choice != 5);
    return 0;
}