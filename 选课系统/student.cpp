#include "student.h"
student::student()//���� ���ļ�
{
	 xieru();
}
student::~student()//���� д���ļ�
{
	 baocun();
}
void student::print()//�����Ϣ
{
	for (int i = 0; i <= top; i++)
	{
		cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "ѧ��: " << stu_suliang[i].no << "  " << "����: " << stu_suliang[i].name << "  " << "�꼶: " << stu_suliang[i].lianji  << "  " << "����: " << stu_suliang[i].age << "  " << "�Ա�: " << stu_suliang[i].sex << endl;
		cout << "ѡ��Ŀγ�:" << endl;
		 stu_suliang[i].print();
		cout << endl;
	};
}
void student::add()//����
{
	int NO, AGE, LIANJI;
	char NAME[20], SEX;
	cout << "������ѧ��: ";
LOP_1: cin >> NO;
	if(find_s(NO)!=-1)
	{
		cout << "ѧ������,����������:";
		goto	LOP_1;
	}
	cout << endl;
	cout << "����������: ";
	cin >> NAME;
	cout << endl;
	cout << "�������꼶: ";
	cin >> LIANJI;
	cout << endl;
	cout << "���������: ";
	cin >> AGE;
	cout << endl;
	cout << "�������Ա�: ";
	cin >> SEX;
	cout << endl;
	top++;
	stu_suliang[top].add(NO,NAME,SEX,LIANJI,AGE);
	cout << endl;
	xieru();
}
void student::del()//ɾ��
{
	int pos = find();
	if (pos != -1)
	{
		swap(stu_suliang[pos], stu_suliang[top]);  // ����Ҫɾ��Ԫ�غ�β��Ԫ��
		top--;  // ɾ��β��Ԫ��
		cout << "ɾ���ɹ�!" << endl;
	}
	else
	{
		cout << endl << "ɾ��ʧ��!" << endl;
	}
}
void student::edit()//�޸�
{
	int i;
	i = find();
	if (i == -1) return;
	cout << "�������޸ĺ������: ";	cin >> stu_suliang[i].name;		cout << endl;
	cout << "�������޸ĺ��ѧ��: ";	cin >> stu_suliang[i].no;			cout << endl;
	cout << "�������޸ĺ������: ";  cin >> stu_suliang[i].age;			cout << endl;
	cout << "�������޸ĺ���꼶: "; cin>> stu_suliang[i].lianji;			cout << endl;
	cout << "�������޸ĺ���Ա�: "; cin>>stu_suliang[i].sex;			cout << endl;
}
int student::find()//��ѯ
{
	int NO;
	cout << "������ѧ��:" ;
	cin >> NO;
	cout << endl;
	for (int i = 0; i <= top; i++)
	{
		if (NO == stu_suliang[i].no)
			return i;
	}
	cout << "ѧ��������!";
	return -1;
}
int student::find_s(int NO)//��ѯ
{
	for (int i = 0; i <= top; i++)
	{
		if (NO == stu_suliang[i].no)
			return i;
	}
	return -1;
}
void student::baocun()
{
	fstream file("student_data.txt", ios::out);
	for (int i = 0; i <= top; i++)
	{
		file.write((char*)&stu_suliang[i], sizeof(stu_suliang[i]));
	}
	file.close();
}
void student::xieru()
{
	stu b;
	top = -1;
	fstream file("student_data.txt",ios::in);
	while (1)
	{
		file.read((char*)&b, sizeof(b));
		if (!file) break;
		top++;
		stu_suliang[top] = b;
		if (b.no == 0) break;
	}
	file.close();
}
void student::add_ke(ke k)//���ӿγ�
{
	int i;
	i = find();
	stu_suliang[i].get(k);
}
void student::del_ke()//ɾ���γ�
{
	int i;
	i = find();
	stu_suliang[i].del();
}
