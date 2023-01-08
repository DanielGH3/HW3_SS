#include "txtfind.h"

char word[WORD];
char mode[WORD];
char empty[LINE];

int main(){
    getword(word);
    getword(mode);
    getuserline(empty);

    if(*mode == 'b'){
        print_similar_words(word);
    }else if(*mode == 'a'){
        print_lines(word);
    }
    
    return 0;
}