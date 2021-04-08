package main

import (
	"fmt"
	"image/color"
	"tgpl/ch6/coloredpoint"
	g "tgpl/ch6/geometry"
	"tgpl/ch6/intset"
)

func main() {
	// Geometry.
	p := g.Point{1, 2}
	q := g.Point{4, 6}
	fmt.Println(g.Distance(p, q))
	fmt.Println(p.Distance(q))

	perim := g.Path{
		{1, 1},
		{5, 1},
		{5, 4},
		{1, 1},
	}
	fmt.Println(perim.Distance())

	// Color points
	red := color.RGBA{255, 0, 0, 255}
	blue := color.RGBA{0, 0, 255, 255}
	var p2 = coloredpoint.ColoredPoint{g.Point{1, 1}, red}
	var q2 = coloredpoint.ColoredPoint{g.Point{5, 4}, blue}
	fmt.Println(p2.Distance(q2.Point))

	// IntSet.
	var x, y intset.IntSet
	x.Add(1)
	x.Add(144)
	x.Add(9)
	fmt.Println(x.String())

	y.Add(9)
	y.Add(42)
	fmt.Println(y.String())

	x.UnionWith(&y)
	fmt.Println(x.String())

	fmt.Println(x.Has(9), x.Has(123))
}
