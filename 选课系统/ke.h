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
	int ke_no=0;//ѧ�Ʊ��
	char ke_name[20] = {""};//�γ�����
	char ke_teacher[20] = { "" };//��ʦ
	void add(int NO, char NAME[], char T[]);
	~ke()
	{}
};