#include <stdio.h>
#include <stdlib.h>

void work(int* arrival, int* burst, int N) {
    int waiting[N];
    int turnaround[N];
    int tmp[N];

    // Calculating waiting time
    tmp[0] = 0;
    waiting[0] = 0;

    for (int i = 1; i < N; i += 1) {
        tmp[i] = tmp[i - 1] + burst[i - 1];
        waiting[i] = tmp[i] - arrival[i];
        if (waiting[i] < 0) {
            waiting[i] = 0;
        }
    }

    // Calculating turnaround time
    for (int i = 0; i < N; i += 1) {
        turnaround[i] = burst[i] + waiting[i];
    }

    printf("\nP#\tCT\tTAT\tWT\n");
    int total_waiting = 0, total_turnaround = 0;
    for (int i = 0; i < N; i++) {
        int completion_time = turnaround[i] + arrival[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, completion_time, turnaround[i], waiting[i]);

        total_waiting += waiting[i];
        total_turnaround += turnaround[i];
    }

    printf("\nAVG WT:  %f\n", (float)total_waiting / N);
    printf("AVG TAT: %f\n", (float)total_turnaround / N);
}

int main() {
    int N;

    printf("Number of processes: ");
    scanf("%d", &N);

    int* arrival;
    arrival = (int*)malloc(sizeof(int) * N);
    int* burst;
    burst = (int*)malloc(sizeof(int) * N);
    
    printf("Enter arrival and brust time for each process:\n");
    for (int i = 0; i < N; i += 1) {
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    work(arrival, burst, N);
    return 0;
}