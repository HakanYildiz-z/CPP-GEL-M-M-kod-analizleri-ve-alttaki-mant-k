//########################################################################
//     AKILLI İŞARETÇİLER İLE HEDEF BELİRLEYİP BUNU OTOMATİK OLARAK FARKLI
//     HAVA SAVUNMA KATMANLARINA BAĞLAYIP HEDEFİ İMHA EDEN CPP KODU.
//#########################################################################



#include<iostream>  // giriş çıkış kütüphanesi
#include<memory>    // akıllı işaretçiler için tanımlarız
#include<string>    // string oluşturabilmek için
#include<thread>    // ihtiysacımız olan süre buyunca iş parçacığını geciktirmek için kullanırız
#include<chrono>    // gerçek saat dilimlerini kodumuuza uygulayabilmek için kulanırız
#include<cstdio>    // dosya işlemlemleri için kullanırız dosya açma dosya kapama

//###############################################################################
//    HEDEFİN VERİLERİNİ İÇEREN ANA SINIFIN KODU
//###############################################################################
class TargetData{

private: // öncelikle özel olarak sınıfımızın iskelet yapısını kuralım. bu kısım çekirdek bölümdür. ilk tanımlamaların
         // ham hallerini burada yapmamız gerekir.
    std::string classication;  // tehditin ne olduğunu ve ismini tutmak için metin tabanlı string oluşturacağız.
    double distance_km;        // füzenin ulaşmasına kaç km kaldı onu belirtir.
    double speed_mach;         // füzenin hızını mach cinsinden verir (bir mach saniyede 340 metre saatte 1225.4 km eder)
    int telemetry_cycle;       // füzenin anlık durumunun kaç kez güncellendiğini söyleyen  bir sayaçtır.

public:  // bu kısımda ise kurucu , yıkıcı , operasyonel , salt okunur şekilde sıralayarak hiyeraşik sıra ile
         // main içinde kullanacağımız fonksiyonları tek tek yazıyoruz.

// ## KURUCU FONKSİYON : özel bölümdeki çekirdekleri somutlaştıran fonksiyondur.
    TargetData(std::string c , double d , double s)
        : classication(c) , distance_km(d) , speed_mach(s) , telemetry_cycle(1) {
        std::cout << " iran yine israili ıskaladı adamlar bize doğru atmışlar " <<classication << "GELİYOOUUUR      "
        << "Anlık mesafesi :" << distance_km << "KM     " <<"Anlık hızı :" << speed_mach << "mach \n";
    }
// ## YIKICI FONKSİYON : shared_ptr nin arka planındaki sayaç sıfırlandığında bunu çalıştırıcaz.
    ~TargetData() {
        std::cout << "Hedefin imhası tamamlandı Lan biriniz gidip şu İranı uyarsın gerekirse gölük falan taksın \n";
    }

// ## DURUM GÜNCELLEYEN FONKSİYON : hareketli bir hedefe sahip olduğumuz için konumunun güncellenmesi gerekiyor.
    void updatePosition(double deltaTimeSeconds) {
        // fonksiyonun içine geçmiş olan zamanı veriyoruz.

        double speedkmpersec = speed_mach * 0.343 ;  // gelen füzenin saniyede kat ettiği mesafeyi km cinsinden verir.
        distance_km -= speedkmpersec * deltaTimeSeconds; // kalan km yi tekrardan güncelliyoruz.
        if (distance_km <0 ) distance_km = 0;  // füzenin uzaklığı negatif olamaz.
        telemetry_cycle ++ ;
    }
   // elimizdeki verilere verileri bozmadan erişebilmek için const olan bir iki fonksiyon yazıyoruz.
   // fark edilebileceği üzere fonksiyonlar herhangi mekanik iş yapmadan sadece verileri return ediyor.
    int getCycle() const { return telemetry_cycle; }
    double getspeed() const { return speed_mach;}
    double getdistance() const { return distance_km;}
};

//########################################################################################
//      ALT SINIFLARA ARA YÜZ ŞABLONU SUNAN SAVUNMA SINIFI
//########################################################################################
class AirDefenseSystem {
protected: // private sahip olduklarını tamamen dış dünyaya kapatırken bu kendi altında yazılmış olan sınıflar için kapalı değil.
           // alttta türetilecek sınıflara bunları vericeğimiz için bunları protected olarak yazıyoruz.
    std::string systemName;  // savunma sisteminin ismini tutuyor örneğin s400
    std::weak_ptr<TargetData> trackedTarget;  //

public:  // fonksiyonları yazdığımız yerdir.

// ## KURUCU FONKSİYON ana fonksiyondur sistemi başlatır.
    AirDefenseSystem (std::string name ) : systemName(name){}

// ## BAŞ YIKICI FONKSİYON virtual sayesinde bu sınıf yok edilirken buna bağlı olan alt sınıfların hepsi de onla birlikte gidiyor.
    virtual ~AirDefenseSystem() = default;   // {} yazabilirdik ama default ile en optimize şekilde yıkıcı oluşturulur ve kullanılır.

    void lockOnTarget(const std::shared_ptr<TargetData> & Target) {
        trackedTarget = Target;
        std::cout << systemName << "hedef telemetri hattına kilitlendi \n";
    }
    void monitorTelemetry() {
        if (auto target = trackedTarget.lock()) {
            std::cout << systemName << " canlı telemetri "<< target-> getCycle() << "    kalan mesafe " << target -> getdistance()
                 << "    son hız\n" << target-> getspeed();
        }else {
            std::cout << systemName<< "hedef imhası başarı ile yapıldı \n";
        }
    }
    virtual bool engageAndDestroy() = 0;
};

