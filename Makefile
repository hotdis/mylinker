build : 
	gcc main.c helper.c elf.c -o main

test : build 
	@./test/test.sh

clean : 
	rm -rf out
	rm main 
