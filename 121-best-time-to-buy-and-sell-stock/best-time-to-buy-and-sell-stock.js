/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let minp = Infinity;
    let maxp = 0;
    for(let price of prices){
        minp = Math.min(minp,price);
        let profit = price - minp;
        maxp = Math.max(maxp, profit);
    }
    return maxp;
};