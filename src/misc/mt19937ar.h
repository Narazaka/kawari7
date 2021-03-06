/* 
   A C-program for MT19937, with initialization improved 2002/1/26.
   Coded by Takuji Nishimura and Makoto Matsumoto.

   Before using, initialize the state by using init_genrand(seed)  
   or init_by_array(init_key, key_length).

   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.                          

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote 
        products derived from this software without specific prior written 
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Any feedback is very welcome.
   http://www.math.keio.ac.jp/matumoto/emt.html
   email: matumoto@math.keio.ac.jp
*/
#ifndef MT19937AR_H
#define MT19937AR_H

// Converted to C++ by KAWARI Developer Team

#include "config.h" // KAWARI configuration

class TMTRandomGenerator {
private:
	enum{N=624};
	unsigned long mt[N];
	int mti;
public:
	// initializes mt[N] with a seed
	void init_genrand(unsigned long s);

	// generates a random number on [0,0xffffffff]-interval
	unsigned long genrand_int32(void);

	// initialize by an array with array-length
	// init_key is the array for initializing keys
	// key_length is its length
	void init_by_array(unsigned long init_key[], unsigned long key_length);

	// generates a random number on [0,0x7fffffff]-interval
	unsigned long genrand_int31(void){
		return (unsigned long)(genrand_int32()>>1);
	}

	// generates a random number on [0,1]-real-interval
	double genrand_real1(void){
		return genrand_int32()*(1.0/4294967295.0); 
		/* divided by 2^32-1 */ 
	}

	// generates a random number on [0,1)-real-interval
	double genrand_real2(void){
		return genrand_int32()*(1.0/4294967296.0); 
		/* divided by 2^32 */
	}

	// generates a random number on (0,1)-real-interval
	double genrand_real3(void){
		return (((double)genrand_int32()) + 0.5)*(1.0/4294967296.0); 
		/* divided by 2^32 */
	}

	/* generates a random number on [0,1) with 53-bit resolution*/
	double genrand_res53(void){ 
		unsigned long a=genrand_int32()>>5, b=genrand_int32()>>6; 
		return(a*67108864.0+b)*(1.0/9007199254740992.0); 
	} 

	// Constructor
	TMTRandomGenerator(unsigned long seed=4357): mti(N+1) {
		init_genrand(seed);
	}
};

#endif //MT19937AR_H
