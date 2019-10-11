#include <iostream>
using namespace std;

// Node Structure
struct Node {
    int data;
    Node* next {nullptr};

    // Constructor for creating a new node
    Node (int data) {
        this->data = data;
    }
};

struct List {
    // A global head and tail pointer
    Node* head {nullptr};
    Node* tail {nullptr};    

    // A global length variable to know the length of the linked list
    uint32_t length {0};

    int search(const int);
    void display(void);
    void insert_at_beg(const int);
    void insert_at_end(const int);
    void insert_at_pos(const int, const uint32_t);
    int delete_at_beg(void);
    int delete_at_end(void);
    int delete_at_pos(const uint32_t);
    int get_head();
    int get_tail();

    // Destructor
    ~List();
};

List::~List() {
    while(head)
        delete_at_beg();
    display();
    cout << "\n\t\tList has been destroyed...\n\n";
    head = tail = nullptr;
}

// function to search for a node in the linked list and return the position of the key
int List::search(const int key) {
    if(head) {
        Node* temp = head;
        uint32_t pos = 0;
        while(temp) {
            ++pos;
            if(temp->data == key) return pos;
            temp = temp->next;
        }
    }
    return -1;
}

// function to traverse the entire linked list and then print the list
void List::display(void) {
    if (head) {
        Node* temp = head;
        while(temp) {
            cout << temp->data;
            cout << " -> ";
            temp = temp->next;
        }
        cout << "\\0";
    } else cout << "\t\tList is empty!\n\n";
}

// function to insert a new node at the beginning of the list
void List::insert_at_beg(const int data) {
    Node* node = new Node(data);
    if (!head)
        head = tail = node;
    else {
        Node* temp = head;
        head = node;
        head->next = temp;
    }
    ++length;
}

// function to insert a new node at the end of the list
void List::insert_at_end(const int data) {
    Node* node = new Node(data);
    if (!head)
        head = tail = node;
    else {
        Node* temp = tail;
        tail = node;
        temp->next = tail;
    }
    ++length;
}

// function to insert a new node at a specified position
void List::insert_at_pos(const int data, const uint32_t pos) {
    // if the list is empty, insertion of the new node is done at the beginning. 
    cout << "\n\t";
    if (!head) {
        insert_at_beg(data); 
        cout << "List was empty, therefore, " << data << " was inserted as the head node";
    } else {
        if (pos < 1 || pos > length + 1) {
            cout << "Invalid Position. Position Range is [1, " << length + 1 << "]";
        } else if (pos == length + 1) {
            insert_at_end(data);
            cout << "Inserted " << data << " at position " << length;
        } else {
            Node* node = new Node(data);
            Node* temp = head;
            uint32_t temp_pos = 1;
            while (temp) {
                if (temp_pos == pos) {
                    Node* temp1 = temp->next;
                    int temp_data = temp->data;
                    temp->data = node->data;
                    node->data = temp_data;
                    temp->next = node;
                    node->next = temp1;
                    if (temp_pos == length) tail = tail->next;
                    break;
                }
                ++temp_pos;
                temp = temp->next;
            }
            ++length;
            cout << "Inserted " << data << " at position " << pos;
        }
    }
    cout << "\n\n";
}

// function to delete a node from the beginning of the list
int List::delete_at_beg(void) {
    if (!head) return -1;
    else {
        Node* temp = head;
        int temp_data = temp->data;
        if (head == tail) head = tail = nullptr;
        else head = head->next;
        delete temp;
        temp = nullptr;
        --length;
        return temp_data;
    }
}

// function to delete a node from the end of the list
int List::delete_at_end(void) {
    if (head) {
        Node* curr = head;
        while (curr->next != tail && curr->next != nullptr)
            curr = curr->next;
        if (curr->next == nullptr) {
            int temp_data = curr->data;
            delete curr;
            head = tail = curr = nullptr;
            --length;
            return temp_data;
        } else {
            int temp_data = tail->data;
            tail = curr;
            delete curr->next;
            tail->next = curr = nullptr;
            --length;
            return temp_data;
        }
    }  
    return -1;
}

// function to delete a node at a specified position in the list
int List::delete_at_pos(const uint32_t pos) {
    if (head) {
        if (pos == 1)   return delete_at_beg();
        else if (pos == length) return delete_at_end();
        else if (pos < 1 || pos > length) {
            cout << "\n\tInvalid Position. Position Range: [1, " << length << "]\n";
            return -2;  
        } else {
            Node* curr = head;
            uint32_t temp_pos = 1;
            while(curr) {
                if (temp_pos + 1 == pos) {
                    Node* temp = curr->next;
                    curr->next = temp->next;
                    temp->next = nullptr;
                    int temp_data = temp->data;
                    delete temp;
                    temp = nullptr;
                    --length;
                    return temp_data;
                }
                ++temp_pos;
                curr = curr->next;
            }
        }
    }
    return -1;
}

// function to see what the head is pointing to
int List::get_head(void) {
    int ans = -1;
    if (head) ans = head->data;
    return ans;
}

// function to see what the tail is pointing to
int List::get_tail(void) {
    int ans = -1;
    if (head) ans = tail->data;
    return ans;
}


// function to show the menu page of the driver program
void show_menu(void) {
    cout << "\t* * * * * * * * * * * * * MENU * * * * * * * * * * * * * *\n";
    cout << "\ta. Print the list\n";
    cout << "\tb. Insert new node at the beginning of the list\n";
    cout << "\tc. Insert new node at the end of the list\n";
    cout << "\td. Insert new node at a specified position of the list\n";
    cout << "\te. Delete a node from the beginning of the list\n";
    cout << "\tf. Delete a node from the end of the list\n";
    cout << "\tg. Delete a node from a specified position of the list\n";
    cout << "\th. Search for a key in the list\n";
    cout << "\ti. Show what head is pointing to\n";
    cout << "\tj. Show what tail is pointing to\n";
    cout << "\tx. Exit the program\n";
    cout << "\n\tEnter the choice: ";
}

// Driver program
int main() {
    List singly;
    cout << "\n\n\tWelcome to the Demonstration of Singly Linked List\n";
    cout << "\t--------------------------------------------------\n\n";
    char choice;
    do {
        show_menu();
        cin >> choice;
        cout << "\n\n\t";
        int x, pos, key;

        switch(choice) {

            case 'a': 
                    singly.display();
                    break;
            
            case 'b': 
                    cout << "Enter the number to insert at the beginning of the list: ";
                    cin >> x; singly.insert_at_beg(x);
                    cout << "\n\n\tNew node has been inserted at the beginning of the list";
                    break;
            
            case 'c': 
                    cout << "Enter the number to insert at the end of the list: ";
                    cin >> x; singly.insert_at_end(x);
                    cout << "\n\n\tNew node has been inserted at the end of the list";
                    break;
            
            case 'd': 
                    cout << "Enter the number to insert: "; cin >> x;
                    cout << "\tEnter the position where the number will be inserted: ";
                    cin >> pos; singly.insert_at_pos(x, pos);
                    break;
            
            case 'e': 
                    x = singly.delete_at_beg();
                    if (x == -1) cout << "List is empty!";
                    else cout << x << " has been deleted successfully!";
                    break;
            
            case 'f': 
                    x = singly.delete_at_end();
                    if (x == -1) cout << "List is empty!";
                    else cout << x << " has been deleted successfully!";
                    break;
            
            case 'g': 
                    cout << "Enter the position to delete the node from: "; cin >> pos;
                    x = singly.delete_at_pos(pos); cout << "\t";
                    if (x == -1) cout << "List is empty!";
                    else if (x != -2) cout << x << " has been deleted successfully!";
                    break;
            
            case 'h': 
                    cout << "Enter the number (key) to be searched: "; cin >> key;
                    pos = singly.search(key);   cout <<"\t";
                    if (pos == -1) cout << "Key not found!";
                    else cout << key << " has been found at position " << pos;
                    break;
            
            case 'i': 
                    x = singly.get_head();  cout << "\n\t";
                    if (x == -1)    cout << "head is pointing to nullptr";
                    else cout << "head is pointing to " << x;
                    break;

            case 'j': 
                    x = singly.get_tail(); cout << "\n\t";
                    if (x == -1)   cout << "tail is pointing to nullptr";
                    else cout << "tail is pointing to " << x;
                    break;

            case 'x': 
                    cout << "Thank you for using the program, please run it again sometime later";
                    break;
            
            default: 
                    cout << "Please enter the choices from a-j. If you want to exit the program, enter x";
                    break;
        
        }
        
        cout << "\n\n";

    } while(choice != 'x');
    
    return 0;
}