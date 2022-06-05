#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

class letterpair{
public:
    int num;
    string letter;
   // letterpair(int num,string letter){num=num,letter=letter;}
};
vector<letterpair>letterlist;

bool divideLetter(char ch,string& letter){
    
        if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z'){
         letter+=(ch<97)?ch+32:ch;
        }
         
          else{
              if(letter.length()){
                  return true;
              }
          }
          return false;
}

int addLetter(int num,string letter){

    for(auto temp:letterlist){

        if(temp.letter==letter)//找到letter
        return temp.num;//返回letter对应编号

    }
    letterpair* l;
    l=new letterpair;
    l->num=num;
    l->letter=letter;
    letterlist.push_back(*l);//未找到
    delete l;

    return -1 ;

}
void  createLetterfile(){
    ifstream  in;//文件输入流
    ofstream out;//文件输出流
    ofstream out2;
    int flag1=0;
    int flag2=0;
    int letternum;
    int webcnt=-1;

    string letter="";
    
    int cnt=0;//计数器
    char ch;
    in.open("news.csv", ios::in);//打开文件

    out.open("letterfile.txt",ios::out);//写入文件
    out2.open("tempfile.txt",ios::out);//写入文件

    while(in>>noskipws>>ch){
            if(flag1){//非网址内单词

                  if(ch=='/'){
                       letter.clear();
                       flag1=0;//进入网址
                   }
                   else{

                         if(divideLetter(ch,letter)){

                            letternum= addLetter(cnt,letter);//判断是否写入

                                 if(letternum==-1){//第一次出现,写入
                                      out<<cnt<<' '<<letter<<endl;
                                      out2<<cnt<<' '<<webcnt<<endl;//单词-网页
                                      cnt++;
                                     }
                                     else{
                                         out2<<letternum<<' '<<webcnt<<endl;//
                                     }
                            letter.clear();
                             }
                             
                         }

           }
           else{//网址内单词
                   if(ch==','){//网址结束
                        flag1=1;
                        webcnt++;
                   }
 
            }
    }     
    in.close();
    out.close();
}




int main()//测试
{
    createLetterfile();
    
}

