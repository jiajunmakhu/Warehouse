#include "include/employee.hpp"
#include "include/shelf.hpp"
#include <string>
#include <vector>

class Warehouse{
    public:
    std::vector<Employee> employees;
    std::vector<Shelf> shelves;

    Warehouse();
    void addEmployee(Employee employee);
    void addShelf(Shelf shelf);
    bool rearrangeShelf(Shelf& shelf, Employee employee);
    bool pickItems(std::string itemName, int itemCount);
};