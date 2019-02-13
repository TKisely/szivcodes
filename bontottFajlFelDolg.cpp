#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Termek{
public:
    string nev;
    int ar;

    Termek(){}
    Termek(string _nev, int _ar){
        nev=_nev;
        ar=_ar;
    }
};

vector<Termek> kiTermekek;
vector<Termek> beTermekek;

const char elvalaszto='=';
const string fajlneve="adatbazis.txt";

void felToltesKonzolrol(){
    string nev;
    int ar;
    int db=0;

    cout<<"A program feltoltese termekekkel a konzolrol"<<endl;
    cout<<"Nev=0 hatasara nem tolti tovabb"<<endl;

    while(nev!="0"){
        cout<<"Kerem adja meg a "<<(db+1)<<". termek nevet: "<<endl;
        cin>>nev;
        if(nev!="0"){
            cout<<"Kerem adja meg a "<<(db+1)<<". termek arat: "<<endl;
            cin>>ar;
            kiTermekek.push_back(Termek(nev, ar));
            db++;
        }
    }
}

void tetszolegesTermekVectorKiirasaKozolra(vector<Termek> &kiIrando){
    for (int i = 0; i < kiIrando.size(); ++i) {
        cout<<kiIrando[i].nev<<elvalaszto<<kiIrando[i].ar<<endl;
    }
}

bool kiIrasFajlba(){

    ofstream fajlomIrasra(fajlneve);

    if(fajlomIrasra.is_open()){

        for (int i = 0; i < kiTermekek.size(); ++i) {
            fajlomIrasra<<kiTermekek[i].nev;
            fajlomIrasra<<elvalaszto;
            fajlomIrasra<<kiTermekek[i].ar;
            fajlomIrasra<<'\n';
        }
        fajlomIrasra.close();
        return true;

    }else{
        cout<<"Nem sikerult megnyitni vagy letrehozni a fajlt irasra!"<<endl;
        return false;
    }
}

bool beOlvasasFajlbol(){
    ifstream fajlomOlvasasra(fajlneve);

    if(fajlomOlvasasra.is_open()){
        string beolvasottSor;

        string beolvasottNev;
        string beolvasottAr;

        while (getline(fajlomOlvasasra,beolvasottSor)){

            unsigned long elvalasztoHelye=beolvasottSor.find(elvalaszto);

            beolvasottNev=beolvasottSor.substr(0, elvalasztoHelye);
            beolvasottAr=beolvasottSor.substr(elvalasztoHelye+1,beolvasottSor.size());

            int konvertaltAr=stoi(beolvasottAr);

            beTermekek.push_back(Termek(beolvasottNev,konvertaltAr));
        }

        fajlomOlvasasra.close();
        return true;

    }else{
        cout<<"Nem sikerult megnyitni olvasasra!"<<endl;
        return false;
    }

}

int maximumKereses(){

    int maximum=beTermekek[0].ar;

    for (int i = 0; i < beTermekek.size(); ++i) {
        if(beTermekek[i].ar>maximum){
            maximum=beTermekek[i].ar;
        }
    }
    return maximum;
}

int minimumKereses(){

    int minimum=beTermekek[0].ar;
    for (int i = 0; i < beTermekek.size(); ++i) {
        if(beTermekek[i].ar<minimum){
            minimum=beTermekek[i].ar;
        }
    }
    return minimum;
}

int osszegSzamitas(){
    int osszeg=0;

    for (int i = 0; i < beTermekek.size(); ++i) {
        osszeg+=beTermekek[i].ar;
    }

    return osszeg;
}

int atlagSzamitas(){

    int atlag=osszegSzamitas()/beTermekek.size();

    return atlag;
}

string legDragabbKereses(){

    string legDragabbNeve=beTermekek[0].nev;
    int maximum=beTermekek[0].ar;

    for (int i = 0; i < beTermekek.size(); ++i) {
        if(beTermekek[i].ar>maximum){
            legDragabbNeve=beTermekek[i].nev;
            maximum=beTermekek[i].ar;
        }
    }
    return legDragabbNeve;
}

string legOlcsobbKereses(){

    string legOlcsobbNeve=beTermekek[0].nev;
    int minimum=beTermekek[0].ar;

    for (int i = 0; i < beTermekek.size(); ++i) {
        if(beTermekek[i].ar<minimum){
            legOlcsobbNeve=beTermekek[i].nev;
            minimum=beTermekek[i].ar;
        }
    }
    return legOlcsobbNeve;
}


int main() {

    felToltesKonzolrol();
    cout<<"A kiTermekek vector feltoltese befejezodott..."<<endl;

    cout<<"Ezek kerultek a vecotrba: "<<endl;
    tetszolegesTermekVectorKiirasaKozolra(kiTermekek);
    
    kiIrasFajlba();
    cout<<"A kiTermekek tartalma kiirasra kerult a fajlba..."<<endl;

    beOlvasasFajlbol();
    cout<<"A beTermekek vector feltoltese befejezodott..."<<endl;

    cout<<"Ezeket olvasta be a program: "<<endl;
    tetszolegesTermekVectorKiirasaKozolra(beTermekek);
    cout<<"Minden a fajlbol beolvasott termek kiirasra kerult a konzolra..."<<endl;

    cout<<"A termekek atlaga: "<<atlagSzamitas()<<endl;
    cout<<"A termekek osszege: "<<osszegSzamitas()<<endl;
    cout<<"A legdragabb termek neve: "<<legDragabbKereses()<<" es ara: "<<maximumKereses()<<endl;
    cout<<"A legolcsobb termek neve: "<<legOlcsobbKereses()<<" es ara: "<<minimumKereses()<<endl;


    std::cout << "A program a vegehez ert." << std::endl;
    return 0;
}
