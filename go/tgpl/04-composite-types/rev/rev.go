// reverse reverses a slice of ints in place.
package main

import "fmt"

func reverse(s []int) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

func reverseArr(a *[32]int) {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

// Precondition: n < len(s)
func rotate(s []int, n int) {
	reverse(s[:n])
	reverse(s[n:])
	reverse(s)
}

func main() {
	a := [...]int{0, 1, 2, 3, 4, 5}
	reverse(a[:])
	fmt.Println(a)

	s := []int{0, 1, 2, 3, 4, 5}
	rotate(s, 2)
	fmt.Println(s)

	a2 := [32]int{0, 1, 2, 3, 4, 5}
	reverseArr(&a2)
	fmt.Println(a2)
}
