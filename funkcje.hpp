//plik zawierajacy wszystkie wolnostojace funkcje

bool nowy_pojazd(std::vector<std::unique_ptr<Pojazd>>& pojazdy){
      std::string komenda;
      std::string komenda2;
      int temp;
      unsigned long longtemp;
      std::cout << "Podaj rodzaj pojazdu (osobowy/motocykl)\n";
      std::cin >> komenda;
      if (komenda=="osobowy"){
        std::cout<<"Podaj marke pojazdu\n";
        std::cin.ignore();
        std::getline(std::cin,komenda);
        std::cout<<"Podaj model pojazdu\n";
        std::getline(std::cin,komenda2);
        std::cout<<"Podaj liczbe drzwi\n";
        std::cin>>temp;
        std::cout<<"Podaj przebieg\n";
        std::cin>>longtemp;
        pojazdy.push_back(std::make_unique<Osobowy>(komenda,komenda2,temp,longtemp));
        return true;
      }
      else if(komenda=="motocykl"){
        std::cout<<"Podaj marke pojazdu\n";
        std::cin.ignore();
        std::getline(std::cin,komenda);
        std::cout<<"Podaj model pojazdu\n";
        std::getline(std::cin,komenda2);
        std::cout<<"Podaj liczbe cylindrow\n";
        std::cin>>temp;
        std::cout<<"Podaj przebieg\n";
        std::cin>>longtemp;
        pojazdy.push_back(std::make_unique<Motocykl>(komenda,komenda2,temp,longtemp));
        return true;
      }
      else{
        std::cout << "Komenda nierozpoznana\n";
        return false;
      }
} //funkcja dodaje nowy pojazd do wektora i zwraca true jesli udalo sie dodac




bool erase_pojazd(std::vector<std::unique_ptr<Pojazd>>& pojazdy){
      int temp;
      std::cout <<"Podaj numer pojazdu\n";
      std::cin >> temp;
      if (temp<=pojazdy.size()){
        pojazdy.erase(pojazdy.begin()+temp-1);
        return true;
      }
      else{
        std::cout << "Nie znaleziono pojazdu\n";
        return false;
      }
} //funkcja kasuje wskazany pojazd i zwraca true jesli sie udalo




void sortuj_pojazdy(std::vector<std::unique_ptr<Pojazd>>& pojazdy){
  std::string komenda;
  std::cout << "Wedlug jakiego parametru sortowac? (marka/model)\n";
  std::cin>>komenda;
  if(komenda=="marka"){
    std::sort(pojazdy.begin(),pojazdy.end(),[](const std::unique_ptr<Pojazd>& left, const std::unique_ptr<Pojazd>& right) {
      return left->getMarka() < right->getMarka();
    });
  }
  else if(komenda=="model"){
    std::sort(pojazdy.begin(),pojazdy.end(),[](const std::unique_ptr<Pojazd>& left, const std::unique_ptr<Pojazd>& right) {
      return left->getModel() < right->getModel();
    });
  }
  else{
    std::cout<<"Komenda nierozpoznana\n";
  }
} //funkcja sortuje wektor pojazdow po marce lub modelu




void pokaz_detale(std::vector<std::unique_ptr<Pojazd>>& pojazdy){
  int temp;
  std::cout<<"Podaj numer pojazdu\n";
  std::cin>>temp;
  if (temp<=pojazdy.size()){
    pojazdy[temp-1]->details();
  }
  else{
    std::cout<<"Nie znaleziono pojazdu\n";
  }
} //funkcja wyswietla dokladne informacje o wskazanym pojezdzie




void listuj(std::vector<std::unique_ptr<Pojazd>>& pojazdy){
  std::cout<<"\n------------------------\n";
  for (int i=0;i<pojazdy.size();i++){
    std::cout<< i+1 <<'\t';
    pojazdy[i]->wyswietl_dane();
  }
  std::cout<<"------------------------\n\n";
} //funkcja wyswietla baze




void zapisz(std::vector<std::unique_ptr<Pojazd>>& pojazdy, std::fstream& plik){
  plik.open("baza.bin",  std::ios::out | std::ios::binary);
  if (plik.good()){
    int temp=pojazdy.size();
    plik.write((const char*)&temp, sizeof(int));
    for(int i=0;i<pojazdy.size();i++){
      pojazdy[i]->zapisz_pojazd(plik);
    }
    plik.close();
  }
  else{
    std::cout<<"Blad pliku\n";
  }
  std::cout<<"Baza zapisana\n";
} //funkcja zapisuje baze do pliku




void odczytaj(std::vector<std::unique_ptr<Pojazd>>& pojazdy, std::fstream& plik){
  int temp;
  int temp2;
  long longtemp;
  plik.open("baza.bin", std::ios::in | std::ios::binary);
    if (plik.good()){
      plik.read((char*)&temp,sizeof(int)); //odczyt liczby elementow w bazie
      pojazdy.clear(); // czyszczenie dotychczasowego wektora
      for (int i=0;i<temp;i++){
        plik.read((char*)&temp2,sizeof(int)); //odczyt typu pojazdu
        if (temp2==0){ //odczyt jesli osobowy
          Osobowy::czytaj(pojazdy, plik);
        }
        else if (temp2==1){ //odczyt jesli motocykl
          Motocykl::czytaj(pojazdy, plik);
        }
        else std::cout <<"Blad pliku\n";
      }
      plik.close();
    }
    else std::cout<<"Blad pliku\n";
} //funkcja odczytuje baze z pliku




int koniec(std::vector<std::unique_ptr<Pojazd>>& pojazdy, std::fstream& plik){
  std::string komenda;
  std::cout<<"Czy chcesz zapisac przed zamknieciem? (tak/nie)\n";
  std::cin>>komenda;
  if(komenda=="tak"){
    zapisz(pojazdy,plik);
    return 1;
  }
  else if(komenda=="nie"){
    return 1;
  }
  else{
    std::cout<<"Komenda nierozpoznana\n";
    return 0;
  }
} //funkcja konczy dzialanie programu - zwraca 1 zeby zakonczyc petle glowna lub 0 jesli nie rozpozna komendy




void lista_komend(){
  std::cout<<"Lista komend:\n dp - dodaj pojazd\n up - usun pojazd\n sort - sortuj baze\n detale - wyswietl dokladne informacje na temat pojazdu\n list - wyswietl baze\n save - zapisz baze\n read - przywroc ostatnia zapisana wersje bazy\n end - zakoncz\n help - wyswietl liste komend\n";
} //funkcja wyswietla dostepne komendy
