/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    let a = 0;
    for(let x of t){
        if(s[a]==x){
            a++;
        }
    }
    return s.length === a;
};