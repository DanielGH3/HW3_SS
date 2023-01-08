#include "isort.h"

int main(){
    int arr[5] = {5,4,3,2,1};

    insertion_sort(arr, 5);

    printf_array(arr, 5);

    return 0;
}