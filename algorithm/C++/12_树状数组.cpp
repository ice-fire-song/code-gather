/*
 ��״����ʵ�����Ƕ����Ƶ�Ӧ�ã���Ҫ����������¼���� 
 �����ǣ���״���������������� 
*/ 

int lowbit(int t) {
	return t&(-t);
} 
// ������� 
void update(int i;int num) {
	for(int k=i;k<=n;k+=lowbit(k)){
		tree[i] += num;
	}
}
// �����ѯ 
int getSum(int i) {
	int ans = 0;
	for(int k=i;k>0;k-=lowbit(k)) {
		ans += tree[k];
	}
	return ans;
}
