class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadBuy, aheadNotBuy, curBuy, curNotBuy;
        aheadNotBuy = aheadBuy = 0;
        for(int ind=n-1;ind>=0;ind--){
            curNotBuy = max(prices[ind] + aheadBuy,
            0 + aheadNotBuy);
            curBuy = max(-prices[ind] - fee + aheadNotBuy, 
            0 + aheadBuy);
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};