const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, ...f_input] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

console.log(Math.min(...f_input) * Math.max(...f_input));