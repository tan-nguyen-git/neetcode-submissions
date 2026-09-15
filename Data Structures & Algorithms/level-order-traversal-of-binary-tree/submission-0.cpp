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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root ==nullptr) return {};
        std::queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr = root;
        vector<vector<int>> res;
        while(!q.empty()){
            std::queue<TreeNode*> currq;
            vector<int> v;
            while(!q.empty()){
                currq.push(q.front());

                q.pop();
                
            }
            while(!currq.empty()){
                curr = currq.front();
                v.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                currq.pop();
            }
            res.push_back(v);
            

        }
        return res;
    }
};
