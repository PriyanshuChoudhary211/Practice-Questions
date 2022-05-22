int maxProfit(int* prices, int pricesSize) {
     int mpp = 0;
    int mxp = 0;
    for(int i = 1; i<pricesSize;i++)
    {
        if((prices[i]-prices[mpp])>mxp)
            mxp = prices[i]-prices[mpp];
        else if(prices[i]-prices[mpp]<0)
            mpp = i;
    }
    return mxp;
}