class Solution {
public:
    int maxDepth(string s) {
        int cur = 0;
        int res = 0;
        for(char c:s){
            if(c == '('){
                cur++;
            }
            if(c == ')'){
                cur--;
            }
            res = max(res,cur);
        }     
        return res;
    }
};