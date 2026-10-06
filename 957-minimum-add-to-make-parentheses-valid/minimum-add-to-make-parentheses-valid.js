var minAddToMakeValid = function(s) {
    let open = 0;
    let additions = 0;

    for (let x of s) {
        if (x === '(') {
            open++;
        } 
        else {
            if (open > 0) {
                open--;       // match an existing '('
            } 
            else {
                additions++;  // need to insert '(' before this ')'
            }
        }
    }

    return additions + open;
};