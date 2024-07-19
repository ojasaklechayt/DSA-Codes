class MedianFinder {
private:
    priority_queue<int> maxHeap; // Max heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for the upper half

public:
    MedianFinder() {
        // Initialize heaps
    }
    
    void addNum(int num) {
        // Add to maxHeap (lower half)
        maxHeap.push(num);
        
        // Ensure the largest of the lower half is not greater than the smallest of the upper half
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int toMove = maxHeap.top();
            maxHeap.pop();
            minHeap.push(toMove);
        }
        
        // Balance the sizes of the two heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            int toMove = maxHeap.top();
            maxHeap.pop();
            minHeap.push(toMove);
        } else if (minHeap.size() > maxHeap.size()) {
            int toMove = minHeap.top();
            minHeap.pop();
            maxHeap.push(toMove);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
