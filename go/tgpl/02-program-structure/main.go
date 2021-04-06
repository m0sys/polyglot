// The Go Programming Language Textbook.
//
// Chapter 2.6 Exercise Slns.
//
// Program Structure -> Pkgs and Files.
//
// @Created At 2021/4/6
// @Author mhd53
package main

import (
	"flag"
	"fmt"
	"os"
	"strconv"
	"tgpl/ch2/distanceconv"
	"tgpl/ch2/massconv"
	"tgpl/ch2/tempconv"
)

var d = flag.Bool("d", false, "distance conversion")
var m = flag.Bool("m", false, "mass conversion")
var T = flag.Bool("T", true, "default temperature conversion")

func main() {
	flag.Parse()
	args := flag.Args()
	for _, arg := range args {
		t, err := strconv.ParseFloat(arg, 64)
		if err != nil {
			fmt.Fprintf(os.Stderr, "cf: %v\n", err)
			os.Exit(1)
		}

		if *d {
			m := distanceconv.Meter(t)
			mi := distanceconv.Mile(t)
			fmt.Printf("%s = %s, %s = %s\n",
				m, distanceconv.MToMi(m), mi, distanceconv.MiToM(mi))
		} else if *m {
			kg := massconv.Kilogram(t)
			lb := massconv.Pound(t)
			fmt.Printf("%s = %s, %s = %s\n",
				kg, massconv.KGToLB(kg), lb, massconv.LBToKG(lb))

		} else {

			f := tempconv.Fahrenheit(t)
			c := tempconv.Celsius(t)
			fmt.Printf("%s = %s, %s = %s\n",
				f, tempconv.FToC(f), c, tempconv.CToF(c))
		}
	}
}
