//#####################################################################################################################
//         SINIF KULLANARAK ÖĞRENCİ VERİLERİNİ SAKLAYAN VE BUNU MAİN FONKSİYONUNDA KULLANARAK LİSTE OLUŞTURAN KOD
//#####################################################################################################################

#include<iostream>     // giriş çıkış kütüphanesidir run penceresine çıktı verirken kullanıyoruz.
#include<string>       // metin verilerini tutar dizi oluşturur.
#include<vector>       // yan yana büyüyebilen diziler oluşturur.
#include<utility>      // std::move fonksiyonu kullanabilmemizi sağlar.
#include<cstdint>      // int türünün kaplayacağı boyutu ayarlamamızı sağlar


//#####################################################################################################################
//     ANA SINIF VE KULLANILACAK OLAN VERİLER.
//#####################################################################################################################

class Student {   // öğrenci ismi ile bir sınıf oluşturuyoruz.

private:    // dış müdehaleye kapalı çekirdeklerin tanımlandığı kısımdır.
            // burada tanımlanan öğeler kurucu fonksiyon ile hayata geçirilirler.

    std::string first_name;  // öğrencimizin ilk ismini taşıyacak olan string değişkenidir.
    std::string last_name;   // öğrencimizin son ismini saklayacak olan string değişkenidir.
    uint32_t student_id;     // öğrencilerin id sini tam sayı olarak saklamamızı sağlar.

// Private bloğunda dışa kapalı çekirdekleri oluşturduk. şimdi sıra bu çekirdeklere değer atamada...

public:

    // klasik yöntemde const std::string& first_name: x(first_name) {} yazarak referan ile eşitliyoruz. fakat biz modern yöntemi tercih ettik
    // std::move bir nesnenin sahipliğini doğrudan başka bir nesneye devrederek eski nesnenin elindeki veriyi söküp yenisine verir.
    Student( std::string first_name1, std::string last_name1, uint32_t student_id1)
        : first_name(std::move(first_name1)) , last_name(std::move(last_name1)) , student_id(student_id1){} // int li ifade tek bir değişken olduğu için ona move yok.
// NOT : x(y) demek soldakini (x) sağdaki parantez içindeki elemana (y) eşitle demektir.
// NOT: move ise içindekinin sahipliğini sökmüş durumda olduğu için artık tek sahiplik soldakinindir.

    // akış operatörü(operator<<) nesneyi doğrudan cout olarak ekrana basmanı sağlar. sınıfların yazdırma işlemlerinde bunu kullanıyoruz
    // & işareti kullanarak nesnenin hiç kopyalamaya maruz kalmadan ana adresten alınıp kullanılmasını sağlıyoruz.
    // friend yazdığımız ifade müttefgik olarak adlandırılıyor ve private özel bloğuna erişebiliyor. referans (&) ile erişmiş.
    // << ifadesi normalde sola bit kaydır demek 5 << 1 demek sola bir bit kaydır yani 2 nin katı ile çarp demektir.
    // << işareti burada sağdakini al soldakinin içen eat demektir. ileride cout ile bunu burdan alıcaz

    // fonksiyonun çıktısını yazıyoruz main içinde sadece std::cout << student; yazarak bu bloğu yazdırabiliriz.
    friend std::ostream& operator<<(std::ostream& os, const Student& student) {  // veriyi Student adresinden al ve student kilit kelimesi ile çıktıya sun.
        return os << "ID :" << student.student_id << " | " << student.first_name << " | " << student.last_name ;
    }
};

//#####################################################################################################################
//   MAİN FONKSİYONU
//#####################################################################################################################
 int main() {

     std::vector<Student> students;


     // elimizdeki 3 farklı nesneyi ( isim , soy isim , id ) emplace_back() fonksiyonunun yardımı ile tek bir nesne haline getiriyoruz
     // tek bir nesne haline getirdiğimiz şey Student( std::string first_name1, std::string last_name1, uint32_t student_id1) kurucu fonksiyonun içindeki bu bloktur.
     // bunu her bir öğrenci için yapıp hafızaya bunları tek blok halinde  sıra sıra kaydediyoruz. bu kayıtlar students dizisi içine yapılıyor.

     students.emplace_back("Arthur", "Schopenhauer", 1001);
     students.emplace_back("Friedrich", "Nietzsche", 1002);
     students.emplace_back("Niccolo", "Machiavelli", 1003);

     // içinde tek bir nesne haline getirdiğimiz öğrenci bilgileri yer alan students dizisinin cout çıktısını veriyoruz
     // bu ismi verirkende bunu tekrar student in içine atıyoruz.
     for (const auto& student : students) {

         // bunun bize vereceği çıktı publikte yazılmış olan sıralama ile olur. 
         std::cout << student << "\n" ;

     }
    return 0;
 }
