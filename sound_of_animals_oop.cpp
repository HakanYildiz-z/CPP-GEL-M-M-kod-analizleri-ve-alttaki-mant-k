//#################################################################################################################################
//        HAYVAN SESLERİNİN AMACINI SÖYLEYEN FOKNSİYON
//#################################################################################################################################


#include<iostream>          // giriş çıkış kütüphanemiz
#include<vector>            // genel olarak her şeyi dizi olarak oluşturmamızı sağlar.
#include<memory>

class Animal {  // bu bizim üst sınıfımız olduğu için verileri virtual olarak yazmamız kritik önem arz ediyor.
public:         // private bloğumuz olmadığı için kurucu yazmamıza da gerek yok.

    virtual ~Animal() = default;          // virtual fonksiyonları çalışma anında tetikleneceğini söyler.
    virtual void makeSound() const = 0;   // 0 burada bunun gövdesinin altta yazılacağını ve bunun bir sanal fonksiyon olduğunu belirtir.
};

class Wolf : public Animal {  // ilk alt sınıfımızı üst sınıfın public bloğunu kullanarak oluşturuyoruz.
public:
    void makeSound() const override {

        std::cout << "kurt ulumasi surunun dagilan uyelerini bir araya toplar.  \n";
    }
};

class Lion :public Animal {
public:
    void makeSound() const override {
        std::cout << "aslan kukremesi alan hakimiyeti ve sinir belirtir.\n";
    }
};

class Crow : public Animal {
public:
    void makeSound() const override {
        std::cout << "kargalrin cikarttigi ses suru hiyerasisini ve guvenligi saglar. \n";
    }
};
int main() {

    // main fonksiyonumuzda ilk önce sınıfımızı kullanabilmek için o sınıfın türünde bir değişken olan animals'ı tanımlıyoruz
    std::vector<std::unique_ptr<Animal>> animals ;

    animals.push_back(std::make_unique<Wolf> ());  // () değeri içine o sınfın private de ihtiyaç duysuğu değeri veriyoruz. bu kodda dışarıdan değer almadığımız için bunu yazmadık.
    animals.push_back(std::make_unique<Lion> ());  // push_back fonksiyonu vector olan yani genel dizi olan değere sondan ekleme yap komutu veriyor.
    animals.push_back(std::make_unique<Crow> ());  // std::make_unique<crow> crow türünde değişken yarat diyor.

    std::cout << " \n HAYVANLARIN CIKARTTIGI SES VE BU SESLERIN AMACLARI :  \n\n";

    for( const auto& a : animals ) {
        a -> makeSound();    // içerideki fonksiyondan faydalanıyoruz.
    }
return 0;
}
