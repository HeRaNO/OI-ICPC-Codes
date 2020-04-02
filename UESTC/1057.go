package main

import (
	"os"
	"fmt"
	"bufio"
	"strings"
)

const MAXN = 100000

var x[1 << 18] int64
var lazy[1 << 18] int64
var a[MAXN] int
var n, m, l, r, v int

func BuildTree(u, l, r int) {
	if l + 1 == r {
		x[u] = int64(a[l])
		return
	}
	var m int
	m = (l + r) >> 1
	BuildTree(u << 1, l, m)
	BuildTree(u << 1 | 1, m, r)
	x[u] = x[u << 1] + x[u << 1 | 1]
}

func add(u, l, r int, v int64) {
	x[u] += int64(r - l) * v
	lazy[u] += v
}

func PushDown(u, l, r int) {
	if lazy[u] != 0 {
		var m int
		m = (l + r) >> 1
		add(u << 1, l, m, lazy[u])
		add(u << 1 | 1, m, r, lazy[u])
		lazy[u] = 0
	}
}

func modify(u, l, r, v, pl, pr int) {
	if l == pl && r == pr {
		add(u, l, r, int64(v))
		return
	}
	PushDown(u, pl, pr)
	var m int
	m = (pl + pr) >> 1
	if r <= m {
		modify(u << 1, l, r, v, pl, m)
	} else {
		if m <= l {
			modify(u << 1 | 1, l, r, v, m, pr)
		} else {
			modify(u << 1, l, m, v, pl, m)
			modify(u << 1 | 1, m, r, v, m, pr)
		}
	}
	x[u] = x[u << 1] + x[u << 1 | 1]
}

func query(u, l, r, pl, pr int) int64 {
	if l == pl && r == pr {
		return x[u]
	}
	PushDown(u, pl, pr)
	var m int
	m = (pl + pr) >> 1
	if r <= m {
		return query(u << 1, l, r, pl, m)
	} else {
		if m <= l {
			return query(u << 1 | 1, l, r, m, pr)
		} else {
			return query(u << 1, l, m, pl, m) + query(u << 1 | 1, m, r, m, pr)
		}
	}
}

func main() {
	rbuf := bufio.NewReader(os.Stdin)
	fmt.Fscan(rbuf, &n)
	for i := 0; i < n; i++ {
		fmt.Fscan(rbuf, &a[i])
	}
	BuildTree(1, 0, n)
	fmt.Fscan(rbuf, &m)
	for i := 0; i < m; i++ {
		fmt.Fscan(rbuf, &l, &r, &v)
		modify(1, l - 1, r, v, 0, n)
		fmt.Println(strings.Trim(fmt.Sprint(query(1, l - 1, r, 0, n)), "[]"))
	}
}