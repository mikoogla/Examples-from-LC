#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool isValid(char *s) {
    int length = (int) strlen(s);
    if (length % 2 != 0) return false;
    int set[126];
    set['{'] = 1;
    set['}'] = -1;
    set['['] = 1;
    set[']'] = -1;
    set['('] = 1;
    set[')'] = -1;
    char check[126];
    check['}'] = '{';
    check[']'] = '[';
    check[')'] = '(';
    int queue[length];
    int h = 0;
    bool found = false;
    for (int i = 0; i < length; i++) {
        queue[i] = set[s[i]];
        if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
            h += queue[i];
            for (int j = i - 1; j >= 0; j--) {
                h += queue[j];
                if (check[s[i]] == s[j] && queue[i] != 0 && queue[j] != 0) {
                    queue[i] = 0;
                    queue[j] = 0;
                    found = true;
                    if (h != 0) {
                        return false;
                    } else break;
                } else if (j == 0) {
                    return false;
                }
            }
        } else {
            found = false;
        }
    }
    if (found == false) return false;
    for (int i = 0; i < length; i++) {
        h += queue[i];
    }
    if (h != 0) return false;
    return true;
}

int main() {

    int res = isValid("(([]){})");

    printf("%d\n", res);
    return 0;
}