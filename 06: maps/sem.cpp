#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    
   map<string,double> m1;

   map<string,double,std::greater<string>> m2
   {
      {"1", 1.5},
      {"2", 2.6},
   };
   // std::pair<string, double>
   // first, second

   cout << m2["2"] << endl;
   cout << m2["3"] << endl;

   const map<string,double> m3{{"a", 10}};

   //cout << m3["a"] << endl;
   m2["4"] = 1000;
   if (auto it = m2.find("4"); it != m2.end()) {
       cout << "4 found: " << it->second << endl;
   } else {
       cout << "4 not found" << endl;
   }

   for (const auto &p : m2) {
       // const std::pair<string,double> p;
       cout << p.first << " " << p.second;
   }
}