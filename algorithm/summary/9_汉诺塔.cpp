/**
 汉诺塔问题：源于印度一个古老传说。
 大梵天创造世界的时候做了三根金刚石柱子，在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。
 大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，任何时候，在
 小圆盘上都不能放大圆盘，且在三根柱子之间一次只能移动一个圆盘。问应如何操作 ？ 
*/
// 汉诺塔问题 -- 移动次数 
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
	cout<<"输入汉诺塔中黄金圆盘的数量：";
	char A = 'A';
	char B = 'B';
	char C = 'C'; 
	while(cin>>n) {
		cRes = move(n,A,B,C); 
		cout<<n<<"个黄金圆盘需要移动："<<cRes<<"次"<<endl;
		cout<<"输入汉诺塔中黄金圆盘的数量："; 
	}
} 
