#include <iostream>
#include <vector>
using namespace std;

// Function Prototypes
void swap(int*, int*);
int partition(vector<int>&, int, int);
void quicksort(vector<int>&, int, int);

// Function's Time Complexity: Constant
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

// Function's Time Complexity: Linear
int partition(vector<int>& v, int start, int end) {
	int pivot = v[end];
	int i = start - 1;
	for (int j = start; j < end; ++j)
		if(v[j] <= pivot) {
			++i;
			swap(&v[i], &v[j]);
		}
	swap(&v[i+1], &v[end]);
	return i+1;
}

// Function's Time Complexity: Linear Logarithmic (Average Case) || Quadratic (Worst Case) 
void quicksort(vector<int>& v, int start, int end) {
	if (start < end) {
		int q = partition(v, start, end);
		quicksort(v, start, q-1);
		quicksort(v, q+1, end);
	}
	return;
}

// Driver Program
int main() {
	cout << "Enter the number of elements in the vector? ";
	int n;	cin >> n;
	vector<int> v(n);
	
	cout << "Enter " << n << " elements (integers) to sort using Quick Sort: \n";
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	
	cout << "The Integers (unsorted) you entered are: ";
	for (int i = 0; i < n; ++i) 
		cout << v[i] << " ";
	cout << "\n";

	quicksort(v, 0, n-1);
	
	cout << "The Integers in a Sorted Order are: ";
	for (int i = 0; i < n; ++i) 
		cout << v[i] << " ";

	return 0;
}