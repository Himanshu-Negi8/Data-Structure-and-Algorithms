class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int idxPop=0;
        for(int i=0;i<pushed.size();i++)
        {
            s.push(pushed[i]);
            while(!s.empty() and s.top()==popped[idxPop]){
                idxPop++;
                s.pop();
            }
        }
        return s.empty();
    }
};
