#pragma once
#include "array"

template <class Type, int Size> class MyArray {
private:
    Type liste[Size];

public:

    int getSize() { return Size; }
    
    Type& at(int n) {
        if (n >= Size || n<=0) {
            throw std::invalid_argument("Indeksen finnes ikke i lista");
        } else {
            return liste[n];
        }
    }
    void fill(Type value) {
        for (Type& el : liste) {
            el = value;
        }
    }
};