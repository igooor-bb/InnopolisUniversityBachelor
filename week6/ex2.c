#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

struct Process {
    int pid; // Process ID
    int at;  // Arrival time
    int bt;  // Burst Time
};

void calculate_waiting_time(struct Process* proc, int wt[], int N) {
    int rt[N]; // Remaining time

    for (int i = 0; i < N; i += 1) {
        rt[i] = proc[i].bt;
    }

    int completed = 0, t = 0;
    int min = INT_MAX; 
    int shortest = 0, finish_time; 
    int flag = FALSE;

    while (completed != N) {
        for (int i = 0; i < N; i += 1) {
            if ((proc[i].at <= t) && (rt[i] < min) && rt[i] > 0) { 
                min = rt[i]; 
                shortest = i; 
                flag = TRUE; 
            }
        }

        if (flag == FALSE) {
            t += 1;
            continue;
        }

        // Decrease remaining time
        rt[shortest] -= 1;

        // Update the minimum time process
        min = rt[shortest];
        if (min == 0) min = INT_MAX;

        // If the process is completed
        if (rt[shortest] == 0) {
            completed += 1;
            flag = FALSE;

            finish_time = t + 1;
            // Calculate wating time
            wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].at;

            if (wt[shortest] < 0) wt[shortest] = 0; 
        }
        t += 1;
    }
}

void calculate_turnaround_time(struct Process* proc, int wt[], int tat[], int N) {
    for (int i = 0; i < N; i += 1) {
        tat[i] = proc[i].bt + wt[i];
    } 
}

void calculate_average_time(struct Process* proc, int N) {
    int wt[N]; // Wating time
    int tat[N]; // Turnaround time
    int total_wt = 0, total_tat = 0;

    calculate_waiting_time(proc, wt, N);
    calculate_turnaround_time(proc, wt, tat, N);

    // Display resulsts
    printf("\nP#\tBT\tWT\tTAT\n");
    
    for (int i = 0; i < N; i += 1) {
        printf("P%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].bt, wt[i], tat[i]);

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage waiting time: %f\n", (float)total_wt / N);
    printf("Average turnaround time: %f\n", (float)total_tat / N);
}

int main() {
    int N;
    
    printf("Number of processes: ");
    scanf("%d", &N);

    // Allocating memory for processes data.
    struct Process* proc;
    proc = (struct Process*)malloc(sizeof(struct Process) * N);

    // Input processes data.
    printf("Enter arrival and brust time for each process:\n");
    for (int i = 0; i < N; i += 1) {
        printf("P%d: ", i+1);
        proc[i].pid = i + 1;
        scanf("%d %d", &(proc[i].at), &(proc[i].bt));
    }

    calculate_average_time(proc, N);
    return 0;
}