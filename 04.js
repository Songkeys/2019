ans = 0
ans2 = 0
for (let i = 134564; i < 585159; ++i) {
	p = i.toString()
	if ([...p].sort().join('') === p && p.match(/(\d)\1/u)) {
		++ans
		if ([...p].map(x => [...p].filter(y => x === y).length).includes(2)) ++ans2
	}
}

console.log(ans, ans2)
