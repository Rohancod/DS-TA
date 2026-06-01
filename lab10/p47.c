// cirular queue

#include <stdio.h>

int Queue[5];
int front = -1;
int rear = -1;

void CrEnqueue(int n)
{
    if ((rear + 1) % 5 == front)
    {
        printf("Overflow");
        return;
    }
    rear = (rear + 1) % 5;
    Queue[rear] = n;
    if (front == -1)
    {
        front = 0;
    }
}

int crDequeue()
{
    if (front == -1)
    {
        printf("Underflow");
        return -1;
    }

    int Y = Queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % 5;
    }

    return Y;
}
void crdisplay()
{
    if (front == -1)
    {
        printf("Queue underflow");
        return;
    }
    int i = front;
    while (1)
    {
        printf("%d ", Queue[i]);
        if (i == rear)
        {
            break;
        }
        if (i == 4)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    }
    printf("\n");
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            CrEnqueue(value);
            break;
        case 2:
            value = crDequeue();
            if (value != -1)
            {
                printf("Dequeued value %d=", value);
            }
            break;
        case 3:
            crdisplay();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice.");
        }
    }
    return 0;
}
