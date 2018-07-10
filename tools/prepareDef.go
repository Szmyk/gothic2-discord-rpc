package main

import (
	"regexp"

	"github.com/Szmyk/go-utils/files"
)

func main() {
	lines := files.ReadLines("output/vdfs32g.def")

	for i := range lines {
		var re = regexp.MustCompile(`([\w]*)\s*@(\d*)`)
		lines[i] = re.ReplaceAllString(lines[i], `$1=OrgVdfs32g.$1  @$2`)
	}

	files.WriteLines(lines, "output/vdfs32g.def")
}
