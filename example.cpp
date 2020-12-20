#include "debug.h" // https://github.com/kiprasmel/debug.h

int main() {
	int a = 1337;
	double b = 6.9;
	const char* c = "c++";

	debug() << imie(a) imie(b) imie(c);

	// stderr => [a: 1337]  [b: 6.9]  [c: c++]
}

