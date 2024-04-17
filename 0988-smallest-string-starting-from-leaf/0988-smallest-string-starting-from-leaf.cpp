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
     string smlst;
    void dfs(TreeNode* temp,string& s)
    {

        if(temp==nullptr) return;
        s.push_back('a'+ temp->val);

        if(temp->left==nullptr&&temp->right==nullptr)
        {
            reverse(s.begin(),s.end());
            if(smlst.empty()) smlst=s;
            else smlst=min(smlst,s);
            reverse(s.begin(),s.end());
        }

            dfs(temp->left,s);
            dfs(temp->right,s);
            s.pop_back();
    }


    string smallestFromLeaf(TreeNode* root) {
        string s="";
        dfs(root,s);
        return smlst;
        }
};