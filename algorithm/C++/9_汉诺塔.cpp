/**
 ��ŵ�����⣺Դ��ӡ��һ�����ϴ�˵��
 �����촴�������ʱ�������������ʯ���ӣ���һ�������ϴ������ϰ��մ�С˳������64Ƭ�ƽ�Բ�̡�
 ���������������Ű�Բ�̴����濪ʼ����С˳�����°ڷ�����һ�������ϡ����ҹ涨���κ�ʱ����
 СԲ���϶����ܷŴ�Բ�̣�������������֮��һ��ֻ���ƶ�һ��Բ�̡���Ӧ��β��� �� 
*/
// ��ŵ������ -- �ƶ����� 
#include<iostream>
using namespace std;
long long move(int n,char A,char B,char C) {
	long long c1,c2;
	if(n == 1) return 1;
	 else {
	 	c1 = move(n-1,A,B,C);
	 	c2 = move(n-1,B,A,C);
	    return c1 + c2 + 1;
	 }
	
}
int main() {
	int n;
	long long cRes;
	cout<<"���뺺ŵ���лƽ�Բ�̵�������";
	char A = 'A';
	char B = 'B';
	char C = 'C'; 
	while(cin>>n) {
		cRes = move(n,A,B,C); 
		cout<<n<<"���ƽ�Բ����Ҫ�ƶ���"<<cRes<<"��"<<endl;
		cout<<"���뺺ŵ���лƽ�Բ�̵�������"; 
	}
} 
