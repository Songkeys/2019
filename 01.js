const fs = require("fs")
const rawInput = fs.readFileSync("./01.txt", "utf8").trim()
const nums = rawInput.split("\n").map(Number)

// part 1
console.log(nums.reduce((x,y) => x + Math.floor(y / 3) - 2, 0))

// part 2
ans = 0
nums.forEach(num => {
	while (num > 0) {
		num = Math.floor(num / 3) - 2
		if (num > 0) ans += num
	}
})

console.log(ans)
