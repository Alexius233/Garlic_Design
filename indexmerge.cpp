#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<int>> merge()
{
    ifstream file;
    file.open("C:/Users/yzc/Desktop/garlic/merge/test.txt", ios::in );  // 开文件用于读取

    if (!file.is_open())
        cout << "打开文件失败" << endl;

    vector<int>slice;
    vector<vector<int>>indexmatrix;
    int item[2] = {-1 , -1};
    int wordnumber = -1;
    string line;

    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            item[0] = int(line[0]) - 48;


            item[1] = int(line[1]) - 48;
            //cout<< line <<endl;
            //cout<< line[2] <<endl;

            if(item[0] != wordnumber)
            {
                if(!slice.empty())
                {
                    indexmatrix.push_back(slice);
                    slice.clear();
                }
                wordnumber ++;
                slice.push_back(item[0]);
                slice.push_back(item[1]);
            }
            else
            {
                slice.push_back(item[1]);
            }
        }
        file.close(); // 关
    }

    //return indexmatrix;

}



int main() {
    //std::cout << "Hello, World!" << std::endl;
    merge();
//    vector<vector<int>>result = merge();
//    cout<< result.size() <<endl;
//    cout << result[0][0] << endl;
//    cout << result[0][1] << endl;
//    cout << result[0][2] << endl;
//    cout << result[1][0] << endl;

    return 0;
}
