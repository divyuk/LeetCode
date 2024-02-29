class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);

        bool isEven=true;

        while(!q.empty()){
            int n=q.size();
            int currValue=isEven?INT_MIN:INT_MAX;
            

            for(int i=0;i<n;i++){
                auto temp=q.front();
                q.pop();

                if(isEven){
                    if(currValue<temp->val and temp->val%2==1){
                        currValue=temp->val;
                    }else{
                        return false;
                    }
                }else{
                    if(currValue>temp->val and temp->val%2==0){
                        currValue=temp->val;
                    }else{
                        return false;
                    }
                }

                if(temp->left!=NULL)
                q.push(temp->left);

                if(temp->right!=NULL)
                q.push(temp->right);
            }

            isEven=!isEven;
        }

        return true;
        
    }
};