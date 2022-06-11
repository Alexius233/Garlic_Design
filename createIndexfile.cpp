#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<cstdlib>
#define romspace 160000//鍐呭瓨瀛樻斁璁板綍鏁?
#define k 10//8璺綊骞?
#define buf 20000
#define min -1
#define max  40000
using namespace std;
int filelongth;

class numPair{
public:
    int wordNum;
    int webNum;
};
class BUFF{
public:
    deque<numPair>buff_area;
};

std::vector<numPair>array;
std::vector<BUFF>buff;

numPair leaf[k+1];
int tree[k];
int point[k]={0};

int quicksort(int head,int tail){//快速排序内部排序 
int pivot=array[head].wordNum;
int i=head;
int j=tail;
numPair temp;
while(i<j&&i<=tail&&j>=head){

while(array[j].wordNum>=pivot&&i<j){
  j--;

}
if(i<j){
temp=array[i];
array[i]=array[j];
array[j]=temp;
}
while(array[i].wordNum<=pivot&&i<j){
i++;
}
if(i<j){
temp=array[j];
array[j]=array[i];
array[i]=temp;
}
}
return j;
}
void sortinside(int head,int tail){//内部排序 
  int pivotLoc;

   pivotLoc=quicksort(head,tail);
    if(head<pivotLoc-1)
    sortinside(head,pivotLoc-1);
    if(pivotLoc+1<tail)
    sortinside(pivotLoc+1,tail);
    
}



void sortTemp(){//生成部分有序文件 
 ifstream in;
 ofstream out;
  ofstream out2;
 in.open("tempfile.txt",ios::in);//打开临时索引文件 
 out.open("sortedfile.txt",ios::out|ios::binary);//生成部分有序文件 二进制 
  out2.open("sortedfile10.txt",ios::out);//生成部分有序文件 十进制 
 int i=0;
 int j=0;
 numPair *n;
 n=new numPair;

 while(!in.eof()){
    in>>n->wordNum>>n->webNum;
    if(i<romspace){//每个归并段16000个记录 
        array.push_back(*n);

    }
     else{
         sortinside(0,romspace-1);
        for(j=0;j<array.size();j++){
             out2<<array[j].wordNum<<' '<<array[j].webNum<<endl;
              out.write((char*)&array[j], sizeof(numPair));
         }
              i=-1;
              array.clear();

          }
      i++;

  }
          sortinside(0,i-1);
         for(j=0;j<array.size();j++){
             out2<<array[j].wordNum<<' '<<array[j].webNum<<endl;
              out.write((char*)&array[j], sizeof(numPair));
         }
}



void adjust(int i){//调整败者树 
int s=(k+i)/2;
int temp;
while(s){

     if(leaf[i].wordNum>leaf[tree[s]].wordNum){
          temp=tree[s];//
          tree[s]=i;//
          i=temp;//胜者 

        }
  
      s=s/2;
}
     tree[0]=i;//最终胜者赋给tree[0] 
}

void initTree(){//初始化树 

    int i;
    for(i=0;i<k;i++)
    tree[i]=k;

    for(i=k-1;i>=0;i--){
        adjust(i);
    }
   
}       

void getdatafromfile(int i){//每次从文件读部分到缓冲区 
ifstream in;
in.open("sortedfile.txt",ios::in|ios::binary);
int cnt=0;
numPair n;
if(point[i]<romspace){
while(cnt<buf){
       in.seekg(romspace*i*sizeof(numPair)+point[i]*sizeof(numPair),ios::beg);
       in.read((char *)&n, sizeof(numPair));
    
       buff[i].buff_area.push_back(n);
      if(in.eof()){
           n.wordNum=max;
           buff[i].buff_area.push_back(n);
           break;
        }
       cnt++;
       point[i]++;
}

}
else{
n.wordNum=max;
buff[i].buff_area.push_back(n);
}
in.close();
}


void input(int i){//从缓冲区读数 
if(buff[i].buff_area.empty()){
getdatafromfile(i);

}
leaf[i]=buff[i].buff_area.front();
buff[i].buff_area.pop_front();

}
 /*  
void input(int i){//鏇存柊娈甸鏁版嵁
ifstream in;//鏂囦欢杈撳叆娴?
int flag=1;
in.open("sortedfile.txt",ios::in|ios::binary);

if(i<k-1){//鍓?娈?

        if(point[i]<romspace){
            in.seekg(romspace*i*sizeof(numPair)+point[i]*sizeof(numPair),ios::beg);
            in.read((char *)&leaf[i], sizeof(numPair));
            point[i]++;

        }else{
             //cout<<point[i];
            leaf[i].wordNum=max;
        }

}
else{//绗崄娈?
        int temp=romspace*i*sizeof(numPair)+point[i]*sizeof(numPair);
      if(temp<filelongth){
        in.seekg(temp,ios::beg);
        in.read((char *)&leaf[i], sizeof(numPair));
        point[i]++;
      }
    else{
        leaf[i].wordNum=max;
        
    }
 

}

 //cout<<gg<<endl;
in.close();
}
*/

void outsidesort(){//外部排序 
ifstream in;
in.open("sortedfile.txt",ios::in|ios::binary);
ofstream out;
out.open("finalsortedfile.txt",ios::out);
int i;
BUFF bf;//初始化队列数组 
for(i=0;i<k;i++){
    buff.push_back(bf);
}

for(i=0;i<k;i++)//取各归并段段首 
input(i);

leaf[k].wordNum=min;
initTree();

while(leaf[tree[0]].wordNum!=max){

   out<<leaf[tree[0]].wordNum<<' '<<leaf[tree[0]].webNum<<endl;
   input(tree[0]);
   adjust(tree[0]);

}


}


int main(){//测试 

//sortTemp();
outsidesort();


}