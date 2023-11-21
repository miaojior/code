#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PREREQ 10 // 每门选修课的最大先修课程数量
#define MAX_COURSES 100 // 最大课程数量

// 课程信息结构体
typedef struct {
    char code[10]; // 课程代码
    char name[50]; // 课程名
    float credit;   // 学分
    char prereq[MAX_PREREQ][10]; // 先修课程
    int num_prereq; // 先修课程数量
    int selected;   // 是否已选
} Course;

// 函数声明
int find_course(char *code, Course courses[], int num_courses);
void add_course(Course courses[], int num_courses);
void delete_course(Course courses[], int num_courses);
void print_courses(Course courses[], int num_courses);
void topo_sort(Course *course, Course courses[], int num_courses);
void sort_courses(Course courses[], int num_courses);

int main() {
    FILE *fp = fopen("courses.txt", "r");
    Course courses[MAX_COURSES]; // 假设最多有100门课程
    int num_courses = 0;

    // 读取课程信息
    if (fp) {
        while (fscanf(fp, "%s %s %f", courses[num_courses].code, courses[num_courses].name,
                      &courses[num_courses].credit) == 3) {
            // 读取先修课程
            char prereq_list[100];
            fscanf(fp, "%s", prereq_list);

            if (strcmp(prereq_list, "无") == 0) {
                courses[num_courses].num_prereq = 0;
            } else {
                char *token = strtok(prereq_list, ",");
                courses[num_courses].num_prereq = 0;

                while (token != NULL && courses[num_courses].num_prereq < MAX_PREREQ) {
                    strcpy(courses[num_courses].prereq[courses[num_courses].num_prereq], token);
                    courses[num_courses].num_prereq++;
                    token = strtok(NULL, ",");
                }
            }

            courses[num_courses].selected = 0; // 初始状态下未选择
            num_courses++;
        }

        fclose(fp);
    }
    num_courses = num_courses - 1;

    while (1) {
        printf("请选择操作：\n");
        printf("1. 添加选修课\n");
        printf("2. 删除已选选修课\n");
        printf("3. 输出已选课程列表和总学分\n");
        printf("4. 给出选修课程的排课顺序\n");
        printf("5. 退出\n");

        int choice;
        printf("请输入选择：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_course(courses, num_courses);
                break;
            case 2:
                delete_course(courses, num_courses);
                break;
            case 3:
                print_courses(courses, num_courses);
                break;
            case 4:
                sort_courses(courses, num_courses);
                break;
            case 5:
                return 0;
            default:
                printf("无效的选择，请重新输入。\n");
        }

        printf("\n");
    }

    return 0;
}

// 找到指定课程在课程数组中的下标
int find_course(char* code, Course courses[], int num_courses) {
    for (int i = 0; i < num_courses; i++) {
        if (strcmp(courses[i].code, code) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to print available elective courses
void print_available_courses(const Course courses[], int num_courses) {
    printf("可选的选修课程有：\n");
    for (int i = 0; i < num_courses; i++) {
        if (!courses[i].selected && courses[i].code[0] == 'X') {
            printf("%s %s %.1f\n", courses[i].code, courses[i].name, courses[i].credit);
        }
    }
}

// Function to add a selected course
void select_course(Course courses[], int num_courses, const char* code) {
    for (int i = 0; i < num_courses; i++) {
        if (!courses[i].selected && strcmp(courses[i].code, code) == 0) {
            courses[i].selected = 1;
            printf("添加成功！\n");
            return;
        }
    }
    printf("未找到对应的选修课程。\n");
}

// Function to handle the process of adding a course
void add_course(Course courses[], int num_courses) {
    print_available_courses(courses, num_courses);

    char code[10];
    printf("请输入想要添加的选修课程代码：");
    scanf("%s", code);

    select_course(courses, num_courses, code);
}


// Function to print selected elective courses
void print_selected_courses(const Course courses[], int num_courses) {
    printf("已选的选修课程有：\n");
    int has_selected = 0;
    for (int i = 0; i < num_courses; i++) {
        if (courses[i].selected && courses[i].code[0] == 'X') {
            printf("%s %s %.1f\n", courses[i].code, courses[i].name, courses[i].credit);
            has_selected = 1;
        }
    }

    if (!has_selected) {
        printf("未选择任何选修课程。\n");
    }
}

// Function to unselect a course
void unselect_course(Course courses[], int num_courses, const char* code) {
    int found = 0;
    for (int i = 0; i < num_courses; i++) {
        if (courses[i].selected && strcmp(courses[i].code, code) == 0) {
            courses[i].selected = 0;
            found = 1;
            printf("删除成功！\n");
        }
    }

    if (!found) {
        printf("未找到对应的选修课程。\n");
    }
}

// Function to handle the process of deleting a course
void delete_course(Course courses[], int num_courses) {
    print_selected_courses(courses, num_courses);

    char code[10];
    printf("请输入要删除的选修课程代码：");
    scanf("%s", code);

    unselect_course(courses, num_courses, code);
}


void print_courses(Course courses[], int num_courses) {
    printf("已选的课程有：\n");
    float total_credit = 0;
    float has_selected = 0;
    for (int i = 0; i < num_courses; i++) {
        if (courses[i].selected) {
            printf("%s %s %.1f\n", courses[i].code, courses[i].name, courses[i].credit);
            total_credit += courses[i].credit;
            has_selected = 1;
        }
    }

    if (!has_selected) {
        printf("未选择任何课程。\n");
    } else {
        printf("总学分：%.1f\n", total_credit);
    }
}


void topo_sort(Course* course, Course courses[], int num_courses) {
    for (int i = 0; i < course->num_prereq; i++) {
        int index = find_course(course->prereq[i], courses, num_courses);
        if (courses[index].num_prereq!=0) {
            topo_sort(&courses[index], courses, num_courses); 
            printf("%s %s\n", courses[index].code, courses[index].name);
        }else{
            printf("%s %s\n", courses[index].code, courses[index].name); 
        }
    }
}


void sort_courses(Course courses[], int num_courses) {
    int num=1;
    for (int i = 0; i < num_courses; i++) {
        if (courses[i].selected && courses[i].code[0] == 'X') { // 如果该门课程已选择且是选修课
            printf("%d:%s选修课程的排课顺序如下：\n",num,courses[i].name);
            printf("----------------------------------\n");
            topo_sort(&courses[i], courses, num_courses); // 调用拓扑排序算法
            printf("%s %s\n", courses[i].code, courses[i].name);
            printf("----------------------------------\n");
            num++;
        }
    }
}

