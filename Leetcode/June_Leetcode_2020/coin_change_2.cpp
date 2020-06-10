class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount+1];
        dp[0] = 1; // if nothing to change not select any coin is one way
        //go through all the coins
        for(int i=0;i<coins.length;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]+=dp[j-coins[i]];//the current index - num ways
            }
        }
        return dp[amount];
    }
}
