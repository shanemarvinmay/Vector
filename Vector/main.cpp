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
//template <class DataType>

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
    cout << "v[0] : " << v.elementAt(0) << " v[2] : " << v.elementAt(3) << endl;
    return 0;
}
