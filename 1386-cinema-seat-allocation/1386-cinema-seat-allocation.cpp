class Solution {
public:
    long long maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        const int LEFT  = 0b00001111; // seats 2-5
        const int MID   = 0b00111100; // seats 4-7
        const int RIGHT = 0b11110000; // seats 6-9

        unordered_map<int, int> rowMasks;

        for (auto& res : reservedSeats) {
            int row = res[0];
            int seat = res[1];
            if (seat >= 2 && seat <= 9) {
                rowMasks[row] |= (1 << (seat - 2));
            }
        }

        long long result = (long long)(n - (int)rowMasks.size()) * 2;

        for (auto& [row, mask] : rowMasks) {
            if ((mask & LEFT) == 0 && (mask & RIGHT) == 0) {
                result += 2;
            } else if ((mask & LEFT) == 0 || (mask & MID) == 0 || (mask & RIGHT) == 0) {
                result += 1;
            }
        }

        return result;
    }
};