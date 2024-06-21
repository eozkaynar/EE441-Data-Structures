#include "X.hpp"

template <class T> //Initializing constructor
X<T>::X (const int nn, const T &item)
{
	n=nn;
	if(n)
	{
		p=new T [n];
		for (int i=0; i<n; i++)
			*(p+i)=item;
	}
}

template <class T> //Copy constructor
X<T>::X (const X<T> &xx)
{
	n=xx.n;
	if(n)
	{
		p=new T [n];
		for (int i=0; i<n; i++)
			*(p+i)=*(xx.p+i);
	}
}

template <class T> //destructor
X<T>::~X(void)
{
	if(n)
		delete [ ] p;
}

template <class T> //Overloaded assignment
X<T> &X<T>:: operator =(const X<T> &r)
{
	if(n)
		delete [ ] p;
	n=r.n;
	if(n)
	{
		p=new T [n];
		for (int i=0; i<n; i++)
			*(p+i)=*(r.p+i);
	}
	return *this;
}

template class X<int>;

