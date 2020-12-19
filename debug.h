#pragma once

/**    //================\\   //================   //================\\   //                //   //==================
      //                //   //                   //                //   //                //   //                  
     //    debug.h     //   //================   //================//   //                //   //        ========\\
    //                //   //                   //                //   //                //   //                //
   //================//   \\================   //================//   \\================//   //================//



   v1                           debug.h
   ------------------------------------
   https://github.com/kiprasmel/debug.h



   Usage:

   #include "debug.h"
   
   int main() {
       int a = 1337;
       double b = 6.9;
       const char* c = "c++";
       
       debug() << imie(a) imie(b) imie(c);
       
       // stderr => [a: 1337]  [b: 6.9]  [c: c++]
   }


                                              **/



#include <iostream>

namespace debug_internal {
	template<typename c> struct rge { c b, e; };
	template<typename c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
	template<typename c> auto dud(c* x) -> decltype(std::cerr << *x, 0);
	template<typename c> char dud(...);
} // namespace debug_internal

struct debug {
	~debug() { std::cerr << std::endl; }
	template<typename c> typename std::enable_if<sizeof debug_internal::dud<c>(0) != 1, debug&>::type operator<<(c i) {
		std::cerr << std::boolalpha << i; return * this;
	}

	template<typename c> typename std::enable_if<sizeof debug_internal::dud<c>(0) == 1, debug&>::type operator<<(c i) {
		return * this << debug_internal::range(begin(i), end(i));
	}

	template<typename c, typename b> debug& operator <<(std::pair<b, c> d) {
		return * this << "(" << d.first << ", " << d.second << ")";
	}

	template<typename c> debug & operator <<(debug_internal::rge<c> d) {
  		*this << "[";
  		for (auto it = d.b; it != d.e; ++it) {
			*this << ", " + 2 * (it == d.b) << *it;
		}
  		return * this << "]";
	}
};
	
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

