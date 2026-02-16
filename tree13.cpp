//222. number of nodes in tree

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
    int leftheight(TreeNode* node){
        int height = 0;
        while(node!=NULL){
            height++;
            node = node->left;
        }
        return height;
    }
    int rightheight(TreeNode* node){
        int height = 0;
        while(node!=NULL){
            height++;
            node = node->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = leftheight(root);
        int right = rightheight(root);
        if(left==right){
            return (1<<left)-1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);

   }

};
