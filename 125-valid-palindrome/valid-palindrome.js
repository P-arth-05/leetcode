/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let left = 0;
    let right = s.length - 1;
    while(left<right){
        while(left<right && !toUse(s[left])) left++;
        while(left<right && !toUse(s[right])) right--;
        if (s[left].toLowerCase() !== s[right].toLowerCase()) return false;
        left++;
        right--;
    }
    return true;
};

function toUse(ch){
    let lower = ch.toLowerCase();
    return (
        (lower >= 'a' && lower <= 'z') || (lower >= '0' && lower <= '9')
    );
};