package coloredpoint

import (
	"image/color"
	g "tgpl/ch6/geometry"
)

type Point struct{ X, Y float64 }

type ColoredPoint struct {
	g.Point
	Color color.RGBA
}
