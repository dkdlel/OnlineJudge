const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [n1, n2] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

const GCD = (a, b) => {

    while (b != 0) {
        let n = a % b;
        a = b;
        b = n;
    }

    return a;
}

let gcd = n1 > n2 ? GCD(n1, n2) : GCD(n2, n1);

console.log(n1 * n2 / gcd);