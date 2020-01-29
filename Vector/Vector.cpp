//
//  Vector.cpp
//  Vector
//
//  Created by Sheldon May Gunlogson on 1/29/20.
//  Copyright © 2020 Shane May. All rights reserved.
//
#include <iostream>
#include "Vector.hpp"

using namespace std;

template <class DataType> Vector<DataType>::Vector()
{
    cout << "Vector created!\n";
    capacity = 0;       // the capacity of the vector
    size = 0;        // Actual number of data item in the vector
    dataItems = new DataType[size] ();  // Array containing the vector data item
}
template <class DataType> Vector<DataType>::~Vector()
{
    
}
template <class DataType> void Vector<DataType>::append(const DataType d)
{
//    check if dataItems size is 0 : turn to size 1
    if( size == 0 && capacity == 0 )
    {
        dataItems = new DataType[1] ();
        dataItems[size] = d;
        size = 1;
        capacity = 1;
    }
//    check if there is any capacity : if capacity == 0 double size
    else if( capacity == 0 )
    {
//        doubling size
        int len = size;
        DataType * temp = new DataType[len*2]();
        for(int i = 0; i < len; i++)
        {
            temp[i] = dataItems[i];
        }
        dataItems = temp;
        capacity = len - size;
        //    add to last available spot
        dataItems[size] = d;
        //    update size and capacity
        size += 1;
        capacity -= 1;
        
    }
    else
    {
        //    add to last available spot
        dataItems[size] = d;
        //    update size and capacity
        size += 1;
        capacity -= 1;
    }
}

template <class DataType> DataType Vector<DataType>::elementAt(const int idx) const
{
    try {
        return dataItems[idx];
    } catch (int error) {
        cout << "Accessing idx out of range\n";
        return -1;
    }
}
/**
// Vector manipulation operations
void insertAt (const int index, const DataType item );  // Insert a new element at the given index
void removeAt (const int index );        // Remove the data item at the given index
void remove(DataType item);                   // Remove the given element from the vector
void clear ();                         // Make the vector empty

// Vector status operations
bool isEmpty () const;                  // Is the Vector empty?
bool isFull() const;                    // Is the Vector full?
int  contains(const DataType item) const;    // Does the vector contain the given item? return the index of the item if found, otherwise, return -1.
DataType  elementAt(const int index) const;  // Access the element at the given index
int  getSize() const;                      // Return the number of items in the vector
DataType &operator[] (const int index);   // overloading subscript []
 */
template class Vector<int>;
template class Vector<float>;
template class Vector<char>;
