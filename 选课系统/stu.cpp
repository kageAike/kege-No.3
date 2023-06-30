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
		cout << endl << "添加成功!" << endl;
	else
		cout << endl << "添加失败!" << endl;
}
void stu::del()//删除课程函数
{
	cout << "请输入希望删除的课程编号: ";
	int NO;
	cin >> NO;
	cout << endl;
	for (int i=0; i <= top_ke; i++)
	{
		if (student_ke[i].ke_no == NO)
		{
			swap(student_ke[i], student_ke[top_ke]);
			top_ke--;
			cout << "删除成功!" << endl;
			return;
		}	
	}
	cout << "未找到相应课程" << endl;
	return;
}
void stu:: print()
{
	for (int i = 0; i < top_ke; i++)
		cout << student_ke[i].ke_no << "   " << student_ke[i].ke_name << "   " << student_ke[i].ke_teacher << endl;
}

