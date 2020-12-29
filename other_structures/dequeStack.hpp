
class dequeStack{
    private:
    struct num{
        int x;
        num* helper;
        num* next;
        num* prev;
    };
    struct stack{
        num* top = nullptr;
        num* pop();
        void push(num* x);
        bool isEmpty();
    };  
   int len;
   num* head;
   num* tail;
   stack* stackTable;
   
   public:
   dequeStack(int len);
   void push(int num);
   void pop();
   bool search(int num);
   void del(int num);
};