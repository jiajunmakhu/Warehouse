#include "include/Icontainer.hpp"
#include "include/pallet.hpp"

class Shelf: public Icontainer{
    public:
    int palletSize;
    Pallet pallets[4];

    Shelf();
    bool isEmpty() override;
    bool isFull() override;
    int checkLeastFullPallet(int index);
    bool swapPellet(int slot, int slot2);
};