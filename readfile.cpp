#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<cstdlib>

using namespace std;

#define letter_num 30
#define file_max 31696

struct lett_str
{
	int serial_num;
	string letters;
};

int find_letter(string flag)
{
	lett_str myletter[file_max+1];
	int i,num;
	int yesorno=0;//����Ƿ���ҵ� 
	string temp;//��ʱ�������ܴ��ļ��������ĵ��� 
	ifstream in;//�ļ�������
	ifstream file;
    file.open("letterfile.txt", ios::in ); 
	for(i=0;i<=file_max;i++)
	{	
	file>>num>>temp;
	myletter[i].serial_num=i;
	myletter[i].letters=temp;
//	cout<<myletter[i].letters<<"\n";//���� 
	}
	//��ȡ�ļ�������ź͵��ʵĽṹ��
	for(i=0;i<=file_max+1;i++)
	{
	if(flag==myletter[i].letters)
		{cout<<i;
		yesorno=1;
		}
	}
	if(yesorno==0)
		cout<<"û�в��ҵ��õ���~"; 
return 0;
}

int main()
{
	string temp;
	cin>>temp;
	find_letter(temp);//���ҵ��ʷ��ؽṹ�� 
	return 0; 
}
