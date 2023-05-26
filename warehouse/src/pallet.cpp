#pragma once
#include "include/pallet.hpp"


Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount): itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount){};

Pallet::Pallet(): itemName(""), itemCapacity(0), itemCount(0){};

bool Pallet::isEmpty(){
    if (this->itemCount == 0){
        return true;
    }
    else{
        return false;
    }
};

bool Pallet::isFull(){
    if (this->itemCount == this->itemCapacity){
        return true;
    }
    else{
        return false;
    }
};

std::string Pallet::getItemName(){
    return this->itemName;
};

int Pallet::getItemCount(){
    return this->itemCount;
};

int Pallet::getRemainingSpace(){
    return this->itemCapacity - this->getItemCount();
};

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity){
    if (this->isEmpty()){
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;
        return true;
    }
    return false;
};

bool Pallet::takeOne(){
    if (!this->isEmpty()){
        this->itemCount-=1;
        return true;
    }
    else{
        return false;
    }
};

bool Pallet::putOne(){
    if (!this->isFull()){
        this->itemCount += 1;
        return true;
    }
    else{
        return false;
    }
};
