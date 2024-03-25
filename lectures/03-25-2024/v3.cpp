//
//  main.cpp
//  PRII-3
//
//  Created by Jake Anderson on 25. 3. 2024..
//

#include <iostream>
using namespace std;

// Koristene skracenice u komentarima
// dflt. = default
// user-def. = user-defined (korisnicki-definirano)
// ctor = constructor (konstruktor)

// Z1.0
char* alocirajTekst(const char* tekst) {
    
    if (tekst == nullptr) {
        return nullptr;
    }
    
    int velicina = strlen(tekst) + 1;
        
    char* novi = new char[velicina];

    // strcpy_s(novi, velicina, tekst);
    strcpy(novi, tekst);

    return novi;
    
}

class Datum {
    
    int* _dan { nullptr };
    int* _mjesec { nullptr };
    int* _godina { nullptr };
    
public:
    
    // Z1.1 :: dflt. ctor
    // postaviti na vrijednost 1.1.2024
    Datum() {
        
        /*
            
            Datum d;
            Datum(1, 5, 2024);  // privremena (temporary) vrijednost
         
            Datum datumi[100];  // dflt ctor
         
             Datum * pok = new Datum;    // dflt ctor
             Datum * pok = new Datum[100];  // dflt ctor
             
         
         */
        
        setDan(1);
        setMjesec(1);
        setGodina(2024);
        
    }
    
    // Z1.2 :: user-def. ctor
    Datum(int dan, int mjesec, int godina) {
        
        /*
         
            Datum d(13, 04, 2024);  // user-def ctor
            Datum * pok = new Datum(1, 7, 2024);
         
         */
        
        setDan(dan);
        setMjesec(mjesec);
        setGodina(godina);
        
    }
    
    // Z1.3 :: copy ctor
    Datum(const Datum& datum) {
        
        /*
         
            1. 'datum' se ne moze mijenjati
            2. const omogucuje da se proslijeduju i temporary/constant vrijednosti
         
         */
        
        setDan(datum.getDan());
        setMjesec(datum.getMjesec());
        setGodina(datum.getGodina());
        
    }
    
    // Z1.4 :: getteri i setteri
    int getDan() const {
        return (_dan == nullptr) ? 1 : *_dan;
    }
    
    int getMjesec() const {
        return (_mjesec == nullptr) ? 1 : *_mjesec;
    }
    
    int getGodina() const {
        return (_godina == nullptr) ? 1 : *_godina;
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
    
    // Z1.5 :: metoda za kopiranje vrijednosti objekta
    void set(const Datum& datum) {
        
        setDan(datum.getDan());
        setMjesec(datum.getMjesec());
        setGodina(datum.getGodina());
        
    }
    
    // Z1.6
    void ispis() const {
        
        cout << getDan() << "." << getMjesec() << "." << getGodina();
        
    }
    
    // Z1.7
    ~Datum() {
        
        delete _dan, delete _mjesec, delete _godina;
        
    }
    
};

class Glumac {
    
    char* _ime { nullptr };
    char* _prezime { nullptr };
    char* _zemljaPorijekla { nullptr };
    Datum* _datumRodjenja { nullptr };
    bool* _spol { nullptr };    // 1 - Muski, 0 - Zenski
    
public:
    
    // Z2.0 :: dflt. ctor
    Glumac() {
        
        setIme("Unknown");
        setPrezime("Unknown");
        setZemljaPorijekla("Unknown");
        setDatumRodjenja(Datum(1, 1, 2024));
        setSpol(true);
        
    }
    
    // Z2.1 user-def. ctor
    Glumac(const char* ime, const char* prezime, const char* zemlja, Datum datumRodjenja, bool spol) {
        
        setIme(ime);
        setPrezime(prezime);
        setZemljaPorijekla(zemlja);
        setDatumRodjenja(datumRodjenja);
        setSpol(spol);
        
    }
    
    // Z2.2 :: copy ctor
    Glumac(const Glumac& glumac) {
        
        setIme(glumac.getIme());
        setPrezime(glumac.getPrezime());
        setZemljaPorijekla(glumac.getZemljaPorijekla());
        setDatumRodjenja(glumac.getDatumRodjenja());
        setSpol(glumac.getSpol());
        
    }

    // Z2.3 :: getteri i setteri
    const char* getIme() const {
        return (_ime == nullptr) ? "" : _ime;
    }
    
    const char* getPrezime() const {
        return (_prezime == nullptr) ? "" : _prezime;
    }
    
    const char* getZemljaPorijekla() const {
        return (_zemljaPorijekla == nullptr) ? "" : _zemljaPorijekla;
    }
    
    Datum getDatumRodjenja() const {
        return (_datumRodjenja == nullptr) ? Datum(1, 1, 2024) : *_datumRodjenja;
    }
    
    bool getSpol() const {
        return (_spol == nullptr) ? true : *_spol;
    }

    void setIme(const char* ime) {
        
        // [temporary] "oscars 2024", pok, const, const pok
        
        delete[] _ime;
        _ime = alocirajTekst(ime);
        
    }
    
    void setPrezime(const char* prezime) {
        
        delete[] _prezime;
        _prezime = alocirajTekst(prezime);
        
    }
    
    void setZemljaPorijekla(const char* zemlja) {
        
        delete[] _zemljaPorijekla;
        _zemljaPorijekla = alocirajTekst(zemlja);
        
    }
    
    // copy ctor
    void setDatumRodjenja(Datum datumRodjenja) {
        
        if (_datumRodjenja == nullptr) {
            _datumRodjenja = new Datum;
        }
        
        _datumRodjenja->set(datumRodjenja);
        
    }
    
    void setSpol(bool spol) {
        
        if (_spol == nullptr) {
            _spol = new bool;
        }
        
        *_spol = spol;
        
    }
    
    // Z2.4 :: metoda za kopiranje vrijednosti
    void set(const Glumac& glumac) {
        
        setIme(glumac.getIme());
        setPrezime(glumac.getPrezime());
        setZemljaPorijekla(glumac.getZemljaPorijekla());
        setDatumRodjenja(glumac.getDatumRodjenja());
        setSpol(glumac.getSpol());
        
    }
    
    // Z2.5
    void ispis() const {
        
        cout << "Ime i prezime: " << getIme() << " " << getPrezime() << endl;
        cout << "Zemlja porijekla: " << getZemljaPorijekla() << endl;
        cout << "Datum rodjenja: ";
        
        getDatumRodjenja().ispis();
        
        cout << endl;
        
        cout << "Spol: " << (getSpol() ? "Muski" : "Zenski") << endl;
        
    }
    
    // Z2.6
    ~Glumac() {
        
        delete[] _ime, delete[] _prezime, delete[] _zemljaPorijekla;
        delete _datumRodjenja, delete _spol;
        
    }
    
};

class Epizoda {
    
    char* _naziv{ nullptr };
    int* _trajanje{ nullptr };  // u minutama
    char _kratakSadrzaj[100] = "";
    Datum _datumPremijere;

    int _maxOcjena; // velicina niza '_ocjene'
    int _trenutnoOcjena = 0;    // brojac
    int* _ocjene{ nullptr };
    
public:
    
    // Z3.0 :: dflt ctor
    Epizoda() {
        
        // implementirati funkciju
        
    }
    
    // Z3.1 :: user-def ctor
    Epizoda(const char* naziv, int trajanje, const char* kratakSadrzaj, Datum datumPremijere, int ukupnoOcjena) {
        
        setNaziv(naziv);
        setTrajanje(trajanje);
        setKratakSadrzaj(kratakSadrzaj);
        setDatumPremijere(datumPremijere);
        setOcjene(0, ukupnoOcjena); // Salje trenutno i max [postavljanje niza]
        
        // setOcjene(trenutno, max, ocjene) -> trenutno, max, drugi niz [postavljanje niza + kopiranje iz drugog niza]
        
    }

    // Z3.2 :: copy ctor
    Epizoda(const Epizoda& epizoda) {
        
        setNaziv(epizoda.getNaziv());
        setTrajanje(epizoda.getTrajanje());
        setKratakSadrzaj(epizoda.getKratakSadrzaj());
        setDatumPremijere(epizoda.getDatumPremijere());
        setOcjene(epizoda.getTrenutnoOcjena(), epizoda.getMaxBrojOcjena(), epizoda.getOcjene());
        
    }

    // Z3.3 :: getteri
    const char* getNaziv() const {
        return (_naziv == nullptr) ? "" : _naziv;
    }
    
    int getTrajanje() const {
        return (_trajanje == nullptr) ? 0 : *_trajanje;
    }
    
    const char* getKratakSadrzaj() const {
        return _kratakSadrzaj;
    }
    
    Datum getDatumPremijere() const {
        return _datumPremijere;
    }
    
    int getTrenutnoOcjena() const {
        return _trenutnoOcjena;
    }
    
    int getMaxBrojOcjena() const {
        return _maxOcjena;
    }
    
    int* getOcjene() const {
        return nullptr;
    }
    
    int getOcjena(int index) const {
        
        if (index < 0 || index > getTrenutnoOcjena()) {
            return 0;
        }
        
        return _ocjene[index];
        
    }
    
    // Z3.4 :: setteri
    void setNaziv(const char* naziv) {
        
        delete[] _naziv;
        _naziv = alocirajTekst(naziv);
        
    }
    
    void setTrajanje(int trajanje) {
        
        if (_trajanje == nullptr) {
            _trajanje = new int;
        }
        
        *_trajanje = trajanje;
        
    }
    
    void setKratakSadrzaj(const char* kratakSadrzaj) {
        
        strcpy_s(_kratakSadrzaj, size(_kratakSadrzaj), kratakSadrzaj);
        // strcpy(_kratakSadrzaj, kratakSadrzaj);   // for my unix homies
        
    }
    
    void setDatumPremijere(Datum datum) {
        
        _datumPremijere.set(datum); // Pogresno: _datumPremijere = datum;
        
    }
    
    // Z3.5 :: metoda koja brise postojeci niz i kreira novi na osnovu tri unesena parametra
    // također, metoda mora uraditi kopiranje ocjena ako je ulazni pokazivač 'ocjene' različit od NULL
    void setOcjene(int trenutnoOcjena, int maxOcjena, int* ocjene = nullptr) {
        
        // Ocjene
        // 0 1 2 3 4 5    6
        // 5 6 7 8 9 JUNK JUNK
        // Trenutno: 5
        // maxOcjena: 7
        
        delete[] _ocjene;   // Dealokacija starog niza
        
        _maxOcjena = maxOcjena; // Promjena velicine
        _trenutnoOcjena = 0;    // Resetovanje brojaca
        
        _ocjene = new int[_maxOcjena];
        
        if (ocjene != nullptr) {
            
            for (int i = 0; i < trenutnoOcjena; i++) {
                
                // _ocjene[i] = ocjene[i];
                dodajOcjenu(ocjene[i]);
                
            }
            
        }
        
    }

    // Z3.6 :: metoda za kopiranje vrijednosti
    void set(const Epizoda& epizoda) {
        
        setNaziv(epizoda.getNaziv());
        setTrajanje(epizoda.getTrajanje());
        setKratakSadrzaj(epizoda.getKratakSadrzaj());
        setDatumPremijere(epizoda.getDatumPremijere());
        setOcjene(epizoda.getTrenutnoOcjena(), epizoda.getMaxBrojOcjena(), epizoda.getOcjene());
        
    }

    // Z3.7
    // Prosiriti niz _ocjene na sljedeci nacin:
    //  * Konstruisati novi niz velicine [_maxBrojOcjena + prosiriZa]
    //  * Kopirati vrijednosti iz starog niza u novi niz
    //  * Dealocirati stari niz
    void expandOcjene(int uvecanje) {
        
        if (uvecanje <= 0) {
            return;
        }
        
        int* temp = _ocjene;
        _ocjene = new int[_maxOcjena + uvecanje];
        
        for (int i = 0; _trenutnoOcjena; i++) {
            _ocjene[i] = temp[i];
        }
        
        _maxOcjena += uvecanje;
        
        delete[] temp;
        temp = nullptr;
        
    }

    // Z3.8 :: metoda za dodavanje ocjene
    // Ukoliko je brojac dosao do kraja (jednak velicini niza), uraditi prosirivanje niza za 10 elemenata
    void dodajOcjenu(int ocjena) {
        
        if (_trenutnoOcjena == _maxOcjena) {
            expandOcjene(10);
        }
        
        _ocjene[_trenutnoOcjena] = ocjena;
        _trenutnoOcjena++;
        
    }
    
    // Z3.9 :: metoda za uklanjanje zadnje ocjene
    bool ukloniZadnjuOcjenu() {
        
        if (_trenutnoOcjena == 0) {
            return false;
        }
        
        _trenutnoOcjena--;
        
        return true;
        
    }
    // Z3.10
    float getProsjecnaOcjena() const {
        
        float suma = 0.0f;
        
        if (_trenutnoOcjena == 0) {
            return suma;
        }
        
        for (int i = 0; i < _trenutnoOcjena; i++) {
            suma += _ocjene[i];
        }
        
        return suma / _trenutnoOcjena;
        
    }
    
    // Z3.11
    void ispis() const {
        
        cout << "Naziv: " << getNaziv() << endl;
        cout << "Trajanje (u minutama): " << getTrajanje() << endl;
        cout << "Kratak sadrzaj: " << getKratakSadrzaj() << endl;
        cout << "Premijerno prikazivanje: ";
        
        getDatumPremijere().ispis();
        
        cout << endl;
        
        cout << "Prosjecna ocjena: " << getProsjecnaOcjena() << endl;
        
    }
    
    // Z3.12
    ~Epizoda() {
        
        delete[] _naziv, delete[] _ocjene;
        delete _trajanje;
        
    }
    
};

class Uloga {
    
    Glumac* _glumac{ nullptr };
    char* _opis{ nullptr };
    char* _tipUloge{ nullptr }; // Glavna, sporedna, epizodna, statista, gostujuca zvijezda, cameo ...
    
public:
    
    // Z4.0 :: dflt ctor
    
    Uloga() {
        
        // implementirati funkciju
        
    }
    
    // Z4.1 :: user-def ctor
    Uloga(Glumac glumac, const char* opis, const char* tip) {
    
        // implementirati funkciju
        
    }
    
    // Z4.2 :: copy ctor
    Uloga(const Uloga& obj) {
        
        // implementirati funkciju
        
    }
    
    // Z4.2 :: getteri i setteri
    Glumac getGlumac() const { return Glumac(); }  // implementirati funkciju
    const char* getOpis() const { return ""; } // implementirati funkciju
    const char* getTipUloge() const { return ""; } // implementirati funkciju
    void setGlumac(Glumac glumac) {
        // implementirati funkciju
    }
    void setOpis(const char* opis) {
        // implementirati funkciju
    }
    void setTipUloge(const char* tipUloge) {
        // implementirati funkciju
    }
    // Z4.4 :: metoda 'set' za kopiranje
    void set(const Uloga& u) {
        // implementirati funkciju
    }
    // Z4.5
    void ispis() const {
        // implementirati funkciju
    }
    // Z4.6
    ~Uloga() {
        // implementirati funkciju
    }
};
class Serija {
    char* _naziv{ nullptr };
    int _trenutnoUloga = 0; // broj validnih elemenata (adresa dinamičkih objekata tipa Uloga).
    Uloga* _uloge[50] = { nullptr }; //Svi elementi (pokazivaci) se postavljaju na NULL

    int _maxBrojEpizoda = 0; // veličina dinamičkog niza
    int _trenutnoEpizoda = 0; // trenutni broj validnih elemenata (epizoda)
    Epizoda* _epizode{ nullptr }; // pokazivač na dinamički niz
public:
    // Z5.1 :: user-def ctor
    Serija(const char* naziv, int maxBrojEpizoda) {
        // implementirati funkciju
    }

    // Z5.2 :: copy ctor
    Serija(const Serija& obj) {
        // implementirati funkciju
    }
    // Z5.3 :: getteri i setteri
    const char* getNaziv() const { return ""; }  // implementirati funkciju
    int getTrenutnoUloga() const { return _trenutnoUloga; }
    Uloga** getUloge() const { return nullptr; } // implementirati funkciju
    int getTrenutnoEpizoda() const { return _trenutnoEpizoda; }
    int getMaxBrojEpizoda() const { return _maxBrojEpizoda; }
    Epizoda* getEpizode() const { return nullptr; } // implementirati funkciju
    void setNaziv(const char* naziv) {
        // implementirati funkciju
    }

    // Z5.4 :: setter za niz pokazivača '_uloge'.Izbrisati postojece uloge i kreirati nove na osnovu ulaznih parametara
    void setUloge(int trenutnoUloga, Uloga** uloge = nullptr) {
        // implementirati funkciju
    }

    // Z5.5 :: setter za pokazivač na niz '_epizode'. Izbrisati postojece epizode i kreirati nove na osnovu ulaznih parametara
    void setEpizode(int trenutnoEpizoda, int maxBrojEpizoda, Epizoda* epizode = nullptr) {
        // implementirati funkciju
    }

    // Z5.6 :: funkcija za dodavanje uloge u niz pokazivaca
    bool dodajUlogu(Uloga uloga) {
        // implementirati funkciju
        return false;
    }
    // Z5.7 :: funkcija za dodavanje epizoda u niz epizoda
    bool dodajEpizodu(Epizoda ep) {
        // implementirati funkciju
        return false;
    }

    // Z5.8 :: metoda koja vraća adresu epizode sa najvećom prosječnom ocjenom
    Epizoda* getNajboljeOcijenjenaEpizoda() {
        // implementirati funkciju
        return nullptr;
    }

    // Z5.9 :: pored ostalih atributa ispisati i sve uloge i sve epizode
    void ispis() {
        // implementirati funkciju
    }
    // Z5.10
    ~Serija() {
        // implementirati funkciju
    }
};
void zadatak1() {
    cout << "Testiranje klase 'Datum'\n\n";
    Datum novaGodina; // dflt ctor
    novaGodina.setDan(1);
    novaGodina.setMjesec(1);
    novaGodina.setGodina(2024);
    novaGodina.ispis();
    cout << endl;
    Datum prviFebruar(novaGodina.getDan(), novaGodina.getMjesec() + 1, novaGodina.getGodina());
    prviFebruar.ispis();
    cout << endl;

    Datum prviMart(1, 3, 2024); // user-def. ctor
    Datum prviTreceg(prviMart); // copy ctor
    prviTreceg.ispis();
    cout << endl;

    Datum danSale(1, 4, 2024);
    Datum prviCetvrtog;
    prviCetvrtog.set(danSale); // metoda 'set' (kopiranje)
    prviCetvrtog.ispis();
    cout << endl;
    cout << "Dealokacija ..." << endl;
}

void zadatak2() {
    cout << "Testiranje klase 'Glumac'\n\n";
    Glumac ryanGosling; // dflt ctor
    ryanGosling.setIme("Ryan");
    ryanGosling.setPrezime("Gosling");
    ryanGosling.setSpol(1);
    ryanGosling.setDatumRodjenja(Datum(1, 1, 1980));
    ryanGosling.setZemljaPorijekla("Kanada");
    ryanGosling.ispis();
    cout << endl;
    //
    Glumac harrisonFord("Harrison", "Ford", "SAD", Datum(2, 2, 1955), 1); // user-def. ctor
    Glumac michellePfeifer("Michelle", "Pfeiffer", "SAD", Datum(3, 3, 1966), 0); // user-def. ctor
    harrisonFord.ispis();
    cout << endl;
    michellePfeifer.ispis();
    cout << endl;

    Glumac jackNicholson;
    jackNicholson.setIme("Jack");
    jackNicholson.setPrezime("Nicholson");
    jackNicholson.setSpol(1);
    jackNicholson.setDatumRodjenja(Datum(1, 4, 1945));
    jackNicholson.setZemljaPorijekla("SAD");
    jackNicholson.ispis();
    cout << endl;

    Glumac heathLedger;
    heathLedger.setIme("Heath");
    heathLedger.setPrezime("Ledger");
    heathLedger.setSpol(1);
    heathLedger.setDatumRodjenja(Datum(5, 3, 1983));
    heathLedger.setZemljaPorijekla("Australija");
    heathLedger.ispis();
    cout << endl;

    Glumac jaredLeto(heathLedger); // copy ctor
    jaredLeto.setIme("Jared");
    jaredLeto.setPrezime("Leto");
    jaredLeto.setSpol(1);
    jaredLeto.setDatumRodjenja(Datum(26, 12, 1971));
    jaredLeto.setZemljaPorijekla("SAD");
    jaredLeto.ispis();
    cout << endl;
    cout << "Dealokacija ..." << endl;
}
void zadatak3() {
    cout << "Testiranje klase 'Epizoda'\n\n";
    Epizoda e1;
    e1.setNaziv("What's Cooking?");
    e1.setTrajanje(21);
    e1.setKratakSadrzaj("Bender decides to become a chef so ...");
    e1.setDatumPremijere(Datum(5, 5, 2024));
    e1.ispis();
    cout << endl;

    Epizoda e2("This Mission is Trash", 22, "Fry, Leela, and Bender travel to the garbage meteor and discover loads of discardedjunk.", Datum(13, 5, 2024), 10);
    e2.ispis();
    cout << endl;

    Epizoda e3;
    e3.setNaziv("Smell-o-Scope");
    e3.setTrajanje(20);
    e3.setKratakSadrzaj("Using Professor Farnsworth's Smell-o-Scope, Fry locates the stinkiest object in the universe.");
    e3.setDatumPremijere(Datum(21, 5, 2024));
    e3.ispis();
    cout << "\n\n";


    Epizoda e4;
    e4.setNaziv("Electric Drug");
    e4.setTrajanje(24);
    e4.setKratakSadrzaj("Bender's electricity addiction puts the Planet Express crew in danger");
    e4.setDatumPremijere(Datum(29, 5, 2024));
    cout << "Dodavanje ocjena: --->" << endl;
    // dodavanje 15 random ocjena
    for (int i = 0; i < 15; i++) {
        int ocjena = rand() % 10 + 1;
        cout << ocjena << " ";
        e4.dodajOcjenu(ocjena);
    }
    // brisemo zadnje dvije ocjene
    e4.ukloniZadnjuOcjenu();
    e4.ukloniZadnjuOcjenu();
    cout << endl;

    Epizoda e5(e4); // copy ctor [kopiranje svih atributa ukljucujuci i ocjene
    e5.ispis();
    cout << "Dealokacija ..." << endl;
}

void zadatak4() {
    cout << "Testiranje klase 'Uloga'\n\n";
    Glumac seanConnery("Sean", "Connery", "Velika Britanija", Datum(25, 8, 1930), 1);
    Glumac danielCraig("Daniel", "Craig", "Velika Britanija", Datum(2, 3, 1968), 1);
    Uloga jamesBond(seanConnery, "MI6 Detective James Bond ....", "Main role");
    jamesBond.setGlumac(danielCraig);
    jamesBond.setOpis("After earning 00 status and a licence to kill, Secret Agent James Bond sets out on his first mission as 007.");
    jamesBond.setTipUloge("Main role");

    // testiranje copy ctor-a
    Uloga bond23(jamesBond); // copy ctor
    bond23.ispis();
    cout << "Dealokacija ..." << endl;
}

void zadatak5() {
    cout << "Testiranje klase 'Serija'\n\n";
    // objekti tipa 'Glumac'
    Glumac jimParsons("Jim", "Parsons", "SAD", Datum(17, 7, 1967), 1);
    Glumac johnnyGalecki("Johnny", "Galecki", "SAD", Datum(15, 3, 1975), 1);
    Glumac kaleyCuoco("Kaley", "Cuoco", "SAD", Datum(13, 4, 1985), 0);

    // objekti tipa 'Uloga'
    Uloga sheldonCooper(jimParsons, "Dr. Sheldon Cooper, a theoretical physicist at Caltech", "Series regular");
    Uloga leonardHofstadter(johnnyGalecki, "Dr. Leonard Hofstadter, a experimental physicist at Caltech", "Series regular");
    Uloga penny(kaleyCuoco, "Penny, a waitress at Cheesecake factory", "Series regular");

    // objekti tipa 'Epizoda'
    Epizoda ep1("The Big Bran Hypothesis", 22, "When Sheldon and Leonard drop off a box of flat pack furniture...", Datum(1, 6, 2024), 100);
    Epizoda ep2("The Luminous Fish Effect", 21, "Sheldon is fired from his job as a physicist after insulting his new boss...", Datum(8, 6, 2024), 100);
    Epizoda ep3("The Bat Jar Conjecture", 22, "The guys decide to compete in a university quiz called physics bowl...", Datum(15, 6, 2024), 100);
    Epizoda ep4("The Nerdvana Annihilation", 21, "In an online auction, Leonard buys a full-sized replica o the time machine...", Datum(22, 6, 2024), 100);
    int ocjene1[] = { 5,7,8 };
    int ocjene2[] = { 10,5,7,10,9 };
    int ocjene3[] = { 9,8,9,9 };
    int ocjene4[] = { 10,5,3,7,6,6 };
    // dodavanje ocjena za za svaku epizodu u seriji
    for (int& ocjena : ocjene1)
        ep1.dodajOcjenu(ocjena);
    for (int& ocjena : ocjene2)
        ep2.dodajOcjenu(ocjena);
    for (int& ocjena : ocjene3)
        ep3.dodajOcjenu(ocjena);
    for (int& ocjena : ocjene4)
        ep4.dodajOcjenu(ocjena);

    // ::::::::::::::::: SERIJA ::::::::::::::::
    // objekt tipa 'Serija'
    Serija teorijaVelikogPraska("The Big Bang Theory", 200);
    // dodavanje uloga u seriju
    teorijaVelikogPraska.dodajUlogu(sheldonCooper);
    teorijaVelikogPraska.dodajUlogu(leonardHofstadter);
    teorijaVelikogPraska.dodajUlogu(penny);
    // dodavanje epizoda u seriju
    teorijaVelikogPraska.dodajEpizodu(ep1);
    teorijaVelikogPraska.dodajEpizodu(ep2);
    teorijaVelikogPraska.dodajEpizodu(ep3);
    teorijaVelikogPraska.dodajEpizodu(ep4);


    // testiranje konstruktora kopije
    Serija bigBang(teorijaVelikogPraska); // copy ctor
    bigBang.ispis();

    Epizoda* ep = bigBang.getNajboljeOcijenjenaEpizoda();
    cout << "Najbolje ocijenjena epizoda: " << ep->getNaziv() << endl;
    cout << "Ocjena: " << ep->getProsjecnaOcjena() << endl;
    cout << "Dealokacija ..." << endl;
}

void menu() {
    int nastaviDalje = 1;
    while (nastaviDalje == 1) {
        int izbor = 0;
        do {
            system("cls");
            cout << "::Zadaci::" << endl;
            cout << "(1) Zadatak 1" << endl;
            cout << "(2) Zadatak 2" << endl;
            cout << "(3) Zadatak 3" << endl;
            cout << "(4) Zadatak 4" << endl;
            cout << "(5) Zadatak 5" << endl;
            cout << "Unesite odgovarajuci broj zadatka za testiranje: -->: ";
            cin >> izbor;
            cout << endl;
        } while (izbor < 1 || izbor > 5);
        switch (izbor) {
        case 1: zadatak1(); cout << "Zadatak 1. Done." << endl; break;
        case 2: zadatak2(); cout << "Zadatak 2. Done." << endl; break;
        case 3: zadatak3(); cout << "Zadatak 3. Done." << endl; break;
        case 4: zadatak4(); cout << "Zadatak 4. Done." << endl; break;
        case 5: zadatak5(); cout << "Zadatak 5. Done." << endl; break;
        default:break;
        }
        do {
            cout << "DA LI ZELITE NASTAVITI DALJE? (1/0): ";
            cin >> nastaviDalje;
        } while (nastaviDalje != 0 && nastaviDalje != 1);
    }
}
int main() {
    menu();
    return 0;
}
