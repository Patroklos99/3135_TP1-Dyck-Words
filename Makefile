motdedyck: motdedyck.c
	gcc -o motdedyck -Wall -Wextra -std=c11 motdedyck.c
test:   motdedyck 
	bats check.bats
