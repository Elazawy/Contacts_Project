# Contacts Manager Console Project
This project is a simple Contacts Manager implemented in C++ as a console application. It allows users to manage their contacts by adding, updating, deleting, and searching for contacts. The application also supports saving contact information to a file and reversing the order of contacts in the list.

## Features:
Add a New Contact: Users can add a new contact by providing details such as first name, last name, classification (friend, work, family, other), phone numbers, emails, and address.

Search Contacts:

By Last Name: Users can search for contacts by entering the last name.

By Classification: Users can filter contacts by their classification (e.g., friend, work, family, other).

Print All Contacts: Displays all contacts in a tabular format with details such as ID, first name, last name, classification, favorite status, address, and phone numbers.

Print Favorite Contacts: Displays only the contacts marked as favorites.

Save to File: Allows users to save the contact information to a specified file path.

Delete Contact: Users can delete a contact by specifying its index.

Update Contact Information: Users can modify the details of an existing contact.

Reverse Contacts: Reverses the order of contacts in the list.

Exit: Exits the application.

## Project Structure:
Address.cpp: Contains the Address class, which manages the address details (street number, street name, town, and state) of a contact.

Array.cpp: Implements a dynamic array template class (Array<T>) that supports resizing, appending, updating, and removing elements. This class is used to store the list of contacts.

Person.cpp: Defines the Person class, which represents a contact. It includes details such as first name, last name, classification, favorite status, phone numbers, emails, and address.

Contacts_book.cpp: Implements the contacts_book class, which manages the list of contacts and provides the main menu for interacting with the contacts (adding, searching, updating, etc.).

main.cpp: The entry point of the application. It initializes the contacts_book and starts the main menu.
## How to Use:
Just clone the project and run main.cpp using c++ compiler


