package main

import (
    "fmt"
    "encoding/json"
)

type server_info struct {
    IP int
    Box []string
}

func main() {
    new_server := &server_info{
        IP: 1,
        Box: []string{"abc", "bcd"}}

    test, _ := json.Marshal(new_server)
    fmt.Println(new_server)
    fmt.Println(string(test))
}
