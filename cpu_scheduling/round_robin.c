#include<stdio.h>
int main() {
    int n, i, count, total = 0;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    int bt[n], tat[n], wt[n], rem[n], qt;
    float awt = 0, atat = 0;
    printf("Enter Burst TIme for Each Process: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &qt);
    while(1) {
        for(i = 0, count = 0; i < n; i++) {
            if(rem[i] == 0) {
                count++;
            } else {
                if(rem[i] > qt) {
                    rem[i] -= qt;
                    total += qt;
                } else {
                    total += rem[i];
                    rem[i] = 0;
                    tat[i] = total;
                }
            }
        }   
        if(count == n) {
            break;
        }
    }
    for(i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        awt += wt[i];
        atat += tat[i];
    }
    awt /= n;
    atat /= n;
    printf("Process\tBurst Time\tWait Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("Average Wait Time: %f\n", awt);
    printf("Average Turnaround Time: %f\n", atat);
    return 0;
}