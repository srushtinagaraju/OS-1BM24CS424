#include <stdio.h>

struct process {
    int id;
    int bt;
    int priority;
    int wt;
    int tat;
};

void findWaitingTime(struct process proc[], int n) {
    proc[0].wt = 0;
    for (int i = 1; i < n; i++) {
        proc[i].wt = proc[i - 1].bt + proc[i - 1].wt;
    }
}

void findTurnAroundTime(struct process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt;
    }
}

void findAverageTime(struct process proc[], int n) {
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_tat / n);
}

void priorityScheduling(struct process proc[], int n) {
    struct process temp;


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].priority > proc[j].priority) {

                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    findWaitingTime(proc, n);
    findTurnAroundTime(proc, n);
    findAverageTime(proc, n);

    printf("\n\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", proc[i].id, proc[i].bt, proc[i].priority, proc[i].wt, proc[i].tat);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("\nEnter burst time for process %d: ", proc[i].id);
        scanf("%d", &proc[i].bt);
        printf("Enter priority for process %d: ", proc[i].id);
        scanf("%d", &proc[i].priority);
    }

    priorityScheduling(proc, n);
    return 0;
}

//OUTPUT
Enter the number of processes: 3

Enter burst time for process 1: 6
Enter priority for process 1: 2

Enter burst time for process 2: 8
Enter priority for process 2: 1

Enter burst time for process 3: 7
Enter priority for process 3: 3


Average Waiting Time: 7.33
Average Turnaround Time: 14.33

Process ID    Burst Time    Priority    Waiting Time    Turnaround Time
2             8             1           0              8
1             6             2           8              14
3             7             3           14             21
