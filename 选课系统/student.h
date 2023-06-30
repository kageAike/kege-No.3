#pragma once
#include"ke_cen.h"
class student
{
public:
	int top;
	stu stu_suliang[MAX];
public:
	student();//构造 打开文件
	virtual ~student();//析构 写入文件
	void print();//输出信息
	void add();//增加
	void del();//删除
	void edit();//修改
	int find();//查询
	int find_s(int NO);//带参查询
	void xieru();
	void baocun();
	void add_ke(ke k);//增加课程
	void del_ke();//删除课程
};
