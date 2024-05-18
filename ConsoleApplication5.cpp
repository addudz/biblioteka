#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Data {
private:
    int dzien;
    int miesiac;
    int rok;
public:
    Data(int d, int m, int r) : dzien(d), miesiac(m), rok(r) {}
    void wyswietl_date() { cout << dzien << "." << miesiac << "." << rok << endl; }
};

class Osoba {
private:
    string imie;
    string nazwisko;
    int numer_telefonu;
    string email;
    string pesel;
public:
    Osoba(const string& i, const string& n, const int& t, const string& e, const string& p) : imie(i), nazwisko(n), numer_telefonu(t), email(e), pesel(p) {}
    Osoba() {}
    string get_imie() { return imie; }
    string get_nazwisko() { return nazwisko; }
    int get_numer_telefonu() { return numer_telefonu; }
    string get_email() { return email; }
    string get_pesel() { return pesel; }

    void set_imie(string i) { imie = i; }
    void set_nazwisko(string n) { nazwisko = n; }
    void set_numer_telefonu(int nr) { numer_telefonu = nr; }
    void set_email(string e) { email = e; }
    void set_pesel(string p) { pesel = p; }
};

class Uzytkownik : public Osoba {
public:
    Uzytkownik(const string& i, const string& n, const int& t, const string& e, const string& p) : Osoba(i, n, t, e, p) {}
    Uzytkownik() {}
    void wyswietl_uzytkownika() {
        cout << Osoba::get_imie() << " " << Osoba::get_nazwisko() << endl << "telefon: " << Osoba::get_numer_telefonu() << endl
            << "email: " << Osoba::get_email() << endl << "pesel: " << Osoba::get_pesel() << endl;
        cout << endl;
    }
    // Dodaj odpowiednie funkcje obsługujące przypadki w switchu
    void sprawdz_dane_uzytkownika() {
        wyswietl_uzytkownika();
    }
    bool czy_pesel_w_systemie(string p) {
        if (p == Osoba::get_pesel()) return true;
        else return false;
    }
    void dodaj_uzytkownika() {
        string imie, nazwisko, email, pesel;
        int numer_telefonu;

        cout << "podaj imie: " << endl;
        cin >> imie;
        Uzytkownik::set_imie(imie);

        cout << "podaj nazwisko: " << endl;
        cin >> nazwisko;
        Uzytkownik::set_nazwisko(nazwisko);

        cout << "podaj email: " << endl;
        cin >> email;
        Uzytkownik::set_email(email);

        cout << "podaj numer_telefonu: " << endl;
        cin >> numer_telefonu;
        Uzytkownik::set_numer_telefonu(numer_telefonu);

        cout << "podaj pesel: " << endl;
        cin >> pesel;
        Uzytkownik::set_pesel(pesel);
    }

    void edytuj_dane_uzytkownika() {
        int wybor;
        string imie, nazwisko, email, pesel;
        int numer_telefonu;
        cout << "Wybierz konkretny segment do edycji: " << endl;
        cout << " 1. imie" << endl;
        cout << " 2. nazwisko" << endl;
        cout << "3. email" << endl;
        cout << "4. pesel" << endl;
        cout << "5. numer_telefonu" << endl;
        cout << "Twoj wybor: " << endl;
        cin >> wybor;
        switch (wybor) {
        case 1: {
            cout << "podaj imie do zmiany: " << endl;
            cin >> imie;
            Uzytkownik::set_imie(imie);
        }
        case 2: {
            cout << "podaj nazwisko do zmiany: " << endl;
            cin >> nazwisko;
            Uzytkownik::set_nazwisko(nazwisko);
        }
        case 3: {

            cout << "podaj email do zmiany: " << endl;
            cin >> email;
            Uzytkownik::set_email(email);
        }
        case 4: {
            cout << "podaj pesel do zmiany: " << endl;
            cin >> pesel;
            Uzytkownik::set_pesel(pesel);
        }
        case 5: {
            cout << "podaj numer_telefonu do zmiany: " << endl;
            cin >> numer_telefonu;
            Uzytkownik::set_numer_telefonu(numer_telefonu);
        }
        }
    }
    void usun_uzytkownika_z_systemu(Uzytkownik &U) {
        delete &U;
    }
    void sprawdz_nieoplacone_grzywny() {
        // implementacja
    }
};

class Autor {
private:
    string imie;
    string nazwisko;
public:
    Autor(const string& i, const string& n) : imie(i), nazwisko(n) {}
    string get_imie() { return imie; }
    string get_nazwisko() { return nazwisko; }
    void set_imie(string i) { imie = i; }
    void set_nazwisko(string n) { nazwisko = n; }
    // Dodaj odpowiednie funkcje obsługujące przypadki w switchu
    void sprawdz_dane_autora() {
        cout << get_imie() << " " << get_nazwisko() << endl;
    }
    bool czy_autor_istnieje(string i, string n) {
        if (i == imie && n == nazwisko) {
            cout << "autor: " << imie << " " << nazwisko << " wystepuje w systemie" << endl;
            return true;
        }
        else
            cout << "brak autora w systemie" << endl; return false;
    }
    void dodaj_autora() {
        string imie, nazwisko;

        cout << "podaj imie: " << endl;
        cin >> imie;
        Autor::set_imie(imie);

        cout << "podaj nazwisko: " << endl;
        cin >> nazwisko;
        Autor::set_nazwisko(nazwisko);
    }
    void edytuj_dane_autora() {
        int wybor;
        string imie, nazwisko, email, pesel;
        int numer_telefonu;
        cout << "Wybierz konkretny segment do edycji: " << endl;
        cout << " 1. imie" << endl;
        cout << " 2. nazwisko" << endl;
        cout << "Twoj wybor: " << endl;
        cin >> wybor;
        switch (wybor) {
        case 1: {
            cout << "podaj imie do zmiany: " << endl;
            cin >> imie;
            Autor::set_imie(imie);
        }
        case 2: {
            cout << "podaj nazwisko do zmiany: " << endl;
            cin >> nazwisko;
            Autor::set_nazwisko(nazwisko);
        }

        }
    }
    void usun_autora_z_systemu() {
        // implementacja
    }
    void wyszukaj_ksiazke_po_autorze(string i, string n) {
        cout << "podaj imie: ";
        string imie, nazwisko;
        cin >> imie;
        cout << endl << "podaj nazwisko: ";
        cin >> nazwisko;
        //trzeba tu wyswietlic wszystkie ksiazki tego autora
    }
};

class Egzemplarz {
private:
    string wydanie;
    string ISBN;
public:
    Egzemplarz(const string& w, const string& i) : wydanie(w), ISBN(i) {}
    string get_wydanie() { return wydanie; }
    string get_ISBN() { return ISBN; }
};

class Ksiazka {
private:
    Autor autor;
    string tytul;
    string gatunek;
    vector<Egzemplarz> egzemplarze;
    Data data_wydania;
public:
    Ksiazka(const Autor& a, const string& t, const string& g, const Data& d) : autor(a), tytul(t), gatunek(g), data_wydania(d) {}
    Autor get_autor() { return autor; }
    string get_tytul() { return tytul; }
    string get_gatunek() { return gatunek; }
    Data get_data_wydania() { return data_wydania; }
    vector<Egzemplarz>& get_egzemplarze() { return egzemplarze; }
    void dodaj_egzemplarz(const Egzemplarz& e) { egzemplarze.push_back(e); }
    void usun_egzemplarz() { egzemplarze.pop_back(); }
    // Dodaj odpowiednie funkcje obsługujące przypadki w switchu
    void sprawdz_szczegoly_ksiazki() {
        // implementacja
    }
    void czy_ISBN_w_systemie() {
        // implementacja
    }
    void dodaj_ksiazke() {
        // implementacja
    }
    void edytuj_dane_ksiazki() {
        // implementacja
    }
    void usun_ksiazke_z_systemu() {
        // implementacja
    }
    void sprawdz_liczbe_egzemplarzy() {
        // implementacja
    }
    void wyszukaj_ksiazke_po_tytule() {
        // implementacja
    }
    void wyszukaj_ksiazke_po_numerze_ISBN() {
        // implementacja
    }
    void wyswietl_ksiazki_z_danego_gatunku() {
        // implementacja
    }
    void wyszukaj_ksiazki_po_dacie_wydania() {
        // implementacja
    }
};

class Wypozyczenie : public Data {
private:
    Ksiazka& ksiazka;
    Uzytkownik& uzytkownik;
public:
    Wypozyczenie(int d, int m, int r, Ksiazka& k, Uzytkownik& u) : Data(d, m, r), ksiazka(k), uzytkownik(u) {}
    Ksiazka& get_ksiazka() { return ksiazka; }
    Uzytkownik& get_uzytkownik() { return uzytkownik; }
};

class Biblioteka {
private:
    vector<Ksiazka> zbior_ksiazek;
    vector<Wypozyczenie> wypozyczenia;
    vector<Uzytkownik> uzytkownicy;
public:
    vector<Ksiazka> get_zbior_ksiazek() { return zbior_ksiazek; }
    vector<Wypozyczenie> get_wypozyczenia() { return wypozyczenia; }
    vector<Uzytkownik> get_uzytkownicy() { return uzytkownicy; }
    void dodaj_ksiazke(const Ksiazka& k) { zbior_ksiazek.push_back(k); }
    // Metoda zwracająca referencję do zbioru książek
    const vector<Ksiazka>& get_zbior_ksiazek() const { return zbior_ksiazek; }
    void wypozycz_ksiazke(Ksiazka& k, Uzytkownik& u, int d, int m, int r) {
        for (Ksiazka& ks : zbior_ksiazek) {
            if (ks.get_tytul() == k.get_tytul() && ks.get_autor().get_imie() == k.get_autor().get_imie() && ks.get_autor().get_nazwisko() == k.get_autor().get_nazwisko() && ks.get_gatunek() == k.get_gatunek()) {
                if (!ks.get_egzemplarze().empty()) {
                    Wypozyczenie wyp(d, m, r, ks, u);
                    wypozyczenia.push_back(wyp);
                    ks.usun_egzemplarz();
                    cout << "Ksiazka \"" << ks.get_tytul() << "\" wypozyczona przez " << u.get_imie() << " " << u.get_nazwisko() << endl;
                    return;
                }
            }
        }
        cout << "Brak dostepnych egzemplarzy ksiazki \"" << k.get_tytul() << "\"" << endl;
    }
    // Dodaj funkcje obsługujące przypadki w switchu
    void wyswietl_informacje_o_bibliotece() {
        // implementacja
    }
    void edytuj_dane_biblioteki() {
        // implementacja
    }
};



int main()
{
    cout << "Wszyscy uzytkownicy w bazie: " << endl;
    Uzytkownik uzytkownik1("Jan", "Kowalski", 123456789, "jan.kowalski@example.com", "1234567890");
    Uzytkownik uzytkownik2("Julia", "Nowak", 123456789, "julia.nowak@example.com", "1256789655");
    Uzytkownik uzytkownik3("Monika", "Walczyk", 123456789, "monika.walczyk@example.com", "1234897810");
    uzytkownik1.wyswietl_uzytkownika();
    uzytkownik2.wyswietl_uzytkownika();
    uzytkownik3.wyswietl_uzytkownika();

    Autor autor("Olga", "Tokarczuk");
    Data data_wydania(10, 5, 2007);
    Ksiazka ksiazka(autor, "Bieguni", "Literatura klasyczna", data_wydania);
    ksiazka.dodaj_egzemplarz(Egzemplarz("Pierwsze", "9788375780621"));
    ksiazka.dodaj_egzemplarz(Egzemplarz("Drugie", "9788375780622"));
    ksiazka.dodaj_egzemplarz(Egzemplarz("Trzecie", "9788375780623"));

    Biblioteka biblioteka;
    biblioteka.dodaj_ksiazke(ksiazka);

    biblioteka.wypozycz_ksiazke(ksiazka, uzytkownik1, 15, 5, 2024);

    //------------------------SYSTEM BIBLIOTECZNY----------------------------------------------------------
    int wybor;
    cout << "Witamy w systemie bibliotecznym SBA :)" << endl;
    cout << "Proszę wybierać jeden z obszarów, w którym chcesz dokonać operacji: " << endl;
    cout << "1. Wypozyczenie/ Zwrot" << endl;
    cout << "2. Użytkownik" << endl;
    cout << "3. Autor" << endl;
    cout << "4. Ksiazka" << endl;
    cout << "5. Status" << endl;
    cout << "6. Biblioteka ogólne" << endl;
    cin >> wybor;
    cout << endl;
    cout << endl;

    switch (wybor) {
    case 1: {
        int decyzja;
        cout << "Wybrales obszar: 'Wypozyczenie/Zwrot'." << endl;
        cout << "Dokonaj wyboru konkretnej operacji z ponizszych dozwolonych: " << endl;
        cout << "1. sprawdz wypozyczenie danej ksiazki" << endl;
        cout << "2. rozpocznij wypozyczenie danej ksiazki" << endl;
        cout << "3. zakoncz wypozyczenie danej ksiazki" << endl;
        cout << "4. sprawdz termin do kiedy ksiazka powinna zostac oddana" << endl;
        cout << "5. zarezerwuj ksiazke" << endl;
        cout << "Twój wybór: ";
        cin >> decyzja;
        cout << endl;
        switch (decyzja)
        {
        case 1:
            // Implementacja
            break;
        case 2:
            // Implementacja
            break;
        case 3:
            // Implementacja
            break;
        case 4:
            // Implementacja
            break;
        case 5:
            // Implementacja
            break;
        }
        break;
    }
    case 2: {
        int decyzja;
        cout << "Wybrales obszar: 'Uzytkownik'." << endl;
        cout << "Dokonaj wyboru konkretnej operacji z ponizszych dozwolonych: " << endl;
        cout << "1. sprawdz dane uzytkownika " << endl;
        cout << "2. sprawdz czy taki pesel jest juz w systemie " << endl;
        cout << "3. dodaj uzytkownika " << endl;
        cout << "4. edytuj dane uzytkownika " << endl;
        cout << "5. usun uzytkownika z systemu" << endl;
        cout << "6. sprawdz czy uzytkownik ma nieoplacone grzywny" << endl;
        cout << "Twój wybór: ";
        cin >> decyzja;
        cout << endl;
        switch (decyzja)
        {
        case 1: {
            string pesel = "";
            bool flaga_czy_uzytkownik_istnieje=false;
            cout << "Podaj PESEL uzytkownika, ktorego dane chcesz sprawdzic: " << endl;
            cin >> pesel;
            cout << endl;
            for (Uzytkownik& uzytkownik : biblioteka.get_uzytkownicy()) {
                if (uzytkownik.get_pesel() == pesel) {
                    cout << "Oto dane uzytkownika: " << endl;
                    uzytkownik.sprawdz_dane_uzytkownika();
                    flaga_czy_uzytkownik_istnieje = true;
                }
            }
            if (!flaga_czy_uzytkownik_istnieje) {
                cout << "Uzytkownik o podanym numerze PESEL nie istenieje w systemie." << endl;
            }
            break;
        }
        case 2: {
            string pesel = "";
            bool flaga_czy_uzytkownik_istnieje = false;
            cout << "Podaj PESEL uzytkownika, ktorego chcesz sprawdzic: " << endl;
            cin >> pesel;
            cout << endl;
            for (Uzytkownik& uzytkownik : biblioteka.get_uzytkownicy()) {
                if (uzytkownik.get_pesel() == pesel) {
                    cout << "Uzytkownik o podanym numerze PESEL istnieje w systemie.: " << endl;
                    flaga_czy_uzytkownik_istnieje = true;
                }
            }
            if (!flaga_czy_uzytkownik_istnieje) {
                cout << "Uzytkownik o podanym numerze PESEL nie istenieje w systemie." << endl;
            }
            break;
        }
        case 3: {
            Uzytkownik uzytkownik;
            uzytkownik.dodaj_uzytkownika();
            break;
        }
        case 4: {
            string pesel = "";
            bool flaga_czy_uzytkownik_istnieje = false;
            cout << "Podaj PESEL uzytkownika, ktorego dane chcesz zmienic: " << endl;
            cin >> pesel;
            cout << endl;
            for (Uzytkownik& uzytkownik : biblioteka.get_uzytkownicy()) {
                if (uzytkownik.get_pesel() == pesel) {
                    flaga_czy_uzytkownik_istnieje = true;
                    uzytkownik.edytuj_dane_uzytkownika();
                }
            }
            if (!flaga_czy_uzytkownik_istnieje) {
                cout << "Uzytkownik o podanym numerze PESEL nie istenieje w systemie." << endl;
            }
            break;
        }
        case 5: {
            string pesel = "";
            bool flaga_czy_uzytkownik_istnieje = false;
            cout << "Podaj PESEL uzytkownika, ktorego chcesz usunac z systemu: " << endl;
            cin >> pesel;
            cout << endl;
            for (Uzytkownik& uzytkownik : biblioteka.get_uzytkownicy()) {
                if (uzytkownik.get_pesel() == pesel) {
                    flaga_czy_uzytkownik_istnieje = true;
                    uzytkownik.usun_uzytkownika_z_systemu(uzytkownik);
                }
            }
            if (!flaga_czy_uzytkownik_istnieje) {
                cout << "Uzytkownik o podanym numerze PESEL nie istenieje w systemie." << endl;
            }
            break;
        }
        case 6:{
            string pesel = "";
            bool flaga_czy_uzytkownik_istnieje = false;
            cout << "Podaj PESEL uzytkownika, ktorego chcesz sprawdzic: " << endl;
            cin >> pesel;
            cout << endl;
            for (Uzytkownik& uzytkownik : biblioteka.get_uzytkownicy()) {
                if (uzytkownik.get_pesel() == pesel) {
                    flaga_czy_uzytkownik_istnieje = true;
                    uzytkownik.sprawdz_nieoplacone_grzywny();
                }
            }
            if (!flaga_czy_uzytkownik_istnieje) {
                cout << "Uzytkownik o podanym numerze PESEL nie istenieje w systemie." << endl;
            }
            break;
        }
        }
        break;
    }
    case 3: {
        int decyzja;
        cout << "Wybrales obszar: 'Autor'." << endl;
        cout << "Dokonaj wyboru konkretnej operacji z ponizszych dozwolonych: " << endl;
        cout << "1. sprawdz dane autora " << endl;
        cout << "2. sprawdz czy taki autor juz istnieje " << endl;
        cout << "3. dodaj autora " << endl;
        cout << "4. edytuj dane autora " << endl;
        cout << "5. usun autora z systemu" << endl;
        cout << "6. wyszukaj ksiazke po autorze" << endl;
        cout << "Twój wybór: ";
        cin >> decyzja;
        cout << endl;
        switch (decyzja)
        {
        case 1:
            // Implementacja
            break;
        case 2:
            // Implementacja
            break;
        case 3:
            // Implementacja
            break;
        case 4:
            // Implementacja
            break;
        case 5:
            // Implementacja
            break;
        case 6:
            // Implementacja
            break;
        }
        break;
    }
    case 4: {
        int decyzja;
        cout << "Wybrales obszar: 'Ksiazka'." << endl;
        cout << "Dokonaj wyboru konkretnej operacji z ponizszych dozwolonych: " << endl;
        cout << "1. sprawdz szczegoly ksiazki " << endl;
        cout << "2. sprawdz czy takie ISBN jest juz w systemie " << endl;
        cout << "3. dodaj ksiazke " << endl;
        cout << "4. edytuj dane ksiazki " << endl;
        cout << "5. usun ksiazke z systemu" << endl;
        cout << "6. sprawdz liczbe egzemplarzy danej ksiazki" << endl;
        cout << "7. wyszukaj ksiazke po tytule" << endl;
        cout << "8. wyszukaj ksiazke po numerze ISBN" << endl;
        cout << "9. wyswietl ksiazki z danego gatunku" << endl;
        cout << "10. wyszukaj ksiazki po dacie wydania" << endl;
        cout << "Twój wybór: ";
        cin >> decyzja;
        cout << endl;
        switch (decyzja)
        {
        case 1:
            int w;

            cout << "jak chcesz wyszukac ksiazke? " << endl;
            cout << "1. po tytule" << endl;
            cout << "2. po autorze" << endl;
            cout << "3. po gatunku" << endl;
            cout << "4. po ISBN" << endl;
            cout << "5. po dacie wydania" << endl;
            cout << "twoj wybor: ";
            cin >> w;

            switch (w) {
            case 1: {
                cout << "podaj tytul:";
                string tytul;
                cin >> tytul;

                //oto lista ksiazek o tym tytule
                ///////////////////////////////////////
                cout << "Książki o tytule \"" << tytul << "\":" << endl;
                for (Ksiazka& ksiazka : biblioteka.get_zbior_ksiazek()) {
                    if (ksiazka.get_tytul() == tytul) {
                        ksiazka.sprawdz_szczegoly_ksiazki();
                    }
                }
            }
            case 2:
            {
                cout << "podaj imie autora: ";
                string imie, nazwisko;
                cin >> imie;
                cout << endl << "podaj nazwisko autora: ";
                cin >> nazwisko;
                ///lista ksiazek konkretnego autora
                ////////////////////

            }



            break;
            }
        case 2:
            // Implementacja
            break;
        case 3:
            // Implementacja
            break;
        case 4:
            // Implementacja
            break;
        case 5:
            // Implementacja
            break;
        case 6:
            // Implementacja
            break;
        case 7:
            // Implementacja
            break;
        case 8:
            // Implementacja
            break;
        case 9:
            // Implementacja
            break;
        case 10:
            // Implementacja
            break;
        }
        break;
    }
    case 5: {
        int decyzja;
        cout << "Wybrales obszar: 'Status'." << endl;
        cout << "Dokonaj wyboru konkretnej operacji z ponizszych dozwolonych: " << endl;
        cout << "1. sprawdz status uzytkownika " << endl;
        cout << "2. sprawdz status dostepnosci ksiazki " << endl;
        cout << "3. sprawdz status wszystkich nieuregulowanych platnosci w systemie  " << endl;
        cout << "Twój wybór: ";
        cin >> decyzja;
        cout << endl;
        switch (decyzja)
        {
        case 1:
            // Implementacja
            break;
        case 2:
            // Implementacja
            break;
        case 3:
            // Implementacja
            break;
        }
        break;
    }
    case 6: {
        int decyzja;
        cout << "Wybrales obszar: 'Biblioteka ogólne'." << endl;
        cout << "Dokonaj wyboru konkretnej operacji z ponizszych dozwolonych: " << endl;
        cout << "1. wyswietl informacje o bibliotece " << endl;
        cout << "2. edytuj dane biblioteki " << endl;
        cout << "Twój wybór: ";
        cin >> decyzja;
        cout << endl;
        switch (decyzja)
        {
        case 1:
            // Implementacja
            break;
        case 2:
            // Implementacja
            break;
        }
        break;
    }
    }

    return 0;
}
