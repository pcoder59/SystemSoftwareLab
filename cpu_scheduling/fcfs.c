#include<stdio.h>
int main() {
    int n, i;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n], total_wait = 0, total_turn = 0;
    float atat, awt;
    printf("Enter Burst Time for Each Process: \n");
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time For Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    tat[0] = bt[0];
    total_turn = tat[0];
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
        total_wait += wt[i];
        total_turn += tat[i];
    }
    awt = total_wait/n;
    atat = total_turn/n;
    printf("Process\tBurst Time\tWait Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("Average Wait TIme: %d\n", awt);
    printf("Average Turnaround TIme: %d\n", atat);
    return 0;
}