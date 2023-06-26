const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [...f_input] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

let arr = f_input.sort((a, b) => a - b);
let sum = f_input.reduce((sum, acc) => sum + acc, 0);

console.log(sum / 5);
console.log(arr[2]);