#include <stdio.h>
#include "Question2.h"

int main()
{
   MyType t1;
   t1 = newObject("Eda",23);
   printInfo(&t1);
   updateName(&t1,"Deha");
   printInfo(&t1);
   updateAge(&t1,14);
   printInfo(&t1);



    return 0;
}
