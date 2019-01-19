
CXXFLAGS +=-I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin/ -fPIC -shared
cc = g++

ODIR = ../out/lib

objects = libagent.so
exe = libagent

src = Main.cpp DebugAgent.cpp

$(exe): $(src)
	mkdir -p $(ODIR)
	$(cc) $(src) $(CXXFLAGS) -o $(ODIR)/$(objects)


.PHONY:clean

clean:
	rm $(objects)