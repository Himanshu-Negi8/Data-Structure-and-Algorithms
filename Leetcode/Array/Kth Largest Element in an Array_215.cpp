/*

Problem Description
215. Kth Largest Element in an Array Leetcode

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     
       priority_queue<int>pq;
        
        for(int i:nums){
            pq.push(i);
        }
        
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};

/*Below one is priority queue as maxHeap*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     
       priority_queue<int>pq;
        
        for(int i:nums){
            pq.push(i);
        }
        
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
