/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */

/****************************************************************************************/

int maxProfit(int* prices, int pricesSize) {
    int buy = 0, sell = 0, max = 0;
    
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < prices[buy])
        {
            buy = i;
            sell = 0;
        }
        else
        {
            if (sell == 0 || prices[sell] < prices[i])
            {
                sell = i;
                
                if (max < prices[sell] - prices[buy])
                {
                    max = prices[sell] - prices[buy];
                }
            }
            
        }
    }
    
    return max;
    
}