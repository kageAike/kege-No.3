#include "student.h"
student::student()//构造 打开文件
{
	 xieru();
}
student::~student()//析构 写入文件
{
	 baocun();
}
void student::print()//输出信息
{
	for (int i = 0; i <= top; i++)
	{
		cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "学号: " << stu_suliang[i].no << "  " << "姓名: " << stu_suliang[i].name << "  " << "年级: " << stu_suliang[i].lianji  << "  " << "年龄: " << stu_suliang[i].age << "  " << "性别: " << stu_suliang[i].sex << endl;
		cout << "选择的课程:" << endl;
		 stu_suliang[i].print();
		cout << endl;
	};
}
void student::add()//增加
{
	int NO, AGE, LIANJI;
	char NAME[20], SEX;
	cout << "请输入学号: ";
LOP_1: cin >> NO;
	if(find_s(NO)!=-1)
	{
		cout << "学生存在,请重新输入:";
		goto	LOP_1;
	}
	cout << endl;
	cout << "请输入姓名: ";
	cin >> NAME;
	cout << endl;
	cout << "请输入年级: ";
	cin >> LIANJI;
	cout << endl;
	cout << "请输入年纪: ";
	cin >> AGE;
	cout << endl;
	cout << "请输入性别: ";
	cin >> SEX;
	cout << endl;
	top++;
	stu_suliang[top].add(NO,NAME,SEX,LIANJI,AGE);
	cout << endl;
	xieru();
}
void student::del()//删除
{
	int pos = find();
	if (pos != -1)
	{
		swap(stu_suliang[pos], stu_suliang[top]);  // 交换要删除元素和尾部元素
		top--;  // 删除尾部元素
		cout << "删除成功!" << endl;
	}
	else
	{
		cout << endl << "删除失败!" << endl;
	}
}
void student::edit()//修改
{
	int i;
	i = find();
	if (i == -1) return;
	cout << "请输入修改后的姓名: ";	cin >> stu_suliang[i].name;		cout << endl;
	cout << "请输入修改后的学号: ";	cin >> stu_suliang[i].no;			cout << endl;
	cout << "请输入修改后的年龄: ";  cin >> stu_suliang[i].age;			cout << endl;
	cout << "请输入修改后的年级: "; cin>> stu_suliang[i].lianji;			cout << endl;
	cout << "请输入修改后的性别: "; cin>>stu_suliang[i].sex;			cout << endl;
}
int student::find()//查询
{
	int NO;
	cout << "请输入学号:" ;
	cin >> NO;
	cout << endl;
	for (int i = 0; i <= top; i++)
	{
		if (NO == stu_suliang[i].no)
			return i;
	}
	cout << "学生不存在!";
	return -1;
}
int student::find_s(int NO)//查询
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
void student::add_ke(ke k)//增加课程
{
	int i;
	i = find();
	stu_suliang[i].get(k);
}
void student::del_ke()//删除课程
{
	int i;
	i = find();
	stu_suliang[i].del();
}
