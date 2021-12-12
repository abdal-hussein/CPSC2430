// Sheng Xu
// assignment 4
// 2021/10/29
// assignment4.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// The function for spliting each data entry
vector<string> split(string str, char del) {
  vector<string> result;
  string temp = "";
  for (int i = 0; i < (int)str.size(); i++) {
    if (str[i] != del) temp += str[i];
    else {
      result.push_back(temp);
      temp = "";
    }
  }
  result.push_back(temp);
  return result;
}

class DataEntry {
  friend class CovidDB;
private:
  string date;
  string country;
  int c_cases;
  int c_deaths;
public:
  DataEntry(string d, string c, int ca, int de) {
    date = d;
    country = c;
    c_cases = ca;
    c_deaths = de;
  }
  string get_date() {return date;}
  string get_country() {return country;}
  int get_cases() {return c_cases;}
  int get_deaths() {return c_deaths;}
};

class CovidDB {
private:
  static const int m = 17; // Hash table size
  vector<vector<DataEntry*>> covid{m}; // Hash table
  // Hash function
  int hash(string country) {
    int sum = 0;
    for (int i = 0; i < (int)country.size(); i++) sum += (i + 1) * country[i];
    return sum % m;
  }
public:
  // Function for inserting one data entry into the hash table
  bool add(DataEntry* d) {
    // If the data entry's country is not in the hash table, insert the data entry 
    if (!get(d->country)) {
      covid[hash(d->country)].push_back(d);
      return true;
    }
    else {
      DataEntry* b = get(d->country);
      // Only if the date is later than the existing data entry's date, update the data entry
      if (b->date < d->date) {
        remove(d->country);
        return add(new DataEntry(d->date, d->country, (b->c_cases + d->c_cases), (b->c_deaths + d->c_deaths)));
      }
      // If the date is earlier than or equal to the date in the current hash table, ignore the new entry
      else return false;
    }
  }
  // Function for retrieving a data entry with the specific country name 
  DataEntry* get(string s) {
    // Get index first
    int i = hash(s);
    // Traverse ith vector to search
    for (int j = 0; j < (int)covid[i].size(); j++) if (covid[i][j]->country == s) return covid[i][j];
    return nullptr;
  }
  // Function for removing the data entry with the specific country name
  void remove(string s) {
    // Get index first
    int i = hash(s);
    // Traverse ith vector to search
    for (int j = 0; j < (int)covid[i].size(); j++) if (covid[i][j]->country == s) covid[i].erase(covid[i].begin() + j);
  };
  // Function for displaying the hash table
  void display() {
    cout << "Covid Tracker hash table here:" << endl;
    for (int i = 0; i < m; i++) {
      cout << i << ":" << endl;
      for (int j = 0; j < (int)covid[i].size(); j++) {
        cout << covid[i][j]->date << ", " << covid[i][j]->country << ", " << covid[i][j]->c_cases <<", "<< covid[i][j]->c_deaths << endl;
      }
      cout << endl;
    }
  }
};

int main() {
  int choice; // User's choice
  string date; // Generic date
  string country; // Generic country
  int c_cases; // Generic number of cases
  int c_deaths; // Generic number of deaths
  bool flag = true; // The hash table initialization flag
  CovidDB c; // Initialize a CovidDB hash table
  ifstream file("WHO-COVID-Data.csv");
  DataEntry* a; // Generic data entry pointer
  // User interface
  cout << "Welcome to Covid Tracker." << endl;
 begin:
  cout << "Please choose the operation you want:" << endl;
  cout << "1. Create the initial hash table" << endl;
  cout << "2. Add a new data entry" << endl;
  cout << "3. Get a data entry" << endl;
  cout << "4. Remove a data entry" << endl;
  cout << "5. Display hash table" << endl;
  cout << "0. Quit the system" << endl;
  cin >> choice;
  
  switch(choice) {
  case 1:
    if (file.is_open()) {
      string line;
      // Use the first line of the file to initialize the following variables date, country, c_cases and c_deaths
      getline(file, line);
      vector<string> result = split(line, ',');
      string date = result[0];
      string country = result[1];
      int c_cases = stoi(result[2]);
      int c_deaths = stoi(result[3]);
      while(getline(file, line)) {
        vector<string> result = split(line, ',');
        // If the line's country is the same as the country recorded, update date, c_cases anc c_deaths of the country
        if (result[1] == country) {
          date = result[0];
          c_cases += stoi(result[2]);
          c_deaths += stoi(result[3]);
        }
        // If the line's country is different from the country recorded, add the last country's data entry to the hash table,
        // and update date, country, c_cases and c_deaths of the new country
        else {
          a = new DataEntry(date, country, c_cases, c_deaths);
          if (!c.add(a)) flag = false;
          date = result[0];
          country = result[1];
          c_cases = stoi(result[2]);
          c_deaths = stoi(result[3]);
        }
      }
      // If all countries' data entries were added to the hash table successfully, the flag keeps true
      if (flag) cout << "A hash table has been created successfully." << endl << endl;
      goto begin;
    }
    else {
      cout << "Open file failed" << endl << endl;
      break;
    }
  case 2:
    cout << "Please type the following information for the data entry you want to add to the hash table:" << endl;
    cout << "Date: ";
    cin >> date;
    cout << "Country: ";
    cin >> country;
    cout << "Covid cases: ";
    cin >> c_cases;
    cout << "Covid deaths: ";
    cin >> c_deaths;
    a = new DataEntry(date, country, c_cases, c_deaths);
    if (c.add(a)) cout << "The data entry has been added to the hash table successfully." << endl << endl;
    else cout << "The data entry failed to add to the hash table." << endl << endl;
    goto begin;
  case 3:
    cout << "Please type a country name of the data entry you want to get: ";
    cin >> country;
    a = c.get(country);
    if (!a) cout << "Sorry, no such data entry exists." << endl << endl;
    else cout << a->get_date() << ", " << country << ", " << a->get_cases() << ", " << a->get_deaths() << endl << endl;
    goto begin;
  case 4:
    cout << "Please type a country name of the data entry you want to remove: ";
    cin >> country;
    if (!c.get(country)) cout << "Sorry, no such data entry exists." << endl << endl;
    else {
      c.remove(country);
      cout << "The data entry has been removed from the hash table successfully." << endl << endl;
    }
    goto begin;
  case 5:
    c.display();
    goto begin;
  case 0:
    cout << "Goodbye!" << endl;
    break;
  default:
    cout << "Goodbye!" << endl;
    break;
  }
  return 0;
}
