/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        // Step 1: Create a mapping between original and copied nodes
        unordered_map<Node*, Node*> nodeMap;

        // Step 2: First Pass - Create Copied Nodes
        Node* original = head;
        while (original) {
            nodeMap[original] = new Node(original->val);
            original = original->next;
        }

        // Step 3: Second Pass - Connect Next Pointers
        original = head;
        while (original) {
            Node* copied = nodeMap[original];
            copied->next = nodeMap[original->next];
            original = original->next;
        }

        // Step 4: Third Pass - Connect Random Pointers
        original = head;
        while (original) {
            Node* copied = nodeMap[original];
            copied->random = nodeMap[original->random];
            original = original->next;
        }

        // The head of the copied list is the node corresponding to the head of the original list.
        return nodeMap[head];
    }
};