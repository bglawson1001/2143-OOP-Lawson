/*************************************************************************
*                                                                        *
*  Author:        Brayden Lawson                                         *
*  Email:         bglawson1001@my.msutexas.edu and bgl200101@gmail.com   *
*  Label:         A03                                                    *
*  Title:         Basic Project Organization Commenting Code             *    
*  Course:        CMPS-2143-201                                          *
*  Semester:      Spring 2023                                            *
*                                                                        *
*  Description:                                                          *
* This program implements a class that will use a                        *
* circular queue which will make the last and first                      *
* element of the queue equal to each other.                              *
* It has various functions including one that sets the                   *
* sizes, one that checks to see to see if the queue is                   *
* full, and it utilizes the push and pop functions.                      *
* The push and pop functions will be called resulting in the queue       *
* going through various changes.                                         *
*                                                                        *
*                                                                        *
*                                                                        *
*  Usage:                                                                *
*       - $ ./main filename                                              *
*       - This will read in a file containing whatever values to         *   
*          be read into our list/array.                                  *
*                                                                        *
*  Files:                                                                *
*       main.cpp    : driver program                                     *
*                                                                        *
*                                                                        *
**************************************************************************/
#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 * 
 * Description:
 *      This class will create a circular que which will make
 *      the first last and first element of the queue equal to each other
 * Public Methods:  
 *                   CircularArrayQue()                  
 *                   CircularArrayQue(int size)
 * void              Push(int item)                 
 * 
 * Private Methods: 
 * void init         (int size = 0)    
 * bool              Full()     
 *      
 * 
 * Usage: 
 * Push() puts new item at the end of the queue.
 * Pop () deletes a new item at the front of the queue.
 *      
 *      
 */

class CircularArrayQue {  
                        
private:
    int *Container;  // size is stored here.
    int Front;       // beginning/top of the stock.
    int Rear;        // end/bottom of the stack.
    int QueSize;     // items in the queue 
    int CurrentSize; // keeps track of the current size of the 
                     //stack.

  /**
     * Private : init
     * 
     * Description:
     *      Initializes various sizes.
     * 
     * Params:
     *      int size = 0    :  sets size to zero
     *      
     * 
     * Returns:
     *      void functions don't return anything.
     */

    void init(int size = 0) 
                            
    {                                     
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }


    /**
     * Private : Full
     * 
     * Description:
     *     returns the current size if the que is full and sets it equal 
     *      to the QueSize.
     * 
     * Params:
     *      none
     *      
     * 
     * Returns:
     *      current size == QueSize
     */

    bool Full() { 
                  
        return CurrentSize == QueSize;
    }

public:
    CircularArrayQue() { 
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /
     * Public : Push
     * 
     * Description:
     *      puts new item at the end of the queue.
     * 
     * Params:
     *      int item    :  //for push to work an item needs to exist so  
     *                       push can add it to the queue                
     *                                                                 
     *                                                                 
     * Returns:                                                        
     *      void functions don't return anything.                      
     */


    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

  /**
     * Public : Pop
     * 
     * Description:
     *      Pop () deletes a new item at the front of the queue.
     * 
     * Params:
     *      none    :      
     *                                            
     *      
     * 
     * Returns:
     *      temp (temporary variable to traverse the queue)
     */

    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
    // The output will result in 1 2 3 being printed twice
}
