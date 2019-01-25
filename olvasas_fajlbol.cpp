
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string beolvasottSor;
	ifstream megnyitottFajl("fajl.txt");
	//leteznie kell a fajlnak, hogy meg tudja nyitni
	if (megnyitottFajl.is_open())
	{
		while (getline(megnyitottFajl, beolvasottSor))
		{
			cout << beolvasottSor << '\n';
		}
		megnyitottFajl.close();
	}

	else cout << "Nem sikerult megnyitni";

	return 0;
}
