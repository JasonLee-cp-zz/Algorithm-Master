
class Solution {
public:
  unordered_set<int> st;
    
    bool findTarget(TreeNode* root, int k) {
      if(!root) return false;
        if(st.count(k-root->val)) return true;
        st.insert(root->val);
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
};