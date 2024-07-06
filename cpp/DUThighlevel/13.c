#include <stdio.h>

int main() {
    int key;
    FILE *in, *out;
    char ch;

    scanf("%d", &key);

    in = fopen("in.txt", "r");
    out = fopen("out.txt", "w");


    while ((ch = fgetc(in)) != EOF) {
        if ('a' <= ch && ch <= 'z') 
            ch = 'a' + (ch - 'a' + key) % 26;
        else if ('A' <= ch && ch <= 'Z') 
            ch = 'A' + (ch - 'A' + key) % 26;
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}
