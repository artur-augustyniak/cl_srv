CC = g++
LDFLAGS=-lws2_32
CFLAGS=-static -m32 --std=c++11 -Wall -O0 -g 
SRCDIR=src
APPNAME = console
src=$(addprefix $(SRCDIR)/, *.cpp)

$(APPNAME): $(src)
	$(CC) $(CFLAGS) $(src) -o $(APPNAME) $(LDFLAGS)


.PHONY: clean
clean:
	rm -f $(APPNAME)*