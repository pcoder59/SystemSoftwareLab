#include<stdio.h>

int main() {
    int f[50], start, length, count, i;
    char ch, temp;
    for(i = 0; i < 50; i++) {
        f[i] = 0;
    }
    do {
        printf("Enter Starting Block and Length of File: ");
        scanf("%d", &start);
        scanf("%d", &length);
        count = 0;
        for(i = 0; i < length; i++) {
            if(f[start+i] == 0) {
                count++;
            }
        }
        if(count == length) {
            for(i = 0; i < length; i++) {
                f[start+i] = 1;
            }
            printf("File is Allocated!\n");
        } else {
            printf("File Cannot be Allocated!\n");
        }
        printf("Do You Want to Enter More Files (Y/N): ");
        scanf("%c", &temp);
        scanf("%c", &ch);
    } while(ch == 'y' || ch == 'Y');
    return 0;
}