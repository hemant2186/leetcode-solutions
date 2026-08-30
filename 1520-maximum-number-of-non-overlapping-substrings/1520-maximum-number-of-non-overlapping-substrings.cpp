class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        
        vector<pair<int,int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) continue;
            
            int start = first[c];
            int end = last[c];
            int i = start;
            
            while (i <= end) {
                int ch = s[i] - 'a';
                if (first[ch] < start) {
                    start = -1;
                    break;
                }
                end = max(end, last[ch]);
                i++;
            }
            
            if (start != -1) {
                intervals.push_back({start, end});
            }
        }
        
        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first > b.first; 
        });
        
        vector<string> result;
        int lastEnd = -1;
        
        for (auto& [start, end] : intervals) {
            if (start > lastEnd) {
                result.push_back(s.substr(start, end - start + 1));
                lastEnd = end;
            }
        }
        
        return result;
    }
};