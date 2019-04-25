# Fast CPF generator

This is a small and simple and fast generator of all possible CPF numbers. It is written in just 50 lines of C code, and the compiled binary has about 9KB of size.

It takes less than a minute to generate all possible CPF numbers.

    $ time ./cpf-generator > /dev/null
    
    real    0m36.693s
    user    0m35.932s
    sys     0m0.704s

That means 1 giga-numbers (1000000000 or 10^9), for a total of 12GB (each number has 11 digits, plus the newline).

    $ ./cpf-generator | wc
    1000000000 1000000000 12000000000

## Requirements

* C compiler. Tested with `gcc`. Should work with any C compiler. If you use another compiler, please tweak the `Makefile`.

## How to compile

Just run `make`. Edit the `Makefile` if you want to tweak the compiler parameters.

If you are on Windows, you'll want to add the `.exe` extension to the compiled binary.

## Why?

I wanted one, I tried searching online, but couldn't find anything. Then I decided to write my own. That's also an opportunity to write some C code.

## But what for?

The output of this tool can be used as a wordlist input for any brute-force password cracking tool. This, then, can be used to benchmark if your encryption or if your passwords are strong enough.

## See also

* <https://pt.wikipedia.org/wiki/Cadastro_de_pessoas_f%C3%ADsicas>
* <https://en.wikipedia.org/wiki/Cadastro_de_Pessoas_F%C3%ADsicas>
