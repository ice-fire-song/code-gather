#include<iostream>
#include<iomanip>

using namespace std;
int main() {
	int a[11][11]={0};
	for(int i=1;i<11;i++) {
		a[i][i] = 1;
		a[i][1] = 1;
	}
	for(int i=3;i<11;i++)
		for(int j=2;j<=i-1;j++) {
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
    for(int i=1;i<11;i++) {
    	for(int j=1;j<=i;j++) {
		    cout<<setw(6)<<left<<a[i][j];
		}
		cout<<endl;
	}		
}
