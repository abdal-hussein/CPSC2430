// Sheng Xu
// assignment 1
// 2021/9/24
// main.cpp

#include "management.h"

int main() {
  Management m;              // Declare a Management object m
  int choice;                // User's choice
  string add_categ = "";     // Generic animal's category for adding an animal
  string get_categ = "";     // Generic animal's category for getting an animal
  string nam = "";           // Generic animal's name
  // User interface
  cout << "--------------------------------------------" << endl;
  cout << "Welcome to Animal Shelter Management System!" << endl;
  cout << "--------------------------------------------" << endl;
 begin:
  cout << "Please type the following numbers to continue:" << endl;
  cout << "1: Add an animal to the system" << endl;
  cout << "2: Get an animal from the system" << endl;
  cout << "Others: Quit the system" << endl;
  cin >> choice;

  switch(choice) {
  case 1:
    cout << "Is it a dog or a cat? ";
    cin >> add_categ;
    // Error handling
    if (add_categ != "dog" && add_categ != "Dog" && add_categ != "cat" && add_categ != "Cat") {
      cout << "Sorry, we only support dogs and cats." << endl << endl;
      goto begin;
    }
    // Add an animal
    cout << "What's this " << add_categ << "'s name? ";
    cin >> nam;
    m.addAnimal(add_categ, nam);
    cout << "Animal added successfully." << endl << endl;
    goto begin;
  case 2:
    cout << "What do you want to adopt(a dog or a cat or any of them)? ";
    cin >> get_categ;
    // Error handling
    if (get_categ != "dog" && get_categ != "Dog" && get_categ != "cat" && get_categ != "Cat" && get_categ != "any" && get_categ != "Any") {
      cout << "Sorry, we don't have this option." << endl << endl;
      goto begin;
    }
    // Get an animal
    m.a_get = m.getAnimal(get_categ);
    get_categ = m.a_get.category;
    nam = m.a_get.name;
    if (nam != "")
      cout << "Congrats! You have adopted a " << get_categ << " called " << nam <<"." << endl << endl;
    goto begin;
  default:
    // Quit the system
    cout << "Goodbye!" << endl;
    break;
  }
  return 0;
}

