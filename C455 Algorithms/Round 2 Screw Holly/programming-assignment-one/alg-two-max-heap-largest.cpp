#include <algorithm>
#include <vector>
#include <iostream>
 
int main()
{

 int array[1000];
 
 srand((unsigned)time(0)); 
     
    for(int i=0; i<size; i++){ 
        array[i] = (rand()%100)+1;              
	} 
    std::vector<int> v = {3, 1, 4, 1, 5, 9}; 
	cout << v;
    std::make_heap(v.begin(), v.end());
 
    std::cout << "heap:\t";
    for (const auto &i : v) {
        std::cout << i << ' ';
    }   
 
    std::sort_heap(v.begin(), v.end());
 
    std::cout << "\nsorted:\t";
    for (const auto &i : v) {                                                   
        std::cout << i << ' ';
    }   
    std::cout << '\n';
}