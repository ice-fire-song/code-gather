// 大数相乘（C/C++）实现 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

void result(string num1,string num2)
{
    int m = num1.size(), n = num2.size();

    //一个i位数乘以一个j位数，结果至少是i+j-1位数
    vector<long long> tmp(m + n - 1);

    //每一位进行笛卡尔乘法
    for(int i = 0; i < m; i++) {
        int a = num1[i] - '0';
        for (int j = 0; j < n; j++){
            int b = num2[j] - '0';
            tmp[i + j] += a*b;
        }
    }
    //进行进位处理，注意左侧是大右侧是小
    int carry = 0;
    for (int i = tmp.size() - 1; i >= 0; i--){
        int t = tmp[i] + carry;
        tmp[i] = t % 10;
        carry = t / 10;
    }
    //若遍历完仍然有进位
    while (carry != 0){
        int t = carry % 10;
        carry /= 10;
        tmp.insert(tmp.begin(), t);
    }
	for(int i = 0;i < tmp.size();i++)
		printf("%lld",tmp[i]);
		printf("\n");
}

int main()
{
	string num1,num2;
    while(cin>>num1>>num2)
    {
		result(num1,num2);
	}
}
