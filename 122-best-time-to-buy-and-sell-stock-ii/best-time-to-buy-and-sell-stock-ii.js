/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let profit = 0;
    let n = prices.length;
    if(n<1){
        return 0;
    }
    for(let i=1; i<n; i++){
        if(prices[i]>prices[i-1])
        profit += prices[i]-prices[i-1];
    }
    return profit;
};