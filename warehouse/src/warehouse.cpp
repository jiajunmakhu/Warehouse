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

bool Warehouse::rearrangeShelf(Shelf& shelf){
    for (int i = 0; i < shelf.palletSize; i++){
        int mostFullPallet = shelf.checkMostFullPallet(i);
        if (mostFullPallet != i){
            shelf.swapPellet(i, mostFullPallet);
        }
    }
};

bool Warehouse::pickItems(std::string itemName, int itemCount){
    int toPickCount = itemCount;
    for (Shelf shelf: this->shelves){
        for (Pallet pallet: shelf.pallets){
            if (pallet.getItemName() == itemName){
                pallet.takeOne();
                toPickCount--;
            }
        }
    }
};