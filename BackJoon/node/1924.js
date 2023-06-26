const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [x, y] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

const day = [31,28,31,30,31,30,31,31,30,31,30,31];
const days = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT'];

let sum = 0;
for(let i = 1 ; i < x ; i++){
    sum += day[i-1];
}
sum += y;

console.log(days[sum % 7]);