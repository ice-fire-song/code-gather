class Solution {
public:
    int getDigitSum(int x) { // 获取数位和
        int sum = 0;
        while(x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    struct Node {
        int x;
        int y;
        Node(int a, int b) {
            x = a;
            y = b;
        }
    };
    int movingCount(int m, int n, int k) {
        vector<vector<int> > vis(m, vector<int>(n, 0)); // 二维vector初始化
        queue<Node>q;
        int ret = 1;
        Node node(0, 0);
        q.push(node);
        vis[0][0] = 1;
        // 向下，向右推进
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        while(!q.empty()) {
            Node top = q.front();
            q.pop();
            for(int i = 0; i < 2; i++) {
                int tx = dx[i] + top.x;
                int ty = dy[i] + top.y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || getDigitSum(tx) + getDigitSum(ty) > k) continue;
                Node node(tx, ty);
                q.push(node);
                vis[tx][ty] = 1;
                ret++;
            }
        }
        return ret;
    }
};