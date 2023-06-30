#pragma once
#include"ke.h"
class stu
{
public:
	int top_ke = -1;
	int no;//学号
	char name[20];// 名字
	char sex;//性别
	int lianji;//年级
	int age;//年纪
	ke student_ke[MAX];//所选择的课程;
public:
	void add(int NO, char NAME[], char SEX, int LJ, int A);
	stu()
	{
		no = 0;
		lianji = 0;
		age = 0;
	}
	~stu()
	{}
	void get(ke k);//增加课
	void del();//删除课
	void print();//显示我的课程
};

