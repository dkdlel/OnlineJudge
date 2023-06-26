const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, k, ...f_input] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

let arr = f_input.sort((a, b) => b - a);

console.log(arr[k - 1]);