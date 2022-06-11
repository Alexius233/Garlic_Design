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
	int yesorno=0;//检测是否查找到 
	string temp;//临时变量接受从文件读出来的单词 
	ifstream in;//文件输入流
	ifstream file;
    file.open("letterfile.txt", ios::in ); 
	for(i=0;i<=file_max;i++)
	{	
	file>>num>>temp;
	myletter[i].serial_num=i;
	myletter[i].letters=temp;
//	cout<<myletter[i].letters<<"\n";//测试 
	}
	//读取文件生成序号和单词的结构体
	for(i=0;i<=file_max+1;i++)
	{
	if(flag==myletter[i].letters)
		{cout<<i;
		yesorno=1;
		}
	}
	if(yesorno==0)
		cout<<"没有查找到该单词~"; 
return 0;
}

int main()
{
	string temp;
	cin>>temp;
	find_letter(temp);//查找单词返回结构体 
	return 0; 
}
