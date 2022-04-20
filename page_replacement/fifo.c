#include<stdio.h>

int searchpage(int frames[], int p, int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(frames[i] == p) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, p, i, j, count = 0, start = 0, faults = 0;
    printf("Enter Number of Frames: ");
    scanf("%d", &n);
    int frames[n];
    for(i = 0; i < n; i++) {
        frames[i] = -1;
    }
    printf("Enter Number of Pages: ");
    scanf("%d", &p);
    int pages[p];
    printf("Enter Page String: ");
    for(i = 0; i < p; i++) {
        scanf("%d", &pages[i]);
    }
    for(i = 0; i < p; i++) {
        if(count == n) {
            if(searchpage(frames, pages[i], n)) {
                faults++;
                frames[start] = pages[i];
                start++;
                if(start == n) {
                    start = 0;
                }
            }
        } else {
            if(searchpage(frames, pages[i], n)) {
                frames[start] = pages[i];
                start++;
                count++;
                faults++;
                if(start == n) {
                    start = 0;
                }
            }
        }
        for(j = 0; j < n; j++) {
            printf("%d\t", frames[j]);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", faults);
}