#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int counter = 0, best = 0, p = 0;
    for (int i = 0; i < strlen(s); i++) {
        counter++;
        for (int j = p; j < i; j++) {
            if (s[j] == s[i]) {
                while (p != j + 1) {
                    counter--;
                    p++;
                }
            }
        }
        if (counter > best) best = counter;
    }
    return best;
}

int main() {
    return lengthOfLongestSubstring("abawdawd awacawcw%^&*%ccdeceiyuiop87653");
}