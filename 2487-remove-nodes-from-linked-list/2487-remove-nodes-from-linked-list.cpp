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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        while(head){
            ListNode* forw = head->next;
            head->next = newHead;
            newHead = head;
            head = forw;
        }
        return newHead;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        int maxi = 0;
        ListNode* prev = NULL;
        ListNode* current = head;
        while(current){
            maxi= max(maxi,current->val);
            if(current->val< maxi){
                prev->next = current->next;
                ListNode* del = current;
                current=current->next;
                del->next =nullptr;
            }
            else{
                prev=current;
                current=current->next;
            }
        }
        return reverseList(head);
    }
};