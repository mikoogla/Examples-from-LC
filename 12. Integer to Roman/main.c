#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SET_SIZE 13
struct DataSet {
    int value;
    char *symbol;
};

struct DataSet **createSet() {
    struct DataSet **Set = malloc(sizeof(struct DataSet *) * 13);

    for (int i = 0; i < SET_SIZE; i++) {
        Set[i] = malloc(sizeof(struct DataSet));
        Set[i]->symbol = calloc(3, 1);
    }
    Set[0]->value = 1;
    Set[0]->symbol = "I";
    Set[1]->value = 4;
    Set[1]->symbol = "IV";
    Set[2]->value = 5;
    Set[2]->symbol = "V";
    Set[3]->value = 9;
    Set[3]->symbol = "IX";
    Set[4]->value = 10;
    Set[4]->symbol = "X";
    Set[5]->value = 40;
    Set[5]->symbol = "XL";
    Set[6]->value = 50;
    Set[6]->symbol = "L";
    Set[7]->value = 90;
    Set[7]->symbol = "XC";
    Set[8]->value = 100;
    Set[8]->symbol = "C";
    Set[9]->value = 400;
    Set[9]->symbol = "CD";
    Set[10]->value = 500;
    Set[10]->symbol = "D";
    Set[11]->value = 900;
    Set[11]->symbol = "CM";
    Set[12]->value = 1000;
    Set[12]->symbol = "M";
    return Set;
}

char *intToRoman(int num) {
    char *res = calloc(100, sizeof(char));
    struct DataSet **set = createSet();
    while (num != 0) {
        for (int i = SET_SIZE - 1; i >= 0; i--) {
            if (num >= set[i]->value) {
                strcat(res, set[i]->symbol);
                num -= set[i]->value;
                i = SET_SIZE;
            }
        }
    }
    return res;
}

int main() {
    int number = 1;
    printf("answer: %s\n",intToRoman(number));
    return 0;
}