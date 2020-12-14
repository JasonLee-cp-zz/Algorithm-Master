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
    vector<TreeNode*>BST(int l, int r){
        vector<TreeNode*> res;
        if(l>r){
            res.push_back(NULL);
            return res;
        }
        if(l==r){
            TreeNode* lastnode = new TreeNode(l);
            res.push_back(lastnode);
            return res;
        }
        
        for(int i=l; i<=r; i++){
             TreeNode* node = new TreeNode(i);
            for(auto leftItr: BST(l,i-1)){
                for(auto rightItr: BST(i+1,r)){
                    node->left = leftItr;
                    node->right = rightItr;
                    res.push_back(node);
                }
            }
        }

        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*>{};
        return BST(1,n);
    }
};