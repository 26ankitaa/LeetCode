class Solution {
public:
    void other(queue<string>&q,string& curr,unordered_set<string>&DE){
    for(int i=0;i<4;i++){
        char ch=curr[i];
        char next=ch=='9'?'0':ch+1;
        char prev=ch=='0'?'9':ch-1;
        curr[i]=next;
        if(DE.find(curr)==DE.end()){
            DE.insert(curr);
            q.push(curr);
        }
        curr[i]=prev;
        if(DE.find(curr)==DE.end()){
            DE.insert(curr);
            q.push(curr);
        }
        curr[i]=ch;

    }
}
    int openLock(vector<string>& deadends, string target) {
        int ans=0;
        unordered_set<string>DE;
        for(auto x:deadends){
            DE.insert(x);
        }
        string start="0000";
        if(DE.find(start)!=DE.end()){
            return -1;
        }
        queue<string> q;
        q.push(start);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if (curr==target){
                    return ans;
                }
                other(q,curr,DE);
            }
            ans++;
        }
        return -1;
    }
};  