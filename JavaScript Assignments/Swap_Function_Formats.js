function changeFunctionFormat(str) {
    function getFunctionType(str) {
        if(str.split(" ")[0] == 'function') { return 0; }
        if(str.split(" ")[0] == 'let' || str.split(" ")[0] == 'var') { return 1; }
        return null;
    }

    function regularToArrow(str) {
        let function_name = (str.split(" ")[1]).split("(")[0];
        let args = (str.split("(")[1]).split(")")[0];
        let body = (str.split(")")[1]);
        let new_str = "let " + function_name + " = " + "(" + args + ")" + " => " + body;
        return new_str;
    }
    
    function arrowToRegular(str) {
        //let sample = (arg1, arg2) =>  {return arg1 + arg2;}
        let function_name = (str.split(" ")[1]).split("=")[0];
        let args = (str.split("=")[1]);
        let body = (str.split("=>")[1]);
        let new_str = "function " + function_name + " = " + args + " " + body;
        return new_str;
    }
    
    let type = getFunctionType(str);
    if(type == null) {return null;}
    if(type === 0) {
        return regularToArrow(str);
    }
    return arrowToRegular(str);
}

let input1 = "function sample (arg1, arg2) {return arg1 + arg2;}";
let input2 = "let sample = (arg1, arg2) =>  {return arg1 + arg2;}";

console.log("The function: \n" + input1 + "\nis converted to: \n" + changeFunctionFormat(input1) + "\n\n");
console.log("The function: \n" + input2 + "\nis converted to: \n" + changeFunctionFormat(input2) + "\n\n");
