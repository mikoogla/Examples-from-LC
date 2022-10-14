#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tabsize{
    int rows;
    int cols;
};

void resetTab(struct tabsize tabsize, char tab[][tabsize.cols]){
    for(int i=0; i<tabsize.rows; i++){
        memset(tab[i], '\0', tabsize.cols);
    }
}
char * convert(char * s, int numRows){
    if(!numRows || numRows <= 0 || s == NULL) return 0;

    struct tabsize tabsize = {
        .rows = numRows,
        .cols = (int)strlen(s)
    };

    char tab[tabsize.rows][tabsize.cols];
    resetTab( tabsize, tab);
    puts("ok");
    return s;
}

int main() {
    convert("123456789", 3);
    return 25/2;
}