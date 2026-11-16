class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string temp = "";
            while (s.size() > 0) {
                string group = s.substr(0, k);
                s.erase(0, k);
                int sum = 0;
                for (int i = 0; i < group.size(); i++) {
                    sum += group[i] - '0';
                }
                temp += to_string(sum);
            }
            s = temp;
        }
        return s;
    }
};