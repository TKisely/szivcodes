//Kis dolgozat 11.12. 12D - Info
//Kisely Tamas
//Kidolgozott megoldasi segedlet

//a konzolra valo kiirashoz es beolvasashoz szukseges konyvtar
#include <iostream>

//definialjuk a TOMBMERET nevu konstans erteket
//tehat ahova azt irom, hogy TOMBMERET, ott a gep automatikusan
//lecsereli a TOMBMERET szoveget a megadott ertekre
#define TOMBMERET 10

//Nevter hasznalata, hogy ne kelljen mindig az std:: -t irni a cin es cout ele
using namespace std;

//letrehozunk egy a fajlban globalis tombot, hogy mindenhonnan elerhessuk
//merete megegyeyik a TOMBMERET szamertekevel
int globalisTomb[TOMBMERET];

//ez a fuggveny a tombunkben cserel 2 db erteket
//ezekre az ertekekre az indexeik szerint hivatkozunk
//tehat megnezi mi van az elso index alatt
//es felcsereli a masodik index alatt talalhato ertekkel
//ehhez parameterlistan meg kell kapnia a ket indexet
//tovabba bool a visszateresi tipusa, mivel ha rossz indexet adunk meg, akkor nem tud lefutni
//es ezt jeleznunk kell
bool csere(int elsoIndex, int masodikIndex){
    //ha mind a ket index megfelelo, akkor...
    if(elsoIndex>=0&&elsoIndex<TOMBMERET&&masodikIndex>=0&&masodikIndex<TOMBMERET){
        //csere folyamata - szuksegunk van egy ideiglenes valtozora
        int ideiglenes = globalisTomb[elsoIndex];
        globalisTomb[elsoIndex]=globalisTomb[masodikIndex];
        globalisTomb[masodikIndex]=ideiglenes;

        //ha sikeres a csere terj vissza igazzal
        return true;
    }
    //ha az egyik, vagy mindket index hibas, akkor terj vissza hamissal
    else return false;
}

//buborek rendezes algoritmusanak megvalositasa C++ -ban
void buborekRendezes()
{
    int i;
    int j;
    for (i = 0; i < TOMBMERET-1; i++) {
        for (j = 0; j < TOMBMERET - i - 1; j++){
            if (globalisTomb[j] > globalisTomb[j + 1])
                csere(j, j + 1);
        }
    }
}

//a konzolrol altalunk beirt szamokat tolti be a tombunkbe
void konzolrolFeltolt(){
    //bejarja a teljes tombot a for ciklus
    for(int i = 0; i < TOMBMERET; ++i) {
        //nem kell kulon valtozo a beolvasasnak, hisz a tomb kello hellyel rendelkezik
        //cin>> maga a beolvasas, a >> utan szerepel, hogy hova, ugy funkcional
        //, mint egy nyilacska, amerre mutat, arra mozog az ertek
        cin>>globalisTomb[i];
    }
}

//kiirja a tomb osszes elemet sorban
void kiir(){
    //bejarja a teljes tombot
    for (int i = 0; i < TOMBMERET; ++i) {
        cout<<i<<". elem = "<<globalisTomb[i]<<endl;
    }
}


int main() {
    //feltoltjuk a konzolrol a tombunk minden helyet
    konzolrolFeltolt();
    //kiirjuk a meg rendezetlen tombot
    kiir();
    //rendezzuk a tombot (ez nem jar kiirassal, igy nem latjuk a folyamatot)
    buborekRendezes();
    //kiirjuk a rendezett tomb elemeit
    kiir();


    std::cout << "Lefutottam vegig" << std::endl;
    return 0;
}
