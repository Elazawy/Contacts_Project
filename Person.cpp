#include "Address.cpp"
#include<vector>
#include<fstream>
class Person {
    private:
        std::string first_name;
        std::string last_name;
        std::string their_class;
        bool is_favorite;
        std::vector<std::string> numbers;
        std::vector<std::string> emails;
        Address address;
    public:
        Person() : first_name(""), last_name(""), their_class(""), is_favorite(false), address(Address()) {}
        Person(std::string fn, std::string ln, std::string cls, bool fav, std::vector<std::string> nums, std::vector<std::string> mails)
            : first_name(fn), last_name(ln), their_class(cls), is_favorite(fav) {
            set_nums(nums);
            set_emails(mails);
        }
        void set_nums(std::vector<std::string> &new_numbers){
            numbers.clear();
            for (size_t i = 0; i < new_numbers.size(); i++)
            {
                numbers.push_back(new_numbers[i]);
            }
        }
        void set_emails(std::vector<std::string> &new_emails){
            emails.clear();
            for (size_t i = 0; i < new_emails.size(); i++)
            {
                emails.push_back(new_emails[i]);
            }
        }
        void set_address(const Address& addr) {
            address = addr;
        }
        bool get_is_favorite(){
            return is_favorite;
        }
        std::string get_last_name(){
            return last_name;
        }
        std::string get_classification(){
            return their_class;
        }
        std::string get_numbers(){
            std::string nums = "";
            for (size_t i = 0; i < numbers.size()-1; i++)
            {
                nums += numbers[i];
                nums += ", "; 
            }
            if(numbers.size() > 0){
                nums += numbers[numbers.size()-1];
            }
            return nums;
        }
        void print_info(size_t id){
            std::cout << "   " << std::setw(10) << std::left << id+1 << std::setw(15) << std::left << first_name
            << std::setw(15) << std::left << last_name << std::setw(20) << std::left << their_class 
            << std::setw(15) << std::left << is_favorite << std::setw(25) << std::left << address.get_full_address()
            << std::setw(25) << std::left << get_numbers() << std::endl;
            std::cout << std::string(112,'-') << std::endl;
        }
        void save_info(size_t id, std::string path){
            std::ofstream p;
            p.open(path);
            p << "   " << std::setw(10) << std::left << id+1 << std::setw(15) << std::left << first_name
            << std::setw(15) << std::left << last_name << std::setw(20) << std::left << their_class 
            << std::setw(15) << std::left << is_favorite << std::setw(25) << std::left << address.get_full_address()
            << std::setw(25) << std::left << get_numbers() << std::endl;
            std::cout << std::string(112,'-') << std::endl;
            p.close();
        }
        Person(const Person& other)
            : first_name(other.first_name), last_name(other.last_name), their_class(other.their_class), is_favorite(other.is_favorite), 
            numbers(other.numbers), emails(other.emails), address(other.address) {}
        Person& operator=(const Person& other) {
            if (this != &other) {
                first_name = other.first_name;
                last_name = other.last_name;
                their_class = other.their_class;
                is_favorite = other.is_favorite;
                numbers = other.numbers;
                emails = other.emails;
                address = other.address;
            }
            return *this;
        }
};
