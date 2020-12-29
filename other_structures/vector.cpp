#include <iostream>
#include "Vector.hpp"


Vector::Vector(int n){
    len = n;
    vec = new int[n];
    from = new int [n];
    to = new int [n];
    top = 0;
    init_val = 0;
}
int& Vector::operator[](int n){
    if(from[n]<top && to[from[n]==n]) return vec[n];
    else{
        from[n] = top;
        to[top] = n;
        vec[n] = init_val;
        top++;

        return vec[n];
    }
}
Vector::~Vector(){
    delete[] vec;
    delete[] from;
    delete[] to;
}

void Vector::insert(int i){
    (*this)[i] = 1;
}
bool Vector::search(int i){
    return (*this)[i] == 1;
}
int Vector::select(int i){
    (*this)[i] = 0;
    return i;
}
void Vector::print(){
    for(int i = 0; i<len; i++){
        if((*this)[i]!=0){
            std::cout<<i<<std::endl;
        }
    }
}
int main(){
    auto first_structure = Vector(10);
    first_structure.insert(4);
    first_structure.insert(6);
    first_structure.insert(1);
    first_structure.print();
    first_structure.select(4);
    first_structure.print();
}