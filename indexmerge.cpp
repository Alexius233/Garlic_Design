#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<int>> merge()
{
    ifstream file;
    file.open("C:/Users/yzc/Desktop/garlic/merge/test.txt", ios::in );  // 开文件用于读取,截取的finalsortedfile

    if (!file.is_open())
        cout << "打开文件失败" << endl;

    vector<int>slice;
    vector<vector<int>>indexmatrix;
    int item[2] = {-1 , -1};
    int wordnumber = -1;
    int wordindex = 0;
    int webindex = 0;
    bool ifblank = false;
    string line;

    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            int size = line.size();

            for(int i = 0; i < size; i++)
            {
                if(line[i] != ' ' && ifblank == false)
                    wordindex = wordindex * 10 + int(line[i]);

                if (line[i] == ' ')
                {
                    ifblank = true;
                    continue;
                }

                if(line[i] != ' ' && ifblank == true)
                    webindex = webindex * 10 + int(line[i]);

                if(i == size - 1)
                {
                    item[0] = wordindex;
                    item[1] = webindex;
                    ifblank = false;
                    wordindex = 0;
                    webindex = 0;
                }

            }


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

    return indexmatrix;

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
