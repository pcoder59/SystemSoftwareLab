#include<stdio.h>

int main() {
    int ind, f[50], i, flag = 0, n, index[50], count;
    char temp, ch;
    for(i = 0; i < 50; i++) {
        f[i] = 0;
    }
    do {
        printf("Enter Index Block: ");
        scanf("%d", &ind);
        if(f[ind] == 0) {
            printf("Enter Number of Blocks to Index: ");
            scanf("%d", &n);
            count = 0;
            for(i = 0; i < n; i++) {
                printf("Enter Block to Index: ");
                scanf("%d", &index[i]);
                if(f[index[i]] == 0) {
                    count++;
                } else {
                    printf("The Block is Already Allocated!\n");
                    break;
                }
            }
            if(count == n) {
                for(i = 0; i < n; i++) {
                    f[index[i]] = 1;
                    printf("%d -------- %d\n", ind, index[i]);
                }
                printf("File Allocated!\n");
            }
        } else {
            printf("Index Block is Already Allocated!\n");
        }
        printf("Do you want to enter more files? (Y/N): ");
        scanf("%c", &temp);
        scanf("%c", &ch);
    } while(ch == 'y' || ch == 'Y');
    return 0;
}