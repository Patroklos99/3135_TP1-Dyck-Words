motdedyck: motdedyck.c
	gcc -o motdedyck -Wall -Wextra -std=c11 motdedyck.c
test:   motdedyck 
	bats check.bats
html: README.md
	pandoc -s --self-contained --css=./misc/github-pandoc.css --metadata title=" " README.md -o README.html ; pandoc -s --self-contained --metadata title=" " --css=./misc/github-pandoc.css sujet.md -o sujet.html 
