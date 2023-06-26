const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [T, ...f_input] = fs.readFileSync(filepath).toString().trim().split("\n");

const GCD = (a, b) => {

    while (b != 0) {
        let n = a % b;
        a = b;
        b = n;
    }

    return a;
}

f_input.map((input) => {
    let [n1, n2] = input.split(' ').map(Number);

    let gcd = n1 > n2 ? GCD(n1, n2) : GCD(n2, n1);

    console.log(n1 * n2 / gcd);
})