function countLoneOnes(number) {
    let str = String(number);
    let count = 0;
    if(str[0] == '1' && str[1] != '1') {
        count++;
    }
    for(let i = 1; i < str.length; i++) {
        if((str[i] == '1') && (str[i-1] != '1') && (str[i+1] != '1')) {
            count++;
        }
    }
    return count;
}

let input = 123112312311001;
console.log(`\nOutput => Number of Lone 1s in ${input} are: ${countLoneOnes(input)}\n`);