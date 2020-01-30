//
//  main.cpp
//  Vector
//
//  Created by Sheldon May Gunlogson on 1/29/20.
//  Copyright © 2020 Shane May. All rights reserved.
//

#include <iostream>
#include "Vector.hpp"
using namespace std;

template <class DataType>
void print(Vector<DataType> v)
{
    int len = v.getSize();
    for(int i = 0; i < len; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
template class Vector<int>;
template class Vector<float>;
template class Vector<char>;

int main(int argc, const char * argv[]) {
    cout << "Program start!\n";
    Vector<int>  v;// = new Vector<int>();
    /**
     TESTING APPEND
     */
    cout << "~~~~~~~~~~~~~~~~~~\n" << "TESTING APPEND\n";
    v.append(666);
    v.append(777);
    v.append(1);
    cout << "v[0] : " << v.elementAt(0) << " v[1] : " << v.elementAt(1)  << " v[2] : " << v.elementAt(2) << endl;
    /**
     TESTING ELEMENT_AT
     */
    cout << "~~~~~~~~~~~~~~~~~~\n" << "TESTING ELEMENT_AT\n";
    cout << "v[0] : " << v.elementAt(0) <</* " v[4] : " << v.elementAt(4) <<*/ endl;
    /**
     TESTING [] OPERATOR
     */
    cout << "~~~~~~~~~~~~~~~~~~\n" << "TESTING [] OPERATOR\n";
    cout << "v[0] : " << v[0] <</* " v[4] : " << v[4] <<*/ endl;
    /**
     TESTING INSERT AT
     */
    cout << "~~~~~~~~~~~~~~~~~~\n" << "TESTING TESTING INSERT AT\n";
    v.insertAt(0,1);
    v.insertAt(1,2);
    print(v);
    /**
     TESTING REMOVE AND REMOVE AT
     */
    cout << "~~~~~~~~~~~~~~~~~~\n" << "TESTING REMOVE AND REMOVE AT\n";
    v.removeAt(0);
    v.remove(1);
    print(v);
    /**
     TESTING CONTAINS,  IS FULL, CLEAR,  IS EMPTY
     */
    cout << "~~~~~~~~~~~~~~~~~~\n" << "TESTING CONTAINS, IS FULL, CLEAR, IS EMPTY\n";
    cout << "v.contains(777) : " << v.contains(777) << endl;
    cout << "v.contains(-1) : " << v.contains(-1) << endl;
    v.clear();
    v.append(0);
    v.append(1);
    cout << "v.isFull() : " << v.isFull() << endl;
    print(v);
    v.clear();
    cout << "v.isEmpty() : " << v.isEmpty() << endl;
    print(v);
    
    
    
    
    
    
    
    return 0;
}
