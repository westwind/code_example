package main

import (
    "fmt"
)

type test struct {
    a func(string)
}

func main() {
    var gg test
    gg.a = qq
    gg.a("Hello World")
}
func qq(data string) {
    fmt.Println(data)
}
