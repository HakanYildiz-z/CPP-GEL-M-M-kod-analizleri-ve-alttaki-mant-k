// ------ RAII tabanlı C++ dosya yöneticisi ------

#include <iostream> // giriş çıkış streamı dır. std::cout gibi nesneleri kontrol etmemizi sağlar.
#include<memory>    // std::uniqueptr kullanmamızı sağlar.
#include<cstdio>    // dosya yönetimi için gerekli olan std::fopen std::fprint gibi komutların kullanımına imkan tanır.
#include<thread>    // std::this_thread::sleep_for fonksiyonunu kullanarak çalışır haldeki kodu duraklatmamızı sağlıyor. 10 saniyede bir veri alımı yapıcamız için bunu yazdık.
#include<chrono>    // zaman hesabı yaparken kullandığımız birimlerin ve tiplerin tanımlamasını yapar.
#include<random>    // std::random_device donanım destekli kriptografik kalitede rasgele sayı üretmeye yarar.
#include<csignal>   // işletim sisteminden gelen sinyalleri yakalayan komutların kullanımına olanak tanır.
#include<atomic>    // std::atomik sınıfı ile değişkenlerin işlem çakışması ile bozulmamasını garanti altına alıyoruz.

std::atomic<bool> systemRunning{true};   // atomik değişim adımlarını tek blok halne getiriyor. bool bizim türümüzdür true ve false döndürür.
                                           // bunu while döngüsü için kullanıcaz.

void signalHandler(int signum) {  // kodu duraklatmak için kullanıyoruz.
    systemRunning = false;
}

//###############################################################
//###########   MAİN FONKSİYONU #################################
//###############################################################


int main() {

    std::signal(SIGINT, signalHandler);   // signal ile işletim sisteminin sinyal tablosuna müdehale edip SIGINT ise koda dışardan CTRL+C sinyali gelince sistemi durdururuz.
                                                 // kodumuz çökmesin diye SIGINT den sonra sistemi signalHandlere bırakırız

    auto fileCloser = [](FILE* fp) {       // auto ile işlemcini otomatik olarak tür atamasını sağlıyoruz.
                                                 // [] işareti boş fonksiyon demektir () kısmında ise bizim verdiğimiz parametreler var.
        if (fp) {
            std::cout<< "Komutununz işleme akındı program kapatılıyor...\n";
            std::fclose(fp);     // açık olan dosyayı işletim seviyesinde kapatır ve kilitleri kaldırır.
        }

    }; // buradaki ; işareti fonksiyona ait değildir atama işlemden gelmektedir fonksiyonun sınırlarını{} bloğu belirler.

    std::unique_ptr<FILE,decltype(fileCloser)> sensorFile(std::fopen("telemetry_data.txt" , "a"), fileCloser);
        // stdunique_ptr nesne yok olduğunda belleği temizler. FILE bir tip'dir int mantığında bir tip
        // decltype(fileCloser) fileCloser in tipini belirleyip unique_ptr ye söyler(bu bir lambda fonksiyondu yukarda öyle yapmıştık).
        // std::fopen dosyayı append yani sonuna ekle modunda açar eski verilere dokunmaz sadece dosyayı açar.
        // "a" append dir. "telemetry_data.txt" açılıcak olan dosyanın mevcut ismidir. ve sonrasında yazılan fileCloser dosyayı kapatmak içindir.
        // sensorFile ise yanındaki parantez ile doğrudan başlatma mekanizmasına sahip olan dosyanın adresini tutar.


    if (!sensorFile) {   // eğere dosyayı oluşturmamışsak hata mesajı vermeliyiz
        std::cerr << "hata hedef dosya oluşturulamadı!  \n";
        return 1;         // progarmın hata ile çöktüğünü bir yazarak bildiriyoruz.
    }


    //###############################################################
    //###########   RASGELE SAYI ÜRETİM MOTORU  #####################
    //###############################################################

    //Hata olmazsa sistemin başladığını belirten bir ekran çıktısı veririz.
    std::cout << "[Sistem]: Gercek zamanli veri hatti acildi. (Durdurmak icin Ctrl+C'ye basin)\n";

    std::random_device rd;         // işletim sisteminin ve donanımın sunduğu mevcut gürültüye ulaşan rd yi tannımlar.

    std::mt19937 gen(rd());     // rd deyi bir fonksiyon gibi çağırdığında o anki anlık gürültüden tek bir sayı alır.
                                   // alınan o tek sayıyı mt19937 motoruna verir ve buradan bize rasgele denebilecek bir sayı üretir.

    std::uniform_int_distribution<> tempDist(1,100);     // üretilece olan sayıyı 1 ile 100 arasında sınırlar

    std::uniform_int_distribution<> speedDist(1,500);    // üretilece olan sayıyı 1 ile 500 arasında sınırlar

    int cycle = 1;  // sayaç olarak döngü içinde kullanıcaz.



    //###############################################################
    //###########   ANA İŞLEM DÖNGÜLERİ #############################
    //###############################################################

    while (systemRunning) {  // systemRunning true veya false değerlerini alır.

       // sadece 1 ve 100 arasında değeler alabilen tempDist'in i içine rasgele değer üreten motoru (gen) koyuyoruz.
        int temp = tempDist(gen);
       // sadece 1 ile 500 arasında değer alanilen speedDist in içine rasgele değer üreten motoru (gen) koyuyoruz
        int speed = speedDist(gen);

        std::cout << "dongu : " << cycle << "   sicaklik :" << temp <<"   hiz : " << speed << "\n";

        std::fprintf(sensorFile.get() , "sicaklik %d C  hiz  %d RPM \n" , temp, speed);
         // std::fprintf ile dosyanıniçine ulaşıp yazıları yazar.
         // sensorFile.get() uniqueptr içindeki veriyi alıp std::fprintf in eline verir.

        std::fflush(sensorFile.get());
         // tampon belleği bekletmeden doğrudan hard diske yazdırır. elektrik kesilse dahi veri kaybını önler.


       //systemRunning true olmaya devam ediyorsa ve i <  ise sistemi devam ettir.
        for ( int i = 0 ; i < 10 && systemRunning ; i++) {

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    cycle++;
    }
return 0;

}

