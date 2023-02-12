# **2022**

## **{4079} Ceas1**

Un atelier de fabricat ceasuri cu cuc are nevoie de plăcuțe cu numerele pentru orele pe care trebuie să le așeze pe discul ceasurilor. Aceste numere sunt realizate la o imprimantă.

Din cauza unei erori imprimanta tipărește plăcuțe cu numere naturale, unele mai mari ca 12. Atelierul poate utiliza doar plăcuțe cu numere cuprinse ı̂ntre 0 și 12. Pentru a utiliza aceste numere este nevoie ca ele să fie tăiate ı̂ncepând din partea dreaptă ı̂n grupuri de maximum două cifre, fiecare grup reprezentând valoarea de pe o plăcuță, care să fie o cifră la 0 la 9 sau unul dintre numerele 10, 11, 12. Dacă pe o plăcuță se găsește un număr mai mare ca 12 atunci plăcuța trebuie tăiată, astfel ı̂ncât ı̂n urma tăierii să se obțină numere de cel mult 2 cifre. Dacă ı̂n numărul de pe o plăcuță cifra zecilor este 0, atunci la prima tăiere se ia doar cifra unităților, altfel dacă numărul format cu cifra zecilor și unităților este mai mare ca 12, atunci se taie prima dată cifra unităților, iar dacă numărul format cu cifra zecilor și unităților este 10, 11 sau 12 se taie prima dată numărul format din ultimele două cifre, apoi procedeul se repetă până la tăierea completă a plăcuței. Imprimanta a realizat N plăcuțe. De exemplu dacă plăcuța este 12030, după tăiere se obțin 0, 3, 0, 12.

### **Cerința 1**

Determinați numărul total de apariții ale cifrei X pe plăcuțe ı̂nainte de tăiere.

### **Cerința 2**

Determinați numărul de tăieturi realizate conform enunțului.

### **Date de intrare**

Pe prima linie a fișierului ceas.in se află valorile C, X și N separate prin câte un singur spațiu. Pe linia a doua se află N numere naturale separate prin câte un singur spațiu, având semnificația din enunț. Pentru C = 1 se rezolvă doar cerința 1, iar pentru C = 2 se rezolvă doar cerința 2.

### **Date de ieșire**

Fișierul ceas.out conține pe prima linie un singur număr natural care reprezintă valoarea calculată
conform cerinței.

### **Restricții și precizări**

-   1 ≤ N ≤ 100.000
-   0 ≤ X ≤ 9
-   Valorile din șir sunt numere naturale ≤ 50.000
-   Pentru testele în care avem C=2 valoarea X este prezentă în fișierul de - - intrare chiar dacă nu este folosită în rezolvare.
-   Pentru teste în valoare de 39 de puncte avem C = 1
-   Pentru teste în valoare de 61 de puncte avem C = 2

### **Exemplul 1:**

`ceas.in`

```
1 0 6
1010 40 201 5123 31 6
```

`ceas.out`

```
4
```

#### **Explicație**

Pe plăcuțe cifra 0 apare de patru ori.

### **Exemplul 2:**

`ceas.in`

```
2 0 6
120 40 201 5123 31 6
```

`ceas.out`

```
7
```

#### **Explicație**

În ordinea tăierilor se obțin: 0,12; 0,4; 1,0,2; 3,12,5; 1,3; 6. Numărul de tăieturi este 7.

<hr/>

## **{4091} sss1**

Se dă un număr N, și un șir de N numere naturale nenule.

### **Cerinta 1**

Determinați suma valorilor aflate pe ultimele K poziții în șir (unde K reprezintă valoarea celei mai din dreapta cifre nenule a primei valori din șir).

### **Cerinta 2**

Ne imaginăm împărțirea șirului în secvențe în următorul mod: prima secvență este formată din primele L elemente, a doua este formată din următoarele L-1 elemente, a treia este formată din următoarele L-2 elemente și așa mai departe, ultima secvență este formată dintr-un singur element și acesta coincide cu ultimul element din șir. Considerând suma valorilor fiecărei secvențe, să se determine cea mai mare dintre aceste sume.

### **Date de intrare**

Pe prima linie a fișierului sss.in se află două valori C și N separate printr-un spațiu. Pe linia a doua se află N numere naturale separate prin câte un spațiu. Pentru C = 1 se rezolvă doar cerința 1 iar pentru C = 2 se rezolvă doar cerința 2.

### **Date de ieșire**

Fișierul sss.out conține un singur număr care reprezintă valoarea calculată conform cerinței.

### **Restricții și precizări**

-   1 ≤ N ≤ 100.000
-   Valorile din șir sunt numere naturale nenule ≤ 100.000;
-   Se garantează că pentru testele în care C = 1 șirul are cel puțin K elemente;
-   Se garantează că valoarea lui N permite descompunerea conform descrierii, pentru testele care au C = 2;
-   Pentru teste în valoare de 51 de puncte avem C = 1;
-   Pentru 27 de puncte dintre testele în care C = 1, primul număr din șir are o cifră;
-   Pentru teste în valoare de 49 de puncte avem C = 2;
-   Pentru teste în valoare de 22 de puncte dintre cele care au C = 2, valoarea lui N este mai mică sau egală cu 10.
-   Denumirea problemei este o prescurtare de la “sume și secvențe”.

### **Exemplu 1**

`sss.in`

```
1 6
120 4 21 5 31 6
```

`sss.out`

```
37
```

### **Explicație**

Ultima cifră nenulă a primului element din șir este 2. Suma ultimelor două valori din șir este 37.

### **Exemplul 2:**

`sss.in`

```
2 10
1 4 2 1 3 6 1 6 5 3
```

`sss.out`

```
11
```

### **Explicație**

Descompunerea se poate realiza în secvențe de lungimile 4, 3, 2 și 1. Sumele obținute pentru fiecare sunt: 8, 10, 11, 3.

### **My solution**

```
#include <unistd.h>

#include <fstream>
#include <iostream>

using namespace std;

int main() {
    int c, n, k, linit = 0, limit, s = 0, max = 0, iteration = 0;

    // Read the numbers from the sss.in file
    ifstream f("sss.in");
    f >> c >> n;
    int v[n];

    // Display the numbers in the sss.out file
    ofstream g("sss.out");

    for (int i = 0; i < n; i++)
        f >> v[i];
    if (c == 1) {
        k = v[0];

        while (k % 10 == 0) {
            k /= 10;
        }

        k = k % 10;

        for (int i = n - k; i < n; i++)
            s += v[i];
        g << s;
    } else {
        int index = linit;
        if (n == 1) {
            g << v[0];
            return 0;
        } else {
            limit = (n - 1) / 2 + 1;

            while (limit < n && limit > 0) {
                int sum = 0;
                for (int i = index; i < limit; i++)
                    sum += v[i];

                if (sum > max)
                    max = sum;

                index = limit;
                iteration++;
                limit = limit + ((n - 1) / 2 - iteration);
            }
        }

        g << max;
    }

    return 0;
}
```

# **2002**

## **{3328} balaur**

### **Cerința**

A fost o dată un balaur cu 6 capete. Într-o zi Făt-Frumos s-a supărat şi i-a tăiat un cap. Peste noapte i-au crescut alte 6 capete în loc. Pe acelaşi gât! A doua zi, Făt-Frumos iar i-a tăiat un cap, dar peste noapte balaurului i-au crescut în loc alte 6 capete … şi tot aşa timp de n zile. În cea de a ( n+1 )-a zi, Făt-Frumos s-a plictisit şi a plecat acasă!

Scrieţi un program care citeşte de la tastatură n , numărul de zile, şi care afişează pe ecran câte capete avea balaurul după n zile.

### **intrare**

Programul citește de la tastatură numărul n.

### **Date de ieșire**

Programul va afișa pe ecran numărul S reprezentând numărul de capete pe care le va avea balaurul după n zile.

### **Restricții și precizări**

`1 ≤ n ≤ 1.000.000.000`

### **Exemplu**

**Intrare**

```
3
```

**Ieșire**

```
15
```

#### **Explicație**

Iniţial balaurul avea 6 capete. În prima zi Făt-Frumos i-a tăiat un cap şi i-au rămas 5 .
Peste noapte i-au crescut alte 6 , deci a doua zi dimineaţa balaurul avea 11 capete. În cea de a doua zi Făt-Frumos îi mai taie balaurului un cap, deci balaurul rămâne cu 10 capete. Peste noapte îi mai cresc 6 , astfel că a treia zi dimineaţă balaurul avea 16 capete. Dar în cea de a treia zi Făt-Frumos îi mai taie balaurului un cap, deci după cea de a treia zi balaurul a rămas cu 15 capete.

### **My solution**

```
#include <iostream>

using namespace std;

int main() {
    int n;  // number of days
    cin >> n;

    int heads = 6;  // initial number of heads

    cout << (n - 1) * 6 + (heads - n) << endl;
    return 0;
}
```
