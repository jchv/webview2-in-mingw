all: webviewdemo.exe

webviewdemo.exe: main.cpp event.cpp
	$(CXX) -g -L. -lWebView2Loader -o $@ $^
