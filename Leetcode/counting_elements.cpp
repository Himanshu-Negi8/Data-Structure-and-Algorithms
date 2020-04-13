class Solution {
public:
    int countElements(vector<int>& arr) {
        
        int count =0;
        
        for(int i=0;i<arr.size();i++){
            int x = arr[i];
            auto it = std::find(arr.begin(),arr.end(),x+1);
            if(it!=arr.end())
            {
                count+=1;
            }
        }
        return count;
    }
};
