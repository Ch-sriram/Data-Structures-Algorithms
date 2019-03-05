#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Function Prototypes:
void swap(int*, int*);
int get_heap_size(void);
bool check_heap_size(void);
void get_elements(vector<int>&);
void min_heapify(vector<int>&, int);
void build_min_heap(vector<int>&);
void insert_into_heap(vector<int>&);
void delete_element_from_heap(vector<int>&);
int heap_extract_min(vector<int>&);
void extract_min_from_min_heap(vector<int>&);
void heap_update_key(vector<int>&);

// Global Variables:
vector<int> heap(1);
int heap_size = heap.size();

// Function's Time Complexity: Constant
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
	return;
}

// Function's Time Complexity: Constant
int get_heap_size(void) {
	return heap_size;
}

bool check_heap_size(void) {
	if(get_heap_size() <= 1)
		return false;
	else return true;
}

// Function's Time Complexity: Linear
void get_elements(vector<int>& heap) {
	if(check_heap_size() == false)
		cout << "Heap Underflow!";
	else {
		cout << "The Min Heap Elements are: ";
		for(int i = 1; i < heap_size; ++i)
			cout << heap[i] << " ";
	}
	cout << "\n";
	return;
}

// Function's Time Complexity: Logarithmic
void min_heapify(vector<int>& heap, int i) {
	int l = 2*i;			// Node-i's Left Child Index
	int r = (2*i)+1;		// Node-i's Right Child Index
	int smallest;
	if(l < heap_size && heap[l] < heap[i])
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

// Function's Time Complexity: Linear Logarithmic
void build_min_heap(vector<int>& heap) {
	for(int i = (heap_size-1)/2; i > 0; --i)
		min_heapify(heap, i);
	return;
}

// Function's Time Complexity: Linear Logarithmic
void insert_into_heap(vector<int>& heap) {
	cout << "Enter the Element to be Inserted into the Min Heap: ";
	int x;	cin >> x;	heap.push_back(x);	++heap_size;
	build_min_heap(heap);
	cout << "Element Inserted into the Min Heap Successfully!\n";
	return;
}

// Function's Time Complexity: Quadratic
void delete_element_from_heap(vector<int>& heap) {
	if(check_heap_size() == false)
		cout << "Heap Underflow!";
	else {
		cout << "Enter the Element to be Deleted from the Min Heap: ";
		int ele;	cin >> ele;
		for(int i = 1; i < heap_size; ++i)
			if(heap[i] == ele) {
				for(int j = i; j < heap_size; ++j)
					heap[j] = heap[j+1];
				break;
			}
		--heap_size;
	}
	cout << "\n";
	return;
}

// Function's Time Complexity: Logarithmic
int heap_extract_min(vector<int>& heap) {
	int min = heap[1];
	heap[1] = heap[heap_size-1];
	--heap_size;
	min_heapify(heap, 1);
	return min;
}

//Function's Time Complexity: Logarithmic
void extract_min_from_min_heap(vector<int>& heap) {
	if(check_heap_size() == false)
		cout << "Heap Underflow!";
	else cout << "Minimum Element that has been Extracted is: " << heap_extract_min(heap);
	cout << "\n";
	return;
}

// Function's Time Complexity: Logarithmic
void heap_update_key(vector<int>& heap) {
	if(check_heap_size() == false)
		cout << "Heap Underflow!";
	else {
		int key, val;
		cout << "Enter the key to be Updated: ";	cin >> key;
		if(key > get_heap_size() || key <= 1)
			cout << "Incorrect Key. Please Enter a Key within heap_size (key > 1 || key < heap_size)";
		else {
			cout << "Enter the Key-" << key << "'s Value: ";	cin >> val;
			heap[key] = val;
			min_heapify(heap, 1);
		}
	}
	cout << "\n";
	return;
}

// Driver Program
int main() {
	do {
		cout << "Welcome to Min Heapifying Fest! Here's the Menu\n";
		cout << "1. Show Elements in Min Heap\n";
		cout << "2. Insert Element into Min Heap\n";
		cout << "3. Delete Element in Min Heap\n";
		cout << "4. Extract Minimum from Min Heap\n";
		cout << "5. Number of Elements in the Min Heap\n";
		cout << "6. Update an Existing Key with a New Value\n";
		cout << "(Press Ctrl+C to Exit the Program)\n";
		cout << "What's Your Option (1-5)? : ";
		int opt;	cin >> opt;
		switch(opt) {
			case 1: {
				get_elements(heap);
				break;
			}
			case 2: {
				insert_into_heap(heap);
				break;
			}
			case 3: {
				delete_element_from_heap(heap);
				break;
			}
			case 4: {
				extract_min_from_min_heap(heap);
				break;
			}
			case 5: {
				cout << "Number of Elements in the Min Heap are: " << get_heap_size()-1 << "\n";
				break;
			}
			case 6: {
				heap_update_key(heap);
				break;
			}
			default: {
				cout << "Enter the Option (1-6) as shown above.\n";
				break;
			}
		}
		cout << "\n";
	} while(1);
	return 0;
}