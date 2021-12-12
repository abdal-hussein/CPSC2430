// Sheng Xu
// assignment 1
// 2021/9/24
// management.cpp

#include "management.h"

// The function for adding an animal to the system
void Management::addAnimal(string category, string name) {
  if (category == "dog" || category == "Dog") dogs.push(Animal("dog", name, ++current));
  else cats.push(Animal("cat", name, ++current));
}

// The function for getting an animal from the system
Management::Animal Management::getAnimal(string category) {
  Animal a;
  // For dog
  if (category == "dog" || category == "Dog") {
    // Error handling
    if (dogs.empty()) cout << "There is not any dog in the shelter at this moment." << endl << endl;
    else {
      a = dogs.front();
      dogs.pop();
    }
  }
  // For cat
  else if (category == "cat" || category == "Cat") {
    // Error handling
    if (cats.empty()) cout << "There is not any cat in the shelter at this moment." << endl << endl;
    else {
      a = cats.front();
      cats.pop();
    }
  }
  // For any of them
  else {
    // Error handling
    if (dogs.empty() && cats.empty()) cout << "There is not any animal in the shelter at this moment." << endl << endl;
    // Only a cat(cats) left
    else if (dogs.empty() && !cats.empty()) {
      a = cats.front();
      cats.pop();
    }
    // Only a dog(dogs) left
    else if (!dogs.empty() && cats.empty()) {
      a = dogs.front();
      dogs.pop();
    }
    else {
      // The "oldest" animal is a dog
      if (dogs.front().order < cats.front().order) {
        a = dogs.front();
        dogs.pop();
      }
      // The "oldest" animal is a cat
      else {
        a = cats.front();
        cats.pop();
      }
    }
  }
  return a;
}
