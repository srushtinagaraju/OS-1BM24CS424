#include <stdio.h>
#define MAX 100

typedef struct {
    int at, bt, rt, ct, tat, wt;
} Process;

int main() {
    int n, completed = 0, time = 0, min_rt, shortest;
    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("AT & BT of P%d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    while (completed < n) {
        shortest = -1, min_rt = 1e9;

        for (int i = 0; i < n; i++)
            if (p[i].at <= time && p[i].rt > 0 && p[i].rt < min_rt)
                min_rt = p[i].rt, shortest = i;

        if (shortest == -1) { time++; continue; }

        p[shortest].rt--;

        if (p[shortest].rt == 0) {
            p[shortest].ct = time + 1;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
            completed++;
        }
        time++;
    }

    printf("\nAT\tBT\tCT\tTAT\tWT\n");
    float totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
    }

    printf("\nAvg TAT: %.2f, Avg WT: %.2f\n", totalTAT / n, totalWT / n);
    return 0;
}
