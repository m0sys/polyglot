package main

import (
	"fmt"

	"example.com/user/hello/morestrings"
	"github.com/google/go-cmp/cmp"
)

func main() {
	fmt.Println("Hello, World!")
	fmt.Println(morestrings.ReverseRunes("!oG ,olleH"))
	fmt.Println(cmp.Diff("Hello, World", "Hello, Go"))
	fmt.Println("Github Hello")
}
