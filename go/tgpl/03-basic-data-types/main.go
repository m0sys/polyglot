package main

import (
	"fmt"
	"io"
	"os"
	"tgpl/ch3/mandelbrot"
	"tgpl/ch3/surface"
)

// NOTE: There are two very interesting exercises on p.60 (e3.3, e3.4).
//		 Come back when you have time.

// NOTE: There are three more very interesting exercises on p.62 (e3.5, e3.6, e3.7).
// 世界天

func main() {
	saveToFile(surface.DrawSurface, "surface.svg")
	saveToFile(mandelbrot.PaintMandelbrot, "mandelbrot.png")
}

func saveToFile(toSave func(io.Writer), fname string) {
	fd, err := os.Create(fname)
	if err != nil {
		fmt.Println(err)
		fd.Close()
		return
	}
	toSave(fd)
}
