#include"student.h"
//////////////////////////////////////////////////界面
void num()
{
	cout << "----------------------------------------------------" << endl;
	cout << "|                       课程管理系统                          " << endl;
	cout << "|                                                                          " << endl;
	cout << "|              1              学生界面                                " << endl;
	cout << "|              2             管理员界面                              " << endl;
	cout << "|              3              学生管理                               " << endl;
	cout << "|                                                                          " << endl;
	cout << "|              0                 退出                                   " << endl;
	cout << "|                                                                           " << endl;
	cout << "----------------------------------------------------" << endl;
}
void num_student()
{
	cout << "----------------------------------------------------" << endl;
	cout << "|                                学生界面                               " << endl;
	cout << "|              1              增加课程                                 " << endl;
	cout << "|              2              删除课程                                " << endl;
	cout << "|              3              显示课程                                 " << endl;
	cout << "|              0               返回                                     " << endl;
	cout << "----------------------------------------------------" << endl;
}
void num_guanliyuan()
{
	cout << "----------------------------------------------------" << endl;
	cout << "|                             管理员界面                             " << endl;
	cout << "|              1              增加课程                                 " << endl;
	cout << "|              2              删除课程                                 " << endl;
	cout << "|              3              查询课程                                 " << endl;
	cout << "|              4              修改课程                                 " << endl;
	cout << "|              5             显示全部课程                            " << endl;
	cout << "|              0                返回                                    " << endl;
	cout << "----------------------------------------------------" << endl;
}
void num_student_guanli()
{
	cout << "----------------------------------------------------" << endl;
	cout << "|                              学生管理                           " << endl;
	cout << "|              1               增加学生                               " << endl;
	cout << "|              2               删除学生                           " << endl;
	cout << "|              3               更改学生                              " << endl;
	cout << "|              4               查询学生									" << endl;
	cout << "|              5             显示全部学生                                   " << endl;
	cout << "|              0                返回                                          " << endl;
	cout << "----------------------------------------------------" << endl;
}
/////////////////////////////////////////////////各个分界面
void guanli_system()
{
	system("cls");
	ke_cen k1;
	char a;
	do
	{
		num_guanliyuan();
		cout << "请输入想要进行的操作:" ;
		cin >> a;
		switch (a)
		{
		case '1':system("cls"); k1.add(); system("pause");system("cls"); break;
		case '2': system("cls"); k1.del(); system("pause"); system("cls"); break;
		case '3':
			{
			 system("cls");
			cout << endl;
			int i = k1.find();
			if(i!=-1)
			cout << "课程编号: " << k1.suliang[i].ke_no << "   " << "课程名: " << k1.suliang[i].ke_name << "   " << "授课教师: " << k1.suliang[i].ke_teacher << endl;
			system("pause"); system("cls");
			break;
			}
		case '4':system("cls"); k1.edit(); system("pause"); system("cls"); break;
		case '5':system("cls"); k1.print(); system("pause"); system("cls"); break;
		case '0':return; break;
		default:cout << "输入错误,请重新输入" << endl;
		}
	} while (a!='0');
	system("cls");
}
void student_system()
{
	system("cls");
	student s;
	ke_cen kc;
	int no;
	char b;
	cout << "请输入你的学号: ";
	LOP:cin >> no;
	if (s.find_s(no) == -1)
	{
		cout << endl << "学生不存在,请重新输入学号: ";
		goto LOP;
	}
	cout << endl;
	do
	{
		num_student();
		cout << "请输入想要进行的操作:";
		cin >> b;
		switch (b)
		{
		case '1':
		{
			system("cls");
			kc.print();
			s.stu_suliang[s.find_s(no)].get(kc.get()); 
			system("pause"); system("cls");
			break;
		}
		case '2':
		{
			system("cls");
			s.stu_suliang[s.find_s(no)].print();
			cout << endl;
			s.stu_suliang[s.find_s(no)].del();
			system("pause"); system("cls");
			break; 
		}
		case '3':system("cls"); s.stu_suliang[s.find_s(no)].print(); system("pause"); system("cls"); break;
		case '0':break;
		default:cout << "输入错误,请重新输入" << endl;
		}
	} while (b!='0');
	system("cls");
}
void student_guanli()
{
	system("cls");
	student s2;
	char a;
	do
	{
		num_student_guanli();
		cout << "请输入想要进行的操作:" << endl;
		cin >> a;
		switch (a)
		{
		case '1': system("cls"); s2.add(); system("pause"); system("cls"); break;
		case '2': system("cls"); s2.del(); system("pause"); system("cls"); break;
		case '3': system("cls"); s2.edit(); system("pause"); system("cls"); break;
		case '4':
		{
			system("cls");
			cout << endl;
			int i = s2.find();
			if (i != -1)
			{
				cout << "学号: " << s2.stu_suliang[i].no << "   " << "姓名: " << s2.stu_suliang[i].name << "   " << "年级: " << s2.stu_suliang[i].lianji << "   " << "年纪: " << s2.stu_suliang[i].age << "性别: " << s2.stu_suliang[i].sex << endl;
				cout << "所选课程: " << endl;
				s2.stu_suliang[i].print();
				cout << endl;
			}
			system("pause"); system("cls");
			break;
		}
		case '5':system("cls"); s2.print(); system("pause"); system("cls"); break;
		case '0':break;
		default:cout << "输入错误,请重新输入" << endl;
		}
	} while (a!='0');
	system("cls");
}
/////////////////////////////////////////////////mian
int main()
{
	char a;
	do
	{
		system("pause");
		system("cls");
		num();
		cout << "请输入想要进行的操作:" << endl;
		cin >> a;
		switch (a)
		{
		case '1':student_system();  break;
		case '2':guanli_system(); break;
		case '3':student_guanli(); break;
		case '0':break;
		default:cout << "输入错误,请重新输入:";
		}
	} while (a != '0');
	return 0;
}
