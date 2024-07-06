#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[11];
    int math;
    int english;
    int chinese;
    int total;
    float average;
} Student;

int compare(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;

    if (studentA->total != studentB->total) {
        return studentB->total - studentA->total;
    } else {
        return studentA->id - studentB->id;
    }
}

int main() {
    int n, i;
    scanf("%d", &n);

    if (n < 1 || n >= 10) {
        printf("Please input 1-9.\n");
        return 1;
    }

    Student students[n];


    for (i = 0; i < n; i++) {
        scanf("%d %10s %d %d %d", &students[i].id, students[i].name, &students[i].math, &students[i].english, &students[i].chinese);
        students[i].total = students[i].math + students[i].english + students[i].chinese;
        students[i].average = students[i].total / 3.0;
    }
    qsort(students, n, sizeof(Student), compare);
    int rank = 1;
    for (i = 0; i < n; i++) {
        if (i > 0 && students[i].total != students[i-1].total) {
            rank = i + 1;
        }
        printf("%4d%10d%10s%5d%5d%5d\n", rank, students[i].id, students[i].name, students[i].math, students[i].english, students[i].chinese);
    }
    return 0;
}
