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
    int time = 0;
    int remaining_burst[n];
    int completed = 0;
   
   
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = proc[i].bt;
    }

    while (completed < n) {
        int min_priority = 1000000;  
        int min_priority_index = -1;
       
       
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0 && proc[i].priority < min_priority) {
                min_priority = proc[i].priority;
                min_priority_index = i;
            }
        }

       
        remaining_burst[min_priority_index]--;
        time++;
 
        if (remaining_burst[min_priority_index] == 0) {
            completed++;
            proc[min_priority_index].wt = time - proc[min_priority_index].bt;
            proc[min_priority_index].tat = proc[min_priority_index].wt + proc[min_priority_index].bt;
        }
    }

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
Enter number of processes: 4
Enter AT, BT, and Priority P1: 0 5 10
Enter AT, BT, and Priority P2: 1 4 20
Enter AT, BT, and Priority P3: 2 2 30
Enter AT, BT, and Priority P4: 4 1 40

Choose Scheduling Algorithm:
1. Preemptive Priority Scheduling
2. Non-Preemptive Priority Scheduling
Enter choice: 1

P#      AT      BT      PR      CT      TAT     WT
1       0       5       10      5       5       0
2       1       4       20      9       8       4
3       2       2       30      11      9       7
4       4       1       40      12      8       7
Average TAT: 7.50
Average WT: 4.50

Enter number of processes: 5
Enter AT, BT, and Priority P1: 0 3 5
Enter AT, BT, and Priority P2: 2 2 3
Enter AT, BT, and Priority P3: 3 5 2
Enter AT, BT, and Priority P4: 4 4 4
Enter AT, BT, and Priority P5: 6 1 1

Choose Scheduling Algorithm:
1. Preemptive Priority Scheduling
2. Non-Preemptive Priority Scheduling
Enter choice: 2

P#      AT      BT      PR      CT      TAT     WT
1       0       3       5       3       3       0
2       2       2       3       11      9       7
3       3       5       2       8       5       0
4       4       4       4       15      11      7
5       6       1       1       9       3       2
Average TAT: 6.20
Average WT: 3.20
