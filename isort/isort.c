#include "isort.h"

void shift_element(int* arr, int i){
    for(++i; i > 1; i--){
        *(arr + i) = *(arr + i - 1);
    }
}

void insertion_sort(int* arr, int len) {
    for (int i = 1; i < len; i++) {
        int key = *(arr + i);
        int j = i - 1;

        while (j >= 0 &&  *(arr + j) > key) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key;
    }
}

void printf_array(int* arr, int len){
    printf("{");
    for(int i = 0; i < len; i++)
        printf("%d ", *(arr + i));
    printf("}");
}