#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1;
    string str2;
    
    cout<<"Add meg az elsot: "<<endl;
    getline(cin,str1);
    //getline(honnan, hova); cin - konzolrol, str1 nevu stringbe
    
    cout<<"Amit megadtal: "<<str1<<endl;
    
    cout<<"Add meg a masodikat: "<<endl;
    getline(cin,str2);
    
    cout<<"Amit masodiknak adtal meg: "<<str2<<endl;
    
    
    cout << "Lefutottam!" << endl;
    return 0;
}
