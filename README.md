# tstools
Tools for MPEG-TS streams.
To compile use cmake for windows, linux, or macOS (see below).

More details in the Wiki.

## qt tools
viewTS : display the timestamp of a ts stream.

To compile first import in Qt top level CMakeLists.txt.
Works on Windows and macOS (Apple Silicon) with Qt 5 or Qt 6.

## macOS (Apple Silicon)

This fork is maintained for macOS arm64 (Apple Silicon). The build is
verified with CMake 4.x, Apple clang, and Homebrew Qt 6.

```sh
brew install cmake qt
```

CLI tools (tscheck, tsmap, tscut) and tests:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j 8
(cd build/test && ../../bin/linux/tstool_tests)
```

Artifacts are placed in `bin/linux/` (upstream directory naming, kept as-is).

viewTS (Qt GUI):

```sh
mkdir -p build/viewTS && cd build/viewTS
qmake ../../qt_tstools/viewTS.pro
make -j 8    # -> ../../bin/mac/viewTS.app
```

![alt text](https://github.com/OlivierLeBozec/tstools/blob/master/screenshots/pcrjitter.png)

![alt text](https://github.com/OlivierLeBozec/tstools/blob/master/screenshots/pcrptsdts.png)

![alt text](https://github.com/OlivierLeBozec/tstools/blob/master/screenshots/ptspcr.png)

## tsmap
NAME
    ./tsmap - list mpeg ts content
    Version 1.0

SYNOPSIS
    ./tsmap FILE [-pidlist -pidmap]

DESCRIPTION
    List mpeg information about the FILE. Without using PSI-SI tables

    -pidlist
       list of the pid in the file

    -pidmap
       map of the pid in the file

## tscheck
NAME
    ./tscheck - check timestamp
    Version 1.0

SYNOPSIS
    ./tscheck FILE -pid <PID> [...]

DESCRIPTION
    Display specified timestamp operation

    -pidpcr <PID>
           set pcr pid

    -pidpts <PID>
           set pts pid

    -piddts <PID>
           set dts pid

Following commands are available only at least one PID is specified

    -dump
           dump timestamp

    -dur
           get duration of the stream

    -rate
           get bitrate of pid

    -delta
           diff between same consecutive timestamp for pcr, pts or dts

    -jitter
           display jitter for pcr

    -diff
           diff between 2 timestamps : pts - pcr, dts - pts or pts - dts

## tscut
   tscut - cut mpeg ts content
   Version 1.0

SYNOPSIS
   /home/olivier/tstools/tscut FILE [-split <nb packet>]

DESCRIPTION
   cut ts stream

    -split <nb packets>
          cut file every nb packets

## Tested examples:
    ./tsmap ./ts/audio.ts -pidlist -pidmap

    ./tscheck ./ts/audio.ts -pidpcr 305 -dur -rate
    ./tscheck ./ts/audio.ts -pidpcr 305 -dump
    ./tscheck ./ts/audio.ts -pidpts 305 -dump
    ./tscheck ./ts/audio.ts -pidpcr 305 -pidpts 305 -diff
    ./tscheck ./ts/audio.ts -pidpcr 305 -jitter
    ./tscheck ./ts/audio.ts -pidpcr 305 -delta

    ./tscheck ./ts/video.ts -pidpcr 601 -dump
    ./tscheck ./ts/video.ts -piddts 601 -dump
    ./tscheck ./ts/video.ts -pidpcr 601 -pidpts 601 -diff
    ./tscheck ./ts/video.ts -pidpcr 601 -pidpts 301 -diff
    ./tscheck ./ts/video.ts -piddts 601 -pidpts 601 -diff

