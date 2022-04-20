#include<stdio.h>
int main() {
    int n, i, j, temp;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], p[n], pn[n], wt[n], tat[n];
    float awt = 0, atat = 0;
    for(i = 0; i < n; i++) {
        printf("Enter Burst TIme for Process %d: ", i+1);
        scanf("%d", &bt[i]);
        printf("Enter Priority of Process %d (0 has highest priority): ", i+1);
        scanf("%d", &p[i]);
        pn[i] = i;
    }
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(p[i] > p[j]) {
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
                pn[i] = j;
                pn[j] = i;
                temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;
            }
        }
    }
    wt[0] = 0;
    tat[0] = bt[0];
    awt = 0;
    atat = bt[0];
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
    }
    awt /= n;
    atat /= n;
    printf("Process\tPriority\tBurst Time\tWait Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\t\t%d\n", pn[i]+1, p[i], bt[i], wt[i], tat[i]);
    }
    printf("Average Wait Time: %f\n", awt);
    printf("Average Turnaround Time: %f\n", atat);
    return 0;
}