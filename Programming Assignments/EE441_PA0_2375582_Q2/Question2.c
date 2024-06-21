#include <stdio.h>
#include <string.h>
#include "Question2.h"


MyType newObject(const char* name, const int age)
{
    MyType type1;

    strcpy(type1.name,name);
    type1.age = age;

    return type1;
}

void printInfo(const MyType* object){

    printf("%s is %d years old.\n",object->name,object->age);
}
void updateName(MyType* object, const char* newName){

    strcpy(object->name, newName);

}

void updateAge(MyType* object, const int age){

    object->age = age;

}
