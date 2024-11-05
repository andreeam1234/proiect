#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Bilet {
private:
    string tip;
    double pret;
    bool priority;

    //constructor cu parametri
public:
    explicit Bilet(const string& tip = "", double pret = 0.0, bool priority = false){
        this->tip = tip;
        this->pret = pret;
        this->priority = priority;
}

    // operator << pentru afisare
    friend ostream& operator<<(ostream& os, const Bilet& bilet) {
        os << "Tip bilet: " << bilet.tip << endl
           << " Pret: " << bilet.pret << endl
           << " Prioritate bilet: " << (bilet.priority ? "da" : "nu");
        return os;
    }
    //getter pentru bilet
    [[nodiscard]]double getPret() const { return pret; }
};

class atractie {
private:
    string nume;
    int inaltime_minima;
    double durata;
    string tip;

public:
    // constructor cu parametri
    explicit atractie(const string& nume = "", int inaltime_minima = 0, double durata = 0.0, const string& tip = "") {
        this->nume= nume;
        this->inaltime_minima=inaltime_minima;
        this->durata= durata;
        this->tip= tip;
    }

    // opperator << pentru afisare
    friend ostream& operator<<(ostream& os, const atractie& atractie) {
        os << "Atractie: " << atractie.nume << endl
           << " Inaltime minima: " << atractie.inaltime_minima << endl
           << " Durata: " << atractie.durata << endl
           << " Tip: " << atractie.tip << endl;
        return os;
    }

    // getter
    [[nodiscard]] const string& getTip() const { return tip; }
};

class vizitator {
private:
    string nume;
    int varsta;
    Bilet bilet;
    double timp_petrecut;
    vector<string> atractii_vizitate;

public:
    // constructor cu parametri
    explicit vizitator(const string& nume = "", int varsta = 0, const Bilet& bilet = Bilet(), double timp_petrecut = 0.0) {
        this->nume=nume;
        this->varsta= varsta;
        this->bilet=bilet;
        this->timp_petrecut=timp_petrecut;
    }

    void add_atractii_vizitate(const string& nume_atractie) {
        atractii_vizitate.push_back(nume_atractie);
    }

    friend ostream& operator<<(ostream& os, const vizitator& vizit) {
        os << "Vizitator: " << vizit.nume << endl
           << " varsta: " << vizit.varsta << endl
           << " " << vizit.bilet << endl
           << " timp_petrecut: " << vizit.timp_petrecut << " ore" << endl
           << " atractii_vizitate: ";
        for(const auto& nume_atractie : vizit.atractii_vizitate) {
            os << "\n  -" << nume_atractie;
        }
        os << endl;
        return os;
    }

    // getter
    [[nodiscard]] double getTimpPetrecut() const { return timp_petrecut; }
    [[nodiscard]] const Bilet& getBilet() const { return bilet; }
};

class parc_distractie {
private:
    vector<vizitator> vizitatori;
    vector<atractie> atractii;

public:
    parc_distractie() = default;

    // constructor de copiere
    parc_distractie(const parc_distractie& other){
        vizitatori = other.vizitatori;
        atractii=other.atractii;
    }
    // operator de atribuire =
    parc_distractie& operator=(const parc_distractie& other) {
        if(this != &other) {
            vizitatori = other.vizitatori;
            atractii = other.atractii;
        }
        return *this;
    }

    //destructor
    ~parc_distractie() = default;

    // functie pentru a adauga o noua atractie
    void add_atractie(const atractie& atractie) {
        atractii.push_back(atractie);
    }

    // functie pentru a adauga un nou vizitator
    void add_vizitator(const vizitator& vizit) {
        vizitatori.push_back(vizit);
    }
    // citire date despre vizitatori si atractii
    void citire() {
        int nrVizitatori, nrAtractii, nrAtractiiVizitate;

        cout << "Numar de vizitatori: ";
        cin >> nrVizitatori;
        cin.ignore();

        for (int i = 0; i < nrVizitatori; i++) {
            string numeVizitator, tipBilet;
            int varsta, timpPetrecut;
            double pretBilet;
            bool priority;

            cout << "\n Datele despre vizitatorul " << (i + 1) << ":\n";
            cout << "Nume: ";
            getline(cin, numeVizitator);
            cout << "Varsta: ";
            cin >> varsta;
            cin.ignore();
            cout << "Tip Bilet: ";
            getline(cin, tipBilet);
            cout << "Pret Bilet: ";
            cin >> pretBilet;
            cin.ignore();
            cout << "Acces Prioritar (1 - Da, 0 - Nu): ";
            cin >> priority;
            cout << "Timp Petrecut (ore): ";
            cin >> timpPetrecut;
            cin.ignore();

            //crearea biletului si a vizitatorului
            Bilet bilet(tipBilet, pretBilet, priority);
            vizitator vizitator(numeVizitator, varsta, bilet, timpPetrecut);

            // atractii vizitate de clienti
            cout << "Numarul de atractii vizitate de " << numeVizitator << ": ";
            cin >> nrAtractiiVizitate;
            cin.ignore();
            for(int j = 0; j < nrAtractiiVizitate; j++) {
                string numeAtractie;
                cout << "Nume Atractie: ";
                getline(cin, numeAtractie);
                vizitator.add_atractii_vizitate(numeAtractie);
            }
            // adaugare vizitator la lista
            add_vizitator(vizitator);
        }

        // citire date despre atractii
        cout << "\n Numarul de atractii: ";
        cin >> nrAtractii;
        cin.ignore();
        for (int i = 0; i < nrAtractii; i++) {
            string nume, tip;
            int inaltimeMinima;
            double durata;

            cout << "\nIntroduceti datele pentru atractia " << (i + 1) << ":\n";
            cout << "Nume: ";
            getline(cin, nume);
            cout << "Inaltime Minima (cm): ";
            cin >> inaltimeMinima;
            cin.ignore();
            cout << "Durata (minute): ";
            cin >> durata;
            cin.ignore();
            cout << "Tip: ";
            getline(cin, tip);

            // creare atractie si adaugare atractie
            atractie atractie(nume, inaltimeMinima, durata, tip);
            add_atractie(atractie);
        }
    }

    // afisare vizitatori si atractii
    void afis() const {
        cout << "Vizitatori:\n";
        for(const auto& vizitator : vizitatori) {
            cout << vizitator << endl;
        }

        cout << "Atractii:\n";
        for(const auto& atractie : atractii) {
            cout << atractie << endl;
        }
    }

    // functie pentru calcul profit
    [[nodiscard]] double calcul_profit() const {
        double total = 0.0;
        for(const auto& vizitator : vizitatori) {
            total += vizitator.getBilet().getPret();
        }
        return total;
    }

    // functie pentru calcul timp mediu petrecut de vizitatori
    [[nodiscard]] double calcul_timp_mediu() const {
        if(vizitatori.empty()) return 0.0;
        double total = 0.0;
        for(const auto& vizitator : vizitatori) {
            total += vizitator.getTimpPetrecut();
        }
        return total / static_cast<double>(vizitatori.size());
    }
};

int main() {
    parc_distractie parc;

    parc.citire();

    cout << "\nAfisarea informatiilor despre parc:\n";
    parc.afis();

    cout << "\nProfitul total al parcului: " << parc.calcul_profit() << " lei\n";
    cout << "Timpul mediu petrecut de vizitatori: " << parc.calcul_timp_mediu() << " ore\n";

    return 0;
}
