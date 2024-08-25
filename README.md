<img src="https://i.imgur.com/TvlDmPS.png" width="1500" height="150">
<div align="center">
  <h1>42 CURSUS PROJECT NETPRACTİCE</h1>
</div>

# İçindekiler

1. [TCP / (İletim Kontrol Protokolü)](#TCP)
2. [IP / (İnternet Protokolü)](#IP)
   - [IPv4 / (İnternet Protokolü Version 4)](#IPv4)
   - [IPv6 / (İnternet Protokolü Version 6)](#IPv6)
3. [Subnet Mask / (Alt Ağ Maskesi)](#SubnetMask)
   - [CIDR / (Sınıfsız Etki Alanları Arası Yönlendirme)](#CIDR)
   - [Network / (Ağ)](#Network)
4. [Switch / (Ağ Anahtarı)](#Switch)
5. [Router / (Yönlendirici)](#Router)

## TCP

<p align="center">
  <img src="https://github.com/remzikutun/42_Cursus/blob/NetPractice/TCP.gif" alt="Image" />
</p>

<p>&nbsp;&nbsp;&nbsp;&nbsp;TCP (İletim Kontrol Protokolü) veri iletimi sırasında güvenliği ve doğruluğu sağlar. Veriyi küçük parçalara (segmentlere) böler, bu parçaları sırasıyla gönderir ve alıcıya ulaştığında doğru sırada ve eksiksiz olup olmadığını kontrol eder. Eğer bir parça kaybolur veya hatalı olur ise, TCP o parçayı yeniden gönderir. Bu sayede veri, alıcıya eksiksiz ve hatasız bir şekilde ulaşır.</p>

## IP

<p>&nbsp;&nbsp;&nbsp;&nbsp;IP (İnternet Protokolü) internet veya bir ağ üzerindeki cihazlar arasında veri iletimini sağlar. Her cihaza benzersiz bir IP adresi atayarak verilerin doğru hedefe ulaşmasını sağlar. Bu adresleme sistemi, cihazların birbiriyle iletişim kurmasına ve veri alışverişi yapmasına olanak tanır. IP’nin iki ana versiyonu vardır. Bunlar; IPv4 ve IPv6’dır.</p>

### IPv4

<p align="center">
  <img src="https://github.com/remzikutun/42_Cursus/blob/NetPractice/IPv4.jpg" alt="Image" />
</p>

<p>IPv4 (İnternet Protokolü Version 4), internet veya bir ağ üzerindeki cihazlar arasında veri iletimi için kullanılan bir IP adresleme sistemidir. IPv4, 32 bitlik adreslerden oluşur ve bu nedenle 4.3 milyar benzersiz IP adresi sunar. IPv4 adresleri nokta ile ayrılan 4 grup halinde rakam içerir.(Örnek: 192.168.1.1)</p>

### IPv6

<p align="center">
  <img src="https://www.beyaz.net/files/elfinder/content_photo/icerik_dosyalari/%C4%B1pv6_nedir.png" alt="Image" />
</p>

<p>IPv6 (İnternet Protokolü Version 6), internet veya bir ağ üzerindeki cihazlar arasında veri iletimi için kullanılan bir IP adresleme sistemidir. IPv6 128 bitlik adreslerden oluşur ve bu nedenle trilyonlarca benzersiz IP adresi sunar. IPv6 adresleri iki nokta üst üste ile ayrılan 8 grup halinde hexadecimal rakam içerir. (Örnek: 2001:0db8:85a3:0000:0000:8a2e:0370:7334)</p>

## SubnetMask

<p align="center">
  <img src="https://gelecegiyazanlar.turkcell.com.tr/sites/default/files/icerik/net12.png" alt="Image" />
</p>

<p>Subnet Mask (Alt Ağ Maskesi), IP adresini ağ kısmı ve cihaz (host) kısmı olarak ayıran bir numaradır. Subnet Mask, ağdaki IP adreslerinin aynı ağda olduğunu belirlemek için kullanılır. Örneğin, bir Subnet Mask 255.255.255.0 ise, bu mask IP adresinin ilk üç oktetini (Örnek: 192.168.1) Ağ adresi olarak tanımlar ve son okteti (Örnek: 1) cihaz adresi olarak bırakır. Bu, ağ trafiğinin doğru şekilde yönlendirilmesini sağlar.</p>

### CIDR

<p align="center">
  <img src="https://img.sysnettechsolutions.com/What-is-CIDR-Nedir-TR.png" alt="Image" />
</p>

<p>CIDR (Sınıfsız Etki Alanları Arası Yönlendirme), IP adreslerini daha esnek ve verimli bir şekilde yönlendirmek ve yönetmek için kullanılan bir yöntemdir. CIDR formatında, bir IP adresi ve onun ardından gelen bir eğik çizgi ile belirtilen bir sayı (Örnek: 192.168.1.0/24) kullanılır. Bu sayı, ağ kısmını belirlemek için kullanılan bit sayısını ifade eder. Örneğin /24 24 bitlik bir ağ maskesini belirtir ve bu da 255.255.255.0 subnet maskesine karşılık gelir.</p>

### Network

<p align="center">
  <img src="https://resim.zayifakim.com/2020/08/network-cihazlari-750x530.png" />
</p>

<p>Network (Ağ), iki veya daha fazla cihazın (Bilgisayarlar, sunucular, telefonlar vb.) birbirine bağlanarak veri paylaşımı ve iletişim sağladığı bir sistemdir. Bu cihazlar kablolu (ethernet) veya kablosuz (Wi-Fi) bağlantılar aracılığı ile iletişim kurabilir. Ağlar, yerel alan ağları (LAN), geniş alan ağları (WAN) gibi farklı ölçeklerde olabilir. Kısacası Network, cihazların veri paylaşımını, internet erişimini, dosya transferini ve daha pek çok iletişim türünü mümkün kılar.</p>

## Switch

<p align="center">
  <img src="https://raw.githubusercontent.com/lpaube/NetPractice/main/img/switch1.png" />
</p>

<p>Switch (Ağ Anahtarı), bilgisayar ağlarında veri paketlerini cihazlar arasında yönlendiren bir ağ cihazıdır. Ağ Anahtarı, ağ trafiğini düzenleyerek verilerin hızlı ve verimli bir şekilde iletilmesini sağlar.</p>

## Router

<p align="center">
  <img src="https://raw.githubusercontent.com/lpaube/NetPractice/main/img/route1.png" />
</p>

<p>Switch (Ağ Anahtarı), bilgisayar ağlarında veri paketlerini cihazlar arasında yönlendiren bir ağ cihazıdır. Ağ Anahtarı, ağ trafiğini düzenleyerek verilerin hızlı ve verimli bir şekilde iletilmesini sağlar.</p>
