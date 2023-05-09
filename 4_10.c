#include <stdio.h>

#define MAX_JOBS 3

typedef struct {
    char id;
    int time_remaining;
} Job;

typedef struct {
    Job jobs[MAX_JOBS];
    int front, rear, count;
} Queue;

void init(Queue* q) {
    q->front = 0;
    q->rear = MAX_JOBS - 1;
    q->count = 0;
}

void enqueue(Queue* q, Job j) {
    if (q->count >= MAX_JOBS) {
        printf("Error: Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_JOBS;
    q->jobs[q->rear] = j;
    q->count++;
}

Job dequeue(Queue* q) {
    if (q->count <= 0) {
        printf("Error: Queue is empty\n");
        Job j = {'\0', 0};
        return j;
    }
    Job j = q->jobs[q->front];
    q->front = (q->front + 1) % MAX_JOBS;
    q->count--;
    return j;
}

void display(Queue* q) {
    printf("Queue: [ ");
    for (int i = q->front; i <= q->rear; i = (i + 1) % MAX_JOBS) {
        printf("%c ", q->jobs[i].id);
    }
    printf("]\n");
}

int main() {
    Queue q;
    init(&q);

    // Add jobs to queue
    Job j1 = {'J', 8};
    enqueue(&q, j1);

    Job j2 = {'K', 12};
    enqueue(&q, j2);

    Job j3 = {'L', 10};
    enqueue(&q, j3);

    // Process jobs
    int quantum = 5;  // Time quantum
    int time_elapsed = 0;
    while (q.count > 0) {
        Job j = dequeue(&q);
        printf("Processing job %c for %d seconds...\n", j.id, quantum);
        j.time_remaining -= quantum;
        time_elapsed += quantum;

        if (j.time_remaining > 0) {
            printf("Job %c needs more processing time, adding it back to queue\n", j.id);
            enqueue(&q, j);
        } else {
            printf("Job %c is complete\n", j.id);
        }
    }

    printf("All jobs completed in %d seconds\n", time_elapsed);

    return 0;
}
