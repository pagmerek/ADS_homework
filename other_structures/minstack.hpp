class minStack{
private:
    int* data;
    int* minind;
    int min;
    int min_index;
    int cnt;
    int len;
public:
    minStack(int len);
    int pop();
    void push(int x);
    void uptomin();
    void print();
};