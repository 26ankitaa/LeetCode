class Solution {
public:
// function of area of histogram
   int MAH(vector<int> &arr, int m){
        stack<int> st;
        vector<int> left(m), right(m);
        int psuedoIdxL = -1, psuedoIdxR = m;
        
        //for NSL
        for(int i=0; i<m; i++){
            while(st.size() > 0 && arr[i] <= arr[st.top()]){
                st.pop();
            }
            if(st.size() == 0){
                left[i] = psuedoIdxL;
            }else{
                left[i] = st.top();
            }
            st.push(i);
        }
        
        // clear stack
        while(!st.empty()){
            st.pop();
        }
        
        //for NSR
        for(int i=m-1; i>=0; i--){
            while(st.size() > 0 && arr[i] <= arr[st.top()]){
                st.pop();
            }
            if(st.size() == 0){
                right[i] = psuedoIdxR;
            }else{
                right[i] = st.top();
            }
            st.push(i);
        }
        
        int mx = INT_MIN;
        for(int i=0; i<m; i++){
            int val = (right[i] - left[i] - 1) * arr[i];
            mx = max(mx, val);
        }
        return mx; 
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> v(m);
        for(int j=0; j<m; j++){
            v[j] = matrix[0][j] - '0';
        }
        
        int mx = MAH(v, m);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '0'){
                    v[j] = 0;
                }
                else{
                    v[j] = v[j] + (matrix[i][j] - '0');
                }
            }
            mx = max(mx, MAH(v, m));
        }
        return mx;
    }
};