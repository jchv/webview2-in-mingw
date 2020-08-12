OUTDIR := Out/mingw-w64
OUT := $(OUTDIR)/webview2-mingw.exe

MKDIRP := mkdir -p
COPY := cp
RMF := rm -f

CFLAGS += -I./WebView/include
ifeq ($(debug),true)
	CFLAGS += -g
else
	CFLAGS += -O3
endif

LDFLAGS += -L./WebView/x64 -lWebView2Loader -mwindows
ifeq ($(static),true)
	LDFLAGS += -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
endif

all: $(OUT)

$(OUT): Src/main.cpp Src/event.cpp
	$(MKDIRP) $(OUTDIR)
	$(CXX) $(CFLAGS) $^ $(LDFLAGS) -o $@
	$(COPY) ./WebView/x64/WebView2Loader.dll $(OUTDIR)/WebView2Loader.dll

clean:
	$(RMF) $(OUT) $(OUTDIR)/WebView2Loader.dll