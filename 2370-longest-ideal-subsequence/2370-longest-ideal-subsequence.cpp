class Solution {
public:
    int longestIdealString(string s, int k) {
        int  n=s.size();
        vector<int>t(26,0);
        int result=1;
        for(int i=0;i<n;i++)
         {  int longest=0;
            int curr=s[i]-'a';
            int left=max(0,curr-k);
            int right=min(25,curr+k);
            for(int j=left;j<=right;j++)
             {
                longest=max(longest,t[j]);
             }
             t[curr]=max(t[curr],longest+1);
             result=max(result,t[curr]);
         }
           
         return result;
    }
};