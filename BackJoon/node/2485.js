const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, ...f_input] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

function GCD(a, b) {
    while (a !== b && b != 0) {
        let n = a % b;
        a = b;
        b = n;
    }
    return a;
}

let arr = f_input.sort((a, b) => b - a);
let diff_arr = [];

for (let i = 0; i < N - 1; i++) {
    let diff = arr[i] - arr[i + 1];
    diff_arr.push(diff);
}

let gcd = diff_arr[0];
for (let i = 1; i < diff_arr.length; i++) {
    gcd = GCD(gcd, diff_arr[i]);
}

let ans = diff_arr.reduce((acc, cur) => acc + cur / gcd - 1, 0);

console.log(ans);