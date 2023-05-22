#include "include/Icontainer.hpp"
#include "include/pallet.hpp"

class Shelf: public Icontainer{
    public:
    Pallet pallets[4];

    Shelf();
    bool isEmpty() override;
    bool isFull() override;
    bool swapPellet(int slot, int slot2);
};