CFLAGS=-g -O2 -Wall -Wextra
#CFLAGS=-g -O2 -std=c89 -ansi -Wall -Wextra -pedantic
LDFLAGS=


CIBLE=test_ordonnanceur
FLAG=-DTEST_INT

run: $(CIBLE)
	./$(CIBLE)

test_ordonnanceur: clean_ordonnanceur test_ordonnanceur.o ordonnanceur.o
	gcc  -o $@ $^ $(LDFLAGS)

clean_ordonnanceur:
	rm -f *.o test_ordonnanceur

%.o: %.c
	gcc -c $(CFLAGS) $< $(FLAG)

clean:
	rm -f *.o $(CIBLE)

rebuild: clean all

