class Solution {
public:
    struct Node {
        Node * links[27];           // 0-25 alphabet 26 = '/'
        bool flag = false;
        bool isContains(char ch){       // Node has ch or not
            return links[ch-'a'] != NULL;
        }
        void put (char ch, Node * node){
            links[ch-'a'] = node;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
    };
    class Trie {
    public:
        Node * root;
        Trie() {
            root = new Node();
        }
        
        void insert(string word) {
            Node * node = root;
            int n = word.size();
            for(int i = 0;i<n;i++){
                char ch = word[i];
                if(word[i] == '/') ch = 'z' + 1;
                if(!(node ->isContains(ch))){   // if node doesn't contain word[i]
                    node->put(ch,new Node());
                }
                node = node->get(ch);          // move forward
            }
            char ch = 'z' + 1;                  // 'z'+1 represents backslash'/'
            node->put(ch, new Node());
            node = node->get(ch);               // add extra backslash to differentiate folders like /a/b/c and /a/b/ca we are adding /a/b/c/ and /a/b/ca/ 
            // if we mark flag and c in /a/b/c and ca will not get traversed so we are adding a backslash and marking flag there
            node->flag = true;                 // word is end here mark flag as true 
        }
    };
    void traverseTrie(Node * root, string curr, vector<string> &ans){       // normal dfs
        if(root == NULL) return;
        if(root->flag) {
            curr.pop_back();    //just remove last backslash as we are adding it additionaly
            ans.push_back(curr);
            return ;
        }
        for(char ch = 'a';ch <='z' + 1;ch++){       // traverse all char and backslash
            if(root->isContains(ch)){
                traverseTrie(root->get(ch), curr + (ch == '{' ? '/' : ch), ans);
                //     'z' + 1 = '{' and we are considering it as / so replace it 
            }
        }
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie trie;
        for(auto word : folder)    trie.insert(word);       // insert element in trie
        vector<string> ans;
        traverseTrie(trie.root,"",ans);
        return ans;
    }
};