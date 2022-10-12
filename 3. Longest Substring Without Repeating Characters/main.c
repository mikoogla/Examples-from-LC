#include <string.h>
#include <stdlib.h>

#define LIMIT 100000
int isInMem(char c, char *memory) {
    for(int j=0; j<)
    return 0;
}

int lengthOfLongestSubstring(char *s) {
    char *memory = malloc(LIMIT);
    memset(memory, '\0', LIMIT-1);
    int i = 0;
    int counter = 0;
    for (i = 0; i < strlen(s); i++) {
        if (!isInMem(s[i], memory))
            counter++;
    }
    if (counter > best) best = counter;
    return best;
}

int main() {
    return lengthOfLongestSubstring(s);
}