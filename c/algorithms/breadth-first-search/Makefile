# Переменная CC указывает компилятор, используемый для сборки
CC=gcc
# В переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c

run: all
	./bfs_test $(size) $(input) $(output1) $(output2)

all: bfs_test clean

show_graph: run
	xdg-open $(output1)".png"
	xdg-open $(output2)".png"

clean:
	rm -rf *.o

bfs_test: queue.o graph.o bfs.o bfs_unit_test.o 
	$(CC) bfs.o bfs_unit_test.o queue.o graph.o -o bfs_test

bfs.o: bfs.c
	$(CC) $(CFLAGS) bfs.c

bfs_unit_test.o: bfs_unit_test.c
	$(CC) $(CFLAGS) bfs_unit_test.c

queue.o: ../../data\ structures/queue/queue.c
	$(CC) $(CFLAGS) ../../data\ structures/queue/queue.c

graph.o: ../../data\ structures/graph_lib/graph.c
	$(CC) $(CFLAGS) ../../data\ structures/graph_lib/graph.c
