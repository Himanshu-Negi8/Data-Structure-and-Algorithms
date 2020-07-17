class Solution(object):
    def reverseString(self,s):
        return s[::-1]
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        p = self.reverseString(s)
        l = p.split()
        
        for i in range(0,len(l)):
            l[i]=self.reverseString(l[i])
        
        
        return ' '.join(map(str,l))
