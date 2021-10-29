class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        queue<TreeNode*>Q;
        Q.push(root);
        
        while(!Q.empty()){
            int size = Q.size();
            double level_sum = 0;
            for(int i=0; i<size; i++){
                auto cur = Q.front(); Q.pop();
                level_sum += cur->val;
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
            
            res.push_back(level_sum / size);
        }
        
        return res;
    }
};