#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, char del){
    vector<string> result;
    // declaring temp string to store the curr "word" upto del
    string temp = "";
    for(int i=0; i<(int)str.size(); i++){
        // If current char is not ',', then append it to the "word", otherwise you have completed the word, and start the next word
        if(str[i] != del){
	    temp += str[i];
        }else{
            result.push_back(temp);
            temp = "";
        }
    }
    // push the last substring after the last ',' to the result
    result.push_back(temp);
    return result;
}

class cvsdata{
  string date;
  string country;
  int cases;
  int deaths;
public:
  cvsdata(string date, string country, int cases, int deaths){
    this->date = date;
    this->country = country;
    this->cases = cases;
    this->deaths = deaths;
  }
};

int main()
{
  vector<cvsdata> recordList;

  // open the file
  ifstream file("WHO-COVID-Data-Test.csv");

  if(file.is_open()){

    cout << "Open File Success" << endl;

    string line;

    while(getline(file, line)){
      
      // split the content in each line
      vector<string> result = split(line, ',');

      // wrap up all the data in the string to a cvsdata type and push it to the vector
      cvsdata oneEntry = cvsdata(result[0], result[1], std::stoi(result[2]), std::stoi(result[3]));
      recordList.push_back(oneEntry);
    }
    cout << "There are " << recordList.size() << " records in total." << endl;
    
  }else{
    cout << "Open file failed" << endl;
  }
  return 0;
