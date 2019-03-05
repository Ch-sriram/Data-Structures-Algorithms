#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Function Prototypes:
void swap(int*, int*);
void get_heap_size(void);
bool max_heap_delete(vector<int>&, int);
void max_heapify(vector<int>&, int);
int heap_extract_max(vector<int>&);
void modify_heap(vector<int>&, int, int);
void build_max_heap(vector<int>&);

// Global Variables: The Heap & its size.
vector<int> heap(1);
int heap_size = heap.size();

// Function's Time Complexity: Constant
void get_heap_size() {
	cout << "Current Heap Size is: " << heap_size-1;
	return;
}

// Function's Time Complexity: Quadratic
bool max_heap_delete(vector<int>& heap, int element) {
	bool found = false;
	for(int i = 1; i < heap_size; ++i) {
		if(heap[i] == element) {
			found = true;
			for(int j = i; j < heap_size; ++j)
				heap[j] = heap[j+1];
			break;
		}
	}
	string status = (found == true) ? "Element Found. " : "Element Not Found. ";
	cout << status;
	return found;
}

// Function's Time Complexity: Constant
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
	return;
}

// Function's Time Complexity: Logarithmic
void max_heapify(vector<int>& heap, int k) {
	int l = 2*k; 	// Index of the Left Child from Root k
	int r = (2*k)+1;	// Index of the Right Child from Root k
	int largest;
	if(l < heap_size && heap[k] < heap[l])
		largest = l;
	else largest = k;
	if(r < heap_size && heap[largest] < heap[r])
		largest = r;
	if(largest != k) {
		swap(&heap[k], &heap[largest]);
		max_heapify(heap, largest);
	}
	return;
}

// Function's Time Complexity: Logarithmic
int heap_extract_max(vector<int>& heap) {
	int max = INT_MIN;
	if(heap_size <= 1)
		cout << "Heap Underflow. Please Insert Elements into the Heap. ";
	else {
		max = heap[1];
		heap[1] = heap[heap_size-1];
		--heap_size;
		max_heapify(heap, 1);
	}
	return max;
}

// Function's Time Complexity: Logarithmic
void modify_heap(vector<int>& heap, int key, int value) {
	heap[key] = value;
	max_heapify(heap, 1);
	return;
}

// Function's Time Complexity: Linear Logarithmic
void build_max_heap(vector<int>& heap) {
	for(int i = (heap_size-1)/2; i > 0; --i)
		max_heapify(heap, i);
	return;
}

// Driver Program
int main() {
	do {
		cout << "\n-------------------------------------------------------------------------------------------\n";
		cout << "Welcome to Max Heapifying Fest! Here's the Menu:\n";
		cout << "1. Show the Elements in the Max Heap\n";
		cout << "2. Insert an Element into the Max Heap\n";
		cout << "3. Delete an Element from the Max Heap\n";
		cout << "4. Extract Max Element from the Max Heap\n";
		cout << "5. Get the Current Size of the Max Heap\n";
		cout << "6. Modify Key in the Max Heap\n";
		cout << "(Press Ctrl+C to Exit the Process)\n";
		cout << "Please Enter Your Preferred Option: "; 
		int option;	cin >> option;	cout << "\n\n";
		switch(option) {
			case 1: { // Show the Elements in the Max Heap
				cout << "Elements in the Max Heap are: ";
				if(heap_size > 1)
					for(int i = 1; i < heap_size; ++i)
						cout << heap[i] << " ";
				else cout << "<none>";
				cout << "\n";
				break;
			} 
			case 2: { // Insert an Element into the Max Heap
				cout << "Enter the Element to be inserted into the Max Heap: ";
				int x;	cin >> x;	heap.push_back(x);	heap_size++;
				build_max_heap(heap);
				cout << "Element " << x << " Inserted into the Max Heap Successfully!";
				break;
			}
			case 3: { // Delete an Element from the Max Heap
				cout << "Enter the Element to be deleted from the Max Heap: ";
				int x;	cin >> x;
				build_max_heap(heap);
				bool status = max_heap_delete(heap, x);
				if(status == true) {
					heap_size--;
					cout << "Element is deleted.";
					build_max_heap(heap);
				}
				else cout << "There's No Element to be deleted.";
				cout << "\n\n";
				break;
			}
			case 4: { // Extract Max Element from the Max Heap: Get the max element in the heap and delete it.
				int max = heap_extract_max(heap);
				if(max != INT_MIN) 
					cout << "Max Element Extraction Successful. The Maximum Element in the Heap was: " << max;
				else cout << "Max Element Extraction Unsuccessful.";
				cout << "\n";
				break;
			} 
			case 5: { // Get the Current Size of the Max Heap
				get_heap_size();
				break;
			}
			case 6: { // Modify Key in the Max Heap
				int key, val;
				cout << "Please Enter the Key to be modified: ";	cin >> key;
				if(key >= heap_size) {
					get_heap_size();
					cout << ". Please Enter a Key within the Range of the Current Heap Size.";
				}
				else {
					cout << "Please Enter the New Value of the Key-" << key << ": ";	cin >> val;
					modify_heap(heap, key, val);
					cout << "Given Key-" << key << "'s Value has been successfully updated to " << val;
				}
				break;
			}
			default: {
				cout << "Please Enter the Options given in the Menu.\n";
				break;
			}
		}
		cout << "\n";
	} while(1);
	
	return 0;
}