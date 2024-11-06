#include "Person.cpp"
#include <fstream>
#include <sstream>
class contacts_book {
    private:
        Array<Person> contacts;
    public:
    void print_head(){
        std:: cout << "\t\t\t\t ---- Contacts Information ----\n"
        << "\t\t\t ======================================================\n";
        std::cout << "   " << std::setw(10) << std::left << "ID" << std::setw(15) << std::left << "FName"
        << std::setw(15) << std::left << "LName" << std::setw(20) << std::left << "Classification" 
        << std::setw(15) << std::left << "Fav" << std::setw(25) << std::left << "Address"
        << std::setw(25) << std::left << "Phone num" << std::endl;
        std::cout << std::string(112,'-') << std::endl;
    }
    void print_all_contacts(){
        print_head();
        for (size_t i = 0; i < contacts.get_size(); i++)
        {
            print_info(i);
        }
    }
    void insert_or_modify_info(size_t index){
        std::string first_name, last_name, their_class;
        bool is_favorite;
        std::vector<std::string> numbers, emails;
        std::cout << "\nfn: ";
        std::cin >> first_name;
        std::cout << "ln: ";
        std::cin >> last_name;
        std::cout << "Class (friend, work, family, other): ";
        std::cin >> their_class;
        std::cout << "Set as fav (press 1 (fav) or 0 (Not)): ";
        std::cin >> is_favorite;
        std::cout << "How many numbers: ";
        size_t n_nums;
        std::cin >> n_nums;
        for (size_t i = 0; i < n_nums; i++)
        {
            std::string num;
            std::cout << "Phone #" << i+1 << ": ";
            std::cin >> num;
            numbers.push_back(num);
        }
        std::cout << "How many mails: ";
        size_t n_mails;
        std::cin >> n_mails;
        for (size_t i = 0; i < n_mails; i++)
        {
            std::string mail;
            std::cout << "email #" << i+1 << ": ";
            std::cin >> mail;
            emails.push_back(mail);
        } 
        size_t street_num;
        std::string street_name, town, state;
        std::cout << "\n\t\t ::Enter Address Details:: ";
        std::cout << "\nStreet Number: ";
        std::cin >> street_num;
        std::cout << "Street Name: ";
        std::cin.ignore();
        std::getline(std::cin, street_name);
        std::cout << "Town: ";
        std::getline(std::cin, town);
        std::cout << "State: ";
        std::getline(std::cin, state);
        Person p(first_name, last_name, their_class, is_favorite, numbers, emails);
        Address address(street_num, street_name, town, state);
        p.set_address(address);
        contacts.update_data(p, index);
    }
    void print_info(size_t index){
        contacts[index].print_info(index);
    }
    void print_list(){
        while(true){
            std::cout << "\t\t   ======================================================================\n"
                << "\t\t   Contacts Book Menu:\n"
                << "\t\t   -------------------------------\n"
                << "\t\t   1. Add a new Contact\n"
                << "\t\t   2. Search by Last Name (Enter LastName correctly)\n"
                << "\t\t   3. Search by Classification (friend, work, family, other)\n"
                << "\t\t   4. Print All Contacts\n"
                << "\t\t   5. Print Fav Contacts\n"
                << "\t\t   6. Save to File\n"
                << "\t\t   7. Delete Contact\n"
                << "\t\t   8. Update Contact Information\n"
                << "\t\t   9. Reverse contacts book\n"
                << "\t\t   10. Exit\n"
                << "\t\t   ======================================================================\n"
                << "Enter your choice: ";
                int choice;
                std::cin >> choice;
                if(choice == 10) {
                    contacts.~Array();
                    break;
                }
                switch(choice){
                    case 1:{
                        clear_screen();
                        std::cout << "\t\t\t\t\t --- Add a new contact --- ";
                        contacts.append_new_object();
                        insert_or_modify_info(contacts.get_size()-1);
                        break;
                    }
                    case 2:{
                        clear_screen();
                        std::cout << "Ln: ";
                        std::string ln;
                        std::cin >> ln;
                        std::vector<size_t> indexes;
                        for (size_t i = 0; i < contacts.get_size(); i++)
                        {
                            if(contacts[i].get_last_name() == ln){
                                indexes.push_back(i);
                            }
                        }
                        if(indexes.size() == 0){
                            std::cout << "\tNO One called \"" << ln << "\"\n";
                        }
                        else{
                            print_head();
                            for(size_t index : indexes){
                                print_info(index);
                            }
                        }
                        break;
                    }
                    case 3:{
                        clear_screen();
                        std::cout << "Class: ";
                        std::string cls;
                        std::cin >> cls;
                        std::vector<size_t> indexes;
                        for (size_t i = 0; i < contacts.get_size(); i++)
                        {
                            if(contacts[i].get_classification() == cls){
                                indexes.push_back(i);
                            }
                        }
                        if(indexes.size() == 0){
                            std::cout << "\tNO One has \"" << cls << "\" classifaction\n";
                        }
                        else{
                            print_head();
                            for(size_t index : indexes){
                                print_info(index);
                            }
                        }
                        break;
                    }
                    case 4:{
                        clear_screen();
                        print_all_contacts();
                        break;
                    }
                    case 5:{
                        clear_screen();
                        print_head();
                        for (size_t i = 0; i < contacts.get_size(); i++)
                        {
                            if(contacts[i].get_is_favorite()){
                                print_info(i);
                            }
                        }
                        break;
                        }
                    case 6:{
                        clear_screen();
                        std::string path;
                        std::cout << "\tEnter the path of the file: ";
                        std::cin >> path;
                        for (size_t i = 0; i < contacts.get_size(); i++)
                        {
                            contacts[i].save_info(i, path);
                        }
                        std::cout << "\tData Saved\n";
                        break;
                        }
                    case 7:{
                        clear_screen();
                        int index;
                        std::cout << "Enter the index: ";
                        std::cin >> index;
                        contacts.remove(index);
                        break;
                    }
                    case 8:{
                        clear_screen();
                        int index;
                        std::cout << "\tEnter the index: ";
                        std:: cin >> index;
                        insert_or_modify_info(index-1);
                        print_all_contacts();
                        break;
                    }
                    case 9:{
                        clear_screen();
                        contacts.reverse();
                        break;
                    }
                    default:{
                        std::cout << "Wrong choice, Please choose correct choice\n";
                    }
                }
        }
    }
};


