// Sheng Xu
// lab 1 and lab 2
// 2021/9/24 2021/10/1
// bico.cpp

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int old_bico(int x, int y);
int new_bico(int x, int y);

int main(){
  int m, n;
  // Input from users
 m:
  cout << "Please input the degree of the binomial(a non-negative integer): ";
  cin >> m;
  if (m < 0) goto m;
 n:
  cout << "Please input the index of the coefficient(a non-negative integer which is not larger than the degree): ";
  cin >> n;
  if (n < 0 || n > m) goto n;

  auto start = high_resolution_clock::now();
  cout << "The result(nested for loop) is: " << old_bico(m, n) << endl;
  auto stop = high_resolution_clock::now();
  auto duration_1 = duration_cast<nanoseconds>(stop - start);

  start = high_resolution_clock::now();
  cout << "The result(recursion) is: " << new_bico(m, n) << endl;
  stop = high_resolution_clock::now();
  auto duration_2 = duration_cast<nanoseconds>(stop - start);

  cout << "The execution time for nested for loop method is: " << duration_1.count() << endl;
  cout << "The execution time for recursion method is: " << duration_2.count() << endl;
}

// Nested for loop
int old_bico(int x, int y) {
  int triangle[x + 1][x + 1];
  for (int i = 0; i < x + 1; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) triangle[i][j] = 1 ;
      else triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
    }
  }
  return triangle[x][y];
}

// Recursion
int new_bico(int x, int y) {
  if (y == 0 || y == x) return 1;
  return new_bico(x - 1, y - 1) + new_bico(x - 1, y);
}

