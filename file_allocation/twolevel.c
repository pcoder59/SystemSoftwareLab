#include<stdio.h>
#include<string.h>

struct file {
    char filename[100][25];
    char dirname[25];
    int fcnt;
}dir[100];

int dircount = 0;

void insertFile() {
    char name[25];
    int i, flag;
    printf("Enter Directory Name: ");
    scanf("%s", name);
    for(i = 0; i < dircount; i++) {
        if(strcmp(dir[i].dirname, name) == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        printf("Enter File Name: ");
        scanf("%s", dir[i].filename[dir[i].fcnt]);
        dir[i].fcnt++;
    } else {
        printf("Directory Not Found!\n");
    }
}

int searchFile() {
    char name[25];
    int i, j, flag = 0;
    printf("Enter File Name: ");
    scanf("%s", name);
    for(i = 0; i < dircount; i++) {
        for(j = 0; j < dir[i].fcnt; j++) {
            if(strcmp(dir[i].filename[j], name) == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) {
            break;
        }
    }
    if(flag == 1) {
        printf("File Found at directory %s, position %d\n", dir[i].dirname, j);
    } else {
        printf("File Not Found!\n");
    }
}

void deleteFile() {
    int pos, i , j, flag;
    char name[25];
    printf("Enter File Name: ");
    scanf("%s", name);
    for(i = 0; i < dircount; i++) {
        for(j = 0; j < dir[i].fcnt; j++) {
            if(strcmp(dir[i].filename[j], name) == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) {
            break;
        }
    }
    if(flag == 1) {
        strcpy(dir[i].filename[j], dir[i].filename[dir[i].fcnt-1]);
        dir[i].fcnt--;
        printf("File Deleted!\n");
    } else {
        printf("File Not Found!\n");
    }
}

void displayFile() {
    int i, j;
    for(i = 0; i < dircount; i++) {
        printf("DIRECTORY %s\n", dir[i].dirname);
        for(j = 0; j < dir[i].fcnt; j++) {
            printf("File %d - %s\n", j+1, dir[i].filename[j]);
        }
    }
}

void createDir() {
    printf("Enter Directory Name: ");
    scanf("%s", dir[dircount].dirname);
    dircount++;
}

int main() {
    int choice;
    do {
        printf("1. Create Directory\n");
        printf("2. Insert\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1 : createDir();
            break;
            case 2: insertFile();
            break;
            case 3:  searchFile();
            break;
            case 4: deleteFile();
            break;
            case 5: displayFile();
            break;
            case 6: break;
            default: printf("Invalid Choice!\n");
        }
    } while(choice != 6);
    return 0;
}