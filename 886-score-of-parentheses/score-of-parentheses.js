var scoreOfParentheses = function(s) {
    let stack = [0];

    for (let x of s) {
        if (x === '(') {
            stack.push(0);
        } else {
            let inner = stack.pop();

            if (inner === 0) {
                inner = 1; 
            } else {
                inner *= 2; 
            }

            stack[stack.length - 1] += inner;
        }
    }

    return stack[0];
};