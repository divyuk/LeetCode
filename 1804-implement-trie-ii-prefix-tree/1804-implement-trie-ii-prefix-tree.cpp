struct Node {
  Node * links[26]; 
  int cntStartsWith = 0; 
  int cntPrefix = 0;

  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL);
  }
  Node * get(char ch) {
    return links[ch - 'a'];
  }
  void put(char ch, Node * node) {
    links[ch - 'a'] = node;
  }
  void increaseStart() {
    cntStartsWith++;
  }
  void increasePrefix() {
    cntPrefix++;
  }
  void deleteStart() {
    cntStartsWith--;
  }
  void reducePrefix() {
    cntPrefix--;
  }
  int getStart() {
    return cntStartsWith;
  }
  int getPrefix() {
    return cntPrefix;
  }
};
class Trie {
private : 
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i< word.size() ; i++){
            if(!node->containsKey(word[i])) node->put(word[i] , new Node());
            node = node->get(word[i]);
            node -> increasePrefix();
        }
        node->increaseStart();
    }
    
    int countWordsEqualTo(string word) {
        Node* node = root;
        for(int i =0; i< word.size() ; i++){
            if(node->containsKey(word[i])) node = node->get(word[i]);
            else return 0;
        }
        return node->getStart();
    }
    
    int countWordsStartingWith(string prefix) {
        Node* node = root;
        for(int i = 0 ; i< prefix.size() ; i++){
            if(node->containsKey(prefix[i])) node = node->get(prefix[i]);
            else return 0;
        }
        return node->getPrefix();
    }
    
    void erase(string word) {
        Node* node = root;
        for(int i=0; i< word.size() ; i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else return ;
            
        }
        node->deleteStart();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */