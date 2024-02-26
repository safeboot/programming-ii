//
//  main.cpp
//  PRII-1
//
//  Created by Jake Anderson on 26. 2. 2024..
//

#include <iostream>

using namespace std;

/*
 
    Integralni ispit [PRII] :: prakticni ispit
    -> funkcionalni kod [~90%]
    -> testni kod [~10%]
    
    Testni kod je unaprijed dat, dok je funkcionalni kod potrebno
    implementirati [od strane studenta].
    (skriveni testni kod -> za testiranje funkcionalnog koda)
 
    Najbolja praksa testiranja softvera ukljucuje pisanje vise testnih
    kodova za jedan funkcionalni kod.
    (u idealnom slucaju 1 funkcija iz funkcionalnog koda -> ima 1 testni kod)
 
 */

/*
    
    Utility funkcija :: globalna funkcija koja sluzi za nadopunjavanje objektnog
    koda (klasa / struktura) / pomocna funkcija.
 
 */

/*
 
    Getter :: funkcija clanica sa prefiksom "get" i sluzi za dohvacanje
    vrijednosti nekog atributa
 
    Svaki atribut moze imati zasebnu getter funkciju.
 
    Primjer: getImePrezime(), getIme(), getStatus(), getGodiste()...
 
    Uglavnom ih koristimo samo za dohvacanje i citanje vrijednosti.
 
    One moraju biti public (dostupno za koristenje van strukture).
 
    ---
 
    Setter :: funkcija clanica sa prefiksom "set" i sluzi za azuriranje
    vrijednosti nekog atributa (1 ili vise njih).
 
    Svaki atribut moze imati zasebnu setter funkciju (ili vise njih).
 
    Setter obicno ima jedan ulazni parametar (nova vrijednost za setovanje
    atributa).
 
    Setter takoder mora biti public (dostupno za koristenje van strukture).
 
    ---
 
    Getter i setteri su interfejs (sucelje) koje sakriva implementaciju
    koda.
 
 */

struct Datum {
    
    int* _dan { nullptr };
    int* _mjesec { nullptr };
    int* _godina { nullptr };
    
    // *(nullptr) -> runtime error [dereferenciranje nulte adrese je automatska greska]
    
    int getDan() {
        return (_dan == nullptr) ? 1 : *_dan;
    }
    
    int getMjesec() {
        return (_mjesec == nullptr) ? 1 : *_mjesec;
    }
    
    int getGodina() {
        return (_godina == nullptr) ? 2024 : *_godina;
    }
    
    void setDan(int dan) {
        
        if (_dan == nullptr) {
            _dan = new int;
        }
        
        *_dan = dan;
        
    }
    
    void setMjesec(int mjesec) {
        
        if (_mjesec == nullptr) {
            _mjesec = new int;
        }
        
        *_mjesec = mjesec;
        
    }
    
    void setGodina(int godina) {
        
        if (_godina == nullptr) {
            _godina = new int;
        }
        
        *_godina = godina;
        
    }
    
    void setAll(int dan, int mjesec, int godina) {
        
        setDan(dan);
        setMjesec(mjesec);
        setGodina(godina);
        
    }
    
    void setAll(Datum& object) {
        
        setDan(object.getDan());
        setMjesec(object.getMjesec());
        setGodina(object.getGodina());
        
    }
    
    void setAll(Datum* object) {
        
        setDan(object->getDan());
        setMjesec(object->getMjesec());
        setGodina(object->getGodina());
        
    }
    
    void ispis() {
        
        cout << getDan() << "." << getMjesec() << "." << getGodina() << endl;
        
    }
    
    void dealokacija() {
        
        delete _dan, delete _mjesec, delete _godina;
        
        _dan = _mjesec = _godina = nullptr;
        
    }
    
};

// Z0.1 Utility funkcija za alokaciju teksta
char* alocirajTekst(const char* tekst) {
    
    // Ova provjera je obavezna zbog toga sto bi kasnije moglo doci do greske (RE)
    // Buduci da string funkcije (funkcije za rad sa char*) ne prihvataju nullptr
    // kao validnu vrijednost
    if (tekst == nullptr) {
        return nullptr;
    }
    
    int vel = strlen(tekst) + 1;
    
    char* novi = new char[vel]; // Alokacija novog teksta
    
    // Xcode has forced my hand and I cannot use the secure version :(
    // strcpy_s(novi, vel, tekst);
    strcpy(novi, tekst);
    
    return novi;
    
}

void zadatak1() {
    
    Datum danNezavisnosti;
    
//    danNezavisnosti.setDan(2);  // Alokacija + promjena vrijednosti
//    danNezavisnosti.setDan(12); // Promjena vrijednosti
//    danNezavisnosti.setDan(1);  // Promjena vrijednosti
//    
//    danNezavisnosti.setMjesec(3);   // Alokacija + promjena vrijednosti
//    danNezavisnosti.setMjesec(2);   // Promjena vrijednosti
//    danNezavisnosti.setMjesec(3);   // Promjena vrijednosti
//    
//    danNezavisnosti.setGodina(2024);
    
    danNezavisnosti.setAll(1, 3, 2024);
    danNezavisnosti.setAll(1, 5, 2024);
    danNezavisnosti.setAll(5, 4, 2024);
    
    Datum noviDatum;
    
    // Primjer 1
    noviDatum.setAll(danNezavisnosti);
    
    // Primjer 2
    noviDatum.setAll(danNezavisnosti.getDan(), danNezavisnosti.getMjesec(), danNezavisnosti.getGodina());
    
    // Primjer 3
    noviDatum.setAll(&danNezavisnosti);
    
    danNezavisnosti.ispis();
    
    danNezavisnosti.dealokacija();
    
}

void zadatak2() {
    
    //
    
}

void zadatak3() {
    
    //
    
}

void menu() {
    
    int nastaviDalje = 1;
    
    while (nastaviDalje == 1) {
        
        int izbor = 0;
        
        do {
            
            cout << ":: Zadaci ::" << endl;
            cout << "(1) Zadatak 1" << endl;
            cout << "(2) Zadatak 2" << endl;
            cout << "(3) Zadatak 3" << endl;
            cout << "Unesite odgovarajuci broj zadatka za testiranje --> ";
            
            cin >> izbor;
            
        } while (izbor < 1 || izbor > 3);
        
        switch (izbor) {
                
            case 1: zadatak1(); cout << "Done." << endl; break;
            case 2: zadatak2(); cout << "Done." << endl; break;
            case 3: zadatak3(); cout << "Done." << endl; break;
                
        }
        
        do {
            
            cout << "Da li zelite nastaviti dalje izvrsavanje? (1 / 0) --> ";
            cin >> nastaviDalje;
            
        } while (nastaviDalje != 0 && nastaviDalje != 1);
        
    }
    
}

int main() {
    
    menu();
    
    return 0;
    
}
