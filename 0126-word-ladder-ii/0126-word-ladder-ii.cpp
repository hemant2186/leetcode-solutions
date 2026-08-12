class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        if (dict.find(endWord) == dict.end()) return result;
        
        unordered_map<string, vector<string>> parents; // word -> predecessors
        unordered_set<string> currentLevel;
        currentLevel.insert(beginWord);
        dict.erase(beginWord);
        
        bool found = false;
        
        while (!currentLevel.empty() && !found) {
            // remove this whole level from dict first,
            // so words within the same level don't chain off each other
            for (const string &w : currentLevel) dict.erase(w);
            
            unordered_set<string> nextLevel;
            
            for (const string &word : currentLevel) {
                string temp = word;
                for (int pos = 0; pos < temp.size(); pos++) {
                    char original = temp[pos];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        temp[pos] = c;
                        
                        if (dict.find(temp) != dict.end()) {
                            nextLevel.insert(temp);
                            parents[temp].push_back(word);
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[pos] = original;
                }
            }
            
            currentLevel = nextLevel;
        }
        
        if (!found) return result;
        
        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parents, path, result);
        
        return result;
    }
    
private:
    void backtrack(const string &word, const string &start,
                    unordered_map<string, vector<string>> &parents,
                    vector<string> &path, vector<vector<string>> &result) {
        if (word == start) {
            vector<string> seq(path.rbegin(), path.rend());
            result.push_back(seq);
            return;
        }
        
        if (parents.find(word) == parents.end()) return;
        
        for (const string &p : parents[word]) {
            path.push_back(p);
            backtrack(p, start, parents, path, result);
            path.pop_back();
        }
    }
};