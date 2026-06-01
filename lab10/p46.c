#include <stdio.h>
#include <stdlib.h>

int Queue[5];
int front = -1;
int rear = -1;

void Enqueue(int n)
{
    if (rear >= 4) { 
        printf("Overflow: Queue is full.");
        return;
    }
    Queue[++rear] = n;

    if (front == -1) {
        front = 0;
    }
  
} 

int Dequeue()
{
    if (front == -1 || front > rear) {
        printf("Underflow: Queue is empty.");
        return -1;
    }

    int Y = Queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }


    return Y;
}

void display()
{
    if (front == -1 || front > rear) {
        printf("Queue is empty.");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", Queue[i]);
    }
 
}

int main()
{
    int choice, value;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                Enqueue(value);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }

    return 0;
}
