#include <iostream>
#include "TAgencyBook.h"

using namespace std;

int main(){
const string path = "C://TouristAgences.txt";
TAgencyBook Object(path);
TAgencyBook* europeCountries = Object.Get_Europe_Countries();
cout << *(europeCountries);
delete europeCountries;
return 0;
}