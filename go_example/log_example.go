package main

import (
    "time"
)
import l4g "code.google.com/p/log4go"

const (
    filename = "test.log"
)

func main() {
    log := make(l4g.Logger)
    //log := l4g.NewDefaultLogger(l4g.DEBUG)
    flw := l4g.NewFileLogWriter(filename, false)
    flw.SetFormat("[%D %T] [%L] (%S) %M")
    flw.SetRotate(false)
    flw.SetRotateSize(0)
    flw.SetRotateLines(0)
    flw.SetRotateDaily(false)
    log.AddFilter("file", l4g.FINE, flw)
    log.Info("log info")
    time.Sleep(1*time.Second)
}
