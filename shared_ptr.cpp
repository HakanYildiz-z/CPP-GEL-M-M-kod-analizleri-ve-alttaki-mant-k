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
        std::cout << " iran yine israili iskaladi adamlar bize  " <<classication << " atmislar \n "
        << "Anlik mesafesi :" << distance_km << "KM     " <<"Anlik hizi :" << speed_mach << "mach \n \n ";
    }
// ## YIKICI FONKSİYON : shared_ptr nin arka planındaki sayaç sıfırlandığında bunu çalıştırıcaz.
    ~TargetData() {
        std::cout << "Hedefin imhasi tamamlandi Lan biriniz gidip şu irani uyarsin gerekirse gozluk falan taksinlar bu ne hep bize atiyorlar \n";
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
    double getSpeed() const { return speed_mach;}
    double getDistance() const { return distance_km;}
};

//########################################################################################
//      ALT SINIFLARA ARA YÜZ ŞABLONU SUNAN SAVUNMA SINIFI
//########################################################################################
// bu sınıf soyut bir sınıftır içinde gövdesi olmayan ve alt sınıflar ile doldurulması gereken fonksiyonlar bulundurur.
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


   // Takip edilecek olan hedefi savunma sistemine bildiren fonksiyon.
   // trackedTarget adındaki değişkeni target eşitleniyor bunu da aşağıdaki başka bir fonksiyona vericek.
    void lockOnTarget(const std::shared_ptr<TargetData> & Target) {
        if (!Target) return;
        trackedTarget = Target;
        std::cout << systemName << "hedef telemetri hattina kilitlendi \n";
    }

   // Ekrana veri yazdıracak olan fonksiyonu yazdık.
    void monitorTelemetry() {
        if (auto target = trackedTarget.lock()) {
            std::cout << systemName << " canli telemetri "<< target-> getCycle() << "    kalan mesafe " << target -> getDistance()
                 << "    son hiz" << target-> getSpeed() <<"\n\n";
        }else {
            std::cout << systemName<< "hedef imhasi başari ile yapildi \n";
        }
    }

   // bu sınıftan türeyen fonksiyonlar bunu kendi içinde kullanmalıdır.
   // saf sanal bir fonksiyondur. içinde bulıuns-duğu sınıfı soyut sınıfa çevirir.
    virtual bool engageAndDestroy() = 0;
};

//################################################################################
//    UZUN MENZİLLİ HAVA SAVUNMA SİSTEMİ
//################################################################################
class LongRangeDefense : public AirDefenseSystem {
// alt sınıfın üst sınıfa ait olduğunu böylelikle belirtiyoruz yoksa üst sınıfa ait olamaz.
public:
    // üst sınıfın kurucusunu çağırıyoruz alt sınıfların kurucuları üst sınıflarinkine eşit olur.
    LongRangeDefense() : AirDefenseSystem("uzun menzilli hava savunma sistemi S-400 , HISAR-U aktif \n\n"){}


    bool engageAndDestroy() override {
        std::cout << systemName << "savunma islemi basari ile gerceklestirildi \n";
        return true;
    }
};
class MediumRangeDefense : public AirDefenseSystem {
public:
    MediumRangeDefense () : AirDefenseSystem(" orta menzilli hava savunma sistemi HISAR-O aktif\n\n"){}


    bool engageAndDestroy() override {
        std::cout << systemName << "savunma işlemi basari ile gerceklestirildi \n";
        return true;
    }
};



//##############################################################################################
//        ANA KONTROL BLOĞUNUN YER ALDIĞI MAİN FONKSİYONUNA GELDİK.
//##############################################################################################
int main() {

   // akıllı işaretçiler C tarzı FILE* kaynaklarını nasıl kapatacağını bilmez biz de dosya açmak istediğimiz için bunu elimizle kapatacağız.
   // dosyayı kapatmak için lambda fonksiyonu yazıyoruz. neden normal fonksiyon yazmıyoruz dersen lamda hafıda yer kaplamıyor yani tassarruf amacı ile
    auto fileCloser = [](FILE* fp) {               // auto değişkenin türün otomatik olarak tespit eder.
        if (fp) {
            std::fclose(fp);
            std::cout<<"dosya kapatildi \n ";
        }

    };

   // unique de dosya açacaksak aşağıdaki mimari zorunluluğa uymak zorundayız
    std::unique_ptr<FILE,decltype(fileCloser)> logFile(std::fopen("radar_telemetry.txt" , "w"), fileCloser);
     // stdunique_ptr nesne yok olduğunda belleği temizler. FILE bir tip'dir int mantığında bir tip
     // decltype(fileCloser) fileCloser in tipini belirleyip unique_ptr ye söyler(bu bir lambda fonksiyondu yukarda öyle yapmıştık).
     // std::fopen dosyayı write yani nesneyi sıfırdan yazar eski verileri siler.
     // "w" write dir. "radar_telemetry.txt" açılıcak olan dosyanın mevcut ismidir. ve sonrasında yazılan fileCloser dosyayı kapatmak içindir.
     // logFile ise yanındaki parantez ile doğrudan başlatma mekanizmasına sahip olan dosyanın adresini tutar.


    // logFile ile dosya adresine ulaşılmazsa yani dosya açılmamışsa hata ver ve kapat.
    if (!logFile) {
        std::cerr << "Telemetri log dosyasi olusturulamadi! Operasyon iptal edildi.\n";
        return 1;
    }
    std::cout << "  KATMANLI HAVA SAVUNMA VE TELEMETRI MERKEZI AKTIF \n\n";

    // Yazdığımız alt sınıfları stack üzerinde main fonksiyonuna geçiriyoruz. stack kendi kendini silen akıllı kısımdı.
    // sınıflarımız aynı zamanda bizim yarattığımız bir tür'dür cpp'nin kendi türleri int double float vs vs iken bizde kendi türümüzü oluşturuyoruz.
    LongRangeDefense LongRange ;
    MediumRangeDefense MediumRange ;

    // heap üzerinde bellek tahsis ediyoruz ve akıllı işaretçileri kullanıyoruz.
    // TargetData bizim yarattığımız bir sınıf bir tür'dür.
    // make_shared kısmındaki veriler Targetdata sınıfının kurucu fonksiyonunun ihtiyaç duyduğu verilerdir.
    std::shared_ptr<TargetData> Target = std::make_shared<TargetData>("Hipersonik fuze " , 500.0, 7.2);


   // nesnenin içindek veriye fonksiyon ile ulaşarak onun belli özelliğini aktif hale getirmesini sağlıyoruz.
    LongRange.lockOnTarget(Target);  // medium olanı şimdilik kullanmıyoryuz çünkü işi önce uzun menzilli yapacak

    std::cout<< "Telemetri akisi basliyor\n";

    // target yok edilmediği sürece döngümüz devam etsin
    for (int i = 0 ;i < 3 && Target ; i++) {
        std::cout << " Telemetri :" << Target ->getCycle() << "\n";

        // hedef konumunu güncelliyoruz . kendi yazdığımız fonksiyonu kullanıyoruz.
        Target -> updatePosition(1.0);

        // monitör verilerini yazdırır clion üzerindeki ekrana basan bu fonksiyon
        LongRange.monitorTelemetry();


        // yukarıda akıllı işaretçi ile oluşturduğumuz dosyanın içine verileri yazıyoruz.
        std::fprintf(logFile.get(), "kontrol: %d, Mesafe: %.2f KM, Hiz: %.1f Mach\n \n \n",
                     Target->getCycle(), Target->getDistance(), Target->getSpeed());      // Target içinden verileri fonksiyonlar yardımıyla alıyoruz daha güvenli olsun diye

        std::fflush(logFile.get()); // Veriyi diske anında yazdırır. sistem çökse bile verinin kayıt altına alınmasını garantiler.
        // 1 saniyelik bekleme ver
        std::this_thread::sleep_for(std::chrono::seconds(1));   // bunun yazımı da standarttır.
        std::cout << "\n"; // satır atla
    }
    std::cout << " tehdit tehdit kritik noktaya geldi atis emri verildi. \n";

    if (LongRange.engageAndDestroy()) {  // YOK EDİCİ FONKSİYON ÇALIŞTIRILIR VE tehdit yok edilir.
        Target.reset();
    }

    std::cout << "\n SON KONTROLLER :\n";


    LongRange.monitorTelemetry();


    // yazdırılmış olan dosyaya son durumu aktarıyoruz
    std::fprintf(logFile.get() , "Hedefin imhası uzun menzilli sistem ile gerçekleştirildi orta menzil HISAR-O kullanılmadı \n\n");

    return 0;
}
