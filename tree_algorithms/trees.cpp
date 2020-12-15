#include "main.h"
#include <iostream>

BST::node* BST::insert(int value, node* to){
    if(to == nullptr){
        to = new node;
        to->value = value;
        to->left = to->right = nullptr;
    }
    else if(value > to->value) to->right = insert(value,to->right);
    else if(value < to->value) to->left = insert(value,to->left);
    return to;
}
BST::node* BST::remove(int value,node* from){
    if(from == nullptr) return nullptr;
    else if(value > from->value) from->right = remove(value,from->right);
    else if(value < from->value) from->left = remove(value,from->left);
    else if(from->left != nullptr && from->right != nullptr){
        node* temp = from;
        while(temp->left != nullptr) temp = temp->left;
        from->value = temp->value;
        from->right = remove(from->value, from->right);
    }
    else{
        node* temp = from;
        if(temp->left == nullptr) from = from->right;
        else if(temp->right == nullptr) from = from->left;
        delete temp;
    }
    return from;
}

AVL::node* AVL::single_right_rotate(node* &what){
    node* temp = what->left;
    what->left = temp->right;
    temp->right = what;
    temp->height = std::max(get_height(temp->left),what->height)+1;
    what->height = std::max(get_height(temp->right), get_height(what->left))+1;
    return temp;
}

AVL::node* AVL::single_left_rotate(node* &what){
    node* temp = what->right;
    what->right = temp->left;
    temp->left = what;
    temp->height = std::max(get_height(temp->right),what->height)+1;
    what->height = std::max(get_height(temp->right), get_height(what->left))+1;
    return temp;
}

AVL::node* AVL::double_left_rotate(node* &what){
   what->right = single_right_rotate(what->left);
   return single_left_rotate(what);
}

AVL::node* AVL::double_right_rotate(node* &what){
    what->left = single_left_rotate(what->left);
    return single_right_rotate(what);
}

int AVL::get_height(node* of){
    if(of == nullptr) return  -1;
    return of->height;
}

int AVL::get_balance(node* of){
    return (of==nullptr) ? 0: get_height(of->left)- get_height(of->right);
}

AVL::node* AVL::insert(int key, node* at){
    if(at == nullptr){
        at = new node;
        at->value = key;
        at->height = 0;
        at->left = at->right = nullptr;
    }
    else if(key > at->value){
        at->right = insert(key,at->right);
        if(get_height(at->right) - get_height(at->left) == 2){
            at = (key > at->right->value) ? single_left_rotate(at): double_left_rotate(at);
        }
    }
    else if(key < at->value){
        at->left = insert(key,at->left);
        if(get_height(at->left) - get_height(at->right) == 2){
            at = (key < at->right->value) ? single_right_rotate(at): double_right_rotate(at);
        }
    }

    at->height = std::max(get_height(at->left),get_height(at->right))+1;
    return at;
}

AVL::node* AVL::remove(int key, node* at){
    node* temp;

    if(at == nullptr) return nullptr;
    else if(key < at->value) at->left = remove(key, at->left);
    else if(key > at->value) at->right = remove(key, at->right);
    
    //zadny if sie nie zapalił wiec znaleziony element

    else if(at->left && at->right){
         temp = at->right;
         while(temp->left != nullptr) temp = temp->left;
         at->value = temp->value;
         at->right = remove(at->value, at->right);
    }
    else{
        temp = at;
        if(at->left == nullptr) at = at->right;
        else at = at->left;
        delete temp;
    }
    if(at == nullptr) return at;

    at->height = std::max(get_height(at->left), get_height(at->right))+1;

    //pozostało zbalansować drzewo

    if(get_height(at->left)) - get_height(at->right == 2){
        return (get_height(at->left->left)) - get_height(at->left->right == 1) ? single_left_rotate(at):double_left_rotate(at);
    }
    else if(get_height(at->right) - get_height(at->left) == 2){
        return (get_height(at->right->right)-get_height(at->right->left)==1) ? single_right_rotate(at):double_right_rotate(at);
    }
    return at;
}

