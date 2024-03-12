/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        unordered_map<int, ListNode*> umap;
        umap[0] = dummyNode;
        int prefixSum=0;
        
        while(head){
            prefixSum += head->val;
            
            if(umap.find(prefixSum) != umap.end()){
                // if the sum is there that means you need delete the amount of node
                //.. starting from 
                
                ListNode* sumFounded = umap[prefixSum];
                ListNode* temp = sumFounded;
                int sum = prefixSum;
                while(temp!=head){
                    temp=temp->next;
                    sum+=temp->val;
                    if(temp!=head) umap.erase(sum); // why this condition check for  [0,0]
                }
                sumFounded->next = head->next;
            }
            else umap[prefixSum] = head;

            head=head->next;
        }
        
        return dummyNode->next;
    }
};