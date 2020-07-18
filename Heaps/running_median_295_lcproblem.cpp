//Best approach O(logn)
class MedianFinder {
    priority_queue<int>lo;
    priority_queue<int,vector<int>,greater<int>>hi;
        
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        
        if(lo.size()<hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
        
    }
    
    double findMedian() {
        return lo.size() >hi.size() ? lo.top():((double) lo.top()+hi.top())*.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 
 
 //sorting approch while adding elements O(logn) for lower bound and O(n) to shift previous elements
 //O(n)+O(logn)
 class MedianFinder {
    vector<int> store; // resize-able container

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        if (store.empty())
            store.push_back(num);
        else
            store.insert(lower_bound(store.begin(), store.end(), num), num);     // binary search and insertion combined
    }

    // Returns the median of current data stream
    double findMedian()
    {
        int n = store.size();
        return n & 1 ? store[n / 2] : ((double) store[n / 2 - 1] + store[n / 2]) * 0.5;
    }
};




 //O(nlogn)
 //TLE naive approach
 class MedianFinder {
    
    vector<int>store;
    
public:
    
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        store.push_back(num);
    }
    
    double findMedian() {
        sort(store.begin(),store.end());
        int n = store.size();
        return ( n&1 ? store[n/2] : ((double) store[n/2 -1]+store[n/2])*.5);
           
    }
};
