#pragma once
#include "include/warehouse.hpp"

Warehouse::Warehouse(){
    std::vector<Employee> employees;
    std::vector<Shelf> shelves;
};


void Warehouse::addEmployee(Employee employee){
    for (Employee person: this->employees){
        if (person == employee){
            return;
        }
    }
    this->employees.push_back(employee);
};

void Warehouse::addShelf(Shelf shelf){
    this->shelves.push_back(shelf);
};

bool Warehouse::rearrangeShelf(Shelf& shelf, Employee employee){
    if (!employee.getBusy() && employee.getForkliftCertificate()){
        for (int i = 0; i < shelf.palletSize; i++){
            int leastFullPallet = shelf.checkLeastFullPallet(i);
            if (leastFullPallet != i){
                shelf.swapPallet(i, leastFullPallet);
            }
        }
        return true;
    }
    return false;
};

bool Warehouse::pickItems(std::string itemName, int itemCount){
    int toPickCount = itemCount;
    for (Shelf shelf: this->shelves){
        for (Pallet pallet: shelf.pallets){
            if (pallet.getItemName() == itemName){
                for (int i  = 0; i < pallet.getItemCount(); i++){
                    if (toPickCount == 0){
                        return true;
                    }
                    pallet.takeOne();
                    toPickCount--;
                }
            }
        }
    }
    if (toPickCount != 0){
        return false;   
    }
};