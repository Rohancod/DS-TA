#include <stdio.h>

int main(){

    char q;

    printf("enter character");
    scanf("%c" , & q);
    
    if(q=='a'|| q=='A'|| q=='e'||q=='E' || q=='i'||q=='I'|| q=='o'||q=='O'||q=='u'||q=='U'){
        printf("it is vowel");

    }else{
        printf("it is not vowel");
    }
    return 0;
}