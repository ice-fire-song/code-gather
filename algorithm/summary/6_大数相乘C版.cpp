// ������ˣ�C/C++��ʵ�� 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

void result(string num1,string num2)
{
    int m = num1.size(), n = num2.size();

    //һ��iλ������һ��jλ�������������i+j-1λ��
    vector<long long> tmp(m + n - 1);

    //ÿһλ���еѿ����˷�
    for(int i = 0; i < m; i++) {
        int a = num1[i] - '0';
        for (int j = 0; j < n; j++){
            int b = num2[j] - '0';
            tmp[i + j] += a*b;
        }
    }
    //���н�λ����ע������Ǵ��Ҳ���С
    int carry = 0;
    for (int i = tmp.size() - 1; i >= 0; i--){
        int t = tmp[i] + carry;
        tmp[i] = t % 10;
        carry = t / 10;
    }
    //����������Ȼ�н�λ
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
