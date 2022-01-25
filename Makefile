motdedyck: motdedyck.c
	gcc -o motdedyck -std=c11 motdedyck.c

test: motdedyck.c 
	bats check.bats
