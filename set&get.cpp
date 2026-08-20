//#################################################################################################################################
//          VERİYİ GÜVENLİK SÜZGECİNDEN GEÇİREREK İŞLEME ALMAK && GET VE SET METHODU
//#################################################################################################################################


#include<iostream>
#include<string>
#include<stdexcept>  // hata mesajlarını çıktıya sunup hatanın ne olduğunu nokta atışı olarak tespit etmemizi sağlayan sınıfları barındırır.

class bankAccount {
private:
    double balance{0.0}; // değer vermek zorunda değiliz ama sistem çöp değer atamasın diye değer verdik.

public:

    // explicit işlemcinin kafasına göre davranıp tür değişimi yapmasını engeller. kurucu fonksiyonu bununla başlatıyoruz.
    explicit bankAccount(double initialBalance) {
        setBalance(initialBalance);        // kendi yazmış olduğumuz set fonksiyonumu kullanıyoruz fonksiyon alt satırlardadır.
    }

    // [[nodiscard]] dönen değer bir değişkene atanmalı ve mutlaka kulanılmalıdır der.
    [[nodiscard]] double getBalance() const noexcept {  // veriyi dışarı veren ve const yani deiştirilemez olan bir kodumuz var.
        return balance;                                 // noexcept sert bir güvenlik duvarıdır ve hata olması halinde kodu std::terminate ile yok eder.
    }

    // değişkenin durum güncellemesini yaparken set kullanırız. burda değişim yapıcağımız için const koymadık.
    void setBalance(double amount) {
        if (amount < 0.0) {  // burada bakiye eşitlemesi yapacağımız için bakiyenin eksi olup olmadığını kontrol ediyoruz çünkü eksi bakiye olmaz.

            throw  std::invalid_argument("HATA  bakiye eksi olamaz."); // buradaki std::invalid_argument geçersiz argüman sınıfıdır.
        }                                                              // kodu durdurma görevini burada throw yapar sınıf sadece hatanın türünü söyler.
        balance = amount;
    }

    // hesaba para yatıran güvenli fonksiyon
    void deposit(double amount) {
        if (amount <= 0.0) {
            throw std::invalid_argument(" HATA yüklenecek tutar sıfır veya daha küçük olamaz.");
        }
        balance += amount;
    }
    void withdraw(double amount) {
        if (amount <= 0.0 || amount > balance) {  // hesabımızdaki güncel paradan daha fazlasını çekmeyelim diye
            throw std::invalid_argument("HATA geçersiz tutar girdiniz lütfen geçerli bir tutar girin.");
        }
        balance -= amount;
    }
// sınıfın private bloğunda çekirdek değişkenimiz olan bakiyeyi tanımladık. publicte kurucu fonksiyonumuzu oluşturduk.
// 4 farklı fonksiyon oluşturduk bunlar dışarıdan amount (tutar/miktar) değeri alıyorlar bu fonksiyonların ana amacı güvenliktir.
};
int main() {
    try {
        bankAccount my_account(0.0) ; // kurucu fonksiyon ile ilk bakiye değerimizi atadık. öğrenci olduğumuz için para sıfırda

        my_account.deposit(5000.0); // 5000 ekleme yapıyoruz.

        // burada balance değerini doğrudan yazdıramayız çünkü o değer private ye ait ve ham halde kullanılamaz.
        // bu yüzden yazdığımız fonksiyonları kullanmak zorundayız.
        std::cout << "hesabina para eklemei yapildi. Yeni bakiyen" << my_account.getBalance() << "\n";

        my_account.setBalance(-500.0);  // hatalı satır ekledik catch yakalasın diye
        }catch ( const std::exception& e) {  // catch ile hatayı yakalarız const std:: exception& e ile hatanın kmliğini kesşn ve net şekilde belirleriz.
            std::cerr<<  "sistem koruyu devrede hata: " << e.what() << "\n ";

        }

}
