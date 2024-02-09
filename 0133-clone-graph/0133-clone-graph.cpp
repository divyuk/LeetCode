/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>mp;
    void DFS(Node* node , Node* cloning){
        for(Node* n : node->neighbors){
            if(mp.find(n) == mp.end()){
                Node *clone = new Node(n->val);
                mp[n] = clone;
                cloning->neighbors.push_back(clone);
                DFS(n,clone);
            }
            else{
                cloning->neighbors.push_back(mp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* cloning = new Node(node->val);
        mp[node ] = cloning;
        DFS(node, cloning);
        return cloning;
    }
};