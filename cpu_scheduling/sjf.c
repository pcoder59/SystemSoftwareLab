#include<stdio.h>
int main() {
    int n, i, j, temp;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    int p[n], pn[n], wt[n], tat[n];
    float total_turn = 0, total_wait = 0, atat = 0, awt = 0;
    printf("Enter Burst Time for Each Process: \n");
    for(i = 0; i < n; i++) {
        printf("Enter Burst TIme for Process %d: ", i+1);
        scanf("%d", &p[i]);
        pn[i] = i;
    }
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(p[i] > p[j]) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                pn[j] = i;
                pn[i] = j;
            }
        }
    }
    wt[0] = 0;
    tat[0] = p[0];
    total_turn = p[0];
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1]+p[i-1];
        tat[i] = wt[i] + p[i];
        total_turn += tat[i];
        total_wait += wt[i];
    }
    awt = total_wait/n;
    atat = total_turn/n;
    printf("Process\tBurst Time\tWait Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\n", pn[i]+1, p[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %f\n", awt);
    printf("Average Turnaround Time: %f\n", atat);
    return 0;
}