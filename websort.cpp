#include <iostream>
#include<map>
#include<vector>
using namespace std;

// 在main里调用的时候，需要创建一个全局的vector: webvalues传进去
// main还没写

std::vector<std::pair<int, int>> create_pair()
{
	std::vector<std::pair<int, int>> webvalues;
	// 读取：方式暂时不知道
	int indexedweb,values;
    while()
	{
		indexedweb = 1;   // 应该正确赋值之后makepair
		values = 1;
		webvalues.push_back(std::make_pair(indexedweb, values));
	}
	return webvalues;
}


void merge_sort_two_vec(std::vector<std::pair<int, int>> &sub_webvalues1,// pair1
						                            std::vector<std::pair<int, int>> &sub_webvalues2,// pair2
						                            std::vector<std::pair<int, int>> &webvalues)     // 合并后的数组
{
    int i,j;

    while(i < sub_webvalues1.size() && j < sub_webvalues2.size())
    {
        if(sub_webvalues1[i].second <= sub_webvalues2[i].second)
        {
            webvalues.push_back(sub_webvalues1[i]);
            i++;
        }
        else
        {
            webvalues.push_back(sub_webvalues2[j]);
            j++;
        }
    }

    for(;i < sub_webvalues1.size(); i++)
        webvalues.push_back(sub_webvalues1[i]);
    for(;j < sub_webvalues1.size(); j++)
        webvalues.push_back(sub_webvalues2[j]);

}

void merge_sort(std::vector<std::pair<int, int>> &webvalues)
{
    if(webvalues.size() < 2)
        return;

    int mid = webvalues.size() / 2;
    std::vector<std::pair<int, int>> sub_webvalues1;
    std::vector<std::pair<int, int>> sub_webvalues2;

    for(int i = 0; i < mid; i++)
            sub_webvalues1.push_back(webvalues[i]);

    for(int i = mid; i < webvalues.size(); i++)
        sub_webvalues1.push_back(webvalues[i]);

    merge_sort(sub_webvalues1);
    merge_sort(sub_webvalues2);
    webvalues.clear();
    merge_sort_two_vec(sub_webvalues1, sub_webvalues2, webvalues);

}




