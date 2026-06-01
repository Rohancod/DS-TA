#include <stdio.h>


int n = 5;
int deque[5];
int front = -1, rear = -1;

// Insert at Front
void insertFront(int value) {
    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = n - 1;
    }
    else {
        front--;
    }

    deque[front] = value;
}

// Insert at Rear
void insertRear(int value) {
    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == n   - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
}

// Delete from Front
void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == n - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

// Delete from Rear
void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = n - 1;
    }
    else {
        rear--;
    }
}

// Display
void display() {
    if (front == -1) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque Elements: ");

    int i = front;

    while (1) {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % n;
    }

    printf("\n");
}

// Main
int main() {
    int choice, value;

    while (1) {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFront(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertRear(value);
            break;

        case 3:
            deleteFront();
            break;

        case 4:
            deleteRear();
            break;

        case 5:
            display();
            break;

        case 6:
            return 0;

        default:
            printf("Invalid Choice\n");
        }
    }
}