function getArrayDepth(arr) {
    if(arr == null) {return 0;}
    function getDepth(arrElement) {
        if(typeof(arrElement) == Number) {return 0;}
        let max = 1;
        for(let j = 0; j < arrElement.length; j++) {
            let d = 1 + getDepth(arrElement[j]);
            if(d > max) { max = d; }
        }
        return max;
    }
    let maxDepth = 1;
    for(let i = 0; i < arr.length; i++) {
        let depth = getDepth(arr[i]);
        if(depth > maxDepth) {maxDepth = depth;}
    }
    return maxDepth;
}

console.log(getArrayDepth([1, [2, [3, [4]]]]));
console.log(getArrayDepth([1, [2,[3,4], 5, [6,[7,[8,[9,[10,11]]]]]], 2,3,4]));
console.log(getArrayDepth());
console.log(getArrayDepth([]));