class Solution {
public:
    string makeGood(string s) {
        
        string result= string(1,s[0]);;
        int l=s.size();
        for(int i=1;i<l;i++){
            if(!result.empty() && (result.back() + 32==s[i]|| 
            result.back() - 32==s[i])){
                result.pop_back();
            }
            else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};