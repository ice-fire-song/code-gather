class MaxQueue {
public:
    queue<int> q;
    deque<int> max_q; // 双端队列，可以向队列中快速删除/插入头部/尾部
    MaxQueue() {

    }
    
    int max_value() {
        return max_q.size() ? max_q.front(): -1;
    }
    
    void push_back(int value) {
        q.push(value);
        while(max_q.size() && max_q.back() < value) max_q.pop_back();
        max_q.push_back(value);
    }
    
    int pop_front() {
        if(q.size() == 0) return -1;
        int top = q.front();
        q.pop();
        if(top == max_q.front()) max_q.pop_front();
        return top;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */