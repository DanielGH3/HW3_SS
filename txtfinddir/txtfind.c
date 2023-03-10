#include "txtfind.h"
int print_similarline(char * str);

int getuserline(char s[]){
    int line_len = 0;
    char word[WORD];
    int word_len;
    int end;

    while(1){
        //get a single word from user into an array
        word_len = getword(word);

        //get chars from the the word array into the line array
        for(end = 0; end < word_len && line_len < LINE; end++, line_len++){
            *(s + line_len) = *(word + end);
        }

        //if the line length passed/reached the max - write eol + break
        if(line_len >= LINE){
            *(s + LINE - 1) = '\n';
            break;
        }

        //if the word ended in \n its the end of line -  break
        if(end == 0 || isEOL(*(word + end - 1))) {
            break;
        }
    }
    return line_len;
}

int getword(char w[]){
    int word_len = 0;

    //get chars from the user into the word array
    char input = '0';
    while(!isEOW(input) && word_len < WORD){
        int val = scanf("%c", &input);
        if(val == -1) return word_len;
        *(w + word_len++) = input;
    }

    return word_len;
}

int substring(char *str1, char *str2) {
    int i, j;

    for (i = 0; !isEOL(*(str1 + i)); i++) {
        for (j = 0; !isEOW(*(str2 + j)) && !isEOL(*(str1 + i + j)); j++) {
            if (*(str1 + i + j) != *(str2 + j)) {
                break;
            }
        }
        if (isEOW(*(str2 + j))) {
            return 1;
        }
    }
    return 0;
}

int similar(char *s, char *t, int n) {
    int i = 0, j = 0;
    int similar = 0;
    int max_errors = n;

    while (!isEOW(*(s + i)) && !isEOW(*(t + j))) {
        if (*(s + i) == *(t + j)) {
            i++;
            j++;
            similar++;
        } else {
            n--;
            i++;
        }
    }
    if (n < 0 || similar != getwordlen(t) - 1 || getwordlen(s) - 1 - similar - max_errors > 0) {
        return 0;
    } else {
        return 1;
    }
}

int getlinelen(char * l){
    int i = 0;
    while(!isEOL(*(l + i))) i++;
    return i + 1;
}

int getwordlen(char * w){
    int i = 0;
    while(!isEOW(*(w + i))) i++;
    return i + 1;
}

int isEOW(char c){
    return !(c != '\n' && c != ' ' && c != '\t' && c != '\0');
}

int isEOL(char c){
    return !(c != '\n' && c != '\0');
}

void print_lines(char * str){
    char line[LINE];
    int cnt = 0;
    while(cnt++ < MAX_LINES ){
        getuserline(line);

        if(substring(line, str)){
            for(int i = 0; !isEOL(*(line + i)); i++){
                printf("%c", *(line + i)); 
            } 
            printf("\n");
        }
    }
}

int print_similarline(char * str){
    int line_len = 0;
    char s[LINE];
    char word[WORD];
    int word_len;
    int end;

    while(1){
        //get a single word from user into an array
        word_len = getword(word);

        //get chars from the the word array into the line array
        if(similar(word, str, 1)){
            for(end = 0; end < word_len && line_len < LINE; end++, line_len++){
                if(!isEOW(*(word + end)))
                    printf("%c", *(word + end));

                *(s + line_len) = *(word + end);
            }
            printf("\n");
        }
        else{
            for(end = 0; end < word_len && line_len < LINE; end++, line_len++){
                *(s + line_len) = *(word + end);
            }
        }

        //if the line length passed/reached the max - write eol + break
        if(line_len >= LINE){
            *(s + LINE - 1) = '\n';
            break;
        }

        //if the word ended in \n its the end of line -  break
        if(end == 0 || isEOL(*(word + end - 1))) {
            break;
        }
    }
    return line_len;
}

void print_similar_words(char * str){
    int cnt = 0;
    while(cnt++ < MAX_LINES ){
        print_similarline(str);
    }
}
