#pragma once
#include"stu.h"
class ke_cen
{
public:
	int top_ke;
	ke suliang[MAX];
public:
	ke_cen();//���� ���ļ�
	virtual ~ke_cen();//���� д���ļ�
	void print();//�������
	ke get();//��ȡ����
	void add();//��������
	void del();//ɾ������
	void edit();//�޸�����
	int find();//��ѯ�Ƿ��пγ�
	int find(int NO);//������ӿγ�ʱ��ѯ�γ̱����Ƿ��Ѿ�����
	int find_s();//����get()����ӿγ�
	void baocun();
	void xieru();
};


