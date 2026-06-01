#include<stdio.h>
#include<string.h>
int main(){
    int n;
    printf("enter number of names");
    scanf("%d",&n);

    char name [n][100];
    char temp[100];

    for(int i=0;i<n;i++){
        printf("enter name");
        scanf("%s",name[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(name[i],name[j])>0){
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%s \n",name[i]);
    }

    return 0 ;
}