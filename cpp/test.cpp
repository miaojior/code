#include<iostream>
#include<stdio.h>
using namespace std;
int num[20] = {};
float data_score[20];
void score() {
	float score;
	cout << "学生成绩录入！" << endl;
	for (int n = 0; n < 20; n++) {
		num[n] = n + 1;
	}
	for (int i = 0; i < 20; i++)
	{
		cout << "输入学号为" << i + 1 << "的学生的成绩" << endl;
		cin >> score;
		data_score[i] = score;
	}
	cout << "学生成绩录入完毕！" << endl;
}
void output1() {
	for (int i = 0; i < 20; i++) {
		if (data_score[i] >= 85) {
			cout << "学号为：" << num[i] << "成绩为：" << data_score[i] << endl;
		}
	}
}
void output2() {
	
	for (int i = 0; i < 20; i++) {
		if (data_score[i] < 60) {
			cout << "学号为：" << num[i] << "成绩为：" << data_score[i] << endl;
		}
	}
}
void order() {
	for (int k = 0; k < 20; k++) {
		for (int i = 0; i < 20-k-1; i++) {
			if (data_score[i] < data_score[i + 1]) {
				float n = 0;
				n = data_score[i];
				data_score[i] = data_score[i + 1];
				data_score[i + 1] = n;
				int m = 0;
				m = num[i];
				num[i] = num[i + 1];
				num[i + 1] = m;
			}
		}
	}
	for (int i = 0; i < 20; i++) {
		cout << "学号：" << num[i] << "成绩：" << data_score[i] << endl;
	}
	}
void average() {
	float average = 0, sum = 0;
	for (int i = 0; i < 20; i++) {
		sum = data_score[i] + sum;
	}
	average = sum / 20;
	int people = 0;
	for (int i = 0; i < 20; i++) {
		if (data_score[i] >= average) {
			people = people + 1;
		}
	}
	cout << "成绩大于或等于平均分的人数为：" << people << endl;
}
bool min() {
	float p;
	for (int k = 0; k < 20; k++) {
		for (int j = 0; j < 20 - k - 1; j++) {
			if (data_score[j] > data_score[j + 1]) {
				float m = 0;
				m = data_score[j];
				data_score[j] = data_score[j + 1];
				data_score[j + 1] = m;
				int w = 0;
				w = num[j];
				num[j] = num[j + 1];
				num[j + 1] = w;
			}
		}
	}p = data_score[0];
	if (p > 60) {
		cout << "没有成绩低于60分的同学！" << endl;
    return true;
    }
    return false;
}
void max() {
	float p;
	for (int k = 0; k < 20; k++) {
		for (int j = 0; j < 20 - k - 1; j++) {
			if (data_score[j] < data_score[j + 1]) {
				float m = 0;
				m = data_score[j];
				data_score[j] = data_score[j + 1];
				data_score[j + 1] = m;
				int w = 0;
				w = num[j];
				num[j] = num[j + 1];
				num[j + 1] = w;
			}
		}
	}p = data_score[0];
	if (p < 85) {
		cout << "没有成绩高于85分的同学！" << endl;
	}
}
int main() {
	cout <<"按键功能如下：\n1：成绩输入\n2：输出成绩大于等于85分同学的学号和成绩\n3：输出成绩低于60同学的学号和成绩\n4：统计大于或等于平均分的同学人数\n5：将成绩由高到低排序\n6：退出程序\n" << "选择菜单项（1 - 6）：" << endl;
	while (true) {
		int n;
		cin >> n;
		if (n == 1) {
			score();
			cout << "请继续选择菜单：" << endl;
		}
		if (n == 2) {
			max();
			output1();
			cout << "请继续选择菜单：" << endl;
		}
		if (n == 3) {
			if(!min())
			output2();             
			cout << "请继续选择菜单：" << endl;
		}
		if (n == 4) {
			average();
			cout << "请继续选择菜单：" << endl;
		}
		if (n == 5) {
			cout << "成绩由高到低为：" << endl;
			order();
			cout << "请继续选择菜单：" << endl;
		}
		if (n == 6) {
			cout << "退出程序" << endl;
			return 0;
		}
	}
}