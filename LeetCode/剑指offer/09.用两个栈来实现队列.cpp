class CQueue {
public:
    stack<int>input;
    stack<int>output;
    CQueue() {
        // 清空栈
        while(!input.empty()) input.pop();
        while(!output.empty()) output.pop();
    }
    
    void appendTail(int value) {
        input.push(value);
    }
    
    int deleteHead() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }

        }
        if(output.empty()) return -1;
        else {
            int i = output.top();
            output.pop();
            return i;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */