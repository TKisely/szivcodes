#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//a szokasos include-ok a megfelelo fugvenyek eleresehez
//sorban: konzol olvasas es iras, szoveg kezelese,
//fajl iras es olvasasa, vector lista hasznalata
//majd pedig std hasznalata, hogy ne kelljen mindenhova std:: -t irni

using namespace std;

//szemelyek nevet es eletkorat olvassuk be egy fajlbol
//a kesobbi feldolgozhatosag miatt egy osztalyban osszekapcsoljuk az ertekeket
//minden publikus, hogy ne kelljenek getterek es setterek (kozvetlen eleres)
class Szemely{
public:
    string nev;
    int kor;

    Szemely(){}
    Szemely(string _nev, int _kor){
        nev=_nev;
        kor=_kor;
    }

};

//mivel elore nem tudjuk, hogy hany szemelyt szeretnenk beolvasni
//emiatt listakban kell gondolkodnunk
vector<Szemely> konzolrolSzemelyek;
vector<Szemely> beolvasottSzemelyek;

//ebben a megoldasban mindent a main fuggvenybe teszunk
//ha minden a mainbe kerul, akkor a sorrendre figyelni kell nagyon
//a sorok fontrol lefele futnak le sorban
int main() {
    //beolvasashoz kellenek valtozok, hogy a programunkban el tudjuk tarolni
    //db amiatt kell, hogy a bekeresnel lassuk, hogy hanyadik szemelynel tartunk
    //elvalaszto pedig azert, hogy elore bebiztositsuk magunkat arrol,
    //mivel valasztjuk majd el az ertekeinket
    string nev;
    int kor;
    int db=1;
    char elvalaszto='\t';

    //beolvassuk konzolrol az adatokat
    //mivel nem tudjuk, hogy pontosan mennyit, igy nem for-t hasznalunk
    //en addig olvasok, mig 0-t nem kapunk a nev helyere
    while(nev!="0"){
        cout<<"Kerem adja meg a "<<db<<". szemely nevet: "<<endl;
        cin>>nev;

        //ha a nev 0, akkor mar a kor-t be sem kell kernunk, hisz tudjuk, hogy vegeztunk
        //ez megforditva, ha NEM nulla a nev, akkor olvassuk be a kor-t
        //es taroljuk el a szemely adatait a vectorunkban
        if(nev!="0"){
            cout<<"Kerem adja meg a "<<db<<". szemely korat: "<<endl;
            cin>>kor;
            //a darab valtozot novelni kell minden felvitt rekord utan
            db++;
            konzolrolSzemelyek.push_back(Szemely(nev,kor));
        }
    }

    //a vector meretet a .size() segitsegevel kerhetjuk le
    cout<<"Beolvasott szemelyek szama: "<<konzolrolSzemelyek.size()<<endl;

    //kiirjuk a fajlunkba a jelenleg meg a programunkban tarolt adatokat
    ofstream fajlom("lista.txt");

    if(fajlom.is_open()){
        cout<<"A fajl megnyitva irasra."<<endl;

        //ugy indexeljuk a vectort mint a tomboket
        //0-tol megyunk a mereteig
        //a meretet a .size() adja meg
        for (int i = 0; i < konzolrolSzemelyek.size(); ++i) {
            fajlom<<konzolrolSzemelyek[i].nev;
            fajlom<<elvalaszto;
            fajlom<<konzolrolSzemelyek[i].kor;
            fajlom<<'\n';
            //beleirta a program az adott szemely nevet, majd tab
            //majd a kora, majd sortores
        }

        cout<<"A fajl feltoltve."<<endl;

    } else{cout<<"Nem sikerult megnyitni a fajlt!";}

    //a fajl zarasaval mindig foglalkozni kell!
    fajlom.close();
    cout<<"A fajl bezarva."<<endl;

    //a feladat masodik resze, hogy ki kell tudnunk olvasni egy feltoltott fajlt
    ifstream fajlomOlvasasra("lista.txt");

    if(fajlomOlvasasra.is_open()){
        cout<<"A fajl megnyitva olvasasra."<<endl;

        //kell egy valtozo a programunkban a teljes sornak
        string beolvasottSor;

        //majd kellenek valtozok a daraboknak, amiket a sorbol kiszedunk
        string kiolvasottNev;
        string kiolvasottKor;

        //mivel nem tudjuk, hogy hany rekord van eltarolva, igy szokas szerint while() fgv.
        //amig van meg rekord (a rekordok sorokban vannak, tehat amig van meg sor)
        //addig olvassunk
        while (getline(fajlomOlvasasra,beolvasottSor)){
            //megkeressuk az elvalasztot es az alapjan feldaraboljuk 2fele
            unsigned long elvalasztoHelye=beolvasottSor.find('\t');
            kiolvasottNev=beolvasottSor.substr(0,elvalasztoHelye);
            kiolvasottKor=beolvasottSor.substr(elvalasztoHelye+1,beolvasottSor.size());

            //kiolvasottKor szoveg volt de nekem szamkent kell,
            //hogy vegezhessek rajta matematikai muveleteket
            int kor=stoi(kiolvasottKor);

            //vegul betoltjuk a masodik vectorunkba
            beolvasottSzemelyek.push_back(Szemely(kiolvasottNev,kor));
        }

    }else{cout<<"Nem sikerult megnyitni a fajlt!";}

    //majd ismet zarunk, mert KELL!
    fajlomOlvasasra.close();
    cout<<"A fajl olvasasa befejezodott."<<endl;

    //megnezzuk miket olvastunk be, hogy stimmel-e
    for (int j = 0; j < beolvasottSzemelyek.size(); ++j) {
        cout<<beolvasottSzemelyek[j].nev<<elvalaszto<<beolvasottSzemelyek[j].kor<<endl;
    }
    cout<<"Minden tarolt adat kiirva."<<endl;

    //harmadik resze a feladatnak a tenyleges feldolgozas
    //eloszor az atlagot szamoljuk ki a tanult modon
    int eletkorokOsszege=0;

    for (int k = 0; k < beolvasottSzemelyek.size(); ++k) {
        eletkorokOsszege+=beolvasottSzemelyek[k].kor;
    }

    int atlagEletkor=eletkorokOsszege/beolvasottSzemelyek.size();

    cout<<"Az atlag eletkor: "<<atlagEletkor<<endl;

    //majd megkeressuk a legfiatalabbat es a legidosebbet
    //de mivel nem a KOR kell nekunk outputnak
    //tehat nem azt kell a konzolra kiirni, hogy hany eves a legidosebb
    //hanem a nevet, igy azokkal is foglalkoznunk kell
    //megadjuk a lista elso elemet mint legidosebb es legfiatalabb
    //majd megnezzuk a vectoron vegighaladva, hogy talalunk-e idosebbet vagy fiatalabbat
    //ha igen, nem csak a minimum es maximum kort csereljuk
    //hanem a hozza tartozo nevet is, hisz azt kell majd a vegen kiirnunk
    int maxEletkor=beolvasottSzemelyek[0].kor;
    int minEletkor=beolvasottSzemelyek[0].kor;

    string legfiatalabbNeve=beolvasottSzemelyek[0].nev;
    string legidosebbNeve=beolvasottSzemelyek[0].nev;

    for (int l = 0; l < beolvasottSzemelyek.size(); ++l) {
        if(beolvasottSzemelyek[l].kor>maxEletkor){
            maxEletkor=beolvasottSzemelyek[l].kor;
            legidosebbNeve=beolvasottSzemelyek[l].nev;
        }

        if(beolvasottSzemelyek[l].kor<minEletkor){
            minEletkor=beolvasottSzemelyek[l].kor;
            legfiatalabbNeve=beolvasottSzemelyek[l].nev;
        }
    }

    cout<<"Legidosebb: "<<legidosebbNeve<<'\t'<<" legfiatalabb: "<<legfiatalabbNeve<<endl;

    std::cout << "A kod a vegehez ert." << std::endl;
    return 0;
}
