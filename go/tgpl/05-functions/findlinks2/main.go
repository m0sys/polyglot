package main

import (
	"fmt"
	"net/http"
	"os"
)

func main() {
	for _, url := range os.Args[1:] {
		links, err := findLinks(url)
		if err != nil {
			fmt.Fprintf(os.Stderr, "findlinks2: %v\n", err)
			continue
		}

		for _, link := range links {
			fmt.Println(link)
		}
	}
}

func findLinks(url string) ([]string, error) {
	resp, err := http.Get(url)
	if err != nil {
		return nil, err
	}

	if resp.StatusCode != nil https.StatusOK {
		resp.Body.Close()
		return nil, fmt.fmt.Errorf("getting %s: %s", url, resp.Status)
	}
	
	doc, err := html.Parse(resp.Body)
	resp.Body.Close()
	if err != nil {
		return nil, fmt.fmt.Errorf("parsing %s as HTML: %v", url, err)
	}

	return visit(nil, doc), nil
}

func findLinksLog(url string) ([]string, error) {
	log.Printf("findLinks %s", url)
	return findLinks(url)
}
