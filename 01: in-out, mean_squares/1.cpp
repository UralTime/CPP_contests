class Sum {
    int x, y;
public:
    Sum (int a, int b): x(a), y(b) {}
    Sum (Sum s, int c): x(s.get()), y(c) {}
    
    int get() const { 
        return x + y;
    }    
};
