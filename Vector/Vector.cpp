//
//  Vector.cpp
//  Vector
//
//  Created by Sheldon May Gunlogson on 1/29/20.
//  Copyright © 2020 Shane May. All rights reserved.
//
#include <iostream>
#include "Vector.hpp"
//#include <array>

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
//    delete dataItems;
//    free(capacity);
//    free(size);
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
    else if( capacity <= 0 )
    {
//        doubling size
        int len = size * 2;
        DataType * temp = new DataType[len]();
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
    if( idx < 0 || idx >= size + capacity)
    {
        exit(0);
    }
    return dataItems[idx];
//    try {
//        return dataItems[idx];
//    } catch (int error) {
//        cout << "Accessing idx out of range\n";
//        return -1;
//    }
}

template <class DataType> DataType &Vector<DataType>::operator[] (const int idx)
{
    if (idx < 0 || idx > size) {
        cout<<"why would you call and index that you know isn't there?\nCome on now.\n";
        exit(0);
    }
    return dataItems[idx];
}

template <class DataType> void Vector<DataType>::insertAt (const int idx, const DataType d )  // Insert a new element at the given index
{
//    checking to see if the array is too small
    int len = size + capacity;
    if(size + 1 > len)
    {
        while(len < idx)
        {
            len *= 2;
        }
        DataType * temp = new DataType[len]();
        for(int i = 0; i < len; i++)
        {
            temp[i] = dataItems[i];
        }
        dataItems = temp;
        capacity = len - size;
    }
//    shifting and inserting the new item
    DataType * copy = new DataType[len]();
    for(int i = 0; i < idx; i++)
    {
        copy[i] = dataItems[i];
    }
    copy[idx] = d;
    for(int i = idx; i < size; i++)
    {
        copy[i+1] = dataItems[i];
    }
    dataItems = copy;
//    update size and compacity
    capacity = len - size;
    size += 1;
}
template <class DataType> int Vector<DataType>::getSize() const  // Return the number of items in the vector
{
    return size + capacity;
}
template <class DataType> void Vector<DataType>::removeAt(const int idx)  // Remove the data item at the given index
{
    int len = size + capacity;
    DataType * copy = new DataType[len];
    for(int i = 0; i < len; i++)
    {
        if(i != idx)
        {
            copy[i] = dataItems[i];
        }
    }
    dataItems = copy;
}
template <class DataType> void Vector<DataType>::remove(DataType item) // Remove the given element from the vector
{
    int len = size + capacity;
    for(int i = 0; i < len; i++)
    {
        if( dataItems[i] == item )
        {
            removeAt(i);
        }
    }
}
template <class DataType> void Vector<DataType>::clear()
{
    capacity = 0;       // the capacity of the vector
    size = 0;        // Actual number of data item in the vector
    dataItems = new DataType[size] ();  // Array containing the vector data item
}
template <class DataType> bool Vector<DataType>::isEmpty() const
{
    return size == 0;
}
template <class DataType> bool Vector<DataType>::isFull() const
{
    return capacity == 0;
}
template <class DataType> int Vector<DataType>::contains(const DataType d) const
{
    int len = size + capacity;
    for(int i = 0; i < len; i++)
    {
        if(dataItems[i] == d)
        {
            return i;
        }
    }
    return -1;
}
/**
// Vector manipulation operations
void clear ();                         // Make the vector empty
// Vector status operations
bool isEmpty () const;                  // Is the Vector empty?
bool isFull() const;                    // Is the Vector full?
int  contains(const DataType item) const;    // Does the vector contain the given item? return the index of the item if found, otherwise, return -1.
 */
template class Vector<int>;
template class Vector<float>;
template class Vector<char>;
