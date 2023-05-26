#pragma once
#include "include/shelf.hpp"
#include <iostream>

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
    int min = 0;
    for ( index ;index < 4; index++){
        if (this->pallets[min].getItemCount() > this->pallets[index].getItemCount()){
            min = index;
        }
    }
    return min;
}

bool Shelf::swapPallet(int slot, int slot2){
    if ((slot < 0) || (slot >= 4) || (slot2 < 0) || (slot2 >= 4)){
        return false;
    };
    Pallet pallet1 = this->pallets[slot];
    Pallet pallet2 = this->pallets[slot2];
    this->pallets[slot] = pallet2;
    this->pallets[slot2] = pallet1;
    return true;
};