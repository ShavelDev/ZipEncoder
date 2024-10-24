//
//  main.cpp
//  ZipEncoder
//
//  Created by Norbert Szawloga on 20/10/2024.
//

#include <iostream>
#include <vector>
#include <assert.h>
#include <bitset>
#include <map>
#include "HuffmanCodesProvider.hpp"
#include "Tester.hpp"
using namespace std;



//void printVector(vector<bool> vector ){
//    for (int i = 0; i < vector.size(); i++) {
//        cout << vector[i];
//    }
//    
//    cout << endl;
//}

int main(int argc, const char * argv[]) {
    // insert code here...
//    
//    FixedHuffmanCodeProvider fcp;
//    
//    
//    vector<bool> code = fcp.intToVector(11, 3);
//    
//    for (int i = 0; i < code.size(); i++) {
//        cout << code[i] << endl;
//    }
//    
//    cout << endl << endl;
//    
//    
//    
//    vector<bool> lenCode = fcp.getLenCode(25);
//    printVector(lenCode);
//    
//    
//    cout << endl << endl;
//    
//    
//    vector<bool> litCode = fcp.getLiteralCode(0);
//    printVector(litCode);
//    
//    
//    cout << endl << endl;
    
    Tester t;
    
    t.testHCodesLength();
    
    t.testHcodesDistance();
    return 0;
}
