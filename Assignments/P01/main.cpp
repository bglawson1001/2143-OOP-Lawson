/************************************************************************
 *
 *  Author:           Brayden Lawson
 *  Title:            Singly linked list vector implementation
 *  Course:           2143-201
 *  Semester:         Spring 2023
 *
 *  Description:
 * Uses a singly linked list as the backend for an STL like "vector" 
 * This program will have various methods which will make modifications 
 * to the linked lists in this program, such as adding values on to it 
 *  and removing some items.
 *
 *
 *  Usage:
 *        Same as a linked list program, but with vectors.
 *
 *  Files: input.dat, test.out, main.cpp
 ************************************************************************/

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
    Vector();
    Vector(int A[], int size);
    Vector(string Filename);
    Vector(const Vector&);


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
    Vector& operator=(const Vector&);
    int& operator[](const int);
};


// prints header to screen.
void printHeader() {
    cout << "Brayden Lawson" << endl;
    cout << "2-13-23" << endl;
    cout << "Spring 2143" << endl;
    cout << " " << endl;

}

// prints header to output file.
void printHeader(ofstream& fout) {
    fout << "Brayden Lawson" << endl;
    fout << "2-13-23" << endl;
    fout << "Spring 2143" << endl;
    fout << " " << endl;

}

// some methods below utilize travel or traverse
// which is used to traverse through the linked lists.

Vector::Vector() {

    // makes the list empty;
    Head = Rear = nullptr;
}

Vector::Vector(string Filename)
{
    Head = Rear = nullptr;
    ifstream infile;
    infile.open(Filename);
    int values; // values is the data in the input file.
    while (infile >> values)
    {

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

void Vector::pushFront(const Vector& other)
{
    Node* traverse = (other.Head);
    other.Rear->next = Head;
    Head = other.Head;
}



void Vector::pushRear(const Vector& other) {
    // traverse other and add values to this list
    Node* traverse = (other.Head);
    while (traverse)
    {
        pushRear(traverse->data);
        traverse = traverse->next;
    }


}

void Vector::pushAt(int loc, int val)
{
    Node* travel = Head;
    int index = 0;

    while (travel != NULL && index != loc)
    {

        travel = travel->next;
        index++;
    }

    Node* insert = new Node(val);
    Node* temp = travel->next;
    temp->next = insert;
    insert->next = temp;

}

int Vector::popFront()
{
    Node* temp = Head;
    Head = Head->next;
    return Head->data;
    delete temp;

}

int Vector::popRear()
{
    int l = Rear->data;
    Node* traverse = Head;


    while (traverse->next->next != NULL)
    {
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

    for (int i = 0; i < index - 1; i++)
    {
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

    if (Head == nullptr)
    {
        Head = temp;
        Rear = temp;

    }
    else
    {

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



Vector& Vector::operator=(const Vector& rhs) {
    if (this == &rhs) {
        return *this;
    }

    this->Head = rhs.Head;
    this->Rear = rhs.Rear;

    return *this;
}

int& Vector::operator[](const int x) {
    Node* travel = Head;
    int t = x;
    // need to test for end of list!! I don't here.
    while (t--) {
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

ostream& operator<<(ostream& banana, const Vector& otherList) {
    Node* temp = otherList.Head;
    while (temp != nullptr) {
        banana << temp->data;
        if (temp->next != nullptr) {
            banana << "->";
        }
        temp = temp->next;
    }
    banana << endl;
    return banana;
}

fstream& operator<<(fstream& banana, const Vector& otherList) {
    Node* temp = otherList.Head;
    while (temp != nullptr) {
        banana << temp->data;
        if (temp->next != nullptr) {
            banana << "->";
        }
        temp = temp->next;
    }
    banana << endl;
    return banana;
}

int main() {
    ofstream fout;
    fout.open("test.out");
    printHeader();
    printHeader(fout);
    int x = 0;

    Vector v1;
    v1.pushFront(18);
    v1.pushFront(20);
    v1.pushFront(25);
    v1.pushRear(18);
    v1.pushRear(20);
    v1.pushRear(25);
    v1.print();
    v1.print(fout);
    // [25, 20, 18, 18, 20, 25]

    int A[] = { 11, 25, 33, 47, 51 };



    Vector v2(A, 5);
    v2.print();
    v2.print(fout);
    // [11, 25, 33, 47, 51]

    v2.pushFront(9);
    v2.inOrderPush(27);
    v2.pushRear(63);
    v2.print();
    v2.print(fout);
    //  [9, 11, 25, 33, 47, 51, 63]

    v1.pushRear(v2);
    v1.print();
    v1.print(fout);
    //  // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

    x = v1.popFront();
    x = v1.popFront();
    x = v1.popFront();
    v1.print();
    v1.print(fout);
    // // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
    cout << x << endl;
    fout << x << endl;
    // // 18

    x = v1.popRear();
    x = v1.popRear();
    x = v1.popRear();
    v1.print();
    v1.print(fout);

    // // [18, 20, 25, 9, 11, 25, 27, 33]
    cout << x << endl;
    fout << x << endl;
    // // 47

    x = v2.popAt(3);
    v2.print();
    v2.print(fout);
    // // [9, 11, 25, 33, 47, 51, 63]
    cout << x << endl;
    fout << x << endl;
    // // 27

    x = v2.find(51);
    cout << x << endl;
    fout << x << endl;
    // // 5

    x = v2.find(99);
    cout << x << endl;
    fout << x << endl;
    // // -1

    Vector v3(v1);
    v3.print();
    v3.print(fout);
    //  // [18, 20, 25, 9, 11, 25, 27, 33]

    v3.pushFront(v2);
    v3.print();
    v3.print(fout);
    // //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

    Vector v4("input.dat");
    v4.pushRear(v3);
    v4.print();
    v4.print(fout);
 // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4,
 //  23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 
 //  11,
 //  25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
    fout.close();
}

