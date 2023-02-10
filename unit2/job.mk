a.out:permutation_s.o job_assignment.o
	gcc permutation_s.o job_assignment.o
permutation_s.o: permutation_s.c
	gcc -c permutation_s.c
job_assignment.o: job_assignment.c permutation_h.h
	gcc -c job_assignment.c
