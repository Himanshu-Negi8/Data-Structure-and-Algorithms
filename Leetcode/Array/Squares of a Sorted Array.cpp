class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int>v(A.size());
        for(int i=0;i<A.size();i++){
            v[i]=A[i]*A[i];
        }
        std::sort(v.begin(),v.end());
        return v;
    }
};
