# Переменная CC указывает компилятор, используемый для сборки
CC=gcc
# В переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c

run: all
	./dfs_test $(size) $(input) $(output1) $(output2)

all: dfs_test clean

show_graph: run
	xdg-open $(output1).png
	xdg-open $(output2).png
	
clean:
	rm -rf *.o

dfs_test: graph.o stack.o dfs.o dfs_unit_test.o 
	$(CC) dfs.o dfs_unit_test.o graph.o stack.o -o dfs_test

dfs.o: dfs.c
	$(CC) $(CFLAGS) dfs.c

dfs_unit_test.o: dfs_unit_test.c
	$(CC) $(CFLAGS) dfs_unit_test.c

graph.o: ../../data\ structures/graph_lib/graph.c
	$(CC) $(CFLAGS) ../../data\ structures/graph_lib/graph.c

stack.o: ../../data\ structures/stack/stack.c
	$(CC) $(CFLAGS) ../../data\ structures/stack/stack.c
