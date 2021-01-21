#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>

#include "klasy.hpp"
#include "funkcje.hpp"

int main() {
  std::fstream plik;

  std::string komenda;
  std::vector <std::unique_ptr<Pojazd>> pojazdy;
  bool temp;

  lista_komend();
  odczytaj(pojazdy, plik);

  for (int i=0;i!=1;){         //petla glowna

    std::cin >> komenda;

    if (komenda=="dp"){
      temp=nowy_pojazd(pojazdy);
      if (temp) std::cout<<"Dodano pojazd\n";
    }
    else if(komenda=="up"){
      temp=erase_pojazd(pojazdy);
      if (temp) std::cout<<"Usunieto pojazd\n";
    }
    else if(komenda=="sort"){
      sortuj_pojazdy(pojazdy);
      listuj(pojazdy);
    }
    else if(komenda=="detale"){
      pokaz_detale(pojazdy);
    }
    else if (komenda=="list"){
      listuj(pojazdy);
    }
    else if(komenda=="end"){
      i=koniec(pojazdy, plik);
    }
    else if(komenda=="save"){
      zapisz(pojazdy, plik);
    }
    else if(komenda=="read"){
      odczytaj(pojazdy, plik);
      listuj(pojazdy);
    }
    else if(komenda=="help"){
      lista_komend();
    }
    else std::cout<<"Komenda nierozpoznana\n";
  }
}