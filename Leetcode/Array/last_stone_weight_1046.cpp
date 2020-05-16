class Solution {
    public int lastStoneWeight(int[] stones) {
        
        
        PriorityQueue<Integer> mp = new PriorityQueue<>();
        
        for(int stone:stones){
            mp.add(-stone);
        }
        
        while(mp.size()>1){
            
            int stone_one = -mp.remove();
            int stone_two = -mp.remove();
            
            if(stone_one!=stone_two){
                mp.add(-(stone_one-stone_two));
            }
        }
        
        return mp.isEmpty() ? 0 : -mp.remove();
    }
}
