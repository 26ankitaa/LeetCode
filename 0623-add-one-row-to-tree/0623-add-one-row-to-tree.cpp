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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        traverse(root, val, depth - 1, 1);
        return root;
    }

    void traverse(TreeNode* node, int val, int depth, int currDepth)
    {
        if (!node)
        {
            return;
        }

        if (currDepth == depth)
        {
            TreeNode* tmp = node->left;
            node->left = new TreeNode(val);
            node->left->left = tmp;
            tmp = node->right;
            node->right = new TreeNode(val);
            node->right->right = tmp;
        }
        else
        {
            currDepth += 1;
            traverse(node->left, val, depth, currDepth);
            traverse(node->right, val, depth, currDepth);
        }
    }
};