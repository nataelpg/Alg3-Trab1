nomePrograma=myavl

all: $(nomePrograma)

$(nomePrograma): avl.o main.o
	gcc -o avl.o main.o $(parametrosCompilacao)

.o: .c
	gcc -c *.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)

purge: clean 
	-rm -f myavl