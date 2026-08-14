Bilgisayarın belleği ram iki ana yönetim merkezine ayrılır.
  Stack : boyutu belli olan ve daha küçük boyutlu veriler için kullanırız. işimiz bittiğinde verileri kendisi temizler daha akıllıdır. veriler bellekte yığın halinde         sıralı dizilir. tek problemi büyük boyutlu veya boyutu bilinmeyen verilerde taşma yapabilir ve kod çökebilir. daha hızlıdır ki zaten boyutu da küçüktür.              Sadece heap veya sadece stack kullanmayız genelde ikisini karma olarak kullanırız fakat oran olarak kullanım farkları büyük boyuttadır.
  
  Stack üzerinde tahsis edilen veriler: STM32 gibi denetleyiciler(alan kısıtlı olduğu için zorunlu ) , oyun motorlarının tasarımında (stack'ın hızlı veri                   işleyebilmesinden dolayı 60 FPS veya 120 FPS gibi hızlara ihtiyaç duyulduğu için ) , borsa işlemlerinde mikrosaniyelik anlık hızlara ihtiyaç duyduğumuz                için burada da stack üzerinde veri tanımlamayı kullanırız.

  
  heap : stack'ın aksine daha kararsız bir yapıdadır ve bunun üzerinde tanımladığımız değişkenler ve adres atamaları kendi kendine temizlenmez bu bize ek iş çıkartır         çünkü geride kalan çöp verileri ekstra kod ile bizim silmemiz gerekir. bunun avantajı boyutu bilinmeyen veya yüksek boyutlu verilerde çökmeden işlem                  yapılabilmesidir. boyutu ram kadardır. daha yavaştır boyutu epey büyük olabilmektedir.

   heap üzerinde veri tahsisi : veri tabanı yönetim sistemlerinde devasa verileri belleğe tamponlamak için , web tabanlı bulut sistemlerinde sunucuya kaç                   kişinin bağlanacağı veya dosya boyutlarının ne kadar olacağı bilinmediği için , sistem ara yüzlerinde veya Chrome sekmelerinde ekranın/sekmenin                       önbellekte kaplayacağı tam olarak bilinmediği için kullanılır.

Uniqueptr de bizim işimiz heap üzerinde yapılacak olan bellek atamasıdır. std::unique_ptr tekil akıllı işaretçidir. tek bir değişkene belirlenmiş bir adresin kullanım hakkını verir ve başka bir değişken ile bu adrese ne ulaşabiliriz nede bunu kopyalayabiliriz. sadece std::move ile taşıma yapabiliriz.
std::unique_ptr bir yana kendi akıllı işaretçi kütüphanemizi de yazabiliriz. genelde projelerde cpp ye ait olan std::unique_ptr yi kullanırız. yani tekerleği zaten icat etmişkler yeniden icat etmeye veya element uydurmaya gerek yok. 


sharedptr uniqueptr nin tam aksine tek bir sahipliğe dayanmaz birçok değişken tarafından sahiplenilir ki tam da bunu yapması için bunu yazarız. paylaşımlı ve kopyalanabilir olması birçok güvenlik problemini ve ver sızıntısı ihtimalini içeriz güvenli değildir. 
birden fazla modül aynı veriye erişmesi gerekir o yüzden std::shared_ptr kulanırız. her bir kullanımda std::shared_ptr içinde yer alan sayaç bir artar. modülün işi bittiğinde elindeki paylaşılmış olan kopyayı sildiğinde sayaçtaki o artış tersine döner ve azalır ne zaman ki sayaç sıfıra geldi akıllı ptr kendini otomatik olarak siler.
Bazen iki shared_ptr iç içe yazılınca (dögüsel olarak birbirine bağlanınca )  sayaca bağlı olan silme sistemi yüzünden problem yaşanabiliyor. Bu sebeple std::weak_ptr yi kullanıyoruz temel mantık aynı sadece sayacı arttırmadan kopyalamaya imkan tanıyor. fakat bu weak kaynağa erişmek için lock() fonksiyonu ile geçici bir shared_ptr oluşturur ve kaynağın silinip silinmediğini expired() fonksiyonu ile kontrol ediyoruz.
