const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, f_input] = fs.readFileSync(filepath).toString().trim().split("\n");
let input = f_input.split(" ").map(Number);

let dumArr = input.sort(function (a, b) {
    return a - b;
});

dumArr = new Set(input);
let uniqueArr = [...dumArr];

let obj = {};

uniqueArr.map((ele, index) => {
    obj[ele] = index;
});

let ouput = "";

f_input.split(" ").map((ele) => {
    ouput += obj[ele] + " ";
});

console.log(ouput);