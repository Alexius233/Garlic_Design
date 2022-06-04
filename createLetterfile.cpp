#include <iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

vector<string>letterlist;
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

bool addLetter(string letter){
    for(auto temp:letterlist){

        if(temp==letter)
        return false;

    }
    letterlist.push_back(letter);
    return true;

}
void  createLetterfile(){
    ifstream  in;//文件输入流
    ofstream out;//文件输出流
    int flag1=0;
    int flag2=0;
    string letter="";
    
    int cnt=0;//计数器
    char ch;
    in.open("news.csv", ios::in);//打开文件
     out.open("letterfile.txt",ios::out);//写入文件
    

    while(in>>noskipws>>ch){
            if(flag1){//非网址内单词

                  if(ch=='/'){
                       letter.clear();
                       flag1=0;//进入网址
                   }
                   else{

                         if(divideLetter(ch,letter)){
                            if(addLetter(letter)){
                            out<<cnt<<' '<<letter<<endl;
                            cnt++;
                            }
                            letter.clear();
                             }
                         }

           }
           else{//网址内单词
                   if(ch==','){//网址结束
                        flag1=1;
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

