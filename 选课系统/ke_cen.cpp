#include "ke_cen.h"
ke_cen::ke_cen() //���� ���ļ�
{
	xieru();
}
ke_cen::~ke_cen()//���� д���ļ�
{
	 baocun();
}
void ke_cen::print()//�������
{
	for (int i = 0; i <= top_ke; i++)
	{
		cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "�γ̱��: " << suliang[i].ke_no << "   " << "�γ���: " << suliang[i].ke_name << "    " << "�γ̽�ʦ: " << suliang[i].ke_teacher << endl;
	}
}
ke ke_cen::get()//��ȡ����
{
	ke k;
	k = suliang[find_s()];
	return k;
}
void ke_cen::add()//��������
{
	int NO;
	char NAME[20], Teacher[20];
	cout << "������γ̱��: ";
	LOP_2: cin >> NO;
	if (find(NO) != -1)
	{
		cout << "�γ��Ѿ�����,����������:";
		goto LOP_2;
	}
	cout << endl;
	cout << "������γ���: ";
	cin >> NAME;
	cout << endl;
	cout << "������γ̽�ʦ: ";
	cin >> Teacher;
	top_ke++;
	suliang[top_ke].add(NO, NAME, Teacher);
	cout << endl;
	xieru();
	return;
}
void ke_cen::del()//ɾ������
{
	int pos=find();
	if (pos != -1)
	{
		swap(suliang[pos], suliang[top_ke]);
		top_ke--;
		cout << endl << "ɾ���ɹ�!" << endl;
		return;
	}
	else
	{
		cout << endl << "ɾ��ʧ��!" << endl;
	}
}
void ke_cen::edit()//�޸�����
{
	int i;
	i = find();
	if (i == -1) return;
	cout << "�������޸ĺ�Ŀγ���: ";		cin >> suliang[i].ke_name;		cout << endl;
	cout << "�������޸ĺ�Ŀγ̱��: ";	cin >> suliang[i].ke_no;			cout << endl;
	cout << "�������޸ĺ�Ľ�ʦ: ";			cin >> suliang[i].ke_teacher;			cout << endl;
}
int ke_cen::find()//��ѯ�ǿγ�
{
	int NO;
	cout << "������γ̺�: ";
	cin >> NO ;
	cout << endl;
	for (int i = 0; i <= top_ke; i++)
	{
		if (NO == suliang[i].ke_no)
			return i;
	}
	cout << "�γ̲�����!" << endl;
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
	cout << "���Ⱥ�������Ҫϣ����ӵĿγ̺�: ";
	cin >> NO;
	cout << endl;
	for (int i = 0; i <= top_ke; i++)
	{
		if (NO == suliang[i].ke_no)
			return i;
	}
	cout << "�γ̲�����!" << endl;
	return -1;
}
void ke_cen::baocun()
{
	fstream file("ke_cen.txt", ios::out);
	for (int i = 0; i <= top_ke; i++)
	{
		file.write((char*)&suliang[i], sizeof(suliang[i]));
		if (!file) cout <<"д��ʧ��";
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

