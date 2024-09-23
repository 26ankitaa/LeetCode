class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        
        long long temp = x;
        long long rem;
        long long ans = 0;
        
        while(temp != 0)
        {
            rem = temp%10;
            ans = ans * 10 + rem;
            temp = temp/10;
        }
        
        return ans == x;
    }
};