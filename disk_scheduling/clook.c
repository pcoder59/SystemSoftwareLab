#include<stdio.h>

void sortArray(int requests [], int n) {
    int i, j, temp;
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(requests[j] < requests[i]) {
                temp = requests[j];
                requests[j] = requests[i];
                requests[i] = temp;
            }
        }
    }
}

int findPos(int requests[], int head, int n) {
    int i, pos;
    for(i = 0; i < n; i++) {
        if(requests[i] >= head) {
            pos = i;
            break;
        }
    }
    return pos;
}

int main() {
    int n, head, pos, i;
    printf("Enter Number of Requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter Requests: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    sortArray(requests, n);
    printf("Enter Head Position: ");
    scanf("%d", &head);
    pos = findPos(requests, head, n);
    printf("Seek Sequence is: ");
    for(i = pos; i < n; i++) {
        printf("%d ", requests[i]);
    }
    for(i = 0; i < pos; i++) {
        printf("%d ", requests[i]);
    }
    printf("\n");
}