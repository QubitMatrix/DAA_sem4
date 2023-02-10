a.out:permutation_s.o permutation_c.o
	gcc permutation_s.o permutation_c.o
permutation_s.o: permutation_s.c
	gcc -c permutation_s.c
permutation_c.o: permutation_c.c permutation_h.h
	gcc -c permutation_c.c
