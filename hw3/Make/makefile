CC = c++
CFLAGS = -g
TARGET = generate
OBJS = generate.o random.o graph.o dot.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

generate.o: generate.cpp graph.h dot.h
	$(CC) $(CFLAGS) -c generate.cpp

random.o: random.cpp random.h
	$(CC) $(CFLAGS) -c random.cpp

graph.o: graph.cpp graph.h random.h
	$(CC) $(CFLAGS) -c graph.cpp

dot.o: dot.cpp dot.h graph.h random.h
	$(CC) $(CFLAGS) -c dot.cpp

clean:
	rm *.o $(TARGET)
