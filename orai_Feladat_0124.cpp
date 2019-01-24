#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ofstream megnyitandoFile ("fajl.txt");
    if (megnyitandoFile.is_open())
    {
        megnyitandoFile << "Elso sor.\n";
        megnyitandoFile << "Masodik sor.\n";
        megnyitandoFile.close();
    }
    else cout << "Nem tudom megnyitni a fajlt";
    return 0;
}
