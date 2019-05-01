/*
 树状数组实质上是二进制的应用，主要用于区间更新及求和 
 以下是：树状数组三个基本函数 
*/ 

int lowbit(int t) {
	return t&(-t);
} 
// 单点更新 
void update(int i;int num) {
	for(int k=i;k<=n;k+=lowbit(k)){
		tree[i] += num;
	}
}
// 区间查询 
int getSum(int i) {
	int ans = 0;
	for(int k=i;k>0;k-=lowbit(k)) {
		ans += tree[k];
	}
	return ans;
}
