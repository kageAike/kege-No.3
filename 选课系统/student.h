#pragma once
#include"ke_cen.h"
class student
{
public:
	int top;
	stu stu_suliang[MAX];
public:
	student();//���� ���ļ�
	virtual ~student();//���� д���ļ�
	void print();//�����Ϣ
	void add();//����
	void del();//ɾ��
	void edit();//�޸�
	int find();//��ѯ
	int find_s(int NO);//���β�ѯ
	void xieru();
	void baocun();
	void add_ke(ke k);//���ӿγ�
	void del_ke();//ɾ���γ�
};
