#include <cmath> 
class MedianFinder {
public:
    priority_queue<int>mx;
    priority_queue<int,vector<int>,greater<int>>mn;
    MedianFinder() {
      
    }
    
    void addNum(int num) {
         if (mx.empty() || num <= mx.top()) {
            mx.push(num);
        } else {
            mn.push(num);
        }
        // added the element now need to make sure the size diffrence is maintained
        int x=mx.size();
        int n=mn.size();
        if(x-n>1||n-x>1){
            if(mx.size()>mn.size()){
                mn.push(mx.top());
                mx.pop();
            }else{
                mx.push(mn.top());
                mn.pop();
            }
        }

    }
    
    double findMedian() {
        if(mx.size()==mn.size()){
            // we have an even case 
            double sum=mx.top()+mn.top();
            return sum/2.0;
        }else{
            // the odd case
            if(mx.size()>mn.size()){
                return mx.top();
            }else return mn.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */