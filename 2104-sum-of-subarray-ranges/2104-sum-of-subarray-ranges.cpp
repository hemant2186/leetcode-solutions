class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> prevMin(n), nextMin(n);
        vector<int> prevMax(n), nextMax(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            prevMin[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            nextMin[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            prevMax[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            nextMax[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long minSum = 0, maxSum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prevMin[i];
            long long right = nextMin[i] - i;
            minSum += 1LL * nums[i] * left * right;
        }

        for (int i = 0; i < n; i++) {
            long long left = i - prevMax[i];
            long long right = nextMax[i] - i;
            maxSum += 1LL * nums[i] * left * right;
        }
        return maxSum - minSum;
    }
};