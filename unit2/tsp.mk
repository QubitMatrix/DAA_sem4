a.out:permutation_s.o tsp.o
	gcc permutation_s.o tsp.o
permutation_s.o: permutation_s.c
	gcc -c permutation_s.c
tsp.o: tsp.c permutation_h.h
	gcc -c tsp.c
