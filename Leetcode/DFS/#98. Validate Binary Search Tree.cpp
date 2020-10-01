
class Solution {
public:
    bool BST(TreeNode* root, TreeNode* left, TreeNode* right){
        if(!root) return true;
        if((left && root->val <= left->val) || (right && root->val >= right->val) ) return false;
        return BST(root->left, left, root) && BST(root->right, root, right);
    }
    bool isValidBST(TreeNode* root) {
        return BST(root,NULL,NULL);
    }
};