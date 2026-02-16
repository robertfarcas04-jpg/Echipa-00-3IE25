#include <iostream> 
#include <string> 
using namespace std; 
class ContBancar { 
private: 
    string titular; 
    double sold; 
public: 
    // Constructor implicit 
    ContBancar() { 
        titular = "Necunoscut"; 
        sold = 0.0; 
    } 
    void setDate(string t, double s) { 
        titular = t; 
        sold = s; 
    } 
    void afisare() { 
        cout << "Titular: " << titular 
             << " | Sold: " << sold << " lei" << endl; 
    } 
    double getSold() { 
        return sold; 
    } 
    // Returneaza adresa soldului 
    double* adresaSold() { 
        return &sold; 
    } 
}; 
  
// Functie pentru depunere bani (modifica sold prin pointer) 
void depune(double* pSold, double suma) { 
    if (pSold != nullptr) { 
        *pSold += suma; 
    } 
} 
void afiseazaLinie() { 
    cout << "------------------------------------" << endl; 
} 
int main() { 
    int n; 
    cout << "Introduceti numarul de conturi: "; 
    cin >> n; 
    // Alocare dinamica 
    ContBancar* banca = new ContBancar[n]; 
    // Citire date 
    for (int i = 0; i < n; i++) { 
        string t; 
        double s; 
        cout << "\nCont " << i + 1 << endl; 
        cout << "Titular: "; 
        cin >> t; 
        cout << "Sold initial: "; 
        cin >> s; 
        banca[i].setDate(t, s); 
    } 
    afiseazaLinie(); 
    cout << "CONTURI INITIALE:" << endl; 
    for (int i = 0; i < n; i++) { 
        banca[i].afisare(); 
    } 
    // Depunere in primul cont 
    if (n > 0) { 
        cout << "\nSe depun 500 lei in primul cont..." << endl; 
        double* ptr = banca[0].adresaSold(); 
        depune(ptr, 500); 
    } 
    afiseazaLinie(); 
    cout << "CONTURI ACTUALIZATE:" << endl; 
  
    for (int i = 0; i < n; i++) { 
        banca[i].afisare(); 
    }
    // Calcul sold total banca (folosind aritmetica pointerilor) 
    double total = 0; 
    for (int i = 0; i < n; i++) { 
        total += (banca + i)->getSold(); 
    } 
  
    if (n > 0) 
        cout << "\nSold total banca: " << total << " lei" << endl; 
  
    // Eliberare memorie 
    delete[] banca; 
    banca = nullptr; 
  
    cout << "\nMemoria a fost eliberata cu succes." << endl; 
  
    return 0; 
} 
