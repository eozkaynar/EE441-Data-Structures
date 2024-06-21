#include <iostream>
#include "Chapter1_Inheritance.hpp"

Person::Person(int a, Gender g): age(a), gender(g){
}
Parent::Parent(int a, Gender g,int c):Person(a,g),children(c){
}
void Person::Info() const{
    std::cout <<" Age: "<< age;
    std::cout <<" Gender: ";
        if(gender == male)
            std::cout<< "male";
        else
            std::cout<< "female";
        std::cout<<std::endl;

}
void Parent::Info() const{
    Person::Info();
    std::cout << ", Number of children: "<<children<<std::endl;
}

void Parent::update(){
    std::cout<<" Age: ";
    std::cin >>age;
    int gender_input;
    std::cout<<" Gender (male = 0, female = 1) ";
    std::cin >>gender_input;
    if (gender_input == 0)
        gender = male;
    else
        gender = female;

    std::cout<<" Number of children: ";
    std::cin >> children;

}

int main(){

    Person person1(10,male);
    Parent parent1(35,female,5);
    person1.Info();
    parent1.Info();

    parent1.update();
    parent1.Info();

    return 0;

}
