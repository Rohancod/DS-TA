#include <stdio.h>

char stack[100];
int top = -1;

void push(char ch)
{
    if (top >= 99)
    {
        printf("stack overflow\n");
    }
    else
    {
        stack[++top] = ch;
    }
}

char pop()
{
    if (top == -1)
    {

        return '\0';
    }
    return stack[top--];
}

int Balanced(char str[])
{
    top = -1;

    for (int i = 0; str[i]; i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            char topChar = pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '['))
            {
                return 0;
            }
        }
    }

    if (top == -1)
    {
        return 1;
    }
}

int main()
{
    int n;
    printf("Enter number of inputs: ");
    scanf("%d", &n);

    while (n--)
    {
        char s[100];
        scanf("%s", s);

        if (Balanced(s))
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }

    return 0;
}
