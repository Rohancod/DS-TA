#include <stdio.h>
#include <string.h>

char stack[1000];
int top = -1;


void push(char ch) {
    if (top >= 999) {
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


void removeStars(char s[], char result[]) {
    top = -1; 

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '*') {
            push(s[i]);
        } else {
            pop(); 
        }
    }


    for (int i = 0; i <= top; i++) {
        result[i] = stack[i];
    }
    result[top + 1] = '\0'; 
}

int main() {
    char s[1000];
    char result[1000];

    printf("Enter the string: ");
    scanf("%s", s);

    removeStars(s, result);

    printf("Output: %s\n", result);

    return 0;
}   
