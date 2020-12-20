# debug.h

small yet handy debugging utility for competitive C++


## install

```sh
curl https://raw.githubusercontent.com/kiprasmel/debug.h/master/debug.h -LO
```

```sh
wget https://raw.githubusercontent.com/kiprasmel/debug.h/master/debug.h
```


### make debug.h global

(optionally) move it to the global includes directory:

```sh
sudo mv debug.h /usr/local/include/
```

## usage

see [./example.cpp](./example.cpp)

```c++
#include "debug.h" // https://github.com/kiprasmel/debug.h

int main() {
	int a = 1337;
	double b = 6.9;
	const char* c = "c++";

	debug() << imie(a) imie(b) imie(c);

 	// stderr => [a: 1337]  [b: 6.9]  [c: c++]
}

```


## conditional usage

see [./example.conditional.cpp](./example.conditional.cpp)

you can add compiler macros to conditionally load the header file
and otherwise provide the fallback:

```c++
#if (false || defined(DEBUG)) && !defined(EVAL)
    #include "debug.h" // https://github.com/kiprasmel/debug.h
#else
    struct debug {
        template <class c> debug& operator <<(const c&) { return * this; }
    };
    #define imie(...) ""
#endif

```

and then either

a) control it with `true`/`false` in the macro, or

b) define `DEBUG`/`EVAL` when compiling, like so:

```
g++ -D DEBUG a.cpp
```

```
g++ -D EVAL a.cpp
```


## license

[MIT](./LICENSE) -- use freely; credit appreciated

The initial debugging template was heavily inspired by [errichto](https://github.com/errichto)

