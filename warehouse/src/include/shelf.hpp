#pragma once
#include "pallet.hpp"

class Shelf: public Icontainer{
    public:
    int palletSize;
    Pallet pallets[4];

    Shelf();
    bool isEmpty() override;
    bool isFull() override;
    int checkMostFullPallet(int index);
    bool swapPellet(int slot, int slot2);
};