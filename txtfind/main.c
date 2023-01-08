#include "txtfind.h"

int main(){
    //printf("substring : %d", substring("hello\n", "lloo\n"));
    print_similar_words("cat");
    printf("%d", similar("cat", "cat", 1));
    return 0;
}

