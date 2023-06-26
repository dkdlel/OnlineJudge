const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [M, N] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

const isPrime = (num) => {

    if (num < 2) return false;

    let sqrt = Math.sqrt(num);
    for (let i = 2; i <= sqrt; i++) {
        if (num % i === 0) {
            return false;
        }
    }

    return true;
}

let ans = [];
for (let i = M; i <= N; i++) {
    if (isPrime(i)) {
        ans.push(i);
    }
}

console.log(ans.join('\n'));