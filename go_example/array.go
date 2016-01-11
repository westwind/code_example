package main

import (
    "fmt"
)

func main() {
    var a1 [3]int
    var a2 [3]int

    fmt.Println("=== INIT a1 ===")
    a1[0]=1
    a1[1]=2
    a1[2]=3

    fmt.Printf("address of a1: %p\n",&a1)
    fmt.Printf("address of a2: %p\n",&a2)
    for i := range a1 {
        fmt.Printf("a1[%d]: %d\n", i, a1[i])
    }
    for i := range a2 {
        fmt.Printf("a2[%d]: %d\n", i, a2[i])
    }

    fmt.Println("=== Copy Array ===")
    a2 = a1

    fmt.Printf("address of a1: %p\n",&a1)
    fmt.Printf("address of a2: %p\n",&a2)
    for i := range a1 {
        fmt.Printf("a1[%d]: %d\n", i, a1[i])
    }
    for i := range a2 {
        fmt.Printf("a2[%d]: %d\n", i, a2[i])
    }
}
