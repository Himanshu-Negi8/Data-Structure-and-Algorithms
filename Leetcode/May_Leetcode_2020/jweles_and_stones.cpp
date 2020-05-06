class Solution {
    public int numJewelsInStones(String J, String S) {
     
         
        int ans=0;
        
        for(int j=0;j<J.length();j++){
            for(int i=0;i<S.length();i++){
                if(S.charAt(i)==J.charAt(j)){
                    ans+=1;
                }
            }
        }
         return ans;   
        
    }
}
