#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Function Prototypes
void merge(vector<int>&, int, int, int);
void mergesort(vector<int>&, int, int);

// Function's Time Complexity: Linear
void merge(vector<int>& v, int lo, int mid, int hi) {
	int n1 = mid-lo+1;
	int n2 = hi-mid;

	vector<int> L(n1+1), R(n2+1);
	
	L[n1] = R[n2] = INT_MAX;
	for(int i = 0; i < n1; ++i)
		L[i] = v[lo+i];
	for(int i = 0; i < n2; ++i)
		R[i] = v[mid+i+1];

	int i = 0, j = 0;
	for(int k = lo; k <= hi; ++k) {
		if(L[i] <= R[j])
			v[k] = L[i++];
		else v[k] = R[j++];
	}
	return;
}

// Function's Time Complexity: Linear Logarithmic
void mergesort(vector<int>& v, int lo, int hi) {
	if (lo < hi) {
		int mid = (lo + hi) / 2;
		mergesort(v, lo, mid);
		mergesort(v, mid+1, hi);
		merge(v, lo, mid, hi);
	}
	return;
}

// Driver Program
int main() {
	cout << "Enter the number of integers you want to enter? "; 
	int n;	cin >> n;
	vector<int> v(n);

	cout << "Enter " << n << " Integers: \n";
	for(int i = 0; i < n; ++i)
		cin >> v[i];

	cout << "The Integers (Unsorted) you entered are: ";
	for (int i = 0; i < n; ++i)
		cout << v[i] << " ";
	cout << "\n\n";

	mergesort(v, 0, n-1);

	cout << "The Integers after Sorting using Merge Sort are: ";
	for (int i = 0; i < n; ++i)
		cout << v[i] << " ";

	return 0;
}