// Sheng Xu
// assignment 2
// 2021/10/2
// assignment2.cpp

#include <iostream>
#include <cmath>

using namespace std;

int sumDigits(int n);

double root5(double n, double y);

int egyptDivision(int x, int y);
int doubleInt(int n);
void halveInt(int n, int& half);

double ramanujan(int x);
double helper(int x, double y);

int main() {
  // Task 1 tests
  cout << "Tests for Task 1: " << endl;
  cout << "sumDigits(123): " << sumDigits(123) << endl;
  cout << "sumDigits(456): " << sumDigits(456) << endl;
  cout << "sumDigits(98765): " << sumDigits(98765) << endl;
  cout << "sumDigits(0): " << sumDigits(0) << endl << endl;

  // Task 2 tests
  cout << "Tests for Task 2: " << endl;
  cout << "root5(5, 1): " << root5(5, 1) << endl;
  cout << "root5(6, 1): " << root5(6, 1) << endl;
  cout << "root5(35, 3): " << root5(35, 3) << endl;
  cout << "root5(3100, 5): " << root5(3100, 5) << endl << endl;

  // Task 3 tests
  cout << "Tests for Task 3: " << endl;
  cout << "egyptDivision(1960, 56): " << egyptDivision(1960, 56) << endl;
  cout << "egyptDivision(2345, 5): " << egyptDivision(2345, 5) << endl;
  cout << "egyptDivision(149, 7): " << egyptDivision(149, 7) << endl;
  cout << "egyptDivision(100, 0): " << egyptDivision(100, 0) << endl << endl;

  // Task 4 tests
  cout << "Tests for Task 4: " << endl;
  cout << "ramanujan(0): " << ramanujan(0) << endl;
  cout << "ramanujan(1): " << ramanujan(1) << endl;
  cout << "ramanujan(2): " << ramanujan(2) << endl;
  cout << "ramanujan(10): " << ramanujan(10) << endl << endl;

  cout << "All tests ended." << endl << endl;
  cout << "The value of the expression in Task 4 when carried out to infinite is 4." << endl;

  return 0;
}

int sumDigits(int n) {
  if (n  == 0) return 0;
  else return n % 10 + sumDigits(n / 10);
}

double root5(double n, double y) {
  // When such precision is reached, we can say y now is a good guess
  if (abs(pow(y, 5) - n) < 0.00001) return y;
  else {
    // A better guess for y
    y = ((4.0 * pow(y, 5)) + n) / (5.0 * pow(y, 4));
    return root5(n, y);
  }
}

int egyptDivision(int x, int y) {
  // Error handling
  if (y == 0) {
    cout << "Sorry, the devisor cannot be 0." << endl;
    return 0;
  }

  int time = 1;             // Column a
  int max = y;              // Column b
  int remainder = x;        // Column c
  int quotient = 0;         // Column d

  // Double max until max is larger than x,
  // when time is doubled the same number of times.
  while (max <= x) {
    max = doubleInt(max);
    time = doubleInt(time);
  }
  while (time > 1) {
    // Halve max and time until max is less than or equal to remainder
    while (max > remainder) {
      halveInt(max, max);
      halveInt(time, time);
    }
    quotient += time;
    remainder -= max;
  }
  return quotient;
}

int doubleInt(int n) {
  return n + n;
}

void halveInt(int n, int& half) {
  // Base case
  if (half + half <= n) return;
  // Recursion
  else halveInt(n, --half);
}

double ramanujan(int x) {
  return helper(x, 0);

  // The value when the expression is carried out to infinite (x is positive infinity) is 4.
}

double helper(int x, double y) {
  double part = (x + 1) * sqrt((x + 6) + y);
  // Base case
  if (x == 0) return part;
  // Recursion
  else return helper(--x, part);
}
