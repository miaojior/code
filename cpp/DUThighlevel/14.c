#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 20

struct Student {
    char name[NAME_LENGTH];
    int score;
};

int main() {
    struct Student students[MAX_STUDENTS];
    int num_students ,i ,j;
    scanf("%d", &num_students);
    for (i = 0; i < num_students; ++i)
        scanf("%s %d", students[i].name, &students[i].score);
    for (i = 0; i < num_students - 1; ++i) {
        for (j = 0; j < num_students - 1 - i; ++j) {
            if (students[j].score < students[j + 1].score) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < num_students; ++i) 
        printf("%15s%5d\n", students[i].name, students[i].score);
    return 0;
}
