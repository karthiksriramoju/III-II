#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char id[5];
    int deadline, profit;
} Job;

void swap(Job *a, Job *b) {
    Job temp = *a;
    *a = *b;
    *b = temp;
}

void sortJobs(Job jobs[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(jobs[j].profit < jobs[j+1].profit)
                swap(&jobs[j], &jobs[j+1]);
}

void jobSequence(Job jobs[], int n) {
    int i, j, maxDeadline = 0;

    for(i = 0; i < n; i++)
        if(jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    int slot[MAX];
    for(i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    int count = 0, profit = 0;

    printf("\nRequired Jobs: ");

    for(i = 0; i < n; i++) {
        for(j = jobs[i].deadline; j > 0; j--) {
            if(slot[j] == -1) {
                slot[j] = i;
                if(count > 0) printf(" --> "); // arrow only after first job
                printf("%s", jobs[i].id);
                profit += jobs[i].profit;
                count++;
                break;
            }
        }
    }

    printf("\nMax Profit: %d\n", profit);
}

int main() {
    Job jobs[] = {
        {"j1", 2, 60}, {"j2", 1, 100}, {"j3", 3, 20},
        {"j4", 2, 40}, {"j5", 1, 20}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for(int i = 0; i < n; i++)
        printf("%10s %10d %10d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);

    sortJobs(jobs, n);
    jobSequence(jobs, n);
    return 0;
}
