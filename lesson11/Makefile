APPNAME= dirls

SRCS+= main.c
SRCS+= dirops.c


all:
	gcc $(SRCS) -o $(APPNAME)

clean:
	rm -f $(APPNAME)

install:
	cp $(APPNAME) /usr/bin

uninstall:
	rm -f /usr/bin/$(APPNAME)