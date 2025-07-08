#include <iostream>
#include "Item.h"
using namespace std;

int main() 
{
    Item item1("AMD CPU", 107);
    Item item2("NVIDIA GPU", 55);

    item1.display();
    item2.display();

    return 0;
}
