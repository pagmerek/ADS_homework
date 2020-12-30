#include <iostream>
#include "minstack.hpp"
minStack::minStack(int len):len(len){
    min = __INT_MAX__;
    cnt = -1;
    min_index = 0;
    data = new int[len];
    minind = new int[len];
}
void minStack::push(int x){
    cnt++;
    data[cnt] = x;
    if(x < min){
        min_index = cnt;
        min = x; 
    }
    minind[cnt] = min_index;

}
int minStack::pop(){
    cnt--;
    return data[cnt+1];
}
void minStack::uptomin(){
    cnt = minind[cnt] - 1;
}
void minStack::print(){
    for(int i = 0; i<=cnt; i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    auto* stack = new minStack(20);
    std::cout<<"Push operations"<<std::endl;
    stack->push(7);
    stack->push(8);
    stack->push(3);
    stack->push(5);
    stack->push(2);
    stack->print();
    std::cout<<"uptomin deletes 2"<<std::endl;
    stack->uptomin();
    stack->print();
    std::cout<<"uptomin deletes 3 and 5"<<std::endl;
    stack->uptomin();
    stack->print();
    std::cout<<"pop 8 and push 0"<<std::endl;
    stack->pop();
    stack->push(0);
    stack->print();

}