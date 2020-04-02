package main

import (
	"os"
	"fmt"
	"bufio"
)

var n, w, k int
var ans, c int64

func main() {
	rbuf := bufio.NewReader(os.Stdin)
	fmt.Fscan(rbuf, &n, &w, &k)
	for i := 0; i < n; i++ {
		var x int
		fmt.Fscan(rbuf, &x)
		if int64(x) + c > int64(w) {
			ans += int64(x) + c - int64(w)
			c += int64(k)
		}
	}
	fmt.Println(ans)
}