struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val) : key(key) , val(val) , next(nullptr), prev(nullptr){}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> umap;
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(umap.find(key) == umap.end()) return -1;
        Node* node = umap[key];
        remove(node);
        add(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(umap.find(key) != umap.end()){
            Node* oldNode = umap[key];
            remove(oldNode);
        }
        // Create a new Node
        Node* node = new Node(key, value);
        umap[key] = node;
        add(node);
        
        if(umap.size() > capacity){
            Node* nodeToDelete = head->next;
            remove(nodeToDelete);
            umap.erase(nodeToDelete->key);
        }
    }
    
    // Adding node to the back of the linked list
    void add(Node *node) {
        Node *previousEnd = tail->prev;
        previousEnd->next = node;
        node->prev = previousEnd;
        node->next = tail;
        tail->prev = node;
    }
    
    // Remove node when update/fetch and existing key, or when capacity overflow.
    void remove(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    // Similar
    // void remove(Node *node) {
    //     node->prev->next = node->next;
    //     node->next->prev = node->prev;
    // }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */