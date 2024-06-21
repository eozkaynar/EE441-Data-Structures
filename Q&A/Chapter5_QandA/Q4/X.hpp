template <class T>
class X
{
    public:
        int n; // number of items in the dynamic array
        T *p; // dynamic array
        /* initializing constructor initializes all entries in the dynamic
        array of size nn identically as item */
        X (const int nn, const T &item);
        X (const X<T> &xx);
        ~X(void);
        X<T> &operator =(const X<T> &r);
};
