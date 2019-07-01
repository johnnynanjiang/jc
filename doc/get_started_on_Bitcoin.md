## To Do
* Add a test to jc
* Add a test for ECDSA

## Source Code

* Understand the code
- The entry point of bitcoind is here: https://github.com/bitcoin/bitcoin/blob/master/src/bitcoind.cpp#L188
- https://bitcointalk.org/index.php?topic=41718.0 ****
- https://github.com/CodeReaderMe/awesome-code-reading/issues/2
- https://dev.visucore.com/bitcoin/doxygen/inherits.html
- https://en.bitcoin.it/wiki/Bitcoin_Core_0.11_(ch_4):_P2P_Network

* Make
http://nuclear.mutantstargoat.com/articles/make/

```
all_src_files = $(wildcard *.cpp)
all_obj_files = $(all_src_files:.cpp=.o)

CC = clang++
```

* Run tests
`make check`

* Run tests individually
https://github.com/bitcoin/bitcoin/blob/master/src/test/README.md
`./test_bitcoin --log_level=all --run_test=getarg_tests`

src/test/test_bitcoin
`./test_bitcoin --log_level=all --run_test=addrman_tests`

* Set up on MacOS
https://github.com/bitcoin/bitcoin/blob/master/doc/build-osx.md

* Configure GDB for Eclipse on Mac OS Mojave
https://stackoverflow.com/questions/52699661/macos-mojave-how-to-achieve-codesign-to-enable-debugging-gdb