#pragma once
#include"ke.h"
class stu
{
public:
	int top_ke = -1;
	int no;//ѧ��
	char name[20];// ����
	char sex;//�Ա�
	int lianji;//�꼶
	int age;//���
	ke student_ke[MAX];//��ѡ��Ŀγ�;
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
	void get(ke k);//���ӿ�
	void del();//ɾ����
	void print();//��ʾ�ҵĿγ�
};

