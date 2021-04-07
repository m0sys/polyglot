package main

import (
	"fmt"
	"os"

	"golang.org/x/net/html"
)

func main() {
	doc, err := html.Parse(os.Stdin)
	if err != nil {
		fmt.Fprintf(os.Stderr, "tagcount: %v\n", err)
		os.Exit(1)
	}
	tagcount(make(map[string]int), doc)
}

func tagcount(counts map[string]int, n *html.Node) {
	if n.Type == html.ElementNode {
		counts[n.Data] += 1
		fmt.Println(counts)
	}

	for c := n.FirstChild; c != nil; c = c.NextSibling {
		tagcount(counts, c)
	}
}
