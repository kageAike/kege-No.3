#include "stu.h"
void stu::add(int NO, char NAME[], char SEX, int LJ, int A)
{
	no = NO;
	strcpy_s(name, NAME);
	sex = SEX;
	lianji = LJ;
	age = A;
}
void stu::get(ke k)
{
	top_ke++;
	strcpy_s(student_ke[top_ke].ke_name, k.ke_name);
	strcpy_s(student_ke[top_ke].ke_teacher, k.ke_teacher);
	student_ke[top_ke].ke_no = k.ke_no;
	if (student_ke[top_ke].ke_no == k.ke_no)
		cout << endl << "��ӳɹ�!" << endl;
	else
		cout << endl << "���ʧ��!" << endl;
}
void stu::del()//ɾ���γ̺���
{
	cout << "������ϣ��ɾ���Ŀγ̱��: ";
	int NO;
	cin >> NO;
	cout << endl;
	for (int i=0; i <= top_ke; i++)
	{
		if (student_ke[i].ke_no == NO)
		{
			swap(student_ke[i], student_ke[top_ke]);
			top_ke--;
			cout << "ɾ���ɹ�!" << endl;
			return;
		}	
	}
	cout << "δ�ҵ���Ӧ�γ�" << endl;
	return;
}
void stu:: print()
{
	for (int i = 0; i < top_ke; i++)
		cout << student_ke[i].ke_no << "   " << student_ke[i].ke_name << "   " << student_ke[i].ke_teacher << endl;
}

