#include <stdio.h>
#include <string.h>

char stack[100];
int top;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

void check_grammar(char str[])
{
    int i = 0;
    char next;

    top = 0;
    stack[top] = 'c';

    next = str[i++];
    while (next != 'c')
    {
        if (next == '\0')
        {
            printf("INVALID STRING");
            return;
        }
        push(next);
        next = str[i++];
    }

    next = str[i++];
    while (stack[top] != 'c')
    {
        if (next == '\0')
        {
            printf("INVALID STRING");
            return;
        }
        char x = pop();
        if (next != x)
        {
            printf("INVALID STRING");
            return;
        }
        next = str[i++];
    }

    if (next == '\0')
    {
        printf("VALID STRING");
    }
    else
    {
        printf("INVALID STRING");
    }
}

int main()
{
    char string[100];
    printf("Enter the string: ");
    scanf("%s", string);

    check_grammar(string);
    return 0;
}
