#include "Array.cpp"
// Libraries
#include <cstddef>
#include<iostream>
#include<vector>

void clear_screen() {
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}
class Address{
    private:
        size_t street_num;
        std::string street_name;
        std::string town;
        std::string state;
    public:
        Address(const int streetnum, const std::string  streetname, std::string town, const std::string  state)
            : street_num(streetnum), street_name(streetname), town(town), state(state) {}
        Address(){
            street_num = 0;
            street_name = "";
            town = "";
            state = "";
        }
        std::string  get_full_address() const {
            return std::to_string(street_num) + ", " + street_name + ", " + town + ", " + state;
        }
        Address(const Address& other)
            : street_num(other.street_num), street_name(other.street_name), town(other.town), state(other.state) {}
        Address& operator=(const Address& other) {
            if (this != &other) {
                street_num = other.street_num;
                street_name = other.street_name;
                town = other.town;
                state = other.state;
            }
            return *this;
        }
};
