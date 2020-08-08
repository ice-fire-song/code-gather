class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int> > q; // 使用小顶堆（自动从小到大）
        vector<int> ret;
        for(int i = 0; i < arr.size(); i++) q.push(arr[i]);
        for(int i = 0; i < k; i++) {
            ret.push_back(q.top());
            q.pop();
        }
        return ret;
    }
};