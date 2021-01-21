// plik zawierajacy klasy pojazdow

class Pojazd
{
  protected:
  std::string marka;
  std::string model;
  unsigned long przebieg;
  
  public:
  Pojazd(std::string m1, std::string m2, unsigned long p): marka(m1), model(m2), przebieg(p){}

  virtual void wyswietl_dane()=0; //wyswietla podstawowe dane o pojezdzie
  virtual void zapisz_pojazd(std::fstream& plik)=0; //zapisuje pojazd do pliku
  virtual ~Pojazd()=default;  
  virtual void details()=0;  //wyswietla dokladne dane pojazdu

  std::string getMarka(){
    return marka;
  }
  std::string getModel(){
    return model;
  }

}; //klasa glowna




class Osobowy : public Pojazd
{
  private:
  int liczba_drzwi;

  public:
  Osobowy(std::string m1, std::string m2,int ld, unsigned long p):Pojazd{m1,m2,p}{
    liczba_drzwi=ld;
  }


  virtual void wyswietl_dane() override{
    std::cout << "Samochod osobowy\t"<<marka<<' '<<model<<'\n';
  }
  
  virtual void details() override{
    std::cout<< "\nSamochod osobowy\nMarka: "<<marka<<"\nModel: "<< model << "\nLiczba drzwi: "<< liczba_drzwi <<"\nPrzebieg: "<<przebieg<<"\n\n";
  }
  
  virtual void zapisz_pojazd(std::fstream& plik) override{
    int temp=0;
    plik.write((const char*)&temp, sizeof(int));
    plik.write(marka.c_str(),marka.size()+1);
    plik.write(model.c_str(),model.size()+1);
    plik.write((const char*)&liczba_drzwi, sizeof(int));
    plik.write((const char*)&przebieg, sizeof(unsigned long));
  } //metoda zapisujaca samochod osobowy do pliku

  static void czytaj(std::vector<std::unique_ptr<Pojazd>>& pojazdy, std::fstream& plik){
    std::string tekst;
    std::string tekst2;
    int temp2;
    unsigned long longtemp;
    getline(plik, tekst, '\0');
    getline(plik, tekst2, '\0');
    plik.read((char*)&temp2,sizeof(int));
    plik.read((char*)&longtemp,sizeof(unsigned long));
    pojazdy.push_back(std::make_unique<Osobowy>(tekst,tekst2,temp2,longtemp));
  } //metoda odczytujaca samochod osobowy z pliku
}; //klasa reprezentujaca samochod osobowy




class Motocykl : public Pojazd
{
  private:
  int liczba_cylindrow;
  public:

  Motocykl(std::string m1, std::string m2,int lc, unsigned long p):Pojazd{m1,m2,p}{
    liczba_cylindrow=lc;
  }

  virtual void wyswietl_dane() override{
    std::cout << "Motocykl        \t"<<marka<<' '<<model<<'\n';
  }

  virtual void details() override{
    std::cout<< "Motocykl\nMarka: "<<marka<<"\nModel: "<< model << "\nLiczba cylindrow: "<< liczba_cylindrow <<"\nPrzebieg: "<<przebieg<<'\n';
  }

  virtual void zapisz_pojazd(std::fstream& plik) override{
    int temp=1;
    plik.write((const char*)&temp, sizeof(int));
    plik.write(marka.c_str(),marka.size()+1);
    plik.write(model.c_str(),model.size()+1);
    plik.write((const char*)&liczba_cylindrow, sizeof(int));
    plik.write((const char*)&przebieg, sizeof(unsigned long));
  } //metoda zapisujaca motocykl do pliku

  static void czytaj(std::vector<std::unique_ptr<Pojazd>>& pojazdy, std::fstream& plik){
    std::string tekst;
    std::string tekst2;
    int temp2;
    unsigned long longtemp;
    getline(plik, tekst, '\0');
    getline(plik, tekst2, '\0');
    plik.read((char*)&temp2,sizeof(int));
    plik.read((char*)&longtemp,sizeof(unsigned long));
    pojazdy.push_back(std::make_unique<Motocykl>(tekst,tekst2,temp2,longtemp));
  } //metoda odczytujaca motocykl z pliku
};