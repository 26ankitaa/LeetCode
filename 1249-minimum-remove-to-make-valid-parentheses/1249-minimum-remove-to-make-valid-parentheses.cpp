class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        string ans="";
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                count++;
            }
            else if(s[i]==')')
            {
                if(count==0)
                s[i]='#';
                else
                count--;
            }
        }
        count=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                count++;
            }
            else if(s[i]=='(')
            {
                if(count==0)
                s[i]='#';
                else
                count--;
            }
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='#')
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};