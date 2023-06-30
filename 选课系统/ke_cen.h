#pragma once
#include"stu.h"
class ke_cen
{
public:
	int top_ke;
	ke suliang[MAX];
public:
	ke_cen();//构造 打开文件
	virtual ~ke_cen();//析构 写入文件
	void print();//输出数据
	ke get();//获取数据
	void add();//增加数据
	void del();//删除数据
	void edit();//修改数据
	int find();//查询是否有课程
	int find(int NO);//用于添加课程时查询课程编码是否已经存在
	int find_s();//用于get()的添加课程
	void baocun();
	void xieru();
};


