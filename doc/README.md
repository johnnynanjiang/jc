## Bitcoin

* Make
http://nuclear.mutantstargoat.com/articles/make/

```
all_src_files = $(wildcard *.cpp)
all_obj_files = $(all_src_files:.cpp=.o)

CC = clang++
```

* Run tests
`make check`

* Set up on MacOS
https://github.com/bitcoin/bitcoin/blob/master/doc/build-osx.md