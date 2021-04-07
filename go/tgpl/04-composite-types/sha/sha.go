package main

import (
	"crypto/sha256"
	"crypto/sha512"
	"flag"
	"fmt"
)

var sha3 = flag.Bool("sha384", false, "Encode string as SHA384")
var sha5 = flag.Bool("sha512", false, "Encode string as SHA512")

func main() {
	// c1 := sha256.Sum256([]byte("x"))
	// c2 := sha256.Sum256([]byte("X"))
	// fmt.Printf("%x\n%x\n%t\n%T\n", c1, c2, c1 == c2, c1)

	ex2()
}

func ex2() {
	flag.Parse()
	args := flag.Args()

	for _, arg := range args {
		b := []byte(arg)
		if *sha3 {
			fmt.Printf("%x\n", sha512.Sum384(b))
			return
		} else if *sha5 {
			fmt.Printf("%x\n", sha512.Sum384(b))
			return
		} else {
			fmt.Printf("%x\n", sha256.Sum256(b))
			return
		}
	}

}
