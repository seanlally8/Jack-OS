#include <stdlib.h>
#include <stdio.h>

int bit(int x, int i, int *array);
void init(int *array);
int multiply(int x, int y, int *array);
int abs(int x);
int divide(int x, int y);
int squrt(int x);

int main(void) {
  int *array = calloc(16, sizeof(int));
  init(array);
  int x, i, a, b, bitt;
  x = -30;

  for (i = 0; i < 16; i++) {
    bitt = bit(x, i, array);
    printf("%i", bitt);
  }
  printf("\n");

  int result = multiply(-6, -30, array);
  a = -18000; b = 6;
  int quotient = divide(a, b);
  int square_root = squrt(32767);
  printf("%i\n", result);
  printf("%i\n", quotient);
  printf("%i\n", square_root);


  free(array);
}

int bit(int x, int i, int *array) {
  int bit_tracker, x_tracker, m;
  bit_tracker = 0;
  x_tracker = abs(x);


  m = 15;

  while (!(m < i)) {
    if (!(array[m] > x_tracker)) {
      bit_tracker = 1;
      x_tracker = x_tracker - array[m];
    }
    else {
      bit_tracker = 0;
    }
    m = m - 1;
  }
    return bit_tracker;
}

void init(int *array) {
  int value = 1; 
  for (int i = 0; i < 16; i++) {
    array[i] = value;
    printf("%i ", value);
    value = value + value;
  }
}

int multiply(int x, int y, int *array) {
  int current_bit, shiftedx;
  int sum, i;
  i = 0;
  sum = 0;
  shiftedx = abs(x);

  while (i < 16) {
    current_bit = bit(y, i, array);
    if (current_bit == 0) {
      shiftedx = shiftedx + shiftedx;
    }
    else {
      sum = sum + shiftedx;
      shiftedx = shiftedx + shiftedx;
    }
    i = i + 1;
  }
  if ((x < 0 && y > 0) || (x > 0 && y < 0)){
    return -sum;
  }
  return sum;
}

int abs(int x) {
  if (x < 0) {
    return -x;
  }
  else {
    return x;
  }
}

int divide(int x, int y) {
  int ax = abs(x);
  int ay = abs(y);
  if (ay > ax) {
    return 0;
  }
  int q = divide(ax, ay + ay);
  if (((ax - 2 * ay * q) < ay) && ((x < 0 && y > 0) || (x > 0 && y < 0))) {
    return -(q + q);
  }
  if ((ax - 2 * ay * q) < ay) {
    return q + q;
  }
  if (((ax - 2 * ay * q) > ay) && ((x < 0 && y > 0) || (x > 0 && y < 0))) {
    return -(q + q + 1);
  }
  else {
    return q + q + 1;
  }
}

int squrt(int x) {
  int exit, upper, lower, result, squr;

  exit = 1;
  upper = x;
  if (x > 182) {
    upper = 182;
  }
  lower = 0;
  result = 0;
  squr = 0;

  while (exit) {
    result = (upper + lower) / 2;
    squr = result * result;
    if (!(squr > x) && !((upper - result) > 1)) {
      exit = 0;
    }
    if (squr > x) {
      upper = result;
    }
    if ((squr < x) & ((upper - result) > 1)) {
      lower = result;
    }
  }
  return result;

}
