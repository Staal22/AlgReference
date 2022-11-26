#include "HashTable/HashTable.h"
#include <iostream>

int main()
{

    HashTable HT;
    if (HT.IsEmpty()) {
        std::cout << "COrrect anwser" << std::endl;
    }
    else {
        std::cout << "Ops"  << std::endl;
    }

    HT.InsertItem(905, "Jim");
    HT.InsertItem(904, "Aim");
    HT.InsertItem(505, "Bim");
    HT.InsertItem(902, "Cim");
    HT.InsertItem(501, "Dim");
    HT.InsertItem(1306, "Eim");

    HT.Print();

    HT.RemoveItem(905);
    HT.RemoveItem(100);
    
    if (HT.IsEmpty()) {
        std::cout << "Ops!" << std::endl;
    }
    else {
        std::cout << "Correct"  << std::endl;
    }
    return 0;
}
