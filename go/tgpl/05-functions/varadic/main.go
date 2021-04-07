package main

import "fmt"

// Exercise 5.15a.

func max(vals ...int) int {
	var ans int
	for _, val := range vals {
		if val > ans {
			ans = val
		}
	}

	return ans
}

func min(vals ...int) int {
	var ans int
	for _, val := range vals {
		if val < ans {
			ans = val
		}
	}

	return ans
}

func main() {
	fmt.Println("Max: ", max(1, 2, 3, 4, 10))
	fmt.Println("Min: ", min(1, 2, 3, 4, 10, -21))
}
