function getPersistence(...number) {
    let sum = 0;
    number.forEach(element => {
        sum += element;
    });

    function multiply(n){
        return n.reduce(function(a,b){return a*b;});
    }
    var count = 0; 
 
    while(sum.toString().length > 1) {
        sum = sum.toString().split("");
        sum = multiply(sum);
        count++;
     }
     return count;
}

console.log(`Output => ${getPersistence(181967981296545, 95809807592354)}`);