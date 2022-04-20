#include<stdio.h>

int main() {
    int f[50], n, i, start, length;
    char ch, temp;
    for(i = 0; i < 50; i++) {
        f[i] = 0;
    }
    printf("Enter Number of Blocks Already Allocated: ");
    scanf("%d", &n);
    printf("Enter Blocks Already Allocated: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &start);
        f[start] = 1;
    }
    do {
        printf("Enter Start and Length of Block to Allocate: ");
        scanf("%d", &start);
        scanf("%d", &length);
        if(f[start] == 1) {
            printf("Start Block is Already Allocated! Cannot Allocate This File!\n");
        } else {
            for(i = 0; i < length; i++) {
                if(f[start+i] == 0) {
                    printf("%d----------> Allocated\n", start+i);
                    f[start+i] = 1;
                } else {
                    printf("%d is Already Allocated\n", start+i);
                    length = length+1;
                }
            }
        }
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &temp);
        scanf("%c", &ch);
    }while(ch == 'y' || ch == 'Y');
    return 0;
}