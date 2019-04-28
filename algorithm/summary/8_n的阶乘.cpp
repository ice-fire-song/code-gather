#include<iostream>
using namespace std;
int s[1000000];
int main()
{
	long long n, i;         
	while (cin >> n)
	{
		s[0] = 1;  long long digit = 1;
		for (i = 2; i <= n; i++)
		{                
			long long num = 0;
			for (int t = 0; t < digit; t++)
			{
				long long tump = s[t]*i+num;
				s[t] = tump % 10;
				num = tump / 10;
			}
			while (num != 0)
			{
				s[digit] = num % 10;
				digit++;
				num=num / 10;
			}
		}
		for (i = digit - 1; i >= 0; i--)
			cout << s[i];
			cout << endl;
	}
}
