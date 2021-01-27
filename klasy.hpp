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
  virtual ~Pojazd()=default;  
  virtual void details()=0;  //wyswietla dokladne dane pojazdu
  virtual int getID()=0;
  virtual int getUnique()=0;

  std::string getMarka(){
    return marka;
  }
  std::string getModel(){
    return model;
  }
  unsigned long getPrzebieg(){
    return przebieg;
  }

}; //klasa glowna




class Osobowy : public Pojazd
{
  private:
  int liczba_drzwi;
  int id=0;
  public:
  Osobowy(std::string m1, std::string m2,int ld, unsigned long p):Pojazd{m1,m2,p}{
    liczba_drzwi=ld;
  }

  virtual int getUnique() override{
    return liczba_drzwi;
  }
  virtual int getID() override{
    return 0;
  }


  virtual void wyswietl_dane() override{
    std::cout << "Samochod osobowy\t"<<marka<<' '<<model<<'\n';
  }
  
  virtual void details() override{
    std::cout<< "\nSamochod osobowy\nMarka: "<<marka<<"\nModel: "<< model << "\nLiczba drzwi: "<< liczba_drzwi <<"\nPrzebieg: "<<przebieg<<"\n\n";
  }
  

  
}; //klasa reprezentujaca samochod osobowy




class Motocykl : public Pojazd
{
  private:
  int liczba_cylindrow;
  public:

  Motocykl(std::string m1, std::string m2,int lc, unsigned long p):Pojazd{m1,m2,p}{
    liczba_cylindrow=lc;
  }

  virtual int getUnique() override{
    return liczba_cylindrow;
  }
  virtual int getID() override{
    return 1;
  }

  virtual void wyswietl_dane() override{
    std::cout << "Motocykl        \t"<<marka<<' '<<model<<'\n';
  }

  virtual void details() override{
    std::cout<< "Motocykl\nMarka: "<<marka<<"\nModel: "<< model << "\nLiczba cylindrow: "<< liczba_cylindrow <<"\nPrzebieg: "<<przebieg<<'\n';
  }

};