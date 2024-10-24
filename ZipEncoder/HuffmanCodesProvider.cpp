//
//  HuffmanCodesProvider.cpp
//  ZipEncoder
//
//  Created by Norbert Szawloga on 24/10/2024.
//

#include "HuffmanCodesProvider.hpp"



int FixedHuffmanCodeProvider::getExtraBitsDistance(int val){
    
    
    int code = 0;
    
    for (const auto& pair : maxValueCodeDistance) {
        if(val < pair.first){
            code = pair.second;
        }
    }
    
    if(code < 4) return 0;
    
    
    
    return ((code - 4)/2 + 1);
}

int FixedHuffmanCodeProvider::getExtraBitsLength(int val){
    
    
    int code = 0;
    
    for (const auto& pair : maxValueCode) {
        if(val < pair.first){
            code = pair.second;
        }
    }
    
    if(code == 285) return 0;
    
    
    
    return ((code - 265)/4 + 1);
}

vector<bool> FixedHuffmanCodeProvider::getCode143(int val){
    return intToVector(val + 48, 8);
}

vector<bool> FixedHuffmanCodeProvider::getCode255(int val){
    return intToVector(val + 400 - 144, 9);
}

vector<bool> FixedHuffmanCodeProvider::getCode279(int val){
    
    
    return intToVector(val - 256, 7);
}

vector<bool> FixedHuffmanCodeProvider::getCode287(int val){
    
    
    return intToVector(192 + val - 280, 8);
}

vector<bool> FixedHuffmanCodeProvider::getCode5Bit(int val){
    return intToVector(val, 5);
}

vector<bool> FixedHuffmanCodeProvider::getLenCode(const int len){
    
    if(len < 3){
        assert(false);
    }
    
    
    int litCode = 0;
    int maxVal = 0;
    for (const auto& pair : maxValueCode) {
        if(len <= pair.first){
            maxVal = pair.first;
            litCode = pair.second;
            break;
        }
    }
    
    cout << "literal code: " << litCode << endl;
    cout << "max val: " << maxVal << endl;

    
    if (len < 11){

        vector<bool> mainCode = getCode279(litCode);
        return mainCode;
    }else if(len < 19){
        vector<bool> mainCode = getCode279(litCode);
        
        if(len % 2 == 0){
            mainCode.push_back(true);
        }else{
            mainCode.push_back(false);
        }
        
        return mainCode;
    }
    else if(len < 35){
        
        vector<bool> mainCode = getCode279(litCode);
        
        vector<bool> extraBits = intToVector(3-maxVal+len, 2);
        
        for (int i = 0; i < extraBits.size(); i++) {
            mainCode.push_back(extraBits[i]);
        }
        
        return mainCode;
    }
    else if(len < 67){
        vector<bool> mainCode = getCode279(litCode);
        
        vector<bool> extraBits = intToVector(7-maxVal+len, 3);
        
        for (int i = 0; i < extraBits.size(); i++) {
            mainCode.push_back(extraBits[i]);
        }
        
        return mainCode;
    }
    else if(len < 115){
        vector<bool> mainCode = getCode279(litCode);
        
        vector<bool> extraBits = intToVector(15-maxVal+len, 4);
        
        for (int i = 0; i < extraBits.size(); i++) {
            mainCode.push_back(extraBits[i]);
        }
        
        return mainCode;
    }
    else if(len < 131){
        vector<bool> mainCode = getCode287(litCode);
        
        vector<bool> extraBits = intToVector(15-(maxVal-len), 4);
        
        for (int i = 0; i < extraBits.size(); i++) {
            mainCode.push_back(extraBits[i]);
        }
        
        return mainCode;
    }
    else if(len < 258){
        vector<bool> mainCode = getCode287(litCode);
        
        vector<bool> extraBits = intToVector(31-maxVal+len, 5);
        
        for (int i = 0; i < extraBits.size(); i++) {
            mainCode.push_back(extraBits[i]);
        }
        
        return mainCode;
    }
    
    assert(false);
}

vector<bool> FixedHuffmanCodeProvider::intToVector(int len, int size){
    
    
    vector<bool> boolVector(size, false);

    for (int i = 0; i < size; ++i) {
        // Set the ith bit
        boolVector[i] = (len & (1 << ((size-1) - i))) != 0;
    }

    return boolVector;
}

vector<bool> FixedHuffmanCodeProvider::getLiteralCode(int val){
    if (val < 144) {
        return getCode143(val);
    }else if(val < 256){
        return getCode255(val);
    }
    else if(val == 256){
        return getCode279(val);
    }
    else{
        assert(false);
        return {};
        
    }
}

vector<bool> FixedHuffmanCodeProvider::getDistanceCode(int dis){
    int litCode = 0;
    int maxVal = 0;
    for (const auto& pair : maxValueCodeDistance ){
        if(dis <= pair.first){
            maxVal = pair.first;
            litCode = pair.second;
            break;
        }
    }
    cout << "literal code: " << litCode << endl;
    cout << "max val: " << maxVal << endl;
    
    vector<bool> litVec = intToVector(litCode, 5);
    
    if (dis < 5) {
        return litVec;
    }
    
    int extraBitsNum = ((litCode - 4)/2 + 1);
    int maxValOfExtraBits = pow(2, extraBitsNum+1)-1;
    vector<bool> extraBits = intToVector(maxValOfExtraBits - (maxVal - dis), extraBitsNum);
    

    for (int i = 0; i < extraBits.size(); i++) {
        litVec.push_back(extraBits[i]);
    }
    
    return litVec;
    
}
