#include <iostream>
#include <vector>

int main( int argc, char *argv[] ){
  std::vector<int> x(10);
  // Creates vector<int> (dynamic array) with 10 zeroes.
  // size_t is an integer >= 0 that is guaranteed to be big
  // enough for every index. Now, and always in the future.
  for( size_t i = 0; i < x. size( ); ++ i ) x[i] = i;
  std::vector<int> y = x;
  y[5] = 12;
  for( size_t i = 0; i < x. size( ); ++ i ) std::cout << i << " : " << x[i] << " " << y[i] << "\n";
  return 0;
}
