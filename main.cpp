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

public:
    explicit Bilet(const string& tip = "", double pret = 0.0, bool priority = false)
        : tip(tip), pret(pret), priority(priority) {}

    Bilet(const Bilet& other) : tip(other.tip), pret(other.pret), priority(other.priority) {}

    Bilet& operator=(const Bilet& other) {
        if(this != &other) {
            tip = other.tip;
            pret = other.pret;
            priority = other.priority;
        }
        return *this;
    }

    ~Bilet() {}

    friend ostream& operator<<(ostream& os, const Bilet& bilet) {
        os << "Tip bilet: " << bilet.tip
           << " Pret: " << bilet.pret
           << " Prioritate bilet: " << (bilet.priority ? "da" : "nu");
        return os;
    }

    double getPret() const { return pret; }
    bool hasPriority() const { return priority; }
    const string& getTip() const { return tip; }
};

class atractie {
private:
    string nume;
    int inaltime_minima;
    double durata;
    string tip;

public:
    explicit atractie(const string& nume = "", int inaltime_minima = 0, double durata = 0.0, const string& tip = "")
        : nume(nume), inaltime_minima(inaltime_minima), durata(durata), tip(tip) {}

    atractie(const atractie& other) : nume(other.nume), inaltime_minima(other.inaltime_minima), durata(other.durata), tip(other.tip) {}

    atractie& operator=(const atractie& other) {
        if(this != &other) {
            nume = other.nume;
            inaltime_minima = other.inaltime_minima;
            durata = other.durata;
            tip = other.tip;
        }
        return *this;
    }

    ~atractie() {}

    friend ostream& operator<<(ostream& os, const atractie& atractie) {
        os << "Atractie: " << atractie.nume
           << " Inaltime minima: " << atractie.inaltime_minima
           << " Durata: " << atractie.durata
           << " Tip: " << atractie.tip;
        return os;
    }

    int getInaltimeMinima() const { return inaltime_minima; }
    double getDurata() const { return durata; }
    const string& getTip() const { return tip; }
};

class vizitator {
private:
    string nume;
    int varsta;
    Bilet bilet;
    double timp_petrecut;
    vector<string> atractii_vizitate;

public:
    explicit vizitator(const string& nume = "", int varsta = 0, const Bilet& bilet = Bilet(), double timp_petrecut = 0.0)
        : nume(nume), varsta(varsta), bilet(bilet), timp_petrecut(timp_petrecut) {}

    vizitator(const vizitator& other)
        : nume(other.nume), varsta(other.varsta), bilet(other.bilet), timp_petrecut(other.timp_petrecut), atractii_vizitate(other.atractii_vizitate) {}

    vizitator& operator=(const vizitator& other) {
        if(this != &other) {
            nume = other.nume;
            varsta = other.varsta;
            bilet = other.bilet;
            timp_petrecut = other.timp_petrecut;
            atractii_vizitate = other.atractii_vizitate;
        }
        return *this;
    }

    ~vizitator() {}

    void add_atractii_vizitate(const string& nume_atractie) {
        atractii_vizitate.push_back(nume_atractie);
    }

    friend ostream& operator<<(ostream& os, const vizitator& vizit) {
        os << "Vizitator: " << vizit.nume
           << " varsta: " << vizit.varsta
           << " bilet: " << vizit.bilet
           << " timp_petrecut: " << vizit.timp_petrecut << " ore"
           << " atractii_vizitate: ";
        for(const auto& nume_atractie : vizit.atractii_vizitate) {
            os << "\n  -" << nume_atractie;
        }
        return os;
    }

    int getVarsta() const { return varsta; }
    double getTimpPetrecut() const { return timp_petrecut; }
    const Bilet& getBilet() const { return bilet; }
    const vector<string>& get_atractie() const { return atractii_vizitate; }
};

class parc_distractie {
private:
    vector<vizitator> vizitatori;
    vector<atractie> atractii;

public:
    parc_distractie() {}

    parc_distractie(const parc_distractie& other) : vizitatori(other.vizitatori), atractii(other.atractii) {}

    parc_distractie& operator=(const parc_distractie& other) {
        if(this != &other) {
            vizitatori = other.vizitatori;
            atractii = other.atractii;
        }
        return *this;
    }

    ~parc_distractie() {}

    void add_atractie(const atractie& atractie) {
        atractii.push_back(atractie);
    }

    void add_vizitator(const vizitator& vizit) {
        vizitatori.push_back(vizit);
    }

    void citire() {
        int nrVizitatori, nrAtractii, nrAtractiiVizitate;

        cout << "Numar de vizitatori: ";
        cin >> nrVizitatori;
        for (int i = 0; i < nrVizitatori; i++) {
            string numeVizitator, tipBilet;
            int varsta, timpPetrecut;
            double pretBilet;
            bool accesPrioritar;

            cout << "\n Datele despre vizitatorul " << (i + 1) << ":\n";
            cout << "Nume: ";
            cin >> numeVizitator;
            cout << "Varsta: ";
            cin >> varsta;
            cout << "Tip Bilet: ";
            cin >> tipBilet;
            cout << "Pret Bilet: ";
            cin >> pretBilet;
            cout << "Acces Prioritar (1 - Da, 0 - Nu): ";
            cin >> accesPrioritar;
            cout << "Timp Petrecut (ore): ";
            cin >> timpPetrecut;

            Bilet bilet(tipBilet, pretBilet, accesPrioritar);
            vizitator vizitator(numeVizitator, varsta, bilet, timpPetrecut);

            cout << "Numarul de atractii vizitate de " << numeVizitator << ": ";
            cin >> nrAtractiiVizitate;
            for(int j = 0; j < nrAtractiiVizitate; j++) {
                string numeAtractie;
                cout << "Nume Atractie: ";
                cin >> numeAtractie;
                vizitator.add_atractii_vizitate(numeAtractie);
            }

            add_vizitator(vizitator);
        }

        cout << "\n Numarul de atractii: ";
        cin >> nrAtractii;
        for (int i = 0; i < nrAtractii; i++) {
            string nume, tip;
            int inaltimeMinima;
            double durata;

            cout << "\nIntroduceti datele pentru atractia " << (i + 1) << ":\n";
            cout << "Nume: ";
            cin >> nume;
            cout << "Inaltime Minima (cm): ";
            cin >> inaltimeMinima;
            cout << "Durata (minute): ";
            cin >> durata;
            cout << "Tip: ";
            cin >> tip;

            atractie atractie(nume, inaltimeMinima, durata, tip);
            add_atractie(atractie);
        }
    }

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

    double calcul_profit() const {
        double total = 0.0;
        for(const auto& vizitator : vizitatori) {
            total += vizitator.getBilet().getPret();
        }
        return total;
    }

    double calcul_timp_mediu() const {
        if(vizitatori.empty()) return 0.0;
        double total = 0.0;
        for(const auto& vizitator : vizitatori) {
            total += vizitator.getTimpPetrecut();
        }
        return total / vizitatori.size();
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
