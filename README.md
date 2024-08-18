<img src="https://i.imgur.com/TvlDmPS.png" width="1500" height="150">
<div align="center">
  <h1>42 CURSUS PROJECT NETPRACTİCE</h1>
</div>

# İçindekiler

1. [TCP](#TCP)
2. [IP](#IP)
   - [IPv4](#IPv4)
   - [IPv6](#IPv6)
3. [Subnet Mask](#SubnetMask)
   - [CIDR](#CIDR)
   - [Network](#Network)
4. [Switch](#Switch)
5. [Router](#Router)

## TCP

<p align="center">
  <img src="https://miro.medium.com/v2/resize:fit:720/format:webp/1*322lRmlTQQDJR4DBWbYAZg.png" alt="Image" />
</p>

<p>&nbsp;&nbsp;&nbsp;&nbsp;TCP (Transmission Control Protocol), veri iletimi sırasında güvenliği ve doğruluğu sağlamak için kullanılan bir iletişim protokolüdür. TCP, veriyi küçük parçalara (segmentlere) böler, bu parçaları sırayla gönderir ve alıcıya ulaştığında doğru sırada ve eksiksiz olup olmadığını kontrol eder. Eğer bir parça kaybolur veya hatalı olursa, TCP o parçayı yeniden gönderir. Bu sayede veri, alıcıya eksiksiz ve hatasız bir şekilde ulaşır.</p>

<p align="center">
  <img src="https://www.educationcyber.com/wp-content/uploads/2020/02/protokola.fw_-1-768x538.png" alt="Image" />
</p>

## IP

<p>&nbsp;&nbsp;&nbsp;&nbsp;IP (Internet Protocol), internet veya bir ağ üzerindeki cihazlar arasında veri iletimini sağlayan bir protokoldür. IP, her cihaza benzersiz bir IP adresi atayarak verilerin doğru hedefe ulaşmasını sağlar. Bu adresleme sistemi, cihazların birbiriyle iletişim kurmasına ve veri alışverişi yapmasına olanak tanır. IP'nin iki ana versiyonu vardır: IPv4 ve IPv6.</p>

### IPv4

<p align="center">
  <img src="https://brandergroup.net/wp-content/uploads/2022/02/What-is-IPv4-705x397.png" alt="Image" />
</p>

<p>IPv4 (Internet Protocol version 4), internet üzerindeki cihazlar arasında veri iletimi için kullanılan bir IP adresleme sistemidir. IPv4, 32 bitlik adreslerden oluşur ve bu nedenle yaklaşık 4.3 milyar benzersiz IP adresi sunar. IPv4 adresleri, genellikle noktalarla ayrılmış dört sayı grubu (örneğin, 192.168.0.1) şeklinde yazılır. Bu adresleme sistemi, internetin ilk yıllarından beri kullanılmakta olup, hala yaygın olarak kullanılmaktadır.</p>

### IPv6

<p align="center">
  <img src="https://www.beyaz.net/files/elfinder/content_photo/icerik_dosyalari/%C4%B1pv6_nedir.png" alt="Image" />
</p>

<p>IPv6 (Internet Protocol version 6), internet üzerindeki cihazlar arasında veri iletimi için kullanılan ve IPv4'ün yerini alması amaçlanan bir IP adresleme sistemidir. IPv6, 128 bitlik adreslerden oluşur ve bu sayede trilyonlarca benzersiz IP adresi sunar, bu da gelecekteki internet büyümesi için yeterli alan sağlar. IPv6 adresleri, genellikle iki nokta üst üste ile ayrılmış sekiz grup halinde, her grup dört hexadecimal rakam içerir (örneğin, 2001:0db8:85a3:0000:0000:8a2e:0370:7334). IPv6, IPv4'ün sunduğu adreslerin yetersiz kalması nedeniyle geliştirilmiştir.</p>

## Subnet Mask

<p align="center">
  <img src="https://gelecegiyazanlar.turkcell.com.tr/sites/default/files/icerik/net12.png" alt="Image" />
</p>

<p>Subnet mask, bir IP adresini ağ kısmı ve cihaz (host) kısmı olarak ayıran bir numaradır. Subnet mask, ağdaki hangi IP adreslerinin aynı ağda olduğunu belirlemek için kullanılır. Örneğin, bir subnet mask 255.255.255.0 ise, bu mask IP adresinin ilk üç oktetini (örneğin, 192.168.1) ağ adresi olarak tanımlar ve son okteti (örneğin, 1) cihaz adresi olarak bırakır. Bu, ağ trafiğinin doğru bir şekilde yönlendirilmesini sağlar.</p>

### CIDR

<p align="center">
  <img src="https://img.sysnettechsolutions.com/What-is-CIDR-Nedir-TR.png" alt="Image" />
</p>

<p>CIDR (Classless Inter-Domain Routing), IP adreslerini daha esnek ve verimli bir şekilde yönlendirmek ve yönetmek için kullanılan bir yöntemdir. CIDR, IP adreslerini "sınıfsız" bir şekilde bölmeye olanak tanır, yani IP adresleri sabit sınıflara (A, B, C) bağlı kalmadan, ağlar daha küçük veya daha büyük parçalar halinde bölünebilir.

CIDR formatında, bir IP adresi ve onun ardından gelen bir eğik çizgi ile belirtilen bir sayı (örneğin, 192.168.1.0/24) kullanılır. Bu sayı, ağ kısmını belirlemek için kullanılan bit sayısını ifade eder. Örneğin, /24 24 bitlik bir ağ maskesini belirtir ve bu da klasik bir 255.255.255.0 subnet maskesine karşılık gelir. CIDR, IP adreslerinin daha verimli kullanılmasını ve daha esnek ağ yapılandırmalarını sağlar.</p>

### Network

<p align="center">
  <img src="https://resim.zayifakim.com/2020/08/network-cihazlari-750x530.png" />
</p>

<p>Network, iki veya daha fazla cihazın (bilgisayarlar, sunucular, telefonlar vb.) birbirine bağlanarak veri paylaşımı ve iletişim sağladığı bir sistemdir. Bu cihazlar, kablolu (ethernet) veya kablosuz (Wi-Fi) bağlantılar aracılığıyla iletişim kurabilir. Ağlar, yerel alan ağları (LAN), geniş alan ağları (WAN) gibi farklı ölçeklerde olabilir. Network, cihazların veri paylaşımını, internet erişimini, dosya transferini ve daha pek çok iletişim türünü mümkün kılar.</p>

## Switch

<p align="center">
  <img src="https://raw.githubusercontent.com/lpaube/NetPractice/main/img/switch1.png" />
</p>

Ağ anahtarı (switch), bilgisayar ağlarında veri paketlerini cihazlar arasında yönlendiren bir ağ cihazıdır.

Veri Yönlendirme: Switch, ağa bağlı cihazlardan gelen veri paketlerini alır ve bu paketleri doğru hedef cihaza yönlendirir. Her cihazın ağda bir MAC adresi vardır, switch bu adresleri kullanarak veriyi doğru şekilde yönlendirir.

Portlar: Switch üzerinde birden fazla port bulunur. Her port, bir cihaza bağlanabilir ve bu sayede switch, birçok cihazın aynı anda iletişim kurmasını sağlar.

Kısacası, ağ anahtarı, ağ trafiğini düzenleyerek verilerin hızlı ve verimli bir şekilde iletilmesini sağlar.

## Router

<p align="center">
  <img src="https://raw.githubusercontent.com/lpaube/NetPractice/main/img/route1.png" />
</p>

Router, genellikle bir ev ağı ile internet gibi geniş ağlar arasında veri trafiğini yönlendirir. Bir paket geldiğinde, router bu paketi doğru hedefe iletmek için en iyi yolu belirler.

IP Adresleme: Router, ağa bağlı cihazlara IP adresleri atar ve ağ üzerindeki veri paketlerini bu IP adreslerine göre yönlendirir.

NAT (Ağ Adresi Çevirisi): Ev ve küçük ofis ağlarında, router genellikle bir NAT işlevi görür. Bu, bir iç ağdaki cihazların tek bir dış IP adresi üzerinden internet erişimi sağlamasına olanak tanır.

Kablosuz Bağlantı: Çoğu modern router, Wi-Fi desteği sunarak kablosuz cihazların ağa bağlanmasını sağlar.

