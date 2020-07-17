
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& numbers) {
     vector<vector<int>> result;
        if(numbers.size()<=2)return result;
        sort(numbers.begin(), numbers.end());
        int d =0; //target
        for (int i = 0; i < numbers.size() - 2; i++) {
            int a = numbers[i];
            if(a > d) break;
            if (i > 0 && a == numbers[i - 1]) continue;
            for (long j = i + 1, k = numbers.size() - 1; j < k;) {
                int b = numbers[j];
                int c = numbers[k];
                int value = a + b + c;
                if (value == d) {
                    //got the required sum
                    result.push_back(vector<int>({a, b, c}));
                    while (j<k && b == numbers[++j]); //incrementing to escape repitive values.
                    while (j < k &&c == numbers[--k]); //decrementing to escape repitive values.
                } else if (value > 0) {
                    //decrementing sequentially
                    k--;
                } else {
                    //incrementing sequentially
                    j++;
                }
            }
        }
        return result;   
    }
};
