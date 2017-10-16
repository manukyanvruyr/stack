SOURCES = type_checker.cpp
OBJDIR = ../../obj
OBJECTS = $(SOURCES:.cpp=.o)
MOVED_OBJECTS = $(addprefix $(OBJDIR)/,$(OBJECTS))
INCLUDEPATH = ..
CPPFLAGS = -std=c++14 -I $(INCLUDEPATH)

all: $(OBJECTS)
	mv *.o $(OBJDIR)

.cpp.o:
	g++ $(CPPFLAGS) $< -c 

clean:
	rm $(MOVED_OBJECTS)
