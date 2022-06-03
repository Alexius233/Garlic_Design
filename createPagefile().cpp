

#include <iostream>
#include<fstream>
#include<string>
using namespace std;

void createPagefile() {
    ifstream  in;
    ofstream out;
    int flag=0;
    char ch;
    int i=0;//字符串指针
    int cnt=0;//计数器
    string str="http://";
    string website="";
    in.open("news.csv", ios::in);
    out.open("pagefile.txt",ios::out);
    if (!in) {
        cout << "文件打开错误！";
        exit(0);
    }
   while(in>>ch)
   {
       if(ch==str[i]){//模式匹配
           i++;
           if(i==6)//匹配成功
           {
               i=0;
               flag=1;
               website+=str;

           }
       }
       else{
           i=0;
       }

       if(flag){

           if(ch!=',')
              website+=ch;
             else{
               
               flag=0;
               out<<cnt<<' '<<website<<endl;
               cnt++;
               cout<<website<<endl;
               website.clear();
           }
       }

    

   }



}









int main()
{
    createPagefile();
    //cout << "Hello World!\n";
}

