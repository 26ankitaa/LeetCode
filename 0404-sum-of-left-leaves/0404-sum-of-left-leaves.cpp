/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode* > st;
        st.push(root);
        int res = 0;
        while(!st.empty()) {
            TreeNode* top = st.top();
            st.pop();
            if (top->left != nullptr) {
                
                st.push(top->left);
                if (top->left->left == nullptr && top->left->right == nullptr) {
                    res += top->left->val;
                }
            }

            if (top->right != nullptr) {
                st.push(top->right);
            }
        }
        return res;
    }
};