#if (false || defined(DEBUG)) && !defined(EVAL)
	#include "debug.h" // https://github.com/kiprasmel/debug.h
#else
	struct debug {
		template <class c> debug& operator <<(const c&) { return * this; }
	};
	#define imie(...) ""
#endif

int main() {
	int a = 1337;
	double b = 6.9;
	const char* c = "c++";

	debug() << imie(a) imie(b) imie(c);

	// stderr => [a: 1337]  [b: 6.9]  [c: c++]
	// or
	// stderr => "" (no output)
}

