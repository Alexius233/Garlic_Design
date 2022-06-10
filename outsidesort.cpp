#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<cstdlib>
using namespace std;
#define romspace 160000//内存存放记录数
#define k 10//10路归并
#define buf 20000//缓冲区
#define min -1
#define max  40000
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

vector<numPair>array;
vector<BUFF>buff;//十个缓冲区域

numPair leaf[k+1];
int tree[k];
int point[k]={0};//每个段已经排好序的个数

int quicksort(int head,int tail){//快速排序
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
void sortinside(int head,int tail){//归并段内部排序
  int pivotLoc;

   pivotLoc=quicksort(head,tail);
    if(head<pivotLoc-1)
    sortinside(head,pivotLoc-1);
    if(pivotLoc+1<tail)
    sortinside(pivotLoc+1,tail);
    
}



void sortTemp(){//生成多个局部有序归并段
 ifstream in;//文件输出流
 ofstream out;
  ofstream out2;
 in.open("tempfile.txt",ios::in);//读取临时索引文件
 out.open("sortedfile.txt",ios::out|ios::binary);//生成部分有序文件二进制
  out2.open("sortedfile10.txt",ios::out);//生成部分有序文件十进制
 int i=0;
 numPair *n;
 n=new numPair;

 while(!in.eof()){
    in>>n->wordNum>>n->webNum;
    if(i<romspace){
        array.push_back(*n);

    }
     else{
         sortinside(0,romspace-1);
         for(auto i:array){
             out.write((char*)&i, sizeof(numPair));
             out2<<i.wordNum<<' '<<i.webNum<<endl;
         }
              i=-1;
              array.clear();

          }
      i++;

  }
          sortinside(0,i-1);
         for(auto i:array){
             out2<<i.wordNum<<' '<<i.webNum<<endl;
              out.write((char*)&i, sizeof(numPair));
         }
}



void adjust(int i){//调整败者树，较小者胜出
int s=(k+i)/2;
int temp;
while(s){

     if(leaf[i].wordNum>leaf[tree[s]].wordNum){
          temp=tree[s];//保存胜者
          tree[s]=i;//树节点为败者
          i=temp;//胜者 

        }
  
      s=s/2;
}
     tree[0]=i;//最终胜者传给tree【0】
}

void initTree(){

    int i;
    for(i=0;i<k;i++)
    tree[i]=k;

    for(i=k-1;i>=0;i--){
        adjust(i);
    }
   
}       

void getdatafromfile(int i){
ifstream in;//文件输入流
in.open("sortedfile.txt",ios::in|ios::binary);
int cnt=0;
numPair n;
if(point[i]<romspace){//段未读完
while(cnt<buf){
       in.seekg(romspace*i*sizeof(numPair)+point[i]*sizeof(numPair),ios::beg);
       in.read((char *)&n, sizeof(numPair));
    
       buff[i].buff_area.emplace_back(n);
      if(in.eof()){//最后一段特殊处理
           n.wordNum=max;
           buff[i].buff_area.emplace_back(n);
           break;
        }
       cnt++;
       point[i]++;
}

}//段已经读完
else{
n.wordNum=max;
buff[i].buff_area.emplace_back(n);
}
in.close();
}


void input(int i){//更新段首数据
if(buff[i].buff_area.empty()){
getdatafromfile(i);

}
leaf[i]=buff[i].buff_area.front();
buff[i].buff_area.pop_front();

}
 /*  
void input(int i){//更新段首数据
ifstream in;//文件输入流
int flag=1;
in.open("sortedfile.txt",ios::in|ios::binary);

if(i<k-1){//前9段

        if(point[i]<romspace){
            in.seekg(romspace*i*sizeof(numPair)+point[i]*sizeof(numPair),ios::beg);
            in.read((char *)&leaf[i], sizeof(numPair));
            point[i]++;

        }else{
             //cout<<point[i];
            leaf[i].wordNum=max;
        }

}
else{//第十段
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

void outsidesort(){//对临时索引外部排序
ifstream in;//文件输入流
in.open("sortedfile.txt",ios::in|ios::binary);
in.seekg(0,ios::end);
filelongth=in.tellg();
in.close();
ofstream out;
out.open("finalsortedfile.txt",ios::out);
int i;
BUFF bf;
for(i=0;i<k;i++){
    buff.emplace_back(bf);
}

for(i=0;i<k;i++)//每隔160000个数据读取一次
input(i);

leaf[k].wordNum=min;
initTree();

while(leaf[tree[0]].wordNum!=max){

   out<<leaf[tree[0]].wordNum<<' '<<leaf[tree[0]].webNum<<endl;
   input(tree[0]);
        //根据新读入的记录的关键字的值，重新调整败者树，找出最终的胜者
   adjust(tree[0]);

}


}


int main(){//测试

sortTemp();//生成部分有序文件
outsidesort();//外部排序10路归并


}