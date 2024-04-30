class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        unordered_set<string>dict(wordList.begin(), wordList.end());
        dict.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int step    = q.front().second;
            q.pop();
            if(word==endWord) return step;
            
            for(int i= 0; i< word.size() ; i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(dict.find(word)!= dict.end()){
                        q.push({word, step+1});
                        dict.erase(word);
                    } 
                }
                word[i] = original;
            }
        }
        return 0;
    }
};