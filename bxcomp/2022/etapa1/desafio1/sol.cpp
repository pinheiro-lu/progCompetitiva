// #include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dbg(args...) printf(args);
#define dbgi(args) dbg(#args) dbg(" = %ld\n", args)
#define dbgf(args) dbg(#args) dbg(" = %lf\n", args)
#define fir(i, a, b) for (int i = (a); i < (b); i++)
#define f0r(i, a) fir(i, 0, a)

typedef long long ll;

typedef struct aux {
  char nome[20];
  int p;
  int f;
  int i;
} Jog;

void solve(void);

int min(int a, int b) {
  if (a < b)
    return a;
  return b;
}

int max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int main() {

  int t = 1;

  // scanf("%d", &t);

  while (t--)
    solve();

  return 0;
}

int penal(const void *r, const void *l) {
  if (((Jog *)l)->p > ((Jog *)r)->p)
    return 1;
  if (((Jog *)l)->p < ((Jog *)r)->p)
    return -1;
  return ((Jog *)l)->i - ((Jog *)r)->i;
}

int frieza(const void *r, const void *l) {
  if (((Jog *)l)->f > ((Jog *)r)->f)
    return 1;
  if (((Jog *)l)->f < ((Jog *)r)->f)
    return -1;
  return ((Jog *)r)->i - ((Jog *)l)->i;
}

void solve(void) {
  int n, j = 0;
  scanf("%d", &n);
  Jog jogs[n];
  f0r(i, n) {
    scanf("%s %d %d", jogs[i].nome, &(jogs[i].p), &(jogs[i].f));
    jogs[i].i = i;
  }
  qsort((void *)jogs, n, sizeof(Jog), penal);
  for (int i = 4; i >= 0; i--)
    printf("%s\n", jogs[i].nome);
  Jog jogs2[n - 5];
  fir(i, 5, n) {
    jogs2[j] = jogs[i];
    j++;
  }
  qsort((void *)jogs2, n - 5, sizeof(Jog), frieza);
  if (n <= 11)
    f0r(i, n - 5) printf("%s\n", jogs2[i].nome);
  else
    f0r(i, 6) printf("%s\n", jogs2[i].nome);
}
