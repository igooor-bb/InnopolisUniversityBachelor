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

void calculate_complete_time(struct Process* proc, int ct[], int quantum, int N) {
    int rt[N]; // Remaining time

    for (int i = 0; i < N; i += 1) {
        rt[i] = proc[i].bt;
    }

    int t = 0;
    int arrival = 0;

    while (TRUE) {
        int flag = TRUE;

        for (int i = 0; i < N; i += 1) {
            if (rt[i] > 0) {
                flag = FALSE;
                if (rt[i] > quantum && proc[i].at <= arrival) {
                    t += quantum;
                    rt[i] -= quantum;
                    arrival += 1;
                } else if (proc[i].at <= arrival) {
                    arrival += 1;
                    t += rt[i];
                    rt[i] = 0;
                    ct[i]= t; 
                }
            }
        }
        if (flag == TRUE) break;
    }
}

void calculate_turnaround_time(struct Process* proc, int ct[], int wt[], int tat[], int N) {
    for (int i = 0; i < N; i += 1) {
        tat[i] = ct[i] - proc[i].at;
        wt[i] = tat[i] - proc[i].bt;
    } 
}

void calculate_average_time(struct Process* proc, int N, int quantum) {
    int wt[N]; // Wating time
    int tat[N]; // Turnaround time
    int ct[N]; // Complete time
    int total_wt = 0, total_tat = 0;

    calculate_complete_time(proc, ct, quantum, N);
    calculate_turnaround_time(proc, ct, wt, tat, N);

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
    int quantum = 2;
    
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

    calculate_average_time(proc, N, quantum);
    return 0;
}