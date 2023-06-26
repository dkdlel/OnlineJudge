const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [a1, a2, b1, b2] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

const GCD = (a, b) => {
    while (b != 0) {
        let n = a % b;
        a = b;
        b = n;
    }
    return a;
}

let n1 = a1 * b2 + a2 * b1;
let n2 = a2 * b2;
let gcd = n1 > n2 ? GCD(n1, n2) : GCD(n2, n1);

console.log(n1 / gcd + ' ' + n2 / gcd);