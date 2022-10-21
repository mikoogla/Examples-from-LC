#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tabsize {
    int rows;
    int cols;
    int length;
};

struct position {
    int x;
    int y;
};

void resetTab(struct tabsize tabsize, char **tab) {
    for (int i = 0; i < tabsize.rows; i++) {
        memset(tab[i], '\0', tabsize.cols);
    }
}


char *convert(char *s, int numRows) {
    if (!numRows || numRows <= 0 || s == NULL) return 0;
    if (numRows == 1) return s;
    struct tabsize tabsize = {
            .rows = numRows,
            .length = (int) strlen(s),
            .cols = (int) strlen(s)
    };

    struct position pos = {
            .x = 0,
            .y = 0
    };

    char **tab = malloc(tabsize.rows * tabsize.rows);
    for (int i = 0; i < tabsize.rows; i++) {
        tab[i] = malloc(tabsize.cols);
    }
    resetTab(tabsize, tab);

    for (int i = 0; i < tabsize.length; i++) {
        if (i < tabsize.length) {
            while (pos.y < tabsize.rows) {
                tab[pos.y][pos.x] = s[i];
                pos.y++;
                i++;
                if (i >= tabsize.length) break;
            }
            pos.y--;
        }


        if (i < tabsize.length) {
            while (pos.y > 0) {
                pos.x++;
                pos.y--;
                tab[pos.y][pos.x] = s[i];
                i++;
                if (i >= tabsize.length) break;
            }
            i -= 2;
        }
    }

    char *output = malloc(tabsize.length + 1);
    memset(output, '\0', tabsize.length + 1);
    int p = 0;
    for (int i = 0; i < tabsize.rows; i++) {
        for (int j = 0; j < tabsize.cols; j++) {
            if (tab[i][j] != '\0') {
                output[p] = tab[i][j];
                p++;

            }
        }
    }
    output[p] = '\0';

    return output;
}

int main() {
    //trzeba zrobić liczbę kolumn = length/rows + length%rows;
    char *ret = convert(
            "hjouvsuyoypayulyeimuotehzriicfskpggkbbipzzrzucxamludfykgruowzgiooobppleqlwphapjnadqhdcnvwdtxjbmyppphauxnspusgdhiixqmbfjxjcvudjsuyibyebmwsiqyoygyxymzevypzvjegebeocfuftsxdixtigsieehkchzdflilrjqfnxztqrsvbspkyhsenbppkqtpddbuotbbqcwivrfxjujjddntgeiqvdgaijvwcyaubwewpjvygehljxepbpiwuqzdzubdubzvafspqpqwuzifwovyddwyvvburczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveymqpxhlrnunyfdzrhbasjeuygafoubutpnimuwfjqsjxvkqdorxxvrwctdsneogvbpkxlpgdirbfcriqifpgynkrrefx",
            503);
    printf("%s\n", ret);
    free(ret);
    return 0;
}