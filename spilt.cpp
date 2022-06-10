#include <iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> spilt(string &sentence)
{
    vector<string>result;
    string temp;
    int i;

    int size = sentence.size();

    temp.clear();
    result.clear();

    for(i = 0; i < size; i++)
    {
        if((i == size - 1)&&(sentence[i] != ' '))
        {
            temp.push_back(sentence[i]);
            result.push_back(temp);
            temp.clear();
        }
        if(sentence[i] != ' ')
        {
            temp.push_back(sentence[i]);
        }
        else
        {
            result.push_back(temp);
            temp.clear();
        }

    }

    return result;
}

int main() { // 测试
    string hw = "hello world wo shi ni die";

    vector<string>r;
    r = spilt(hw);
    int size = r.size();

    for(int i = 0; i < size; i++)
    {
        cout<<r[i];
        cout<<'\n';
    }


    return 0;
}
