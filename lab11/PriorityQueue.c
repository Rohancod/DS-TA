// priority QUeue
#include <stdio.h>
#define size 5
struct pQueue
{

    int value;
    int priority;
};

struct pQueue Queue[size];
int front = -1;
int rear = -1;      

void PrEnqueue(int v, int p)
{
    if (rear==size-1) {
        printf("Overflow");
        return;
    }
    rear = rear + 1;
    Queue[rear].value = v;
    Queue[rear].priority = p;

    if (front == -1) {
        front = 0;
    }

}
int PrDequeue()
{
    if (front==-1) {
        printf("Underflow");
        return -1;
    }
    int max = Queue[front].priority;
    int index = front;
    for (int i=front;i<=rear;i++) {
        if (Queue[i].priority>max) {
            max=Queue[i].priority;
            index = i; 
        }
    }
    int Y = Queue[index].value;
    for (int i=index; i<rear; i++) {
        Queue[i] = Queue[i + 1];
    }
    rear--;
    if (rear < front) {
        front = rear = -1;
    }
    return Y;
}

void Prdisplay()
{
    if (front == -1) {
        printf("underflow");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("(%d, %d) ", Queue[i].value, Queue[i].priority);
    }
    printf("\n");
}

int main()
{
    int choice, value, priority;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value and priority: ");
            scanf("%d %d", &value, &priority);
            PrEnqueue(value, priority);
            break;
        case 2:
            value = PrDequeue();
            if (value != -1) {
                printf("Dequeued: %d\n", value);
            }
            break;
        case 3:
            Prdisplay();
            break;
        case 4:
            return 0;
 
        }
    }
    return 0;
}
