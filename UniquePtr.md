Bilgisayarın belleği ram iki ana yönetim merkezine ayrılır.
  Stack : boyutu belli olan ve daha küçük boyutlu veriler için kullanırız. işimiz bittiğinde verileri kendisi temizler daha akıllıdır. veriler bellekte yığın halinde         sıralı dizilir. tek problemi büyük boyutlu veya boyutu bilinmeyen verilerde taşma yapabilir ve kod çökebilir. daha hızlıdır ki zaten boyutu da küçüktür.              Sadece heap veya sadece stack kullanmayız genelde ikisini karma olarak kullanırız fakat oran olarak kullanım farkları büyük boyuttadır.
  
        Stack üzerinde tahsis edilen veriler: STM32 gibi denetleyiciler(alan kısıtlı olduğu için zorunlu ) , oyun motorlarının tasarımında (stack'ın hızlı veri                   işleyebilmesinden dolayı 60 FPS veya 120 FPS gibi hızlara ihtiyaç duyulduğu için ) , borsa işlemlerinde mikrosaniyelik anlık hızlara ihtiyaç duyduğumuz                için burada da stack üzerinde veri tanımlamayı kullanırız.

  
  heap : stack'ın aksine daha kararsız bir yapıdadır ve bunun üzerinde tanımladığımız değişkenler ve adres atamaları kendi kendine temizlenmez bu bize ek iş çıkartır         çünkü geride kalan çöp verileri ekstra kod ile bizim silmemiz gerekir. bunun avantajı boyutu bilinmeyen veya yüksek boyutlu verilerde çökmeden işlem                  yapılabilmesidir. boyutu ram kadardır. daha yavaştır boyutu epey büyük olabilmektedir.

        heap üzerinde veri tahsisi : veri tabanı yönetim sistemlerinde devasa verileri belleğe tamponlamak için , web tabanlı bulut sistemlerinde sunucuya kaç                   kişinin bağlanacağı veya dosya boyutlarının ne kadar olacağı bilinmediği için , sistem ara yüzlerinde veya Chrome sekmelerinde ekranın/sekmenin                       önbellekte kaplayacağı tam olarak bilinmediği için kullanılır.

Uniqueptr de bizim işimiz heap üzerinde yapılacak olan bellek atamasıdır. std::unique_ptr tekil akıllı işaretçidir. tek bir değişkene belirlenmiş bir adresin kullanım hakkını verir ve başka bir değişken ile bu adrese ne ulaşabiliriz nede bunu kopyalayabiliriz. sadece std::move ile taşıma yapabiliriz.
std::unique_ptr bir yana kendi akıllı işaretçi kütüphanemizi de yazabiliriz.

