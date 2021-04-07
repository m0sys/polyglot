/*
The Go Programming Language Textbook.

Chapter 4.3 Exercise Slns.

Composite Types -> Maps.

@Created At 2021/4/7
@Author mhd53
*/

package exercise

import (
	"bufio"
	"fmt"
	"os"
)

var wordvect = make(map[string]int)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	for scanner.Scan() {
		word := scanner.Text()
		wordvect[word] += 1
	}

	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading input: ", err)
		return
	}
	fmt.Printf(wordvect)
}
