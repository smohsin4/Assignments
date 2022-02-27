const getNumberedStrings = (stringArray) => {
    let output = [];
    for(let i = 0; i < stringArray.length; i++) {
        for(let j = 0; j < stringArray[i].length; j++) {
            if(stringArray[i][j] == parseInt(stringArray[i][j])) {
                output.push(stringArray[i]);
                break;
            }
        }
    }
    return output;
}

let input = [
    "lorem",
    "ipsum",
    "hey12",
    "HELLO 1234"
];
console.log(getNumberedStrings(input));