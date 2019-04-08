// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

int main () {
  int myints[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  std::vector<int> v(myints,myints+5);
  std::make_heap (v.begin(),v.end());
  std::cout << "initial max heap   : " << v.front() << '\n';
  return 0;
}