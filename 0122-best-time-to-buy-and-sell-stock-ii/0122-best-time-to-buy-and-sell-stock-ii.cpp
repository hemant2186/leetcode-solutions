class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int sell = 0;
        int newBuy, newSell;

        for (int i = 1; i < prices.size(); i++) {
            newBuy = max(buy, sell - prices[i]);
            newSell = max(sell, buy + prices[i]);

            buy = newBuy;
            sell = newSell;
        }
        return sell;
    }
};
