#include <stdio.h>

#define MAXSIZE 100

// 定义顺序栈结构
typedef struct {
    int data[MAXSIZE];
    int top; // 栈顶指针
} SeqStack;

// 十进制转八进制函数
int DecimalToOctal(int dec) {
    SeqStack s;
    s.top = -1;

    // 将十进制数不断除以8，并将余数入栈
    while (dec > 0) {
        if (s.top == MAXSIZE - 1) {
            printf("Stack Overflow\n");
            return -1;
        }
        s.data[++s.top] = dec % 8;
        dec /= 8;
    }

    // 从栈中依次出栈，得到八进制数
    int octal = 0;
    while (s.top != -1) {
        octal = octal * 10 + s.data[s.top--];
    }

    return octal;
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    int octal = DecimalToOctal(decimal);
    printf("Octal equivalent: %d\n", octal);

    return 0;
}