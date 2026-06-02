#include<stdio.h>
#define m 10

int hashset[m];

void init(){
    for(int i=0; i<m ; i++){
        hashset[i] = -1;
    }
}


int f(int key){
    return key%m ;
}


void add(int key){
    int index = f(key);
    if(hashset[index] == -1){
        hashset[index] = key;
        return;
    }
    else if(hashset[index] == key){
        printf("Key already exist.\n");
        return;
    }
    else{
        //collision
        //linear probing
        for(int probe=1; probe<m ; probe++){
            int i = (index + probe)%m;
            if(hashset[i] == -1){
                hashset[i] = key;
                return;
            }
            if(hashset[i] == key){
                printf("Key already exists.\n");
                return;
            }
        }
        printf("HAshset is full.\n");        
    }

}

void display(){
    for(int i=0; i<m ; i++){
        printf("%d\t", hashset[i]);
    }
}

int search(int key){
    int index = f(key);
    if(hashset[index] == -1){
        return 0;
    }
    if(hashset[index] == key){
        return 1;
    }
    else{
        for(int probe=1; probe<m ; probe++){
            int i = (index + probe)%m;
            if(hashset[i] == -1){
                return 0;
            }
            if(hashset[i] == key){
                return 1;
            }
        }
        return 0;
    }
}

void main(){
    init();
    add(5);
    add(18);
    add(55);
    add(78);
    add(35);
    add(15);
    display();
    printf("\n %d",search(5));
}