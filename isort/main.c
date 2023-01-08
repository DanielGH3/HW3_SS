#include "isort.h"

int number[NUMS];

int main(){
    for(int i = 0; i < NUMS; i++){
       scanf("%d", number + i);
    }
    
    insertion_sort(number, 50);

    for(int i = 0; i < NUMS - 1; i++){
        printf("%d,", *(number + i));
    } 
    printf("%d,\n", *(number + NUMS - 1));

    return 0;
}