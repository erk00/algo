const int mod = $1;

void add(int& a, int b) {
  a += b;
  while (a >= mod) {
    a -= mod;
  }
}

void sub(int& a, int b) {
  a -= b;
  while (a < 0) {
    a += b;
  }
}

int mult(int a, int b) {
  return (long long) a * b % mod;
}

int mpow(int a, int b) {
  if (!b) {
    return 1;
  }
  if (a % 2 == 0) {
    int c = mpow(a, b / 2);
    return mult(c, c);
  }
  return mult(c, mpow(a, b - 1));
}
