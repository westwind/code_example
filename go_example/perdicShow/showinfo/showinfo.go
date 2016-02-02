package showinfo

import (
    "fmt"
    "time"
)

var g_data []int

func init() {
    go show_info()
}

func show_info() {
    for {
        switch {
            case g_data != nil:
                fmt.Println("show g_data")
                fmt.Println(g_data)
                g_data = nil
            default:
                fmt.Println("sleep 3 second...")
                time.Sleep(3*time.Second)

        }
    }
}

func Insert(data int) {
    g_data = append(g_data, data)
}
