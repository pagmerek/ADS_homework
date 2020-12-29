//1.28
class Vector{
private:
    int* vec;
    int* from;
    int* to;
    int top;
    int init_val;
    int len;
public:     
    Vector(int n);

    int& operator[](int n);

    ~Vector();

    int select(int i);
    bool search(int i);
    void insert(int i);
    void print();
};