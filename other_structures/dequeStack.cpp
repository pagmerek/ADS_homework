#include "dequeStack.hpp"
dequeStack::dequeStack(int len):len(len){
    stackTable = new stack[len];
    head = new num;
    tail = new num;
    head->next = tail;
    tail->prev = head;

}
dequeStack::num* dequeStack::stack::pop(){
    auto* temp = new num;
    temp->helper = top->helper;
    temp->x = top->x;
    auto* prev = top->prev;
    delete top;
    top = prev;
    return temp;
}
void dequeStack::stack::push(num* x){
    top->next = x;
    x->prev = top;
    top = x;
}
bool dequeStack::stack::isEmpty(){
    return top == nullptr;
}
void dequeStack::push(int num){
    auto* que = new dequeStack::num;
    auto* sta = new dequeStack::num;
    que->x = num;
    sta->x = num;
    que->helper = sta;
    sta->helper = que;
    stackTable[num].push(sta);
    que->next = head->next;
    head->next->prev = que;
    head->next = que;
    que->prev = head;
}
void dequeStack::pop(){
    num* temp = head->next;
    head->next = head->next->next;
    head->next->prev = head;
    stackTable[temp->x].pop();
}
bool dequeStack::search(int num){
    return !stackTable[num].isEmpty();
}
void dequeStack::del(int num){
    dequeStack::num* temp = stackTable[num].pop();
    dequeStack::num* toDel = temp->helper;
    toDel->next->prev = toDel->prev;
    toDel->prev->next = toDel->next;
    delete temp;
    delete toDel;
}