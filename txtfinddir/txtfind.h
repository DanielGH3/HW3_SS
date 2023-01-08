#include <stdio.h>

#define WORD 30
#define LINE 256
#define MAX_LINES 250

int getuserline(char s[]);
int getword(char w[]);
int substring(char *str1, char *str2);
int getlinelen(char * l);
int getwordlen(char * w);
void print_lines(char * str);
int similar(char *s, char *t, int n);
void print_similar_words(char * str);
int isEOW(char c);
int isEOL(char c);