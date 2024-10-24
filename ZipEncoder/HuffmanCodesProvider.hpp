//
//  HuffmanCodesProvider.hpp
//  ZipEncoder
//
//  Created by Norbert Szawloga on 24/10/2024.
//

#pragma once

#include <iostream>
#include <map>
#include <assert.h>
using namespace std;

class FixedHuffmanCodeProvider{
private:
    
    const map<int,int> maxValueCodeDistance = {
        {1,0},
        {2,1},
        {3,2},
        {4,3},
        {6,4},
        {8,5},
        {12,6},
        {16,7},
        {24,8},
        {32,9},
        {48,10},
        {64,11},
        {96,12},
        {128,13},
        {192,14},
        {256,15},
        {384,16},
        {512,17},
        {768,18},
        {1024,19},
        {1536,20},
        {2048,21},
        {3072,22},
        {4096,23},
        {6144,24},
        {8192,25},
        {12288,26},
        {16384,27},
        {24576,28},
        {32768,29}
        
        
    };
    
    const map<int, int> maxValueCode = {
        {3,257},
        {4,258},
        {5,259},
        {6,260},
        {7,261},
        {8,262},
        {9,263},
        {10,264},
        {12,265},
        {14,266},
        {16,267},
        {18,268},
        {22,269},
        {26,270},
        {30,271},
        {34,272},
        {42,273},
        {50,274},
        {58,275},
        {66,276},
        {82,277},
        {98,278},
        {114,279},
        {130,280},
        {162,281},
        {194,282},
        {226,283},
        {257,284},
        {258,285}
    };
    
    int getExtraBitsDistance(int val);
    
    int getExtraBitsLength(int val);
    
    
    
    //The numbers at the end of the function name represent the max value of the each variable
    vector<bool> getCode143(int val);
    
    vector<bool> getCode255(int val);
    
    vector<bool> getCode279(int val);
    
    vector<bool> getCode287(int val);
    
    vector<bool> getCode5Bit(int val);
    
    
    
       
public:
    
    vector<bool> getLenCode(const int len);
    
    vector<bool> intToVector(int len, int size);
    
    vector<bool> getLiteralCode(int val);
    
    vector<bool> getDistanceCode(int dis);
};
