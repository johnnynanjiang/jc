## To Do

Suitable good first issue
- https://github.com/bitcoin/bitcoin/issues/16306

C++ Concurrency in Action
https://legacy.gitbook.com/book/chenxiaowei/cpp_concurrency_in_action/details

## Understanding Bitcoin source code

* developer documents *****
https://bitcoin.org/en/developer-documentation

## Source Code

* Understand the code
- [PRs - P2P related] (https://github.com/bitcoin/bitcoin/pulls?page=21&q=is%3Apr+is%3Aclosed+p2p&utf8=%E2%9C%93)
- The entry point of bitcoind is here: https://github.com/bitcoin/bitcoin/blob/master/src/bitcoind.cpp#L188
- https://bitcointalk.org/index.php?topic=41718.0 ****
- https://github.com/CodeReaderMe/awesome-code-reading/issues/2
- https://dev.visucore.com/bitcoin/doxygen/inherits.html
- https://en.bitcoin.it/wiki/Bitcoin_Core_0.11_(ch_4):_P2P_Network
- https://blog.csdn.net/pure_lady/article/details/77623301 比特币源码分析 ****
- ***** [Who controls Bitcoin Core?](https://medium.com/@lopp/who-controls-bitcoin-core-c55c0af91b8a)

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

* Set up Bitcoin with Eclipse on MacOS
http://www.gubatron.com/blog/2014/02/09/setting-up-eclipse-as-your-ide-for-bitcoin-c-development-on-macosx/

* Launch Eclipse with sudo to avoid permission issues
sudo /Applications/Eclipse.app/Contents/MacOS/eclipse

* Configure GDB for Eclipse on Mac OS Mojave
1. https://stackoverflow.com/questions/52699661/macos-mojave-how-to-achieve-codesign-to-enable-debugging-gdb
2. https://stackoverflow.com/questions/37982876/mac-c-mars-eclipse-gdb-debug-hangs-at-launching-test-96

* Eclipse stuck at `launching: configuring GDB (97%)` when running bitcoind in debug mode
---
Sign gdb
Clean up Eclipse project and re-import
Launch Eclipse with sudo

## Community

* Bitcoin Core Slack / M*P*clsno
https://app.slack.com/client/T0J422BCZ/C0J42JBK9
