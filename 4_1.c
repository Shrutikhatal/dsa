#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <queue>

using namespace std;

#define MAX_TICKETS 100
#define SERVICE_TIME 3 // in minutes
#define SIMULATION_TIME 480 // in minutes

int main() {
    srand(time(NULL)); // initialize random number generator

    queue<int> regularQueue;
    queue<int> frequentQueue;

    // generate random number of tickets for each queue
    int regularTickets = rand() % MAX_TICKETS + 1;
    int frequentTickets = rand() % MAX_TICKETS + 1;

    // simulate ticket sales
    int currentTime = 0;
    int regularTotalWaitTime = 0;
    int frequentTotalWaitTime = 0;

    while (currentTime < SIMULATION_TIME || !regularQueue.empty() || !frequentQueue.empty()) {
        // check if new passengers arrive
        if (currentTime < SIMULATION_TIME) {
            if (regularTickets > 0) {
                regularQueue.push(currentTime);
                regularTickets--;
            }
            if (frequentTickets > 0) {
                frequentQueue.push(currentTime);
                frequentTickets--;
            }
        }

        // determine which passenger to serve next
        int nextPassenger = -1; // -1 indicates no passenger selected yet
        bool serveRegular = false;
        if (!regularQueue.empty()) {
            if (nextPassenger == -1 || regularQueue.front() < nextPassenger) {
                nextPassenger = regularQueue.front();
                serveRegular = true;
            }
        }
        if (!frequentQueue.empty()) {
            if (nextPassenger == -1 || frequentQueue.front() < nextPassenger) {
                nextPassenger = frequentQueue.front();
                serveRegular = false;
            }
        }

        // serve next passenger
        if (nextPassenger != -1) {
            int waitTime = currentTime - nextPassenger;
            if (serveRegular) {
                regularTotalWaitTime += waitTime;
            } else {
                frequentTotalWaitTime += waitTime;
            }
            usleep(SERVICE_TIME * 60 * 1000000); // simulate ticket agent's service time
            if (serveRegular) {
                regularQueue.pop();
            } else {
                frequentQueue.pop();
            }
        }

        // advance simulation time
        currentTime++;
    }

    // calculate average waiting time
    int regularAvgWaitTime = (regularQueue.size() == 0) ? (regularTotalWaitTime / (SIMULATION_TIME - regularTickets)) : 0;
    int frequentAvgWaitTime = (frequentQueue.size() == 0) ? (frequentTotalWaitTime / (SIMULATION_TIME - frequentTickets)) : 0;

    printf("Regular passengers: %d tickets, average wait time: %d minutes\n", regularTickets, regularAvgWaitTime);
    printf("Frequent flyers: %d tickets, average wait time: %d minutes\n", frequentTickets, frequentAvgWaitTime);

    return 0;
}
