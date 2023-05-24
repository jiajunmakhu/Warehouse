#include "include/shelf.hpp"

Shelf::Shelf(){
    int palletSize = 4;
    Pallet pallets[palletSize];
};

bool Shelf::isEmpty(){
    bool empty = true;
    for (Pallet pallet: this->pallets){
        if (!pallet.isEmpty()){
            empty = false;
            break;
        }
    }
    return empty;
};

bool Shelf::isFull(){
    bool full = true;
    for (Pallet pallet: this->pallets){
        if (!pallet.isFull()){
            full = false;
            break;
        }
    }
    return full;
};

int Shelf::checkLeastFullPallet(int index){
    int max = 0;
    for (int i = index; i < palletSize; i++){
        if (pallets[max].getItemCount() < pallets[i].getItemCount()){
            max = i;
        }
    }
    return max;
}

bool Shelf::swapPellet(int slot, int slot2){
    Pallet pallet1 = this->pallets[slot];
    Pallet pallet2 = this->pallets[slot2];
    this->pallets[slot] = pallet2;
    this->pallets[slot2] = pallet1;
    return true;
};