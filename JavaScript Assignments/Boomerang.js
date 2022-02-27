const findBoomerangs = (input) => {
    let arr = [];
    for(let i = 0; i < input.length - 1; i++) {
        if((input[i] == input[i+2]) && (input[i] != input[i+1])) {
            arr.push(input.slice(i, i+3));
        }
    }
    return arr;
}

const printBoomerangs = (input, output) => {
    console.log(`\nInput=> ${input}`);
    console.log("Output => " + output.length + " boomerangs in this sequence: ");
    console.log(output);
    console.log("\n");
}

let input_array = [3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2]; 
printBoomerangs(input_array ,findBoomerangs(input_array));