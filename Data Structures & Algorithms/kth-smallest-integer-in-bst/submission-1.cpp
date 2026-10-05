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
    void dfsInOrderTraversal(TreeNode* curr, int& k, int& res){
        if(!curr || res > -1) return ;
        dfsInOrderTraversal(curr->left, k, res);
        k--;
        if(k== 0){
            res = curr->val;
            return;
        }
        dfsInOrderTraversal(curr->right, k, res);


    }
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        dfsInOrderTraversal(root, k, res);
        //k is 1-indexed
        return res;
    }
};
