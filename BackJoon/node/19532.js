const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [a, b, c, d, e, f] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

let x = (b * f - c * e) / (b * d - a * e);
let y = (a * f - c * d) / (a * e - b * d);

console.log(x + ' ' + y);