#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PAGES 50
#define NUM_JOBS 100

typedef struct {
    int pages;
    int time;
} PrintJob;

typedef struct {
    PrintJob* jobs;
    int size;
} PrintQueue;

void initQueue(PrintQueue* q) {
    q->jobs = (PrintJob*)malloc(NUM_JOBS * sizeof(PrintJob));
    q->size = 0;
}

void enqueue(PrintQueue* q, PrintJob job) {
    q->jobs[q->size++] = job;
}

PrintJob dequeue(PrintQueue* q) {
    int min_index = 0;
    for (int i = 1; i < q->size; i++) {
        if (q->jobs[i].pages < q->jobs[min_index].pages) {
            min_index = i;
        }
    }
    PrintJob job = q->jobs[min_index];
    for (int i = min_index + 1; i < q->size; i++) {
        q->jobs[i - 1] = q->jobs[i];
    }
    q->size--;
    return job;
}

void printJob(PrintJob job, int printer) {
    printf("Printed job with %d pages on printer %d\n", job.pages, printer);
}

void processJobs(int num_printers) {
    PrintQueue queue;
    initQueue(&queue);
    int time = 0;
    for (int i = 0; i < NUM_JOBS; i++) {
        PrintJob job = {rand() % MAX_PAGES + 1, 0};
        enqueue(&queue, job);
        printf("Received job with %d pages\n", job.pages);
    }
    while (queue.size > 0) {
        if (num_printers == 1) {
            PrintJob job = dequeue(&queue);
            printJob(job, 1);
            time += job.pages / 10;
        } else {
            for (int i = 0; i < num_printers; i++) {
                if (queue.size == 0) {
                    break;
                }
                PrintJob job = dequeue(&queue);
                printJob(job, i + 1);
                time += job.pages / 10;
            }
        }
    }
    printf("Total time to process %d jobs with %d printer(s): %d minutes\n", NUM_JOBS, num_printers, time);
}

int main() {
    srand(time(NULL));
    printf("Using 1 printer:\n");
    processJobs(1);
    printf("\nUsing 2 printers:\n");
    processJobs(2);
    printf("\nUsing 3 printers:\n");
    processJobs(3);
    return 0;
}
