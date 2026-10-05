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
    void dfsInOrderTraversal(TreeNode* curr, vector<int>& vec){
        if(!curr) return ;
        dfsInOrderTraversal(curr->left, vec);
        vec.push_back(curr->val);
        dfsInOrderTraversal(curr->right, vec);


    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec{};
        dfsInOrderTraversal(root, vec);
        //k is 1-indexed
        return vec.at(k-1);
    }
};
