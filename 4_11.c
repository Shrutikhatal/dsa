#include <stdio.h>
#include <stdlib.h>

// Function to download a document
void download_document() {
    printf("Downloading document...\n");
    // Simulate download time
    sleep(5);
    printf("Document downloaded.\n");
}

// Function to listen to music
void listen_music() {
    printf("Listening to music...\n");
    // Simulate music time
    sleep(3);
    printf("Music stopped.\n");
}

// Function to play a game
void play_game() {
    printf("Playing a game...\n");
    // Simulate game time
    sleep(10);
    printf("Game over.\n");
}

int main() {
    int queue[3] = {1, 2, 3}; // 1: download, 2: music, 3: game
    int current_task = 0; // Index of current task in queue
    int num_downloads = 2; // Number of downloads to perform
    
    // Loop until all tasks are completed
    while (num_downloads > 0 || current_task < 3) {
        // If there are downloads remaining, perform them first
        if (num_downloads > 0) {
            download_document();
            num_downloads--;
        }
        // If all downloads are completed, perform next task in queue
        else {
            switch (queue[current_task]) {
                case 1: // Download
                    break; // Skip download task
                case 2: // Music
                    listen_music();
                    break;
                case 3: // Game
                    play_game();
                    break;
                default:
                    printf("Invalid task in queue.\n");
                    break;
            }
            current_task++;
        }
    }
    printf("All tasks completed.\n");
    return 0;
}
