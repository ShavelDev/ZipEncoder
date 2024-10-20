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
using namespace std;

class FixedHuffmanCodeProvider{
private:
    //The numbers at the end of the function name represent the max value of the each variable
    vector<bool> getCode143(int val){
        return getCodeOf(val + 48, 8);
    }
    
    vector<bool> getCode255(int val){
        return getCodeOf(val + 400 - 144, 9);
    }
    
    vector<bool> getCode279(int val){
        
        
        return getCodeOf(val, 7);
    }
    
    vector<bool> getCode287(int val){
        
        
        return getCodeOf(192 + val - 280, 8);
    }
    
    
    int numToVector(int val){
        return 0 ;
    }
    
    
    
    int getLenght(int len){
        return 257 + len;
    }
    
    
    
    
    
    
    
public:
    
    vector<bool> getCodeOf(int len, int size){
        
        
        vector<bool> boolVector(size, false);

        for (int i = 0; i < size; ++i) {
            // Set the ith bit
            boolVector[i] = (len & (1 << ((size-1) - i))) != 0;
        }

        return boolVector;
    }
    
    vector<bool> getLiteralCode(int val){
        if (val < 144) {
            return getCode143(val);
        }else if(val < 256){
            return getCode255(val);
        }
        else if(val < 280){
            return getCode279(val);
        }
        else if(val < 288){
            return getCode287(val);
        }else{
            assert(false);
            return {};
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    FixedHuffmanCodeProvider fcp;
//    cout << bitset<8>(fcp.getLiteralCode(193)) << endl<< endl;
//    cout << bitset<8>(fcp.getLiteralCode(0)) << endl;
//    cout << bitset<8>(fcp.getLiteralCode(143)) << endl << endl;
//    
//    
//    cout << (fcp.getLiteralCode(144)) << endl;
//    cout << (fcp.getLiteralCode(255)) << endl;
//    cout << bitset<9>(fcp.getLiteralCode(144)) << endl;
//    cout << bitset<9>(fcp.getLiteralCode(255)) << endl << endl;
//    
//    cout << bitset<7>(fcp.getLiteralCode(256)) << endl;
//    cout << bitset<7>(fcp.getLiteralCode(279)) << endl << endl;
//    
//    cout << bitset<8>(fcp.getLiteralCode(280)) << endl;
//    cout << bitset<8>(fcp.getLiteralCode(287)) << endl << endl;
    
    
    vector<bool> code = fcp.getCodeOf(11, 3);
    
    for (int i = 0; i < code.size(); i++) {
        cout << code[i] << endl;
    }
    
    
    
    return 0;
}
