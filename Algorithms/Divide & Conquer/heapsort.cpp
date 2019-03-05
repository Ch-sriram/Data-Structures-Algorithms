#include <iostream>
#include <vector>
using namespace std;

// Function Prototypes
void swap(int*, int*);
void min_heapify(vector<int>&, int);
void max_heapify(vector<int>&, int);
void heapify(vector<int>&, int);
void build_heap(vector<int>&);
void heapsort(vector<int>&);

// Sorting Option & heap size is a Global Variable
bool option;
int heap_size;

// Function's Time Complexity: Constant
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
	return;
}

// Function's Time Complexity: Logarithmic
void min_heapify(vector<int>& heap, int i) {
	// cout << "min_heapify(); ";
	int l = 2*i;		// Index of the Left Child of Node-i
	int r = 2*i+1;		// Index of the Right Child of Node-i
	int smallest;
	if(l < heap_size && heap[i] > heap[l])
		smallest = l;
	else smallest = i;
	if(r < heap_size && heap[smallest] > heap[r])
		smallest = r;
	if(smallest != i) {
		swap(&heap[smallest], &heap[i]);
		min_heapify(heap, smallest);
	}
	return;
}

// Function's Time Complexity: Logarithmic
void max_heapify(vector<int>& heap, int i) {
	// cout << "max_heapify(); ";
	int l = 2*i;		// Index of the Left Child of Node-i
	int r = 2*i+1;		// Index of the Right Child of Node-i
	int largest;
	if(l < heap_size && heap[i] < heap[l])
		largest = l;
	else largest = i;
	if(r < heap_size && heap[largest] < heap[r])
		largest = r;
	if(largest != i) {
		swap(&heap[largest], &heap[i]);
		max_heapify(heap, largest);
	}
	return;
}

// Function's Time Complexity: Logarithmic
void heapify(vector<int>& heap, int i) {
	// cout << "heapify(); ";
	if(option == true) // Non-Increasing Order
		min_heapify(heap, i);
	else max_heapify(heap, i);	// Non-Decreasing Order
	return;
}

// Function's Time Complexity: Linear Logarithmic
void build_heap(vector<int>& heap) {
	// cout << "build_heap(); ";
	for(int i = (heap_size-1)/2; i > 0; --i)
		heapify(heap, i);
	return;
}

// Function's Time Complexity: Linear Logarithmic
void heapsort(vector<int>& v) {
	// cout << "heapsort(); ";
	build_heap(v);
	for(int i = heap_size-1; i > 1; --i) {
		swap(&v[i], &v[1]);
		--heap_size;
		heapify(v, 1);
	}
	return;
}

// Driver Program
int main() {
	cout << "Enter the Number of Integers you want to Sort: ";
	int n;	cin >> n;
	heap_size = n+1;
	cout << "Enter the Integers: ";
	vector<int> v(n+1);
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
	
	cout << "0. Non-Increasing Order\n";
	cout << "1. Non-Decreasing Order\n";
	// This Loop will run until there's a correct option entered
	int opt;
	do {
		cout << "Choose The Option: ";	cin >> opt;
	} while(!(opt == 0 || opt == 1));
	
	option = opt;
	heapsort(v);
	
	string sort = (option == true) ? "Non-Increasing Order" : "Non-Decreasing Order";
	cout << "The Array after applying Heapsort (" << sort << ") on it: ";
	for(int i = 1; i <= n; ++i)
		cout << v[i] << " ";
	cout << "\n";

	return 0;
}