#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>





int heapAlgorithm(int x[])
{
	std::vector<int> v(x, x + sizeof x / sizeof x[0]);
	std::make_heap(v.begin(), v.end());

	std::cout << "\nunsorted:\t";
	for (const auto &i : v) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
	return 0;
}
void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}
int trivialAlgorithm(int x[])
{
	for (int i = 0; i < 10; i++) {
		std::cout << x[i] << '\n';
	}
	quickSort(x, 0, 10);
	std::cout << sizeof x << "\n";
	std::cout << "Trivial sort\n";
	for (int i = 0; i < 10; i++) {
		std::cout << x[i] << ' ';
	}
	return 0;
}

int main() {
	const int size = 10;
	int x[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		x[i] = (rand() % 100);
	}	
	for (int i = 0; i < 10; i++) {
		std::cout << x[i] << '\n';
	}
	//heapAlgorithm(x);
	trivialAlgorithm(x);
}