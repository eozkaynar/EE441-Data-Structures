#include <stdio.h>
#include <string.h>

typedef struct myType {
 char name[10];
 int age;
} MyType;



MyType newObject(const char* name, const int age);
void updateName(MyType* object, const char* newName);
void updateAge(MyType* object, const int age);
void printInfo(const MyType* object);
