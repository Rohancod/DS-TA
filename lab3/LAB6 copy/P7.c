#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void reverseSubstring(char str[], int end) {
    int start = 0;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int T;
    printf("Enter number of test cases: ");
    scanf("%d", &T);
    while (T--) {
        int N;
        char S[1000];
        scanf("%d", &N);
        scanf("%s", S);
        for (int i = 0; i < N; i++) {
            if (isVowel(S[i])) {
                reverseSubstring(S, i - 1);
            }
        }
        printf("%s\n", S);
    }
    return 0;
}