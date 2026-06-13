//257. binary tree paths

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
    void getPaths(TreeNode* root, string curr, vector<string>& ans) {
        if (!root) return;
        curr += to_string(root->val);
        if (!root->left && !root->right) {
            ans.push_back(curr);
        } 
        else {
            curr += "->";
            getPaths(root->left, curr, ans);
            getPaths(root->right, curr, ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        getPaths(root,"",ans);
        return ans;
    }
};
