#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define START 97
#define STOP 122

bool checkIfPangram(char * sentence){
    char *alpha = calloc(27, 1);
    for(int i=0; i<strlen(sentence); i++){
        if(sentence[i] >= START && sentence[i] <= STOP){
            alpha[sentence[i] - START] = 'a';
        }
    }
    if(strlen(alpha) == 26) return true;
    return false;
}

int main(){
    checkIfPangram("thequickbrownfoxjumpsoverthelazydog");
    printf("%d %d\n", 'a', 'z');
}