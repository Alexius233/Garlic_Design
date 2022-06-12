#include <iostream>
#include <cmath>
using namespace std;

int norm(int score[])// 传一个数组包含三个参数
{
    double size = 3;
    double finalscore;

    double mean;
    double weightedmean;
    double result[3];
    double yipuxilong = 0.001;
    int blance = 100;

    mean = (score[0] + score[1] + score[2]) / size;
    weightedmean = sqrt( (pow((score[0] - mean) , 2) + pow((score[0] - mean) , 2) + pow((score[0] - mean) , 2)) / size);

    result[0] = ((score[0] - mean) / sqrt( pow(weightedmean , 2) + yipuxilong)) * blance;
    result[1] = ((score[1] - mean) / sqrt( pow(weightedmean , 2) + yipuxilong)) * blance;
    result[2] = ((score[2] - mean) / sqrt( pow(weightedmean , 2) + yipuxilong)) * blance;

    finalscore = result[0] + result[1] + result[2];

    return int(finalscore);

}

int main() { // 测试
    int a[3];
    norm(a);
    return 0;
}
