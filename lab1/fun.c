// fun.c
#include "fun.h"

size_t fact(size_t n) {
  if (n==0) return 1;
  if (n==1) return 1;
  return n*fact(n-1);
}
