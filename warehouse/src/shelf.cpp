#include "include/shelf.hpp"

Shelf::Shelf(){
    Pallet pallets[4];
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

bool Shelf::swapPellet(int slot, int slot2){
    Pallet pallet1 = this->pallets[slot];
    Pallet pallet2 = this->pallets[slot2];
    this->pallets[slot] = pallet2;
    this->pallets[slot2] = pallet1;
    return true;
};