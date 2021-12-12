// Sheng Xu
// assignment 1
// 2021/9/24
// management.h

#pragma once

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Management {
private:
  struct Animal {
  // Constructor
  Animal() {
    this->category = "";
    this->name = "";
  };
  Animal(string c, string n, int o) {
    this->category = c;
    this->name = n;
    this->order = o;
  };
  string category;     // Animals' category
  string name;         // Animals' name
  int order;           // The order animals arrive at the shelter
  };
  int current = 0;     // The total number of animals that are or have been in the shelter
  queue<Animal> dogs;  // Dogs' queue
  queue<Animal> cats;  // Cats' queue
public:
  void addAnimal(string category, string name);
  Animal getAnimal(string category);
  Animal a_get;        // The animal about to be adopted or an empty "Animal"
};

