class Solution {
public:
    int minimumLength(string s) {
      
        int left = 0;
        int right = s.length() - 1;
        
        while(left<right && s[left]==s[right])
        {
            char ch = s[left];
            
            while(left<right && ch == s[left])
            {
                left++;
            }
            
            while(left<=right && ch==s[right])
            {
                right--;
            }
        }
        return right-left+1;
    }
};