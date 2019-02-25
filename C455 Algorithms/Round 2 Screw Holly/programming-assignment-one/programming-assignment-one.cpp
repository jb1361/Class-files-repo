#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono> 
using namespace std;
using namespace std::chrono;

int trivialAlgorithm(int size, int x[]);
void quickSort(int arr[], int left, int right);
void heapify(int arr[], int n, int i);
void printSortedHeap(int arr[], int n);
void heapSort(int arr[], int n);

int main() {
	const int size = 1000;
	int x[size];
	int y[size];
	
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++) {
		int val = (rand() % 1000);
		x[i] = val;
		y[i] = val;
	}
	auto tStart = high_resolution_clock::now();
	trivialAlgorithm(size, x);
	auto tStop = high_resolution_clock::now();
	auto trivialSortDuration = duration_cast<microseconds>(tStop - tStart);
	std::cout << "\n============================================\n";
	cout << "Heap sort before\n";
	for (int i = 0; i < size; i++) {
		cout << y[i] << ' ';
	}
	cout << "\n";
	auto hStart = high_resolution_clock::now();
	heapSort(y, size);
	auto hStop = high_resolution_clock::now();
	auto heapSortDuration = duration_cast<microseconds>(hStop - hStart);
	cout << "Heap sort after\n";
	for (int i = 0; i < size; i++) {
		cout << y[i] << ' ';
	}
	cout << "\n";
	cout << "Trivial Sort Running Time: " << trivialSortDuration.count() << " microseconds." << endl;
	cout << "Heap Sort Running Time: " << heapSortDuration.count() << " microseconds." << endl;
}

void heapify(int arr[], int n, int i)
{	
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] < arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] < arr[largest])
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
	}
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

int trivialAlgorithm(int size, int x[])
{
	cout << "Trivial sort before\n";
	for (int i = 0; i < size; i++) {
		cout << x[i] << ' ';
	}
	quickSort(x, 0, (size-1));
	cout << "\nTrivial sort after\n";
	for (int i = 0; i < size; i++) {
		cout << x[i] << ' ';
	}
	return 0;
}