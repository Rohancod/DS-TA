#include <stdio.h>

int stack[5];
int top = -1;

void push(int n)
{
    if (top >= 4)
    {
        printf("stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = n;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
        return 0;
    }
    int val = stack[top];
    top--;
    return val;
}

int peep(int n)
{
    if (top - n + 1 < 0)
    {
        printf("stack underflow\n");
        return 0;
    }
    return stack[top - n + 1];
}

void display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

void change(int i, int n)
{

    if (top - n + 1 < 0)
    {
        printf("stack underflow\n");
    }

    stack[top - i + 1] = n;
}

int main()
{
    int ch, x, a, n, i;

    while (1)
    {
        printf("\nEnter choice (1-Push, 2-Pop, 3-Peep, 4-display, 5-change, 6-exit): ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the number to push: ");
            scanf("%d", &a);
            push(a);
            break;
        case 2:
            x = pop();
            printf("Popped: %d\n", x);
            break;
        case 3:

            printf("Enter the position from top to peep: ");
            scanf("%d", &a);
            x = peep(a);
            printf("Peeped: %d\n", x);
            break;

        case 4:
            display();
            break;
        case 5:
            printf("Enter the position : ");
            scanf("%d", &i);
            printf("Enter the new number  : ");
            scanf("%d", &n);
            change(i, n);
            break;

        case 6:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}