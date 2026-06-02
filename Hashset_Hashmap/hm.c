#include<stdio.h>
#include<string.h>
#define m 10

struct pair
{
    char key[10];
    int value;
};

struct pair hashmap[m];

int f(char key[]){
    int total = 0;
    for(int i=0; i<strlen(key); i++){
        total = total + key[i];
    }
    return total%m;
}

void add(char x[], int y){
    int index = f(x);
    if(hashmap[index].key[0] == '\0'){
        strcpy(hashmap[index].key,x);
        hashmap[index].value = y;
        return;
    }
    else if(strcmp(hashmap[index].key,x) == 0){
        hashmap[index].value = y;
        return;
    }
    else{
        //collision
        //linear probing
        for(int probe=1; probe<m; probe++){
            int i = (index + probe)%m;
            if(hashmap[i].key[0] == '\0'){
                strcpy(hashmap[i].key,x);
                hashmap[i].value = y;
                return;
            }
            if(strcmp(hashmap[i].key,x)==0){
                hashmap[i].value = y;
                return;
            }
        }
        printf("\n Hashmap is full.");
    }
}

void display(){
    for(int i=0; i<m ; i++){
        printf("\n %d : {%s : %d}",i, hashmap[i].key, hashmap[i].value);
    }
}

void main(){
    add("Ajay",70);
    add("Ajay",80);
    add("Shreya",96);
    add("Nayan", 78);
    display();
}