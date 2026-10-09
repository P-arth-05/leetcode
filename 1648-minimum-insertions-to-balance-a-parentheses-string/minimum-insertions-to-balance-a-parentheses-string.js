// /**
//  * @param {string} s
//  * @return {number}
//  */
// var minInsertions = function(s) {
//     let st = [];
//     let ans = 0;
//     for(let i=0; i<s.length; i++){
//         if(s[i] == '(') st.push(s[i]);
//         else if(s[i] == ')' && s[i+1] == ')'){
//             st.pop(st[st.length - 1]);
//             i++;
//         }
//         else{
//             ans++;
//         }
//     }
//     return st.length - ans;
// };

var minInsertions = function(s) {
    let ans = 0;
    let need = 0;

    for (let c of s) {
        if (c === '(') {
            if (need % 2 === 1) {
                ans++;
                need--;
            }
            need += 2;
        } else {
            need--;
            if (need < 0) {
                ans++;
                need = 1;
            }
        }
    }
    return ans + need;
};
