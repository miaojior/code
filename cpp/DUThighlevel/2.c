#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

void longest_common_substring(char *s, char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    int longest = 0;
    int end_index = 0;

    int dp[MAX_LEN + 1][MAX_LEN + 1] = {0};
    int i,j;
    for (i = 1; i <= len_s; i++) {
        for (j = 1; j <= len_t; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > longest) {
                    longest = dp[i][j];
                    end_index = i;
                }
            }
        }
    }

    if (longest == 0) {
        printf("No Answer\n");
    } else {
        for (i = end_index - longest; i < end_index; i++) {
            putchar(s[i]);
        }
        printf("\n");
    }
}

int main() {
    char s[MAX_LEN + 1];
    char t[MAX_LEN + 1];

    if (fgets(s, sizeof(s), stdin) == NULL) {
        return 1;
    }
    if (fgets(t, sizeof(t), stdin) == NULL) {
        return 1;
    }

    s[strcspn(s, "\n")] = '\0';
    t[strcspn(t, "\n")] = '\0';

    longest_common_substring(s, t);

    return 0;
}
