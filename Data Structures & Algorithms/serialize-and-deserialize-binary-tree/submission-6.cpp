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

class Codec {
public:

    // Encodes a tree to a single string.
    //use dfs and string pre-order
    void dfs(TreeNode* curr, std::string& res){
        if(!curr){
            res += "n,";
            return;
        }
        res = res + std::to_string(curr->val) +",";
        dfs(curr->left, res);
        dfs(curr->right, res);
    }
    string serialize(TreeNode* root) {
        if(!root) return {};
        std::string res{};

        dfs(root, res);
        return res;
    }
    TreeNode* dfsMakeNode(const std::string& data, int& idx ){
        if (idx >= data.size()) return nullptr;

        if (data[idx] == 'n') {
            idx += 2; // skip "n,"
            return nullptr;
        }

        int sign = 1;
        if (data[idx] == '-') {
            sign = -1;
            idx++;
        }

        int val = 0;
        while (idx < data.size() && data[idx] != ',') {
            val = val * 10 + (data[idx] - '0');
            idx++;
        }
        idx++; // skip comma

        TreeNode* curr = new TreeNode(sign * val);
        curr->left = dfsMakeNode(data, idx);
        curr->right = dfsMakeNode(data, idx);
        return curr;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        if(data.size()==0) return nullptr;

        
        TreeNode* root = nullptr;
        int start =0;
        root = dfsMakeNode(data, start);
        return root;

    }
};
