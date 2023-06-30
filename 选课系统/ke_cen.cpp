#include "ke_cen.h"
ke_cen::ke_cen() //构造 打开文件
{
	xieru();
}
ke_cen::~ke_cen()//析构 写入文件
{
	 baocun();
}
void ke_cen::print()//输出数据
{
	for (int i = 0; i <= top_ke; i++)
	{
		cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "课程编号: " << suliang[i].ke_no << "   " << "课程名: " << suliang[i].ke_name << "    " << "课程教师: " << suliang[i].ke_teacher << endl;
	}
}
ke ke_cen::get()//获取数据
{
	ke k;
	k = suliang[find_s()];
	return k;
}
void ke_cen::add()//增加数据
{
	int NO;
	char NAME[20], Teacher[20];
	cout << "请输入课程编号: ";
	LOP_2: cin >> NO;
	if (find(NO) != -1)
	{
		cout << "课程已经存在,请重新输入:";
		goto LOP_2;
	}
	cout << endl;
	cout << "请输入课程名: ";
	cin >> NAME;
	cout << endl;
	cout << "请输入课程教师: ";
	cin >> Teacher;
	top_ke++;
	suliang[top_ke].add(NO, NAME, Teacher);
	cout << endl;
	xieru();
	return;
}
void ke_cen::del()//删除数据
{
	int pos=find();
	if (pos != -1)
	{
		swap(suliang[pos], suliang[top_ke]);
		top_ke--;
		cout << endl << "删除成功!" << endl;
		return;
	}
	else
	{
		cout << endl << "删除失败!" << endl;
	}
}
void ke_cen::edit()//修改数据
{
	int i;
	i = find();
	if (i == -1) return;
	cout << "请输入修改后的课程名: ";		cin >> suliang[i].ke_name;		cout << endl;
	cout << "请输入修改后的课程编号: ";	cin >> suliang[i].ke_no;			cout << endl;
	cout << "请输入修改后的教师: ";			cin >> suliang[i].ke_teacher;			cout << endl;
}
int ke_cen::find()//查询是课程
{
	int NO;
	cout << "请输入课程号: ";
	cin >> NO ;
	cout << endl;
	for (int i = 0; i <= top_ke; i++)
	{
		if (NO == suliang[i].ke_no)
			return i;
	}
	cout << "课程不存在!" << endl;
	return -1;
}
int ke_cen::find(int NO)
{
	for (int i = 0; i <= top_ke; i++)
	{
		if (NO == suliang[i].ke_no)
			return i;
	}
	return -1;
}
int ke_cen::find_s()
{
	int NO;
	cout << "请先后输入想要希望添加的课程号: ";
	cin >> NO;
	cout << endl;
	for (int i = 0; i <= top_ke; i++)
	{
		if (NO == suliang[i].ke_no)
			return i;
	}
	cout << "课程不存在!" << endl;
	return -1;
}
void ke_cen::baocun()
{
	fstream file("ke_cen.txt", ios::out);
	for (int i = 0; i <= top_ke; i++)
	{
		file.write((char*)&suliang[i], sizeof(suliang[i]));
		if (!file) cout <<"写入失败";
	}
	file.close();
}
void ke_cen::xieru()
{
	ke b;
	top_ke = -1;
	fstream file("ke_cen.txt", ios::in);
	while (1)
	{
		file.read((char*)&b, sizeof(b));
		if (!file) break;
		top_ke++;
		suliang[top_ke] = b;
	}
	file.close();
}

