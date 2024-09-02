run: compile
	./a.out

compile: hello.c
	clang hello.c

clean:
	rm -rf *.out*
