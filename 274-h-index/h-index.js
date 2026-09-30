/**
 * @param {number[]} citations
 * @return {number}
 */
var hIndex = function(citations) {
    citations.sort((a,b)=>b-a);
    let ans = 0;
    for(let i=0; i<citations.length; i++){
        ans++;
        if(citations[i]<i+1){
            ans -= 1;
            break;
        }
    }
    return ans;
};