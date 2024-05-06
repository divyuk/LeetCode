class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stack;
        ListNode* current = head;
        while (current) {
            stack.push(current);
            current = current->next;
        }

        current = stack.top();
        stack.pop();
        int maximum = current->val;
        ListNode* resultList = new ListNode(maximum);

        // Remove nodes from the stack and add to result
        while (!stack.empty()) {
            current = stack.top();
            stack.pop();
            // small
            if (current->val < maximum) continue;
            else {
                ListNode* newNode = new ListNode(current->val);
                newNode->next = resultList;
                resultList = newNode;
                maximum = current->val;
            }
        }

        return resultList;
    }
};