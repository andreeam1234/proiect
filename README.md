# FunLand

### Project Description

This project represents a simulation of an amusement park, which includes attractions, such as Ferris Wheel, Carousel
and Roller Coaster, visitors and tickets.
The project provides functionalities that allow adding attractions, visitors and managing them.
Exceptions are implemented for attractions that have exceeded the number of visitors, invalid tickets, visitors that are
too short to ride certain attractions.

This project represents a simulation of an amusement park, which includes attractions, such as Ferris Wheel, Carousel
and Roller Coaster, visitors and tickets.
The project provides functionalities that allow adding attractions, visitors and managing them.
Exceptions are implemented for attractions that have exceeded the number of visitors, invalid tickets, visitors that are
too short to ride certain attractions.

The project is structured in several classes:

1. Park

- [ ] Represents the amusement park. It contains a list of attractions and visitors.
- [ ] It allows for adding attractions and visitors, displaying them, and managing the profit generated from ticket
  sales.

2. Attraction

- [ ] The base class for all attractions in the park.
- [ ] It contains common information like the attraction's name, price, and capacity, but also methods that are specific
  to individual attractions.

3. Visitor

- [ ] Represents a park visitor, containing information like their name, age, height, and tickets. Visitors can visit
  attractions but may encounter exceptions like height restrictions or invalid tickets.

4. Ticket

- [ ] Represents a ticket issued to a visitor. Tickets can be valid or invalid, and their price is added to the park's
  profit.

5. RollerCoaster, FerrisWheel, Carousel: Classes derived from Attraction.

- [ ] Each attraction has specific methods to simulate the experience provided to visitors (e.g., screamTest for roller
  coasters, spinAround for carousels, etc.).

Template class VisitorList is used to manage a list of visitors to an amusement park. The class is designed to handle
visitors of different
types, such as AdultVisitor and ChildVisitor.

Observer Pattern is implemented to manage the interaction between the amusement park and its visitors.
This pattern allows the park to notify its visitors whenever important events occur, such as the addition of new
attractions or the park closing.

he TicketFactory interface defines the contract for creating tickets, while concrete factories like
StandardTicketFactory and VIPTicketFactory.

### Cerințe modele de limbaj la nivel de semestru

- [ ] minim o funcționalitate majoritar doar cu LLM
- [ ] minim 2-3 funcționalități ~50% voi, ~50% LLM-ul
- [ ] minim 2-3 funcționalități suficient de complicate pe care un LLM nu le poate implementa

### Tema 0

- [ ] Nume proiect (poate fi schimbat ulterior)
- [ ] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Tema 1

#### Cerințe

- [ ] definirea a minim **3-4 clase** folosind compunere cu clasele definite de voi
- [ ] constructori de inițializare cu parametri
- [ ] pentru o aceeași (singură) clasă: constructor de copiere, `operator=` de copiere, destructor

<!-- - [ ] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor -->
<!-- - [ ] pentru o altă clasă: toate cele 5 funcții membru speciale -->

- [ ] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [ ] cât mai multe `const` (unde este cazul)
- [ ] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin
  1-2 funcții mai complexe
    - nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [ ] scenariu de utilizare a claselor definite:
    - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
    - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă
      aveți nevoie de date din fișiere, creați alte fișiere separat
- [ ] tag de `git`: de exemplu `v0.1`
- [ ] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Tema 2

#### Cerințe

- [ ] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri:
    - minim o clasă de bază și **3 clase derivate** din aceeași ierarhie
    - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
    - [ ] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
        - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
        - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
        - afișare virtuală, interfață non-virtuală
    - [ ] apelarea constructorului din clasa de bază din constructori din derivate
    - [ ] clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin pointer
      de bază, eventual prin interfața non-virtuală din bază
        - [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
        - [ ] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
        - [ ] smart pointers (recomandat, opțional)
- [ ] excepții
    - [ ] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori
      specifice
    - [ ] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în
      `main`
    - această ierarhie va fi complet independentă de ierarhia cu funcții virtuale
- [ ] funcții și atribute `static`
- [ ] STL
- [ ] cât mai multe `const`
- [ ] funcții *de nivel înalt*, de eliminat cât mai mulți getters/setters/funcții low-level
- [ ] la sfârșit: commit separat cu adăugarea unei noi clase derivate fără a modifica restul codului, **pe lângă cele 3
  derivate deja adăugate** din aceeași ierarhie
    - noua derivată nu poate fi una existentă care a fost ștearsă și adăugată din nou
- [ ] tag de `git`: de exemplu `v0.2`

## Tema 3

#### Cerințe

- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
    - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri

<!-- - [ ] o specializare pe funcție/clasă șablon -->

- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

## Instrucțiuni de compilare

Proiectul este configurat cu CMake.

Instrucțiuni pentru terminal:

0. Biblioteci necesare pe Linux (presupunem sistem de operare bazat pe Debian)

```sh
sudo apt-get update && \
  sudo apt-get install libxrandr-dev \
    libxcursor-dev \
    libudev-dev \
    libopenal-dev \
    libflac-dev \
    libvorbis-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev \
    libdrm-dev \
    libgbm-dev \
    libfreetype6-dev
```

Dacă lipsesc și alte biblioteci, ștergeți folder-ul de build de la pasul 1 și reconfigurați proiectul după ce ați
instalat ce lipsea.

1. Pasul de configurare

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

Sau pe Windows cu GCC:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja
```

La acest pas putem cere să generăm fișiere de proiect pentru diverse medii de lucru.

2. Pasul de compilare

```sh
cmake --build build --config Debug --parallel 6
```

Cu opțiunea `parallel` specificăm numărul de fișiere compilate în paralel.

3. Pasul de instalare (opțional)

```sh
cmake --install build --config Debug --prefix install_dir
```

Vezi și [`scripts/cmake.sh`](scripts/cmake.sh).

## Resurse

- [SFML](https://github.com/SFML/SFML/tree/2.6.1) (Zlib)
    - [OpenAL](https://openal-soft.org/) (LGPL): din cauza licenței, trebuie distribuită ca shared library
- adăugați trimiteri către resursele externe care v-au ajutat sau pe care le-ați folosit
