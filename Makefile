all: webviewdemo.exe

flags += 
ifeq ($(static),true)
	flags += -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
endif

webviewdemo.exe: main.cpp event.cpp
	$(CXX) -g $^ -L. -lWebView2Loader $(flags) -mwindows -o $@
