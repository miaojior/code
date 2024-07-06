#include <stdio.h>
#include <string.h>

struct CharFreq {
    char character;
    int freq;
};

int main() {
    struct CharFreq charFreq[26];
    int frequency[26] = {0};
    int maxFreq = 0;
    char input[1000];
    int c, i = 0,j=0,row;

    while ((c = getchar()) != EOF && i < 999) {
        input[i++] = c;
    }
    input[i] = '\0';

    for (i = 0; input[i] != '\0'; ++i) {
        if (input[i]>='a'&&input[i]<='z') {
            frequency[input[i] - 'a']++;
        }
    }

    for (i = 0; i < 26; ++i) {
        charFreq[i].character = 'a' + i;
        charFreq[i].freq = frequency[i];
    }

    for (i = 0; i < 26; ++i) {
        for (j = i + 1; j < 26; ++j) {
            if (charFreq[i].freq > charFreq[j].freq) {
                struct CharFreq temp = charFreq[i];
                charFreq[i] = charFreq[j];
                charFreq[j] = temp; 
            }
        } 
    }

    maxFreq = charFreq[25].freq; 
    for(j=0;charFreq[j].freq==0;++j);

    for (row = maxFreq; row > 0; --row) {
        for (i=j; i < 26; ++i) {
            if (charFreq[i].freq >= row) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
