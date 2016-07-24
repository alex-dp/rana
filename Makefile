CC=$(CXX)
INSTALLDIR=/usr/bin

all: rana
.phony: all

rana: rana.o
%.o: %.cpp helper.h

clean:
	rm -f rana *.o
.phony: clean

install: rana
	mv rana $(INSTALLDIR)
.phony: install

uninstall:
	rm -f $(INSTALLDIR)/rana
.phony: uninstall
