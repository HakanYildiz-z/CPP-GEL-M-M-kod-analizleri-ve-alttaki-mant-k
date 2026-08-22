//#################################################################################################################################
//       HACİME GÖRE SIRALAMA İŞLEMLERİ.   polimorfizm ile küp küreleri hacimlendirip sonrasında bunların hacimlerine göre sıralıyoruz.
//#################################################################################################################################

#include<iostream>     // giriş çıkış kütüphanesi
#include<vector>       // bir nesnenin farklı elemanlarını oluşturur o nesne dizi gibi davranır.
#include<memory>       // std::unique ve shared pointerleri kullanmamızı sağlayan akıllı bellek yönetimi kütüphanemizdir.
#include<cmath>        // matematiksel hesapları kusursuzca çözen hesap modülüdür.
#include<algorithm>    // büyüklüğe göre sıralama eleman arama eleman değiştyirme gibi bir çok görevi üstlenir

class sekil {
public:                         //virtual fonksiyonların çalışma anında tetikleneceğini söyler bunun sayesinde dinamik olarak uygun fonksiyonlar çalıştırılır.
    virtual ~sekil() = default; // polimorfizm kuralları gereği virtual zorunludur fakat = default; yerine {} koyabiliriz.

    // sanal fonksiyonlarımızı yazıyoruz. bunların herbiri her alt sınıfta yeniden ve daha farklı olarak yazılıcak
    virtual double hacim_hesapla() const = 0;   // 0 bu fonksiyonu gövdesiz bırakarak soyut komuta merkezi haline getirir. buna saf sanal fonksiyon denir.
    virtual void bilgi_yazdir() const = 0;
};

class kup : public sekil {
private:
    double kenar;

public:
    kup (double k) : kenar(k){}   // kurucu fonksiyon

    double hacim_hesapla() const override { // çalışmak için dışarıdan veri almıyor sınıfın kenar değişkenini kullanıyor.
        return std::pow(kenar,3);   // std::pow(x,3) matematikte kuvvet alma işlemidir x in 3. kuvvetini alır.
    }
    void bilgi_yazdir() const override {    // override bu fonksiyonun bir sanal fonksiyondan türediğini söylüyor.
        std::cout << "kenar uzunlugu :" << kenar << "hacim degeri :" << hacim_hesapla() << "\n";
    }
};

class kure : public sekil{
private:
    double yari_cap;
    double const PI = 3.141592653589793238;
public:
    kure (double yari_cap ) : yari_cap(yari_cap) {}

    double hacim_hesapla() const override {
        return (4.0 / 3.0) * PI * std::pow(yari_cap,3);
    }
    void bilgi_yazdir() const override{
        std::cout << "yari_cap :" <<yari_cap << "hacim degeri :" << hacim_hesapla()<< "\n";
    }
};

// bir üst sınıf yazdık ve onun içine eklediğimiz sanal fonksiyonları 2 tane alt sınıfımızda ayrı ayrı kullandık.

//#################################################################################################################################
//       MAİN FONKSİYONU
//#################################################################################################################################


int main() {
    // std::vector iletanımladığımız dizi içine her türlü öğeyi alabilirken string sadece metin dizilerini alır.
    std::vector<std::unique_ptr<sekil>> sekiller ;  // tür içinde tür uygulayarak kurucu sınıfımıza bağlı olan ve sahipli tek bir değişkene ait olan bir dizi tanımlıyoruz.

    // şimdi sekiller üzerine 5 tane kup verisi ekleyelim.
    // make_unique weak ile karıştırma!! bu fonksiyon heap üzerinde nesne oluşturup onu unique ye verir.
    sekiller.push_back(std::make_unique<kup>(2.5));      // bu bir yazım standartıdır. nesneyi sekiller doğrudan kapar.
    sekiller.push_back(std::make_unique<kup>(3.4));
    sekiller.push_back(std::make_unique<kup>(4.5));
    sekiller.push_back(std::make_unique<kup>(7.2));
    sekiller.push_back(std::make_unique<kup>(1.9));

    // sekiller üzerine 5 tanede kure verisi ekleyelim aynı yazım tarzıyla aynı unique içine...
    sekiller.push_back(std::make_unique<kure>(2.3));
    sekiller.push_back(std::make_unique<kure>(6.5));
    sekiller.push_back(std::make_unique<kure>(2.9));
    sekiller.push_back(std::make_unique<kure>(4.4));
    sekiller.push_back(std::make_unique<kure>(3.1));


    // şimdi bunların hepsinin hacmini büyükten küçüğe sıralayalım.

    // std::sort asıl ameleliği yapan ve içine verilen değişkenleri küçükten büyüğe sıralayan elemandır. kod içine yazdığımız > işareti ile büyükten küçüğe sıralar.
    // sekiller.begin ile kodun en başından başlayarak kapsama almasını sağlıyoruz. sekiller.end ile kapsamın en sona kadar olduğunu söylüyoruz.
    // [] işareti bir lambda fonksiyondur. lambda fonksiyon anlık olarak bulunduğu konumda tanımlanıp işleme alınır fakat normal fonksiyonu kodun başka bir yerinde tanımlaman gerekir.
    // lambda fonksiyon yazıyoruz ve içine a ve b olmak üzere iki tane kendi yarattığımız tür ile değişken atıyoruz.
    // -> işaretini a akıllı pointer olduğu için onun içine girip içinde bulunan hacim_hesapla() fonksiyonunu çalıştırması için yazdık
    // bu kısmın nasıl çalıştığını sonra daha detaylı anlatıcam
    std::sort(sekiller.begin() , sekiller.end(),
        [](const std::unique_ptr<sekil>& a , const std::unique_ptr<sekil>& b) {
            return a -> hacim_hesapla() > b -> hacim_hesapla();
        });

    std::cout << "kup ve kurelerin hacimlerine gore siralanmis hali \n";

    for (const auto& sekil : sekiller) {
        sekil -> bilgi_yazdir();
    }
}
