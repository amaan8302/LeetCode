class info{
    public:
    int maxi;
    int mini;
    bool isBst;
    int sum;
};
class Solution {
public:
    info solve(TreeNode* root, int &ans)
    {
        if(root==NULL)
            return {INT_MIN, INT_MAX, true, 0};  
        info left = solve(root->left,ans);
        info right = solve(root->right,ans);
        info currNode;
        currNode.sum = left.sum + right.sum + root->val;
        currNode.maxi = max(root->val,right.maxi);
        currNode.mini = min(root->val,left.mini);
        if(left.isBst && right.isBst &&(root->val>left.maxi&&root->val<right.mini))
            currNode.isBst=true;
        else
            currNode.isBst=false;
        if(currNode.isBst)
            ans = max(ans,currNode.sum);
        return currNode;
                    
    }
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        info temp = solve(root,sum);
        return sum;
    }
};