# PoC: WebView2 in MinGW
Although it is not documented, it is in fact possible, and even reasonable, to use WebView2 in MinGW. Once you have the necessary files from the NuGet package, it's simply a matter of using the `CINTERFACE` variants of the COM functions.

I don't know what the best practices are for implementing COM classes in C so I came up with my own approach for the event handlers. It should generally be good enough for this use case, although there is a lot of room for improvement. The point of this demo is more to show that 1. it is possible to do this 2. how one might do it from a technical sense. Hopefully, actual implementations will be better than my weeknight hack. :)

## Usage
Simply compile with a MinGW toolchain. Msys2 + MinGW64 should work fine. Run make:

```
make
```

and if it works, you will have webviewdemo.exe in your working directory.