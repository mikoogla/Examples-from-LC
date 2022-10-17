#include <stdlib.h>
#include <string.h>



int lengthOfLastWord(char * s){
    int counter = 0;
    for(int i = (int)strlen(s)-1; i>=0; i--){
        if(s[i] != ' '){
            while(!(s[i] == ' ' || i < 0)){
                counter++;
                i--;
                if(i<0) return counter;
            }
            break;
        }
    }
    return counter;
}

int main(){

    char *s = "a";
    return lengthOfLastWord(s);
}