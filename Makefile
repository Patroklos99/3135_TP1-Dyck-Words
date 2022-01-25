motdedyck: motdedyck.c
	gcc -o motdedyck -std=c11 motdedyck.c

test:   motdedyck 
	bats check.bats
