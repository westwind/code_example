package main

import (
    "showinfo"
    "time"
    "fmt"
)

func main() {
    i := 0
    for {
        time.Sleep(1*time.Second)
        fmt.Println("Insert data")
        showinfo.Insert(i)
        i++
    }
}
