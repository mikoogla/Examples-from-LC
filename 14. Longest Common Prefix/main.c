#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LIMIT 200

char *longestCommonPrefix(char **strs, int strsSize) {
    puts("ok");
    char *output = calloc(LIMIT, sizeof(char));
    if (strsSize == 0 || strlen(*strs) == 0) return output;
    for (int i = 0; i < LIMIT; i++) {         //cols
        output[i] = strs[0][i];
        for (int j = 0; j < strsSize; j++) {  //rows
            if (strs[j][i] != output[i]) {
                output[i] = '\0';
                return output;
            }
        }
        if (strs[0][i + 1] == NULL) break;
    }
    return output;
}

int main() {
    char **strs = malloc(LIMIT * sizeof(char *));
    for (int i = 0; i < LIMIT; i++) {
        strs[i] = malloc(LIMIT * sizeof(char));
    }
    strs[0] = "a";

    char *out = longestCommonPrefix(strs, 1);
    puts("goto");
    return 0;
}