#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Song {
    char name[50];
    struct Song* prev;
    struct Song* next;
};


struct Song* head = NULL;
struct Song* current = NULL;


struct Song* createSong(char name[]) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));

    strcpy(newSong->name, name);
    newSong->prev = NULL;
    newSong->next = NULL;

    return newSong;
}


void addSong(char name[]) {
    struct Song* newSong = createSong(name);


    if (head == NULL) {
        head = newSong;
        current = head;
        return;
    }


    struct Song* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newSong;
    newSong->prev = temp;
}


void displayPlaylist() {
    struct Song* temp = head;

    printf("\nPlaylist:\n");

    while (temp != NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}


void playCurrent() {
    if (current != NULL)
        printf("\nNow Playing: %s\n", current->name);
    else
        printf("\nPlaylist is empty\n");
}


void nextSong() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("\nPlaying Next: %s\n", current->name);
    } else {
        printf("\nNo next song available\n");
    }
}


void previousSong() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("\nPlaying Previous: %s\n", current->name);
    } else {
        printf("\nNo previous song available\n");
    }
}


int main() {


    addSong("Shape of You");
    addSong("Believer");
    addSong("Perfect");
    addSong("Faded");

    displayPlaylist();

    playCurrent();

    nextSong();
    nextSong();

    previousSong();

    return 0;
}