#include <stdio.h>
#include <string.h>



char stack[100];
int top = -1;

void push(char ch) {
    if (top >= 99) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) {
        return '\0';  
    }
    return stack[top--];
}

int isValid(char str[]) {
    top = -1;
    int i = 0;
    
   
    while (str[i] == 'a') {
        push('a');
        i++;
    }


    if (top == -1) {
        return 0;
    }


    while (str[i] == 'b') {
        if (pop() != 'a') {
            return 0; 
        }
        i++;
    }


    if (str[i] == '\0' && top == -1) {
        return 1;
    }

    return 0;
}

int main() {
    char str[100];

    printf("Enter the string: ");
    scanf("%s", str);

    if (isValid(str)) {
        printf("Valid string (a^i b^i where i >= 1)");
    } else {
        printf("Invalid string");
    }

    return 0;
}

