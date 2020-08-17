/**
 * Key-indexed search uses key values as array indices rather than comparing
 * them, and depends on the keys being distinct integers falling in the same
 * range as the table indices.
 *
 * Hashing: reference items in a table directly by doing arithmetic operations
 * to transform keys into table addresses. Not a panacea
 *
 * First Step: compute a hash function that transforms the search key into a
 * table address. Ideally, different keys map to different addresses, but some-
 * times two or more keys hash to same address.
 * Second Step: Collision resolution
 *
 * Hash Functions:  transforms keys into table addresses
 * An ideal hash function is easy to compute and approximates a random function:
 * For each input, every output should be in some sense equally likely
 *
 * The hash function depends on the key type. Strictly speaking, we need a
 * different hash function for each kind of key that might be used.
 *
 * Example of Hashing function:
 * If the keys are greater than s and less than t for any fixed s and t, rescale
 * by subtracting s and dividing by t–s, which puts them between 0 and 1, then
 * multiply by M to get a table address.
 *
 * Efficient method for w-bit integers: Modular Hash Function
 * the table size M to be prime, and, for any integer key k, to compute the
 * remainder when dividing k by M, or h (k) = k mod M
 *
 * Converting text to modular hash
 * text   |     Decimal(21-bit number)        | table size 64
 * now    |  110111011011111110111 = 1816567  |     55
 *
 * Choice of table size M = 64 is unfortunate because x mod 64 is unaffected by
 * addition of multiples of 64 - hash function of any key is the value of key's
 * last 6 bits.
 *
 * Mersenne prime: 2^p - 1 (may be prime)
 *
 * alternative for integer keys is to combine the multiplicative and
 * modular methods: Multiply the key by a constant between 0 and 1, then reduce
 * it modulo M. That is, use the function h(k) = floor(kα) mod M
 *
 * alpha = Golden Ratio = 1.618033... (popular choice)
 *
 *
 **/
#include <iostream>
using namespace std;

// Hash Function for string keys
// one multiplication and one addition per character in the key
int hash(char *v, int M) {
  int h = 0, a = 127;
  for (; *v != 0; v++) {
    h = (a * h + *v) % M;
  }
  return h;
}

int main(void) {}