class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m;  //declaration of map
        string st,kl;
        for(int i=0;i<s.size();i++){ // storing in the map
            m[s[i]]++;
        }
        for(int i=0;i<order.size();i++){
        st+=string(m[order[i]],order[i]); //searching elements of order in the given string !!//if yes add them as number of times they are present !!
        m[order[i]]=0;  //declaring frequency zero 
                    
                    
            
        }
        for(auto ele:m){  // loop for element in the string and not in order with repeated case also
            if(ele.second>=1)
            kl+=string(ele.second,ele.first);

        }
        st+=kl;  //reunion of left out element of string to the answer string  .....
        return st;
    }
};