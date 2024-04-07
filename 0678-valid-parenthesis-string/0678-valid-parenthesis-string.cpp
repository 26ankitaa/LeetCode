class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        int precnt = 0; // to count the total number of *
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*') precnt++;
        }
        int cnt = 0; // to get the suffix sum to count * present after the current index
        int varcnt = 0; // to get the count of * encountered till the current index
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(precnt - cnt); // all the available * present for '('
            }
            else if (s[i] == ')')
            {
                // if the stack is empty (means no '(' present), and there are no * left return false
                if (st.empty() && varcnt <= 0) return false;
                else if (st.empty()) varcnt--; // if there are * present before, we use it to satisfy ')' and reduce its count
                else st.pop(); // if '(' is present we use that to satisfy ')' 
            }
            else
            {
                varcnt++;
                cnt++;
            }
        }
        // to count all the * that have been used while satisfying the left '('
        int sum = 0; 
        // remember stack contains the number of available * present 
        //after the index of '(' that was encountered while filling it
        while (!st.empty())
        {
            // no more * left to satisfy '('
            if (st.top() - sum <= 0) return false;
            else
            {
                // increse the sum signifies one * has been used
                sum++;
            }
            st.pop();
        }
        return true;
    
    }
};