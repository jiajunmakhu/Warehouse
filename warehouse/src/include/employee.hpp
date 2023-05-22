#include <string>

class Employee{
    private:
    const std::string name;
    bool busy;
    bool forkliftcertificate;

    public:
    Employee(std::string name, bool forkliftCertificate);
    std::string getName();
    bool getBusy();
    void setBusy(bool busy);
    bool getForkliftCertificate();
    void setForkliftCertificate();
};