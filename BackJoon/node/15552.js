const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [T, ...f_input] = fs.readFileSync(filepath).toString().trim().split('\n');

let ans = '';
f_input.forEach((input) => {
    let [A,B] = input.split(' ').map(Number);
    ans += A + B + '\n';
});

console.log(ans);