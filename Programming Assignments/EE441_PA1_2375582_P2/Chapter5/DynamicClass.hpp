#ifndef DYNAMICCLASS_HPP_INCLUDED
#define DYNAMICCLASS_HPP_INCLUDED
template <class T>
class DynamicClass
{
    private:
        // variable of type T and a pointer to data of type T
        T member1;
        T *member2;

    public:
        //constructor with parameters to initialize member data
        DynamicClass(const T &m1, const T &m2);
        //destructor
        ~DynamicClass(void);
        //address
        DynamicClass<T>* Address(void);
        //get members
        void GetMembers (void);
        // Overloaded assignment operator =
        // = returns a reference to the current object
        // this must be a member function, i.e., declared inside the class
        DynamicClass<T>& operator= (const DynamicClass <T>& rhs)
        {
            //copy static data member from rhs to the current object
            member1=rhs.member1;
            // content of the dynamic memory must be same as that rhs
            *member2=*rhs.member2;
            cout<<"Assignment Operator: "<<member1<<'/'<<*member2<<endl;
            return *this;
        }
        // copy constructor
        DynamicClass(const DynamicClass<T>&);

};

template <class T>
DynamicClass<T>::DynamicClass (const T &m1, const T &m2)
{
    // parameter m1 initializes static member
    member1=m1;
    //allocate dynamic memory and initialize it with value m2
    member2=new T(m2);
    cout<<"Constructor:"<<member1<<'/'<<*member2<<endl;
}

template <class T>
DynamicClass<T>::~DynamicClass (void)
{
    cout<<"Destructor:"<<member1<<'/'<<*member2<<endl;
    delete member2;
}

template <class T>
DynamicClass<T>* DynamicClass<T>::Address (void)
{
    return this;
}

template <class T>
void DynamicClass<T>::GetMembers (void)
{
    cout<<"Members:"<<member1<<'/'<<*member2<<"\n";
}


//copy constructor: initialize new object to have the same data as obj.
template <class T>
DynamicClass<T>::DynamicClass(const DynamicClass<T>& obj)
{
    // copy static data member from obj to current object
    member1=obj.member1;
    //allocate dynamic memory and initialize it with value *obj.member2
    member2=new T(*obj.member2);
    cout<<"Copy Constructor:"<<member1<<'/'<<*member2<<endl;
}


#endif // DYNAMICCLASS_HPP_INCLUDED
