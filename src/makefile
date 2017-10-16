SUBDIRS = tests
SOURCES = main.cpp
EXECUTABLE_DIR = ../bin
EXECUTABLE = run_tests
OBJECTS = $(SOURCES:.cpp=.o)
OBJDIR = ../obj
INCLUDEPATH = .
CPPFLAGS = -std=c++14 -I $(INCLUDEPATH)
MOVED_OBJECTS = $(addprefix $(OBJDIR)/,$(OBJECTS))

all: $(OBJECTS)
	mkdir -p $(OBJDIR)
	$(foreach subdir, $(SUBDIRS), cd $(subdir); make; cd ..;)
	mv *.o $(OBJDIR)
	mkdir -p $(EXECUTABLE_DIR)
	g++ $(CPPFLAGS) $(OBJDIR)/* -o $(EXECUTABLE_DIR)/$(EXECUTABLE)

.cpp.o:
	g++ $(CPPFLAGS) $< -c

clean:
	rm $(EXECUTABLE_DIR)/$(EXECUTABLE) $(MOVED_OBJECTS)
	$(foreach subdir, $(SUBDIRS), cd $(subdir); make clean; cd ..)
