#include <string>
#include "include/Icontainer.hpp"

class Pallet : public Icontainer{
    private:
    int itemCount;
    std::string itemName;
    int itemCapacity;

    public:

    Pallet(std::string itemName, int itemCapacity, int itemCount);
    Pallet();
    bool isEmpty() override;
    bool isFull() override;
    std::string getItemName();
    int getItemCount();
    int getRemainingSpace();
    bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
    bool takeOne();
    bool putOne();
};