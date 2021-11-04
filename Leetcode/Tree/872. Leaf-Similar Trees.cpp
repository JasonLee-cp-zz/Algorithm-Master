// Using string-trick
class Solution {
public:
    void postorder(TreeNode* root, string &s){
        if(!root) return;
        if(root->left == root->right) s += to_string(root->val) + "*";
        postorder(root->left, s);
        postorder(root->right, s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1, s2;
        postorder(root1, s1);
        postorder(root2, s2);
        return s1 == s2;
    }
};

// standard vector solution
class Solution {
public:
    
    void postorder(TreeNode* root, vector<int>&seq){
        if(!root) return;
        if(root->left == root->right) seq.push_back(root->val);
        postorder(root->left, seq);
        postorder(root->right, seq);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaf1, leaf2;
        postorder(root1, leaf1);
        postorder(root2, leaf2);
        
        if(leaf1.size() != leaf2.size()) return false;
        for(int i=0; i<leaf1.size(); i++){
            if(leaf1[i] != leaf2[i]) return false;
        }
        
        return true;
    }
};