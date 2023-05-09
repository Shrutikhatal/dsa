#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int timestamp; // time when request was made
    char type; // 'T' for takeoff, 'L' for landing
} Request;

typedef struct {
    Request requests[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

int isQueueFull(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(Queue *q, Request r) {
    if (isQueueFull(q)) {
        printf("Error: queue is full\n");
        exit(1);
    }
    q->requests[q->rear] = r;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

Request dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Error: queue is empty\n");
        exit(1);
    }
    Request r = q->requests[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return r;
}

int main() {
    srand(time(NULL)); // initialize random number generator
    
    Queue takeoffQueue, landingQueue;
    initQueue(&takeoffQueue);
    initQueue(&landingQueue);
    
    int takeoffsCompleted = 0, landingsCompleted = 0;
    int takeoffWaitTime = 0, landingWaitTime = 0;
    
    for (int i = 0; i < 120; i += 5) {
        // generate a request (either takeoff or landing)
        Request r;
        r.timestamp = i;
        if (rand() % 2 == 0) {
            r.type = 'T';
            printf("Request for takeoff at time %d\n", i);
            enqueue(&takeoffQueue, r);
        } else {
            r.type = 'L';
            printf("Request for landing at time %d\n", i);
            enqueue(&landingQueue, r);
        }
        
        // check if a runway is available and process a request
        if (!isQueueEmpty(&landingQueue)) {
            Request r = dequeue(&landingQueue);
            printf("Landing at time %d\n", i);
            landingWaitTime += i - r.timestamp;
            landingsCompleted++;
        } else if (!isQueueEmpty(&takeoffQueue)) {
            Request r = dequeue(&takeoffQueue);
            printf("Takeoff at time %d\n", i);
            takeoffWaitTime += i - r.timestamp;
            takeoffsCompleted++;
        } else {
            printf("Runways idle at time %d\n", i);
        }
    }
    
    // print statistics
    printf("Takeoffs completed: %d\n", takeoffsCompleted);
    printf("Landings completed: %d\n", landingsCompleted);
    printf("Average takeoff queue wait time: %f minutes\n", (float)takeoffWaitTime / takeoffsCompleted);
    printf("Average landing queue wait time: %f minutes\n", (float)landingWaitTime / landingsCompleted);
    
    return 0;
}
