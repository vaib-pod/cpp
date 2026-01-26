//110. Balanced binary trees


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
private:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int count1 = maxDepth(root->left);
        int count2 = maxDepth(root->right);
        

        return 1 + max(count1,count2);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int c1 = maxDepth(root->left);
        int c2 = maxDepth(root->right);
        if((abs(c1-c2)<=1 ) && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;

    }
};
