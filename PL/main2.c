#include <stdio.h>
#include <stdlib.h>

void cube_it(int *val){
  *val = *(val) * *(val) * *(val);
}

double polynome(int a, int b, int c){
double result = 12 - (2 + a) * b*b*b + 7 * b * c*c;
return result;
}

void incremente(int *p, int inc){
  *p = *(p) + inc;
}

void ascii_triangle(int n){
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      printf("*");
    }
    printf("\n");
  }
}

int max_of_three(int a, int b, int c) {
  if (a >= b && a >= c) {
    return a;
  } else if (b >= a && b >= c) {
  
    return b;
  } else if (c >= a && c >= b) {
    return c;
  }
}

int main(int argc, char* argv[]){
  
  return 0;
}