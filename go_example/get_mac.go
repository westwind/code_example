package main

import (
    "fmt"
    "net"
)

func main() {
    interfaces, err := net.Interfaces()
    if err != nil {
        panic("Pool soul, here is what you get: " + err.Error())
    }

    for _, inter := range interfaces {
        fmt.Println(inter.Name, inter.HardwareAddr)
        if addrs, err := inter.Addrs(); err ==nil {
            for _, addr := range addrs {
                fmt.Println(inter.Name, "->", addr)
            }
        }
    }
}

