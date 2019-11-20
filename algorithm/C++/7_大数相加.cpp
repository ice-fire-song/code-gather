#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2, sum;
	int f = 0;//数据多会出错
	cin >> s1 >> s2;
	//较短的字符串放在第二位。
	if (s1.size() < s2.size())
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}
	int len = s1.size() - s2.size();
	string s3(len, '0'); //较短的字符串前面补‘0’，使两个字符串等长。
	s2 = s3 + s2;
	int a = 0;
	for (int i = s1.size() - 1; i >= 0; i--)
	{
		int b = (s1[i] - '0') + (s2[i] - '0') + a; //字符转化为数字，相加和大于9则进1；
		if (b > 9)
		{
 
			sum.push_back((b-10)+'0');
			f++;  //数字转化为字符，存入新字符串。
			a = 1;
		} else {
			sum.push_back(b+'0');
			f++;  //将最后一位进为插入新字符串。
			a = 0;
		}
	}
	if(a>0){
		sum.push_back(a+'0');
		f++;
	}
	for(int i = f-1;i >= 0;i--)
		cout<<sum[i];//逆序输出
	//for (string::reverse_iterator i = sum.rbegin(); i != sum.rend(); ++i) ////新字符串逆序输出。
	//cout << *i;
	return 0;
}
//能实现多组数据输入
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2; int f = 0;char sum[150];
	while (cin >> s1 >> s2)
	{
		if (s1.size() < s2.size())
	{
	string temp = s1;
	s1 = s2;
	s2 = temp;
	}
	int len = s1.size() - s2.size();
	string s3(len, '0');
	s2 = s3 + s2;
	int a = 0;
	for (int i = s1.size() - 1; i >= 0; i--)
	{
		int b = (s1[i] - '0') + (s2[i] - '0') + a;
		if (b > 9)
		{
			sum[f]=((b - 10) + '0'); f++;
			a = 1;
		} else {
			sum[f] = (b + '0'); f++;
			a = 0;
		}
	}
	if (a > 0) {
		sum[f] = (a + '0'); 
		f++;
	}
	for (int i = f - 1; i >= 0; i--)
		cout << sum[i];
		cout << endl;
		f = 0;
	}
}
 
