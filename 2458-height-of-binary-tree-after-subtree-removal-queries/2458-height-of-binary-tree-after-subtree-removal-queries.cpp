class Solution {
public:
    unordered_map<int,int> lheight;
    unordered_map<int,int> rheight;
    unordered_map<int,int> res;
    int findHeight(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        int left= findHeight(root->left);
        int right= findHeight(root->right);

        lheight[root->val]= left;
        rheight[root->val]= right;

        return 1+ max(left, right);

    }
    void newHeight(TreeNode* root, int maxi, int level)
    {
        if(root==NULL)
        return;
        res[root->val]= maxi;
        newHeight(root->left, max(maxi, level + rheight[root->val]), level+1);
        newHeight(root->right, max(maxi, level + lheight[root->val]), level+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int m= queries.size();
        lheight.clear();
        rheight.clear();
        res.clear();
        vector<int> answer(m, 0);
        if(root==NULL) return answer;
        findHeight(root);
        newHeight(root, 0, 0);

        for(int i=0; i<m; i++)
        {
            answer[i]=res[queries[i]];
        }
        return answer;
    }
};