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
char* alocirajTekst(const char*);

class Datum {
    
private:
    int* _dan { nullptr };
    int* _mjesec { nullptr };
    int* _godina { nullptr };
    
    // *(nullptr) -> runtime error [dereferenciranje nulte adrese je automatska greska]
    
public:
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
	
	int toInt() {
		
		return getGodina() * 365 + getMjesec() * 30 + getDan();
		
	}
    
    void dealokacija() {
        
        delete _dan, delete _mjesec, delete _godina;
        
        _dan = _mjesec = _godina = nullptr;
        
    }
    
};

class Glumac {
	
private:
	char _jmbg[14] = "";	// "\0" je na samom pocetku
	char* _ime = nullptr;
	char* _prezime = nullptr;
	Datum* _datumRodjenja = nullptr;
	char* _mjestoRodjenja = nullptr;
	char _drzava[100] = "";
	bool _spol;	// 1: Muski, 0: Zenski
	
public:
	void setAll(const char* jmbg, const char* ime, const char* prezime, Datum& datumRodjenja, const char* mjestoRodjenja, const char* drzava, bool spol) {
		
		setJmbg(jmbg);
		setIme(ime);
		setPrezime(prezime);
		setDatumRodjenja(datumRodjenja);
		setMjestoRodjenja(mjestoRodjenja);
		setDrzava(drzava);
		setSpol(spol);
		
	}
	
	void setAll(Glumac& glumac) {
		
		setJmbg(glumac.getJmbg());
		setIme(glumac.getIme());
		setPrezime(glumac.getPrezime());
		setDatumRodjenja(glumac.getDatumRodjenja());
		setMjestoRodjenja(glumac.getMjestoRodjenja());
		setDrzava(glumac.getDrzava());
		setSpol(glumac.getSpol());
		
	}
	
	const char* getJmbg() {
		return _jmbg;
	}
	
	const char* getIme() {
		return (_ime == nullptr) ? "" : _ime;
	}
	
	const char* getPrezime() {
		return (_prezime == nullptr) ? "" : _prezime;
	}
	
	Datum& getDatumRodjenja() {
		
		// Datum datum;
		//
		// if (_datumRodjenja == nullptr) {
		// 	  return datum;
		// }
		
		return *_datumRodjenja;
		
	}
	
	const char* getMjestoRodjenja() {
		return (_mjestoRodjenja == nullptr) ? "" : _mjestoRodjenja;
	}
	
	const char* getDrzava() {
		return _drzava;
	}
	
	bool getSpol() {
		return _spol;
	}
	
	// Uvijek je dobra praksa da povratne vrijednost gettera imaju isti
	// tip kao ulazne vrijednosti settera.
	void setJmbg(const char* jmbg) {
		
		// strcpy(_jmbg, size(_jmbg), jmbg);
		strcpy(_jmbg, jmbg);
		
	}
	
	void setIme(const char* ime) {
		
		// Delete komanda kada naide na nullptr, ignorise ga.
		delete[] _ime;
		
		_ime = alocirajTekst(ime);
		
	}
	
	void setPrezime(const char* prezime) {
		
		delete[] _prezime;
		
		_prezime = alocirajTekst(prezime);
		
	}
	
	void setDatumRodjenja(Datum& datumRodjenja) {
		
		if (_datumRodjenja == nullptr) {
			_datumRodjenja = new Datum;	// Alokacija jednog dinamickog objekta strukture Datum
		}
		
		// Primjer 1
		(*_datumRodjenja).setAll(datumRodjenja);
		
		// Primjer 2
		_datumRodjenja->setAll(datumRodjenja);
		
	}
	
	void setMjestoRodjenja(const char* mjestoRodjenja) {
		
		delete[] _mjestoRodjenja;
		
		_mjestoRodjenja = alocirajTekst(mjestoRodjenja);
		
	}
	
	void setDrzava(const char* drzava) {
		
		// strcpy(_drzava, size(_drzava), drzava);
		strcpy(_drzava, drzava);
		
	}
	
	void setSpol(bool spol) {
		_spol = spol;
	}
	
	void ispis() {
		
		cout << "Ime i Prezime: " << getIme() << " " << getPrezime() << endl;
		cout << "Datum Rodjenja: ";
		
		// Ovo ce ispisati error ako je null!
		// _datumRodjenja->ispis();
		
		getDatumRodjenja().ispis();
		
		cout << "Mjesto i Drzava Rodjenja: " << getMjestoRodjenja() << ", " << getDrzava() << endl;
		
		cout << "Spol: " << (getSpol() ? "Muski" : "Zenski") << endl;
		
	}
	
	void dealokacija() {
		
		// Ovo ce ispisati error ako je null!
		// _datumRodjenja->dealokacija();
		
		getDatumRodjenja().dealokacija(); // Brisanje atributa
		
		delete _datumRodjenja; // Brisanje pokazivaca
		
		delete[] _ime, delete[] _prezime, delete[] _mjestoRodjenja;
		
		_ime = _prezime = _mjestoRodjenja = nullptr, _datumRodjenja = nullptr;
		
	}
	
};

class Film {
	
private:
	// Opisni Atributi
	char _filmID[50] = "";	// ISAN standard
	char* _naziv = nullptr;
	char _zanr[40] = "";
	int _godinaIzlaska = 0;
	
	int _trenutnoGlumaca = 0;	// Brojacka varijabla
	Glumac _glumackaPostava[20];
	
	int _trenutnaOcjena = 0;	// Brojacka varijabla
	int* _ocjene = nullptr;
	
public:
	const char* getFilmID() {
		return _filmID;
	}
	
	const char* getNaziv() {
		return (_naziv == nullptr) ? "" : _naziv;
	}
	
	const char* getZanr() {
		return _zanr;
	}
	
	int getGodinaIzlaska() {
		return _godinaIzlaska;
	}
	
	int getTrenutnoGlumaca() {
		return _trenutnoGlumaca;
	}
	
	Glumac* getGlumackaPostava() {
		return _glumackaPostava;
	}
	
	int getTrenutnaOcjena() {
		return _trenutnaOcjena;
	}
	
	int* getOcjene() {
		return _ocjene;
	}
	
	void setFilmID(const char* filmID) {
		
		// Use secure version!!!1
		// strcpy_s(_filmID, size(_filmID, filmID))
		strcpy(_filmID, filmID);
		
	}
	
	void setNaziv(const char* naziv) {
		
		delete[] _naziv;
		_naziv = alocirajTekst(naziv);
		
	}
	
	void setZanr(const char* zanr) {
		
		// strcpy_s(_zanr, size(_zanr, zanr))
		strcpy(_zanr, zanr);
		
	}
	
	void setGodinaIzlaska(int godinaIzlaska) {
		_godinaIzlaska = godinaIzlaska;
	}
	
	void setGlumackaPostava(Glumac* glumci, int velicina) {
		
		// Code goes here...soon™
		
	}
	
	void setOcjene(int* ocjene, int velicina) {
		
		// Code goes here... soon™
		
	}
	
	bool dodajGlumca(Glumac& glumac) {
		
		if (getTrenutnoGlumaca() == size(_glumackaPostava)) {
			return false;
		}
		
		_glumackaPostava[_trenutnoGlumaca].setAll(glumac);
		_trenutnoGlumaca++;
		
		return true;
		
	}
	
	bool dodajOcjenu(int ocjena) {
		
		/*
			
			Sa svakim pozivom je potrebno uraditi dinamicko prosirivanje
			niza za 1.
		 
			Ne smiju se izgubiti podaci o prethodnim ocjenama.
		 
			Hint: sacuvati stari niz u jedan privremeni pokazivac,
			kreirati novi niz (veci za 1), kopirati iz starog u novi,
			kopirati vrijednost 'ocjena' na odgovarajuce mjesto i na
			kraju uvecati brojac.
		 
			GL ;)
		 
		 */
		
	}
	
};

bool areEqual(Datum& datum1, Datum& datum2) {
	
	return datum1.getDan() == datum2.getDan()
		&& datum1.getMjesec() == datum2.getMjesec()
		&& datum1.getGodina() == datum2.getGodina();
	
}

// Datum& je izlazni parametar (ulaznik parametar koji izlazi iz
// funkcije kao povratna vrijednost).
Datum& getStarijiDatum(Datum& datum1, Datum& datum2) {
	
	return datum1.toInt() < datum2.toInt() ? datum1 : datum2;
	
}

Datum& getNovijiDatum(Datum& datum1, Datum& datum2) {
	
	return datum1.toInt() > datum2.toInt() ? datum1 : datum2;
	
}

Datum* getNajstarijiDatum(Datum datumi[], int size) {
	
	Datum* temp = &datumi[0];	// Adresa prvog objekta iz niza.
	
	for (int i = 0; i < size; i++) {
		temp = &getStarijiDatum(*temp, datumi[i]);
	}
	
	return temp;
	
}

Datum* getNajnovijiDatum(Datum datumi[], int size) {
	
	Datum* temp = &datumi[0];	// Adresa prvog objekta iz niza.
	
	for (int i = 0; i < size; i++) {
		temp = &getNovijiDatum(*temp, datumi[i]);
	}
	
	return temp;
	
}

// Z0.1 Utility funkcija za alokaciju teksta
char* alocirajTekst(const char* tekst) {
    
    // Ova provjera je obavezna zbog toga sto bi kasnije moglo doci do greske (RE)
    // Buduci da string funkcije (funkcije za rad sa char*) ne prihvataju nullptr
    // kao validnu vrijednost
    if (tekst == nullptr) {
        return nullptr;
    }
    
    int vel = strlen(tekst) + 1;
    
    char* novi = new char[vel];	// Alokacija novog teksta
    
    // Xcode has forced my hand and I cannot use the secure version :(
    // strcpy_s(novi, vel, tekst);
    strcpy(novi, tekst);
    
    return novi;
    
}

void zadatak1() {
    
    // Datum danNezavisnosti;
    
    // danNezavisnosti.setDan(2);  // Alokacija + promjena vrijednosti
    // danNezavisnosti.setDan(12); // Promjena vrijednosti
    // danNezavisnosti.setDan(1);  // Promjena vrijednosti
    
    // danNezavisnosti.setMjesec(3);   // Alokacija + promjena vrijednosti
    // danNezavisnosti.setMjesec(2);   // Promjena vrijednosti
    // danNezavisnosti.setMjesec(3);   // Promjena vrijednosti
    
    // danNezavisnosti.setGodina(2024);
    
    // danNezavisnosti.setAll(1, 3, 2024);
    // danNezavisnosti.setAll(1, 5, 2024);
    // danNezavisnosti.setAll(5, 4, 2024);
    
    // Datum noviDatum;
    
    // Primjer 1
    // noviDatum.setAll(danNezavisnosti);
    
    // Primjer 2
    // noviDatum.setAll(danNezavisnosti.getDan(), danNezavisnosti.getMjesec(), danNezavisnosti.getGodina());
    
    // Primjer 3
    // noviDatum.setAll(&danNezavisnosti);
    
    // danNezavisnosti.ispis();
	
	/*
	 
		Ovaj dio moze da dovede do RE-a. Zbog toda sto imamo raw_copy (bukvalno
		kopiranje) vrijednosti attributa iz jednog objekta u drugi.
	 
		(Vrijednost pokazivaca iz objekta danNezavisnoti se kopiraju u vrijednost
		pokazivaca objekta "noviDatum2").
	 
		[To je problem], iz razloga sto imamo pokazivace u razlicitim objektima
		sa istim adresama.
	 
		Ovo ce dovesti do rusenja programa zbog pokusaja dvostruke dealokacije
		istog memorijskog prostora.
	 
		---
	 
		Ova greska ce se adekvatno rijesavati implementacijom eksplicitnog
		konstruktora kopije.
	 
	 */
	// Datum noviDatum2 = danNezavisnosti; --> GRESKA!!!
    
    // danNezavisnosti.dealokacija();
	
	// noviDatum.ispis();
	
	// noviDatum.dealokacija();
	
	Datum prviMart;
	prviMart.setAll(1, 3, 2024);
	
	Datum prviMaj;
	prviMaj.setAll(1, 5, 2024);
	
	areEqual(prviMart, prviMaj) ? cout << "Datumi su isti." << endl : cout << "Datumi nisu isti." << endl;
	
	Datum danD, operacijaBarbarossa, sarajevskiAtentat, apolloSlijetanje, blackThursday;
	
	danD.setAll(6, 6, 1944);
	operacijaBarbarossa.setAll(2, 6, 1941);
	sarajevskiAtentat.setAll(28, 6, 1914);
	apolloSlijetanje.setAll(24, 7, 1969);
	blackThursday.setAll(24, 10, 1929);
	
	Datum historijskiDogadjaji[5];
	
	historijskiDogadjaji[0].setAll(danD);
	historijskiDogadjaji[1].setAll(operacijaBarbarossa);
	historijskiDogadjaji[2].setAll(sarajevskiAtentat);
	historijskiDogadjaji[3].setAll(apolloSlijetanje);
	historijskiDogadjaji[4].setAll(blackThursday);
	
	cout << endl << "Najstariji datum: " << endl;
	getNajstarijiDatum(historijskiDogadjaji, 5)->ispis();
	
	cout << endl << "Najnoviji datum: " << endl;
	getNajnovijiDatum(historijskiDogadjaji, 5)->ispis();
	
	danD.dealokacija();
	operacijaBarbarossa.dealokacija();
	sarajevskiAtentat.dealokacija();
	apolloSlijetanje.dealokacija();
	blackThursday.dealokacija();
	
	for (int i = 0; i < 5; i++) {
		historijskiDogadjaji[i].dealokacija();
	}
	
	prviMart.dealokacija();
	prviMaj.dealokacija();
	
	cout << endl << "<><><> Dealokacija uspjesna! <><><>" << endl;
    
}

void zadatak2() {
    
	Glumac alPacino, deNiro;
	Datum temp1, temp2;
	
	temp1.setAll(25, 4, 1940);
	temp2.setAll(17, 8, 1943);
	
	alPacino.setAll("1304996055555", "Alfredo", "Pacino", temp1, "Manhattan, NYC", "SAD", true);
	
	// deNiro = alPacino -> Pogresno kopiranje
	deNiro.setAll(alPacino);	// Ispravno kopiranje
	
	deNiro.setIme("Robert");
	deNiro.setPrezime("De Niro");
	deNiro.setDatumRodjenja(temp2);
	deNiro.setMjestoRodjenja("Greenwich Village");
	// deNiro.setDrzava("SAD");
	// deNiro.setSpol(true);
	
	alPacino.ispis();
	deNiro.ispis();
	
	temp1.dealokacija();
	temp2.dealokacija();
	
	alPacino.dealokacija();
	deNiro.dealokacija();
    
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
