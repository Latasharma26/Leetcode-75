class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;          // Maximum profit when not holding stock
        int hold = -prices[0]; // Maximum profit when holding stock (initially buy on the first day)

        for (int i = 1; i < prices.size(); i++) {
            cash = max(cash, hold + prices[i] - fee); // Sell stock
            hold = max(hold, cash - prices[i]);       // Buy stock
        }

        return cash; // Return maximum profit when not holding stock
    }
};