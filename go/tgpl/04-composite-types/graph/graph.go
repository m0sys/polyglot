package main

import "fmt"

var graphy = make(map[string]map[string]bool)

func addEdge(from, to string) {
	edges := graphy[from]
	if edges == nil {
		edges = make(map[string]bool)
		graphy[from] = edges
	}
	edges[to] = true
}

func hasEdge(from, to string) bool {
	return graphy[from][to]
}

func main() {
	addEdge("America", "Europe")
	fmt.Println("America -> Europe: ", hasEdge("America", "Europe"))
}
