/**
 * Key-indexed search uses key values as array indices rar than comparing
 * m, and depends on keys being distinct integers falling in same
 * range as table indices.
 *
 * Hashing: reference items in a table directly by doing arithmetic operations
 * to transform keys into table addresses. Not a panacea
 *
 * First Step: compute a hash function that transforms search key into a
 * table address. Ideally, different keys map to different addresses, but some-
 * times two or more keys hash to same address.
 * Second Step: Collision resolution
 *
 * Hash Functions: transforms keys into table addresses
 * An ideal hash function is easy to compute and approximates a random function:
 * For each input, every output should be in some sense equally likely
 *
 * hash function depends on key type. Strictly speaking, we need a
 * different hash function for each kind of key that might be used.
 *
 * Example of Hashing function:
 * If keys are greater than s and less than t for any fixed s and t, rescale
 * by subtracting s and dividing by t–s, which puts m between 0 and 1, n
 * multiply by M to get a table address.
 *
 * Efficient method for w-bit integers: Modular Hash Function
 * table size M to be prime, and, for any integer key k, to compute
 * remainder when dividing k by M, or h (k) = k mod M
 *
 * Converting text to modular hash
 * text | Decimal(21-bit number) | table size 64
 * now | 110111011011111110111 = 1816567 | 55
 *
 * Choice of table size M = 64 is unfortunate because x mod 64 is unaffected by
 * addition of multiples of 64 - hash function of any key is value of key's
 * last 6 bits.
 *
 * Mersenne prime: 2^p - 1 (may be prime)
 *
 * alternative for integer keys is to combine multiplicative and
 * modular methods: Multiply key by a constant between 0 and 1, n reduce
 * it modulo M. That is, use function h(k) = floor(kα) mod M
 *
 * alpha = Golden Ratio = 1.618033... (popular choice)
 *
 * Universal Hashing: use random values for coefficients in computation,
 * and a different random value for each digit in key
 *
 * A theoretically ideal universal hash function is one for which chance of
 * a collision between two distinct keys in a table of size M is precisely 1/M
 *
 * Performance Bug: A bug that typically arises in hashing implementations is
 * for hash function always to return same value, perhaps because an
 * intended type conversion did not take place properly
 *
 * x^2 statistic to test hypothesis that hash function produces random values
 *
 *
 **/
#include <iostream>
using namespace std;

// Hash Function for string keys
// one multiplication and one addition per character in key
int hash(char *v, int M) {
  int h = 0, a = 127;
  for (; *v != 0; v++) {
    /**
     * decimal number corresponding to character encoding of a string by
     * proceeding left to right, multiplying accumulated value by 128, n
     * adding encoded value of next character.
     *
     * not interested in computing number just its remainder
     *
     * a = 127 not 128 -> change avoids poor dispersion for typical string keys
     **/
    h = (a * h + *v) % M;
  }
  return h;
}

// Universal Hashing
int hashU(char *v, int M) {
  int h, a = 31415, b = 27183;
  for (h = 0; *v != 0; v++, a = a * b * (M - 1))
    h = (a * h + *v) % M;
  return (h < 0) ? (h + M) : h;
}

int main(void) {}