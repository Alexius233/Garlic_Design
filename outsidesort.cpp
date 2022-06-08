#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;
#define romspace 16//内存存放记录数
vector<numPair>array;

int quicksort(int head,int tail){
int pivot=array[head];
int i=head;
int j=tail;
int temp;
while(i<j&&i<=tail&&j>=head){

while(array[j]>=pivot&&i<j){
  j--;

}
if(i<j){
temp=array[i];
array[i]=array[j];
array[j]=temp;
}
while(array[i]<=pivot&&i<j){
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
void sortinside(int head,int tail){
  int pivotLoc;

   pivotLoc=quicksort(head,tail);
    if(head<pivotLoc-1)
    sortinside(head,pivotLoc-1);
    if(pivotLoc+1<tail)
    sortinside(pivotLoc+1,tail);
    
}

int main(){
    array.push_back(10);
    array.push_back(1);
    array.push_back(2);
    array.push_back(7);
    array.push_back(9);
    array.push_back(3);
    array.push_back(5);
    array.push_back(8);
    array.push_back(4);
     array.push_back(6);
    array.push_back(1);
    array.push_back(2);
    array.push_back(7);
    array.push_back(9);
    array.push_back(13);
    array.push_back(11);

    int head=0;
    int tail=romspace-1;
    sortinside(head,tail);
    for(int i=0;i<16;i++){
        cout<<array[i]<<' ';
    }


}