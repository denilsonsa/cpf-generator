.PHONY: all clean

all: cpf-generator

clean:
	rm -f cpf-generator

cpf-generator: cpf-generator.c
	gcc $< -o $@ -O3 -Wall -pedantic -march=native
