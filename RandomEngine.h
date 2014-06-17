#ifndef __RANDOMENGINE_H__
#define __RANDOMENGINE_H__

extern "C" {
#include <uuid/uuid.h>
}
#include <cstdlib>
#include <iostream>

/**
 * @class  RandomEngine
 * @author Nathan Grau (ngrau@augie.edu)
 * @date   May 2014
 * 
 * @brief  Singleton class for high periodicity Mersenne Twistor. 
 *         Stolen mostly from ROOT TRandom3. See documentation therein.
 *
 */

class RandomEngine {

 public:

  /**
   * @brief Return the singleton
   */
  static RandomEngine* instance() {
    if(__instance == NULL) {
      __instance = new RandomEngine();
    }
    return __instance;
  }

  /**
   * @brief return a random number between [0,1)
   */
  double getRandom() {
    unsigned int y;

    static const int  kM = 397;
    static const int  kN = 624;
    static const unsigned int kTemperingMaskB =  0x9d2c5680;
    static const unsigned int kTemperingMaskC =  0xefc60000;
    static const unsigned int kUpperMask =       0x80000000;
    static const unsigned int kLowerMask =       0x7fffffff;
    static const unsigned int kMatrixA =         0x9908b0df;

    if (_count >= kN) {
      int i;

      for (i=0; i < kN-kM; i++) {
	y = (_Mt[i] & kUpperMask) | (_Mt[i+1] & kLowerMask);
	_Mt[i] = _Mt[i+kM] ^ (y >> 1) ^ ((y & 0x1) ? kMatrixA : 0x0);
      }

      for (   ; i < kN-1    ; i++) {
	y = (_Mt[i] & kUpperMask) | (_Mt[i+1] & kLowerMask);
	_Mt[i] = _Mt[i+kM-kN] ^ (y >> 1) ^ ((y & 0x1) ? kMatrixA : 0x0);
      }

      y = (_Mt[kN-1] & kUpperMask) | (_Mt[0] & kLowerMask);
      _Mt[kN-1] = _Mt[kM-1] ^ (y >> 1) ^ ((y & 0x1) ? kMatrixA : 0x0);
      _count = 0;
    }

    y = _Mt[_count++];
    y ^=  (y >> 11);
    y ^= ((y << 7 ) & kTemperingMaskB );
    y ^= ((y << 15) & kTemperingMaskC );
    y ^=  (y >> 18);

    // 2.3283064365386963e-10 == 1./(max<UINt_t>+1)  -> then returned value cannot be = 1.0  
    if (y) return ( (double) y * 2.3283064365386963e-10); // * Power(2,-32)
    return getRandom();
  }

 private:

  /**
   * @brief Constructor
   * Seed the random number generator with a uuid. Uses uuid/uuid.h
   */
  RandomEngine() {
    uuid_t uuid;
    uuid_generate_random(uuid);
    char s[16];
    uuid_unparse(uuid,s);
    _seed = int(uuid[3])*16777216 + int(uuid[2])*65536 + int(uuid[1])*256 + int(uuid[0]);

    _count = 624;
    _Mt[0] = _seed;
    // use multipliers from  Knuth's "Art of Computer Programming" Vol. 2, 3rd Ed. p.106
    for(int i=1; i<624; i++) {
      _Mt[i] = (1812433253 * ( _Mt[i-1]  ^ ( _Mt[i-1] >> 30)) + i );
    }
  }

  /** 
   * @brief The generator seed 
   */
  int _seed;

  /**
   * @brief The 624-integer state of the engine
   */
  int _Mt[624];

  /**
   * @brief A counter for the internal state
   */
  int _count;

  /** 
   * @brief The singleton 
   */
  static RandomEngine *__instance;

};

#endif /* __RANDOMENGINE_H__ */


////////
/// in main.cc
/// RandomEngine *dice = RandomEngine::instance();
/// dice->getRandom();
////////
