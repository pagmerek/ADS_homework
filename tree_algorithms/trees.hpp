class BST{
    struct node{
        int value;
        node* left;
        node* right;
    };

    node* root;

    node* insert(int to_insert, node* at);

    node* remove(int to_remove, node* from);
};
class AVL{

    struct node{
        int value;
        int height;
        node* left;
        node* right;
    };
    node* root;
    
    node* insert(int to_insert, node* at);
    node* remove(int to_remove, node* from);
    node* single_right_rotate(node* &what);
    node* single_left_rotate(node* &what);
    node* double_left_rotate(node* &what);
    node* double_right_rotate(node* &what);
    int get_height(node* of);
    int get_balance(node* of);
};
class BRT{
       public:
    enum color { BLACK, RED };
    struct node{
        node* parent;
        node* left;
        node* right;
        enum color col;
        int key;
    };
    node* get_parent(node* n);
    node* get_grandparent(node* n);
    node* get_sibling(node* n);
    node* get_uncle(node* n);

    void left_rotate(node* n);
    void right_rotate(node* n);

    node* insert(node* to_insert,int value);
    node* remove(node* to_remove);
    void insert_fix(node* n);
    void double_black_fix(node* n);
    

    node* root;
    
};