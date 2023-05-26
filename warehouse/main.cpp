#include <iostream>
#include "src/include/warehouse.hpp"

int main(void){
    std::cout << "Hello world" << std::endl;

    Shelf shelf2 = Shelf();
    Pallet pallet5("Books", 100, 0);
    Pallet pallet6("Books", 100, 0);
    Pallet pallet7("Books", 100, 1);
    Pallet pallet8("Books", 100, 0);
    shelf2.pallets[0] = pallet5;
    shelf2.pallets[1] = pallet6;
    shelf2.pallets[2] = pallet7;
    shelf2.pallets[3] = pallet8;
    std::cout << shelf2.checkLeastFullPallet(1);
};
