#include<stdio.h>
#include<stdlib.h>
 int main(){

    int *iptr = (int *)malloc(sizeof(int));
    char *cptr = (char*)malloc(sizeof(char));
    float *fptr = (float*)malloc(sizeof(float));

    if(iptr && cptr && fptr){
      *iptr = 8;
      *cptr='v';
      *fptr=8.2;

      printf("%d %c %f",*iptr,*cptr,*fptr);
      free(iptr);
      free(cptr);
      free(fptr);

    }
    else{
      printf("memory allocation failed 😞");
    }
    return 0;
 }