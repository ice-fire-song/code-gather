#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2, sum;
	int f = 0;//���ݶ�����
	cin >> s1 >> s2;
	//�϶̵��ַ������ڵڶ�λ��
	if (s1.size() < s2.size())
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}
	int len = s1.size() - s2.size();
	string s3(len, '0'); //�϶̵��ַ���ǰ�油��0����ʹ�����ַ����ȳ���
	s2 = s3 + s2;
	int a = 0;
	for (int i = s1.size() - 1; i >= 0; i--)
	{
		int b = (s1[i] - '0') + (s2[i] - '0') + a; //�ַ�ת��Ϊ���֣���Ӻʹ���9���1��
		if (b > 9)
		{
 
			sum.push_back((b-10)+'0');
			f++;  //����ת��Ϊ�ַ����������ַ�����
			a = 1;
		} else {
			sum.push_back(b+'0');
			f++;  //�����һλ��Ϊ�������ַ�����
			a = 0;
		}
	}
	if(a>0){
		sum.push_back(a+'0');
		f++;
	}
	for(int i = f-1;i >= 0;i--)
		cout<<sum[i];//�������
	//for (string::reverse_iterator i = sum.rbegin(); i != sum.rend(); ++i) ////���ַ������������
	//cout << *i;
	return 0;
}
//��ʵ�ֶ�����������
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
 
