#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <array>

void print_char() {
   using namespace std;
   char ch;
   cout << "The chars you want to print in the terminal: \n(ctrl+z to suspend, ctrl + c to kill, ctrl + d represent EOF)\n";
   cin.get(ch);
   while(cin.fail() == false) {
      cout << ch;
      cin.get(ch);
   }
   cout << "Done!";
}

std::vector<std::string> my_split(std::string& s, char delim) {
   std::vector<std::string> parts;
   std::string cur;
   for(char ch: s) {
      if(ch == delim) {
         if(!cur.empty()) {
            parts.push_back(cur);
            cur.clear();
         }
      }
      else {
         cur += ch;
      }
   }

   if (!cur.empty()) parts.push_back(cur);
   return parts;
}

void wait() {
   using namespace std;
   cout << "Enter the time you want to delay in seconds: ";
   double sec;
   cin >> sec;
   clock_t delay = sec * CLOCKS_PER_SEC;
   clock_t start = clock();
   while(clock() - start < delay)
   ;
   cout << "Done!";

}

void test2(){
   std::array<long double, 10> a;
   a.at(0) = a.at(1) = 1;
   std::cout << a.at(0) << std::endl;
   std::cout << a.at(1) << std::endl;
   for(int i = 2; i < 10; i++) {
      a.at(i) = i * a.at(i-1);
      std::cout << a.at(i) << std::endl;
   }
}

struct Car{
   std::string maker;
   int year;
};

void get_car_mes() {
   using namespace std;
   cout << "How many cars do you wish to catalog?";
   int test_cases;
   cin >> test_cases;
   cin.get();
   Car* a = new Car[test_cases];
   for(int i = 0; i < test_cases; i++) {
      cout << "Car #" << i + 1 << ":\n";
      cout << "Please enter the maker: ";
      getline(cin, a[i].maker);
      cout << "Please enter the year made: ";
      cin >> a[i].year;
      cin.get();
   }
   cout << "Here is your collection:\n";
   for(int i = 0; i < test_cases; i++) {
      cout << a[i].year << " " << a[i].maker << endl;
   }
   delete[] a;
}

/*   using namespace std;
   ofstream outfile;
   outfile.open("test.txt");
   outfile.precision(2);
   double digit = 36.3753255;
   outfile << digit;
   outfile << "This is a test sentence\n";
   outfile << "Today is Jan 27\n";
   outfile << "Tomorrow is Jan 28\n";
   ifstream infile;
   outfile.close();
   infile.open("test.txt");
   char s[80];
   infile.getline(s, 80);
   cout << s;*/

void get_from_file(std::string filename) {
   using namespace std;
   ifstream infile;
   infile.open(filename);
   if(!infile.is_open()) {
      cout << "The file is not exist.\n";
   }
   string s;
   while(getline(infile, s)) {
      cout << s;
   }
   if(infile.eof()) {
      cout << "End of file reached.\n";
   }
   else if(infile.fail()) {
      cout << "Input terminated by data mismatched.\n";
   }
   else {
      cout << "Input terminated by unknown reason.\n";
   }
}



int main() {
   
}