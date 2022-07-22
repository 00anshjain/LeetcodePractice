class MedianFinder {
public:
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2; // 
    int n1 = 0, n2 = 0;
    MedianFinder() {
        n1 = 0;
        n2 = 0;
        // pq.clear();
        // pq2.clear();
    }
    
    void addNum(int num) {
        pq.push(num);
        auto t = pq.top();
        pq.pop();
        pq2.push(t);
        if(n2 > n1)
        {
            pq.push(pq2.top());
            pq2.pop();
            n1++;
        }
        else
            n2++;
        
    }
    
    double findMedian() {
        if(n1 == 0 && n2 == 0)
            return -1;
        if(n2 > n1)
            return pq2.top();
        return (pq.top() + pq2.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */