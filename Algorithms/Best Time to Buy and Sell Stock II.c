/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

/****************************************************************************************/

int maxProfit(int* prices, int pricesSize) {
    int  max = 0, buy = 0, sell = 0;
    
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < prices[buy])
        {
            if (0 != sell)
            {
                max += prices[sell] - prices[buy];
                sell = 0;
            }
            buy = i;
        }
        else
        {
            if (0 == sell || prices[i] > prices[sell])
            {
                sell = i;
            }
            else
            {
                if (prices[i] < prices[sell])
                {
                    max += prices[sell] - prices[buy];
                    sell = 0;
                    buy = i;
                }
            }
        }
    }
    
    if (sell > buy)
    {
        max += prices[sell] - prices[buy];
    }
    
    return max;
    
}