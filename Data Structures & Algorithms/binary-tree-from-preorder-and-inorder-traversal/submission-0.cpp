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
    int currPreOrderIdx = 0;
    TreeNode* build(vector<int>& preorder, 
                    unordered_map<int,int>& m, int l, int r){
        if(l>r) return nullptr;

        TreeNode* curr = new TreeNode();
        curr->val = preorder[currPreOrderIdx];

        int rootIndex = m[preorder[currPreOrderIdx]];
        currPreOrderIdx ++;
        curr-> left = build(preorder,m, l, rootIndex -1);
        curr-> right = build(preorder, m, rootIndex +1, r);


        return curr;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map <int,int> indexMp;
        int sz = inorder.size();
        for(int i = 0 ; i < sz; i ++){
            indexMp[inorder[i]] = i;
        }

        TreeNode* root = nullptr;
       

        root = build( preorder, indexMp, 0, sz-1);
        
       


        return root;
        

    }
};
