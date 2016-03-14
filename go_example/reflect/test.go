package main

import (
    "fmt"
    "reflect"
)

func main() {
    s := "This is String"
    fmt.Println(reflect.TypeOf(s))
    fmt.Println(reflect.ValueOf(s).Len())
}
