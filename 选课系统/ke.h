#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
const int MAX = 50;
class ke
{
public:
	int ke_no=0;//学科编号
	char ke_name[20] = {""};//课程名称
	char ke_teacher[20] = { "" };//教师
	void add(int NO, char NAME[], char T[]);
	~ke()
	{}
};