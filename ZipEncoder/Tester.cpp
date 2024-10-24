//
//  Tester.cpp
//  ZipEncoder
//
//  Created by Norbert Szawloga on 24/10/2024.
//

#include "Tester.hpp"

void printVector(vector<bool> vector ){
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i];
    }
    
    cout << endl;
}

bool compareVectors(vector<bool> v1, vector<bool> v2){
    
    if (v1.size() != v2.size()) {
        return false;
    }
    
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    
    return true;
    
}


vector<bool> writeVector(string code){
    vector<bool> newVec;
    
    for(char c : code){
        if(c == ' ') continue;
        newVec.push_back(c == '0' ? 0 : 1);
    }
    
    return newVec;
};


void Tester::testHCodesLength(){
    FixedHuffmanCodeProvider hp;

    
    vector<bool> c1 = hp.getLenCode(10);
    vector<bool> c2 = writeVector("0001000");
    
    
    
    if(c1 != c2){
        printVector(c1);
        cout <<" not similar with" << endl;
        printVector(c2);
        assert(false);
    }
    
    c1 = hp.getLenCode(193);
    c2 = writeVector("11000010 11110");
    
    if(c1 != c2){
        assert(false);
    }
    
    c1 = hp.getLenCode(3);
    c2 = writeVector("0000001");
    
    if(c1 != c2){
        assert(false);
    }
    
    c1 = hp.getLenCode(45);
    c2 = writeVector("0010010 010");
    
    if(c1 != c2){
        assert(false);
    }
    
    c1 = hp.getLenCode(114);
    c2 = writeVector("0010111 1111");
    
    if(c1 != c2){
        assert(false);
    }
    
    c1 = hp.getLenCode(115);
    c2 = writeVector("11000000 0000");
    
    if(c1 != c2){
        assert(false);
    }
    
    c1 = hp.getLenCode(12);
    c2 = writeVector("0001001 1");
    
    if(c1 != c2){
        assert(false);
    }
        
    
};

void Tester::testHcodesDistance(){
    cout << "testing distance hcodes" << endl;
    FixedHuffmanCodeProvider hp;

    
    vector<bool> c1 = hp.getDistanceCode(1);
    vector<bool> c2 = writeVector("00000");
    
    
    
    if(c1 != c2){
        printVector(c1);
        cout <<" not similar with" << endl;
        printVector(c2);
        assert(false);
    }
    
    c1 = hp.getDistanceCode(16);
    c2 = writeVector("00111 11");
    
    
    
    if(c1 != c2){
        printVector(c1);
        cout <<" not similar with" << endl;
        printVector(c2);
        assert(false);
    }
    
    c1 = hp.getDistanceCode(31);
    c2 = writeVector("01001 110");
    
    
    
    if(c1 != c2){
        printVector(c1);
        cout <<" not similar with" << endl;
        printVector(c2);
        assert(false);
    }
    
    c1 = hp.getDistanceCode(10000);
    c2 = writeVector("11010  0111 0000 1111");
    
    
    
    if(c1 != c2){
        printVector(c1);
        cout <<" not similar with" << endl;
        printVector(c2);
        assert(false);
    }
    

    
    
    c1 = hp.getDistanceCode(16384);
    c2 = writeVector("11011 111111111111");
    
    
    
    if(c1 != c2){
        printVector(c1);
        cout <<" not similar with" << endl;
        printVector(c2);
        assert(false);
    }
    
    c1 = hp.getDistanceCode(16);
    c2 = writeVector("00111 11");
    
    
    
    if(c1 != c2){
        printVector(c1);
        cout <<" not similar with" << endl;
        printVector(c2);
        assert(false);
    }
    
    c1 = hp.getDistanceCode(16);
    c2 = writeVector("00111 11");
    
    
    
    if(c1 != c2){
        printVector(c1);
        cout <<" not similar with" << endl;
        printVector(c2);
        assert(false);
    }
};
