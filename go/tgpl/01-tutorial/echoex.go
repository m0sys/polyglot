// The Go Programming Language Textbook.
//
// Chapter 1.2 Exercise Slns.
//
// Tutorial -> Command-Line-Arguments.
//
// @Created At 2021/4/5
// @Author mhd53

package main

import (
	"fmt"
	"log"
	"os"
	"strings"
	"time"
)

func main() {
	fmt.Println("Starting Ex1...")
	ex1()

	fmt.Println("\nStarting Ex2...")
	ex2()

	fmt.Println("\nStarting Ex3...")
	ex3()

	fmt.Println("\nStarting Ex3v2...")
	ex3v2()

	fmt.Println("\nGoodbye!")
}

func ex1() {
	var s, sep string
	for i := 0; i < len(os.Args); i++ {
		s += sep + os.Args[i]
		sep = " "
	}

	fmt.Println(s)
}

func ex2() {
	s, sep := "", ""

	for _, arg := range os.Args[1:] {
		s += sep + arg
		sep = "\n"
	}
	fmt.Println(s)
}

func ex3() {
	start := time.Now()
	joinArgs()
	elapsed := time.Since(start)
	log.Printf("Using Join: time elapsed -> %s \n", elapsed)

	start = time.Now()
	ex2()
	elapsed = time.Since(start)
	log.Printf("Using Range: time elapsed -> %s \n", elapsed)
}

func joinArgs() {
	fmt.Println(strings.Join(os.Args[1:], " "))
}

func ex3v2() {
	fmt.Println("Using neat trick for timing go programs!")
	defer timeTrack(time.Now(), "Join")
	joinArgs()
	defer timeTrack(time.Now(), "Range")
	ex2()
}

// Using neat trick for timing programs.
func timeTrack(start time.Time, name string) {
	elapsed := time.Since(start)
	log.Printf("%s took %s\n", name, elapsed)
}
