all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
test2: all
	bin/gauss dane/2A dane/2b
test3: all
	bin/gauss dane/3A dane/3b
test4: all
	bin/gauss dane/4A dane/4b
test5: all
	bin/gauss dane/5A dane/5b
