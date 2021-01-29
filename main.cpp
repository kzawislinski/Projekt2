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
  const std::string filename="baza.bin";
  std::string komenda;
  std::vector <std::unique_ptr<Pojazd>> pojazdy;
  bool temp;
  int i=0;
  try{
    odczytaj(pojazdy, filename);
    lista_komend();
  }
  catch(int a){
    if (a==404){
      std::cout<<"ERROR "<<a<<": Nie znaleziono pliku\n";
    }
    if (a==418){
      std::cout<<"I’m a teapot\n";
    }
    i=1;
  }

  while (i!=1){         //petla glowna

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
      i=koniec(pojazdy, filename);
    }
    else if(komenda=="save"){
      try{
        odczytaj(pojazdy, filename);
      }
      catch(int a){
        if (a==404){
          std::cout<<"ERROR "<<a<<": Nie znaleziono pliku\n";
        }
        if (a==418){
          std::cout<<"I’m a teapot\n";
        }
        i=1;
      }
    }
    else if(komenda=="read"){
      odczytaj(pojazdy, filename);
      listuj(pojazdy);
    }
    else if(komenda=="help"){
      lista_komend();
    }
    else std::cout<<"Komenda nierozpoznana\n";
  }
}