class MedianFinder {
public:
    /** initialize your data structure here. */

    priority_queue<int, vector<int>, less<int> > maxHeap;   // 大顶堆，从大到小
    priority_queue<int, vector<int>, greater<int> > minHeap; // 小顶堆，从小到大
    int size;
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        size++;
        maxHeap.push(num);

        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

    }
    
    double findMedian() {
        if(size % 2 == 1) return maxHeap.top();
        return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */