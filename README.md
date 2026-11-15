# Mars-Kolonisi-Yasam-Destek-Simulatoru
C dili kullanılarak yazılan bu simülasyon oyununda amaç, 15 gün boyunca belirli şartlar sağlanacak şekilde Mars'ta hayatta kalmaya çalışmaktır. Bu 15 gün içerisinde Mars'taki bir küçük araştırma merkezinde mahsur kalan mühendis oyuncumuz; keşif yapılabilir, uyuyabilir, kum fırtınasına yakalanabilir, su yardımı ile oksijen üretebilir, hava şartlarını en aza indirmek için hava kilidi kullanabilir ve tüm bunları yaparken enerji harcadığı için uyurken enerji toplayabilir. 15 Günün sonunda oyuncuyu kurtarmak için kurtarma ekibi gelecektir. Oyuncu, oyunun zorluk seviyesini kendisi belirleyebilmektedir. Kolay, Normal ve Zor olmak üzere 3 aşama vardır. Oyun başarılı sonuçlanır ise oyun bitiminde ekrana oyuncunun kazandığı puan 'durum raporu' olarak çıkarılacaktır. Bu puan, oyunda kalan oksijen, su, enerji ve modül hasarının belirli bir formüle göre hesaplanmasıyla oluşturulur. Eğer oyun başarılı sonuçlanmaz ise ekranda "OYUN BİTTİ: HAYATTA KALAMADINIZ" yazısı çıkmaktadır.

 Oyuna Başlangıç ve Zorluk Seviyeleri
Oyun başladığında sizden bir zorluk seviyesi seçmeniz istenecektir:

[K] Kolay: Başlangıç kaynakları (su, yedek parça) bol, fırtına süresi kısadır (3 tur).

[N] Normal: Dengeli kaynaklar ve orta süreli fırtına (5 tur).

[Z] Zor: Kaynaklar son derece kıt, koşullar ağır ve fırtına süresi uzundur (7 tur).

KOMUTLAR VE İŞLEVLERİ:

Keşif Görevi: Enerji (15) ve oksijen (10) harcar. Rastgele zar atılarak su, yedek parça bulma veya yaralanma ihtimalleri hesaplanır.

Oksijen Üretimi: Su ve enerji harcayarak oksijen üretir.

Modül Tamiri: Yedek parça ve enerji harcayarak modül hasarını kademeli olarak azaltır.

Durum Raporu: Sağlık, enerji, oksijen, su, parça, hasar ve hava kilidi durumunu listeler. Kritik uyarıları ve "TÜM SİSTEMLER NORMAL" mesajını gösterir.

Uyu / Dinlen: Enerji ve sağlık yeniler. Oksijen kritik seviyedeyse (< 20) dinlenirken sağlık kötüleşir.

Kum Fırtınası: Zorluk süresine göre 'for' döngüsüyle fırtına turlarını simüle eder. Çift numaralı turlarda rüzgar şiddetlenir ve hasar iki katına çıkar.

Hava Kilidi Şifresi: Gün sayısına bağlı olarak dinamik türetilen şifreyi çözmek için en fazla $3$ deneme hakkı veren doğrulama mekanizmasıdır.

Çıkış: Oyunu anında sonlandırarak sonuç raporuna atlar.

