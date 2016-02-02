package main
import (
    "fmt"
)

func main() {
    var s1 []int
    s1 = make([]int,0, 5)

    fmt.Println("======")
    fmt.Printf("s1: %d\n", s1)
    fmt.Printf("len of s1: %d\n", len(s1))
    fmt.Printf("cap of s1: %d\n", cap(s1))

    for i:=0;i<20;i++ {
        s1 = append(s1, i)
        fmt.Printf("====== [%d]\n",i)
        fmt.Printf("s1: %d\n", s1)
        fmt.Printf("len of s1: %d\n", len(s1))
        fmt.Printf("cap of s1: %d\n", cap(s1))
    }
}
