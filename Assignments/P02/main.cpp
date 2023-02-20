/***********************************************************************
 *
 *  Author:           Brayden Lawson
 *  Title:            Vector Class 2
 *  Course:           2143-201
 *  Semester:         Spring 2023
 *
 *  Description:
 * Uses a singly linked list as the backend for an STL like "vector"
 * This program will have various methods which will make modifications
 * to the linked lists in this program, such as adding values on to it
 * and removing some items. This program has code from the first Vector
 * Class program, but it includes some added use with
 * overloading operators.
 *
 *
 *  Usage:
 *       Same as a linked list program, but with vectors, and overloading
 *        operators.
 *
 *  Files: output.txt
 ***********************************************************************/

#include <fstream>
#include <iostream>

using namespace std;

struct Node {
public:
    int data;
    Node* next;

    // default constructor
    Node() {
        data = 0;
        next = nullptr;
    }

    // overloaded constructor
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

/**
 * Class Name - Vector
 *
 * Description:
 *      This class uses methods to modify linked lists.
 *
 *
 *
 *
 * Public Methods:
 *  void pushFront(int val);
 *  void pushRear(int val);
 *  void pushFront(const Vector &);
 *  void pushRear(const Vector &);
 *  void inOrderPush(int val);
 *  int popAt(int);
 *  int popFront();
 *  int popRear();
 *  int find(int key);
 *  void print();
 *  void print(ofstream &fout);
 *  void pushAt(int loc, int val);
 *
 * Private Methods:
 *      Node *Head;         beginning of list.
 *      Node *Rear;         end of list.
 *
 *
 *
 *
 * Usage: print()        prints my name, class and assignment name.
 *        pushFront()    adds item at the front of the list.
 *        pushRear()     adds item at the back of the list.
 */
class Vector {
private:
    Node* Head;
    Node* Rear;

public:
    Vector();  // default constructor
    Vector(int A[], int size); // overload 1
    Vector(string Filename);   // overload 2
    Vector(const Vector&);    // copy constructor

    // Function Prototypes

    /**
     * Public : pushFront
     *
     * Description:
     *      adds item at the front of the list.
     *
     * Params:
     *      int    :   val
     *
     *
     * Returns:
     *      nothing because it's a void method.
     */
    void pushFront(int val);
    /**
     * Public : pushRear
     *
     * Description:
     *      adds item at the back of the list.
     *
     * Params:
     *      int    :   val
     *
     *
     * Returns:
     *      nothing because it's a void method.
     */
    void pushRear(int val);
    /**
     * Public : pushFront
     *
     * Description:
     *      adds a linked list in front of another linked list.
     *
     * Params:
     *      const    :   Vector &
     *
     *
     * Returns:
     *      nothing because it's a void method.
     */
    void pushFront(const Vector&);
    /**
     * Public : pushRear
     *
     * Description:
     *      adds a linked list at the end of another linked list.
     *
     * Params:
     *      const    :   Vector &
     *
     *
     * Returns:
     *      nothing because it's a void method.
     */
    void pushRear(const Vector&);
    /**
     * Public : inOrderPush
     *
     * Description:
     *      adds item to the list in the correct order based on least to
     *      greatest.
     *
     * Params:
     *      int    :   val
     *
     *
     * Returns:
     *      nothing because it's a void method.
     */
    void inOrderPush(int val);
    /**
     * Public : popat
     *
     * Description:
     *      removes an item in the list based on the number passed in
     *
     *
     * Params:
     *      int
     *
     *
     * Returns:
     *      integer aka the number that was deleted.
     */
    int popAt(int);
    /**
     * Public : popFront
     *
     * Description:
     *      removes an item at the front of the list.
     *
     *
     * Params:
     *      int
     *
     *
     * Returns:
     *      integer aka the number that was deleted.
     */
    int popFront();
    /**
     * Public : popRear
     *
     * Description:
     *      removes an item at the end of the list.
     *
     *
     * Params:
     *      int
     *
     *
     * Returns:
     *      integer aka the number that was deleted.
     */
    int popRear();
    /**
     * Public : find
     *
     * Description:
     *      finds a specific number in the list.
     *
     *
     * Params:
     *      int key
     *
     *
     * Returns:
     *      integer aka the number that was found, if it's not in the
     *      list  a -1 is returned instead.
     */
    int find(int key);
    /**
     * Public : print
     *
     * Description:
     *      prints the linked list
     *
     *
     * Params:
     *      none
     *
     *
     * Returns:
     *      nothing it's void
     */
    void print();
    /**
     * Public : print
     *
     * Description:
     *      prints the linked list to an outfile.
     *
     *
     * Params:
     *      ofstream & fout
     *
     *
     * Returns:
     *      nothing it's void.
     */
    void print(ofstream& fout);
    /**
     * Public : pushAt
     *
     * Description:
     *      pushes a specific value at a specific point in the list
     *      depending on the number passed in.
     *
     *
     * Params:
     *      int loc, int val
     *
     *
     * Returns:
     *      nothing it's void.
     */
    void pushAt(int loc, int val);
    friend ostream& operator<<(ostream&, const Vector&);
    friend fstream& operator<<(fstream&, const Vector&);
    // IntList operator+(const int);
    void operator+(int);
    Vector operator+=(const int);
    //overloads assignment.
    Vector operator=(const Vector&);
    int& operator[](const int);
    /**
       * Public : operator+
       *
       * Description:
       *      overloads the additon operator
       *
       *
       * Params:
       *      const Vector, &rhs
       *
       *
       * Returns:
       *      a Vector named V.
       */
    Vector operator+(const Vector& rhs);
    /**
       * Public : operator-
       *
       * Description:
       *      overloads the subtraction operator
       *
       *
       * Params:
       *      const Vector, &rhs
       *
       *
       * Returns:
       *      a Vector named V.
       */
    Vector operator-(const Vector& rhs);
    /**
       * Public : operator/
       *
       * Description:
       *      overloads the division operator
       *
       *
       * Params:
       *      const Vector, &rhs
       *
       *
       * Returns:
       *      a Vector named V.
       */
    Vector operator/(const Vector& rhs);
    /**
       * Public : operator+
       *
       * Description:
       *      overloads the multiplication operator
       *
       *
       * Params:
       *      const Vector, &rhs
       *
       *
       * Returns:
       *      a Vector named V.
       */
    Vector operator*(const Vector& rhs);
    /**
       * Public : operator+
       *
       * Description:
       *      overloads the equality operator
       *
       *
       * Params:
       *      const Vector, &rhs
       *
       *
       * Returns:
       *      a 0 or 1.
       */
    bool operator==(const Vector& rhs);
    
};

// prints header to screen.
void printHeader() {
    cout << "Brayden Lawson" << endl;
    cout << "2-21-23" << endl;
    cout << "Spring 2143" << endl;
    cout << " " << endl;
}

// prints header to output file.
void printHeader(ofstream& fout) {
    fout << "Brayden Lawson" << endl;
    fout << "2-21-23" << endl;
    fout << "Spring 2143" << endl;
    fout << " " << endl;
}

// some methods below utilize travel or traverse
// which is used to traverse through the linked lists.

Vector::Vector() {

    // makes the list empty;
    Head = Rear = nullptr;
}

Vector::Vector(string Filename) {
    Head = Rear = nullptr;
    ifstream infile;
    infile.open(Filename);
    int values; // values is the data in the input file.
    while (infile >> values) {

        pushRear(values);
    }
    infile.close();
}

Vector::Vector(int A[], int size) {
    Head = Rear = nullptr;
    for (int i = 0; i < size; i++) {
        pushRear(A[i]);
    }
}

Vector::Vector(const Vector& other) {

    Head = Rear = nullptr;

    Node* temp = other.Head;

    while (temp != nullptr) {
        pushRear(temp->data);
        temp = temp->next;
    }
}

void Vector::pushFront(int val) {
    Node* temp = new Node(val);
    if (Head == nullptr) {
        Head = temp;
        Rear = temp;

    }
    else {
        temp->next = Head;
        Head = temp;
    }
}

void Vector::pushFront(const Vector& other) {
    Node* traverse = (other.Head);
    other.Rear->next = Head;
    Head = other.Head;
}

void Vector::pushRear(const Vector& other) {
    // traverse other and add values to this list
    Node* traverse = (other.Head);
    while (traverse) {
        pushRear(traverse->data);
        traverse = traverse->next;
    }
}

void Vector::pushAt(int loc, int val) {
    Node* travel = Head;
    int index = 0;

    while (travel != NULL && index != loc) {

        travel = travel->next;
        index++;
    }

    Node* insert = new Node(val);
    Node* temp = travel->next;
    temp->next = insert;
    insert->next = temp;
}

int Vector::popFront() {
    Node* temp = Head;
    Head = Head->next;
    return Head->data;
    delete temp;
}

int Vector::popRear() {
    int l = Rear->data;
    Node* traverse = Head;

    while (traverse->next->next != NULL) {
        traverse = traverse->next;
    }
    Node* temp = traverse->next->next;
    delete temp;
    temp = NULL;
    traverse->next = NULL;
    Rear = traverse;
    return l;
}

int Vector::popAt(int index) {
    // check to make sure index > length of the list

    Node* traverse = Head;

    Node* temp;

    int hold;

    for (int i = 0; i < index - 1; i++) {
        traverse = traverse->next;
    }
    hold = traverse->next->data;
    temp = traverse->next;
    traverse->next = traverse->next->next;

    delete temp;
    return hold;
}
// key is the value it's looking for so it can print it out.
int Vector::find(int key) {
    Node* travel = Head;
    int index = 0;

    while (travel) {
        if (travel->data == key) {
            return index;
        }

        travel = travel->next;
        index++;
    }
    return -1;
}

void Vector::pushRear(int val) {

    Node* temp = new Node(val);

    if (Head == nullptr) {
        Head = temp;
        Rear = temp;

    }
    else {

        Rear->next = temp;
        Rear = temp;
    }
}

void Vector::inOrderPush(int val) {
    Node* temp = new Node(val);
    // logic to find spot
    if (!Head) {
        Head = Rear = temp;
    }
    else if (temp->data < Head->data) {
        pushFront(val);
    }
    else if (temp->data > Rear->data) {
        pushRear(val);
    }
    else {

        Node* travel = Head;

        while (travel->next->data < temp->data) {
            travel = travel->next;
        }

        temp->next = travel->next;
        travel->next = temp;
    }
}

//overloading assignment.
Vector Vector::operator=(const Vector& rhs) {

    // check for self assignment
    if (this == &rhs)
    {
        return *this;
    }
    Node* temp = Head;




    this->Head = rhs.Head;
    this->Rear = rhs.Rear;



    while (temp != NULL)
    {
        temp = temp->next;
    }

    return *this;
}

int& Vector::operator[](const int x) {
    Node* travel = Head;
    int t = x;
    // need to test for end of list!! I don't here.
    while (t-- && travel) {
        travel = travel->next;
    }
    return travel->data;
}

// neatly organizes the output and formats it for the screen.
void Vector::print() {
    Node* temp = Head;
    cout << "[";

    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << ", ";
        }
        temp = temp->next;
    }
    cout << "]" << endl;
}

// neatly organizes the output and formats it for the output file.
void Vector::print(ofstream& fout) {
    Node* temp = Head;
    fout << "[";

    while (temp != nullptr) {
        fout << temp->data;
        if (temp->next != nullptr) {
            fout << ", ";
        }
        temp = temp->next;
    }
    fout << "]" << endl;
}

ostream& operator<<(ostream& format, const Vector& otherList) {
    format << "["; 
    // format is the variable that writes the brackets to the 
    // console and the output file. 
   //using cout or fout in this function would cause an 
   //issue where the brackets are misplaced.
    Node* temp = otherList.Head;

    while (temp != nullptr) {
        format << temp->data;
        if (temp->next != nullptr) {
            format << ",";
        }
        temp = temp->next;
    }
    format << "]";
    format << endl;
    return format;
}

fstream& operator<<(fstream& format, const Vector& otherList) {
    Node* temp = otherList.Head;

    while (temp != nullptr) {
        format << temp->data;
        if (temp->next != nullptr) {
            format << ",";
        }
        temp = temp->next;
    }
    format << endl;
    return format;
}

// overloading addition.
Vector Vector::operator+(const Vector& rhs) {
    Vector V;
    Node* shorter;
    Node* longer;
    Node* temp = Head;
    int length = 0;  // length of first list.
    int length2 = 0; // length of second list.
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }

    temp = rhs.Head;
    while (temp != NULL) {
        temp = temp->next;
        length2++;
    }
    if (length < length2) {
        shorter = this->Head;
        longer = rhs.Head;

    }
    else {
        longer = this->Head;
        shorter = rhs.Head;
    }
    while (shorter) {
        V.pushRear(shorter->data + longer->data);
        shorter = shorter->next;
        longer = longer->next;
    }


    while (longer) {
        V.pushRear(longer->data);
        longer = longer->next;
    }

    return V;
}

// overloading subtraction
Vector Vector::operator-(const Vector& rhs) {
    Vector V;
    Node* left = Head;
    Node* right = rhs.Head;

    while (left != NULL && right != NULL) {
        V.pushRear(left->data - right->data);
        right = right->next;
        left = left->next;
    }

    while (left != NULL) {
        V.pushRear(left->data);
        left = left->next;
    }

    while (right != NULL) {
        V.pushRear(right->data);
        right = right->next;
    }

    return V;
}

// overloading multiplication
Vector Vector::operator*(const Vector& rhs) {
    Vector V;
    Node* left = Head;
    Node* right = rhs.Head;

    while (left != NULL && right != NULL) {
        V.pushRear(left->data * right->data);
        right = right->next;
        left = left->next;
    }

    while (left != NULL) {
        V.pushRear(left->data);
        left = left->next;
    }

    while (right != NULL) {
        V.pushRear(right->data);
        right = right->next;
    }

    return V;
}

// overloading division
Vector Vector::operator/(const Vector& rhs) {
    Vector V;
    Node* left = Head;
    Node* right = rhs.Head;

    while (left != NULL && right != NULL) {
        V.pushRear(left->data / right->data);
        right = right->next;
        left = left->next;
    }

    while (left != NULL) {
        V.pushRear(left->data);
        left = left->next;
    }

    while (right != NULL) {
        V.pushRear(right->data);
        right = right->next;
    }

    return V;
}

// overloads equality.
bool Vector::operator==(const Vector& rhs) {

    bool isEqual = true;
    Node* left = Head;
    Node* right = rhs.Head;

    while (left != NULL && right != NULL) {
        if (left->data != right->data) {
            return false;
        }
        right = right->next;
        left = left->next;
    }

    if (left != NULL && right != NULL) {
        return false;

    }

    else {
        return true;
    }
}



int main() {
    int a1[] = { 1, 2, 3, 4, 5 };
    int a2[] = { 10, 20, 30 };

    Vector v1(a1, 5);
    Vector v2(a2, 3);

    ofstream fout;
    fout.open("output.txt");
    printHeader();
    printHeader(fout);
    cout << v1[2] << endl;
    fout << v1[2] << endl;
    // writes out 3

    // return the location of v1[4] then overwrite it with the 9.
    v1[4] = 9;
    // v1 now = [1,2,3,4,9]

    cout << v1 << endl;
    // writes out [1,2,3,4,9] to console.

    fout << v1 << endl;
    // writes out [1,2,3,4,9] to the output file.

    Vector v3 = v1 + v2;
    cout << v3 << endl;
    // writes out [11,22,33,4,9] to console.
    fout << v3 << endl;
    // writes out [11,22,33,4,9] to the output file.

    v3 = v1 - v2;
    cout << v3 << endl;
    // writes out [-9,-18,-27,4,9] to console.
    fout << v3 << endl;
    // writes out [-9,-18,-27,4,9] to the output file.

    v3 = v2 - v1;
    cout << v3 << endl;
    // writes out [9,18,27,4,9] to console
    fout << v3 << endl;
   . // writes out [9,18,27,4,9] to the output file.

    v3 = v2 * v1;
    cout << v3 << endl;
    // writes out [10,40,90,4,9] to console.
    fout << v3 << endl;
    // writes out [10,40,90,4,9] to the output file.

    v3 = v1 * v2;
    cout << v3 << endl;
    // writes out [10,40,90,4,9] to console.
    fout << v3 << endl;
    // writes out [10,40,90,4,9] to console.

    v3 = v1 / v2;
    cout << v3 << endl;
    // writes out [0,0,0,4,9] to console.
    fout << v3 << endl;
    // writes out [0,0,0,4,9] to the output file.

    v3 = v2 / v1;
    cout << v3 << endl;
    // writes out [10,10,10,4,9] to console.
    fout << v3 << endl;
    // writes out [10,10,10,4,9] to the output file.

    cout << (v2 == v1) << endl;
    // writes 0 to console (false) .
    fout << (v2 == v1) << endl;
    // writes 0 to the output file (false) .

    Vector v4 = v1;
    cout << (v4 == v1) << endl;
    // writes 1 to console (true) .
    fout << (v4 == v1) << endl;
    // writes 1 to the output file (true) .
}
