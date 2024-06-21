#ifndef CHAPTER1_INHERITANCE_HPP_INCLUDED
#define CHAPTER1_INHERITANCE_HPP_INCLUDED



#endif // CHAPTER1_INHERITANCE_HPP_INCLUDED

enum Gender {male, female};

class Person{
    protected:
        Gender gender;
        int age;
    public:
        Person(int a = 0,Gender g = male);
        void Info() const;

};

class Parent:public Person{
    private:
        int children;
    public:
        Parent(int a = 20, Gender g = female, int c = 0);
        void Info() const;
        void update();
};

