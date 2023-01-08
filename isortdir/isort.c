#include "isort.h"

void shift_element(int* arr, int i){
    for(; i > 0; i--){
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
