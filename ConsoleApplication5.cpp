#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class Data {
private:
    int dzien;
    int miesiac;
    int rok;
public:
    Data(int d, int m, int r) : dzien(d), miesiac(m), rok(r) {}
    void wyswietl_date_wypozyczenia() { cout << "data wypozyczenia to: " << dzien << "." << miesiac << "." << rok << endl; }
    void wyswietl_date_zwrotu() {
        // Konwertowanie daty na strukturę tm
        tm timeinfo = { 0 };
        timeinfo.tm_mday = dzien;
        timeinfo.tm_mon = miesiac - 1; // miesiące są od 0 do 11
        timeinfo.tm_year = rok - 1900; // rok jest przesunięty o 1900
        mktime(&timeinfo);

        // Dodanie 30 dni
        timeinfo.tm_mday += 30;
        mktime(&timeinfo);

        // Wyświetlenie daty zwrotu
        cout << "data zwrotu to: " << timeinfo.tm_mday << "." << timeinfo.tm_mon + 1 << "." << timeinfo.tm_year + 1900 << endl;
    }
    void wyswietl_date() { cout << "data: " << dzien << "." << miesiac << "." << rok << endl; }

    void set_data(int d, int m, int r) { dzien = d, miesiac = m, rok = r; }
};

class Grzywny {
private:
    float kwota;
    string powod;
public:
    Grzywny(float k, const string& p) : kwota(k), powod(p) {}

    float get_kwota() const { return kwota; }
    string get_powod() const { return powod; }
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
    vector<Grzywny> grzywny; // wektor przechowujący grzywny użytkownika
    Uzytkownik(const string& i, const string& n, const int& t, const string& e, const string& p) : Osoba(i, n, t, e, p) {}
    void wyswietl_uzytkownika() {
        cout << Osoba::get_imie() << " " << Osoba::get_nazwisko() << endl << "telefon: " << Osoba::get_numer_telefonu() << endl
            << "email: " << Osoba::get_email() << endl << "pesel: " << Osoba::get_pesel() << endl;
        cout << endl;
    }

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
        case 1:
            cout << "podaj imie do zmiany: " << endl;
            cin >> imie;
            Uzytkownik::set_imie(imie);
            break;
        case 2:
            cout << "podaj nazwisko do zmiany: " << endl;
            cin >> nazwisko;
            Uzytkownik::set_nazwisko(nazwisko);
            break;
        case 3:

            cout << "podaj email do zmiany: " << endl;
            cin >> email;
            Uzytkownik::set_email(email);
            break;
        case 4:
            cout << "podaj pesel do zmiany: " << endl;
            cin >> pesel;
            Uzytkownik::set_pesel(pesel);
            break;
        case 5:
            cout << "podaj numer_telefonu do zmiany: " << endl;
            cin >> numer_telefonu;
            Uzytkownik::set_numer_telefonu(numer_telefonu);
            break;
        }
        }
    }
    void usun_uzytkownika_z_systemu() {
        // implementacja
    }
    void sprawdz_nieoplacone_grzywny() {
        // implementacja
    }
};


class Ksiazka;

class Autor : public Osoba {
    vector<Ksiazka> ksiazki;
public:

    Autor(const string& i, const string& n) : Osoba(i, n, 0, "", "") {}

    Autor() {}
    // Dodaj odpowiednie funkcje obsługujące przypadki w switchu
    void wyswietl_dane_autora() {
        cout << "Autor:" << get_imie() << " " << get_nazwisko() << endl;
    }
    bool czy_autor_istnieje(vector<Autor>& autorzy, const string& i, const string& n) {
        for (auto& autor : autorzy) {
            if (autor.get_imie() == i && autor.get_nazwisko() == n) {
                cout << "Autor " << i << " " << n << " występuje w systemie" << endl;
                return true;
            }
        }
        cout << "Brak autora " << i << " " << n << " w systemie" << endl;
        return false;
    }

    // Dodajemy metodę do dodawania książki do autora
    void dodaj_ksiazke(Ksiazka& ksiazka) {
        ksiazki.push_back(ksiazka);
    }
    void edytuj_dane_autora(vector<Autor>& autorzy, const string& imie, const string& nazwisko) {
        for (auto& autor : autorzy) {
            if (autor.get_imie() == imie && autor.get_nazwisko() == nazwisko) {
                int wybor;
                cout << "Wybierz konkretny segment do edycji: " << endl;
                cout << "1. Imię" << endl;
                cout << "2. Nazwisko" << endl;
                cout << "Twój wybór: ";
                cin >> wybor;

                switch (wybor) {
                case 1: {
                    string nowe_imie;
                    cout << "Podaj nowe imię: ";
                    cin >> nowe_imie;
                    autor.set_imie(nowe_imie);
                    break;
                }
                case 2: {
                    string nowe_nazwisko;
                    cout << "Podaj nowe nazwisko: ";
                    cin >> nowe_nazwisko;
                    autor.set_nazwisko(nowe_nazwisko);
                    break;
                }
                default:
                    cout << "Niepoprawny wybór." << endl;
                    break;
                }
            }
        }
    }

        }
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
    Egzemplarz(string& w, string& i) : wydanie(w), ISBN(i) {}
    string get_wydanie() { return wydanie; }
    string get_ISBN() { return ISBN; }
    void set_egzemplarz(string w, string isb) { wydanie = w; ISBN = isb; }
};

class Ksiazka {
private:
    Autor autor;
    string tytul;
    string gatunek;
    vector<Egzemplarz> egzemplarze;
    Data data_wydania;

public:
    Ksiazka(Autor& a, string& t, string& g, Data& d) : autor(a), tytul(t), gatunek(g), data_wydania(d) {}
    Autor get_autor() { return autor; }
    string get_tytul() { return tytul; }
    string get_gatunek() { return gatunek; }
    Data get_data_wydania() { return data_wydania; }
    vector<Egzemplarz>& get_egzemplarze() { return egzemplarze; }

    // Settery
    void set_autor(Autor& au) { autor = au; }
    void set_tytul(string& t) { tytul = t; }
    void set_gatunek(string& gat) { gatunek = gat; }
    void set_data_wydania(Data& d) { data_wydania = d; }

    void dodaj_egzemplarz(Egzemplarz& e) { egzemplarze.push_back(e); }
    void usun_egzemplarz() { egzemplarze.pop_back(); }

    // Metody
    void sprawdz_szczegoly_ksiazki() {
        cout << "Tytul: " << tytul << endl
            << "Autor: " << autor.get_imie() << " " << autor.get_nazwisko() << endl
            << "Gatunek: " << gatunek << endl
            << "Data wydania: ";
        data_wydania.wyswietl_date();
        cout << "Egzemplarze: " << egzemplarze.size() << endl;
    }

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
public:
    vector<Ksiazka> get_zbior_ksiazek() { return zbior_ksiazek; }
    vector<Wypozyczenie> get_wypozyczenia() { return wypozyczenia; }
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
        return false;
    }
};

int main()
{
    //POMOCNICZE WYSWIETLENIA SPRAWDZAJACE POPRAWNOSC KODU
    /*Data data1(10, 5, 2007);
    data1.wyswietl_date_wypozyczenia();
    data1.wyswietl_date_zwrotu();

    cout <<endl<< "Wszyscy uzytkownicy w bazie: " << endl;
    Uzytkownik uzytkownik1("Jan", "Kowalski", 123456789, "jan.kowalski@example.com", "1234567890");
    Uzytkownik uzytkownik2("Julia", "Nowak", 123456789, "julia.nowak@example.com", "1256789655");
    Uzytkownik uzytkownik3("Monika", "Walczyk", 123456789, "monika.walczyk@example.com", "1234897810");
    uzytkownik1.wyswietl_uzytkownika();
    uzytkownik2.wyswietl_uzytkownika();
    uzytkownik3.wyswietl_uzytkownika();

    */
    vector<Autor> autorzy;
    vector<Uzytkownik> uzytkownicy;
    vector<Ksiazka> ksiazki;
    // Dodanie kilku użytkowników do wektora
    uzytkownicy.push_back(Uzytkownik("Jan", "Kowalski", 123456789, "jan@kowalski.com", "12345678901"));
    uzytkownicy.push_back(Uzytkownik("Anna", "Nowak", 987654321, "anna@nowak.com", "98765432109"));
    uzytkownicy.push_back(Uzytkownik("A", "N", 1, "an@nk.com", "1"));
    // Przykładowe dodanie autorów do wektora
    autorzy.push_back(Autor("olga", "tokar"));
    autorzy.push_back(Autor("piotr", "malanowski"));

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

    switch (wybor) {
    case 1:
        break;

    case 2:
        int decyzja;
        cout << endl << "Wybrales obszar: 'Uzytkownik'." << endl;
        cout << "Dokonaj wyboru konkretnej operacji z ponizszych dozwolonych: " << endl;
        cout << "1. sprawdz dane uzytkownika " << endl;
        cout << "2. sprawdz czy taki pesel jest juz w systemie " << endl;
        cout << "3. dodaj uzytkownika " << endl;
        cout << "4. edytuj dane uzytkownika " << endl;
        cout << "5. usun uzytkownika z systemu" << endl;
        cout << "6. sprawdz czy uzytkownik ma nieoplacone grzywny" << endl;
        cout << "7. dodaj grzywne do uzytkownika. " << endl;
        cout << "TWOJ WYBOR: ";
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
    case 3: {
        int decyzja;
        cout << "Wybrales obszar: 'Autor'." << endl;
        cout << "Dokonaj wyboru konkretnej operacji z ponizszych dozwolonych: " << endl;
        cout << "1. wyswietl wszystkich autorow " << endl;
        cout << "2. sprawdz czy taki autor juz istnieje " << endl;
        cout << "3. dodaj autora " << endl;
        cout << "4. edytuj dane autora " << endl;
        cout << "5. usun autora z systemu" << endl;
        cout << "6. znajdz wszystkie ksiazki danego autora" << endl;
        cout << "7. dodaj ksiazke do autora." << endl;
        cout << "TWOJ wybor: ";
        cin >> decyzja;
        cout << endl;
        switch (decyzja)
        {

        case 1: {
            Autor autor;
            autor.wyswietl_wszystkich_autorow(autorzy);
            break;

        }

        case 2: {
            string imie, nazwisko;
            cout << "Podaj imię autora do sprawdzenia: ";
            cin >> imie;
            cout << "Podaj nazwisko autora do sprawdzenia: ";
            cin >> nazwisko;
            Autor autor;
            autor.czy_autor_istnieje(autorzy, imie, nazwisko);
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

        case 5: {
            string imie, nazwisko;
            cout << "Podaj imię autora do usunięcia: ";
            cin >> imie;
            cout << "Podaj nazwisko autora do usunięcia: ";
            cin >> nazwisko;
            Autor autor;
            autor.usun_autora_z_systemu(autorzy, imie, nazwisko);
            break;
        }
        case 6: {
            Autor autor;
            cout << "Podaj imie autora: ";
            string imie;
            cin >> imie;
            autor.set_imie(imie);

            cout << "Podaj nazwisko autora: ";
            string nazwisko;
            cin >> nazwisko;
            autor.set_nazwisko(nazwisko);

                //oto lista ksiazek o tym tytule
                ///////////////////////////////////////
                cout << "Książki o tytule \"" << tytul << "\":" << endl;
                for (const Ksiazka& ksiazka : biblioteka.get_zbior_ksiazek()) {
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

            // Szukamy autora w wektorze autorów
            bool znaleziono_autora = false;
            for (auto& a : autorzy) {
                if (a.get_imie() == autor.get_imie() && a.get_nazwisko() == autor.get_nazwisko()) {
                    // Znaleziono autora, przypisujemy książki
                    cout << "Podaj tytul ksiazki: ";
                    string tytul;
                    cin >> tytul;

                    cout << "Podaj gatunek ksiazki: ";
                    string gatunek;
                    cin >> gatunek;
                    cout << endl;

                    cout << "Podaj date wydania ksiazki (dd mm rrrr): ";
                    int dzien, miesiac, rok;
                    cin >> dzien >> miesiac >> rok;
                    Data data_wydania(dzien, miesiac, rok);

                    Ksiazka nowa_ksiazka(autor, tytul, gatunek, data_wydania);
                    a.dodaj_ksiazke(nowa_ksiazka);
                    znaleziono_autora = true;
                    break;
                }
            }

            if (!znaleziono_autora) {
                cout << "Nie znaleziono autora o podanych danych." << endl;
            }
        }
        default:
            cout << "Niepoprawny wybór." << endl;
            break;
        }
    }
    }
    return 0;

}