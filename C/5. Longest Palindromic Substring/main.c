#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LIMIT 1001
struct Substring {
    int start;
    int stop;
    int counter;
};

char *longestPalindrome(char *s) {
    char *substring = malloc(LIMIT);
    memset(substring, '\0', LIMIT);
    strncpy(substring, s, 1);
    struct Substring sub = {
            .start = 0,
            .stop = 0,
            .counter = 0
    };
    int counter;
    int temp_i, temp_j;
    int length = (int)strlen(s);
    for (int i = 0; i < length; i++) {
        for (int j = length - 1; j > i; j--) {
            if (s[i] == s[j]) {
                counter = j - i + 1;
                temp_i = i;
                temp_j = j;
                while (temp_i < temp_j) {
                    temp_i++;
                    temp_j--;
                    if (s[temp_i] != s[temp_j]) {
                        counter = 0;
                    }
                }
                if (counter > sub.counter) {
                    sub.counter = counter;
                    sub.start = i;
                    sub.stop = j;
                    strncpy(substring, &s[sub.start], sub.counter);
                }
                if(sub.counter > (length/2)) return substring;

            }
        }
    }
    return substring;
}

int main() {
    char *this = longestPalindrome("dwvvlmokkdtnbrpnueyamqwrvrcwpwiaglvoizmsfuxzgvkvsexgwxwoygayznjlswucmoehugrkjkduwtdrguaqtqwdvrekxgphbitvxmpazkceodsyjzuvjfvgjbtiawrpcwomeiwgoelilfylydsdgawybjjmbgfhkndnvqdryncglaxmzndsoziqqmrwticjomsyatisjduifwfzjkgpdpneurlylzgrdlixhosmmwhaqgpxhmjqxsasfnqnppyufxwpukaruvlnfetymzqwzfklpwdwwrupvrttxdkgjbrzwuvwkkjiynnoemfzrjaepvejvxqkvhqtegtiwtbwlneqzryjzzjyrzqenlwbtwitgetqhvkqxvjevpeajrzfmeonnyijkkwvuwzrbjgkdxttrvpurwwdwplkfzwqzmytefnlvurakupwxfuyppnqnfsasxqjmhxpgqahwmmsohxildrgzlylruenpdpgkjzfwfiudjsitaysmojcitwrmqqizosdnzmxalgcnyrdqvndnkhfgbmjjbywagdsdylyflileogwiemowcprwaitbjgvfjvuzjysdoeckzapmxvtibhpgxkervdwqtqaugrdtwudkjkrguheomcuwsljnzyagyowxwgxesvkvgzxufsmziovlgaiwpwcrvrwqmayeunprbntdkkomlvvwd");
    printf("wynik: %s\n", this);
    return 0;
}