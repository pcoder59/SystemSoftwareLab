#include<stdio.h>
#include<stdlib.h>

int searchpage(int frames[], int p, int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(frames[i] == p) {
            return 0;
        }
    }
    return 1;
}

int hitposition(int frames[], int p, int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(frames[i] == p) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, p, i, j, count = 0, start = 0, faults = 0, pos;
    printf("Enter Number of Frames: ");
    scanf("%d", &n);
    int frames[n], hp[n];
    for(i = 0; i < n; i++) {
        frames[i] = -1;
        hp[i] = 0;
    }
    printf("Enter Number of Pages: ");
    scanf("%d", &p);
    int pages[p];
    printf("Enter The Pages: ");
    for(i = 0; i < p; i++) {
        scanf("%d", &pages[i]);
    }
    for(i = 0; i < p; i++) {
        if(count == n) {
            if(searchpage(frames, pages[i], n)) {
                pos = 0;
                for(j = 1; j < n; j++) {
                    if(hp[j] > hp[pos]) {
                        pos = j;
                    }
                }
                frames[pos] = pages[i];
                faults++;
                hp[pos] = 0;
            } else {
                pos = hitposition(frames, pages[i], n);
                if(pos == -1) {
                    exit(-1);
                }
                hp[pos] += 1;
            }
        } else {
            if(searchpage(frames, pages[i], n)) {
                frames[start] = pages[i];
                start++;
                count++;
                faults++;
            } else {
                pos = hitposition(frames, pages[i], n);
                if(pos == -1) {
                    exit(-1);
                }
                hp[pos] += 1;
            }
        }
        for(j = 0; j < n; j++) {
            printf("%d\t", frames[j]);
        }
        printf("\n");
    }
    printf("Number of Page Faults: %d\n", faults);
    return 0;
}