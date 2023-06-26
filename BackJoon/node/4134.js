const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [T, ...f_input] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

const isPrime = (num) => {
    let sqrt = Math.sqrt(num);

    if (num < 2) return false;

    for (let i = 2; i <= sqrt; i++) {
        if (num % i === 0) {
            return false;
        }
    }

    return true;
}

f_input.forEach((num) => {

    let ans = num;
    for (let i = ans; ; i++) {
        if (isPrime(i)) {
            console.log(i);
            break;
        }
    }
});