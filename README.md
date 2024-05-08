<img src="https://i.imgur.com/TvlDmPS.png" width="1500" height="150">
<div align="center">
  <h1>42 CURSUS PROJECT LİBFT </h1>
</div>
Ecole 42 okullarında, 42Cursus (ana eğitim) kapsamında ilk olarak tamamlanması gereken proje, Libft projesidir. Bu proje, öğrencilere kendi kütüphanelerini oluşturma fırsatı sunar. Libft kütüphanesi daha sonraki projelerde kullanılmak üzere tasarlanmıştır. Bu GitHub deposu, Libft projesi için gerekli açıklamaları ve kodları içermektedir.

<br></br>
	<tr><h1 align="center"> FONKSİYONLAR VE AÇIKLAMALARI</h1> </h1></tr>
 <td>
	 
|Fonksiyon Adı     |Fonksiyon Açıklaması                                                                                                                                          |Fonksiyonun Yazımı                                                            |
|:---              |:---                                                                                                                                                          |:---                                                                          |
|ft_isalpha        |Alfabetik bir karakter olup olmadığını kontrol eder. Alfabetik karakter ise "1" değil ise "0" return eder.                                                    |int      ft_isalpha(int c)                                                    |
|ft_isdigit        |Rakam olup olmadığını kontrol eder. Rakam ise "1" değil ise "0" return eder.                                                                                  |int	    ft_isdigit(int c)                                                    |
|ft_isalnum        |Alfabetik karakter veya rakam olup olmadığını kontrol eder. Alfabetik karakter veya rakam ise "1" değil ise "0" return eder.                                  |int	    ft_isalnum(int c)                                                    |
|ft_isascii        |ASCII karakter setinde olup olmadığına kontrol eder. ASCII karakter ise "1" değil ise "0" return eder.                                                        |int	    ft_isascii(int c)                                                    |
|ft_isprint        |Karakterin yazdırılabilir (printable) olup olmadığını kontrol eder. Yazdırılabilir karakter ise "1" değil ise "0" return eder.                                |int	    ft_isprint(int c)                                                    |
|ft_strlen         |Dizinin karakter sayısını sayan bir fonksiyondur. Dizinin karakter sayısını return eder.                                                                      |size_t   ft_strlen(const char *s)                                             |
|ft_memset         |Dİzinin içerisine girilen karakteri kopyalar. Return değeri yoktur.                                                                                           |void	    *ft_memset(void *b, int c, size_t len)                               |
|ft_bzero          |Dizinin içerisini null karakteri ile doldurur. Return değeri yoktur.                                                                                          |void	    ft_bzero(void *s, size_t n)                                          |
|ft_memcpy         |Bellekteki adreste bulunan veriyi başka bir adrese kopyalar. Return değeri yoktur.                                                                            |void	    *ft_memcpy(void *dst, const void *src, size_t n)                     |
|ft_memmove        |Bellekteki adreste bulunan veriyi overloop oluşmaması için sondan başlayarak kopyalar. Return değeri yoktur.                                                  |void	    *ft_memmove(void *dst, const void *src, size_t len)                  |
|ft_strlcpy        |Girilen adresteki kaynağı başka hedefteki adrese kopyalama işlemi yapar ve sonuna '\0' atar. Return değeri hedefteki karakter sayısıdır.                      |size_t   ft_strlcpy(char * dst, const char *src, size_t dstsize)              |
|ft_strlcat        |Girilen adresteki kaynağı başka bir hedefteki adresin sonuna ekler. Return değeri hedefteki karakter sayısıdır.                                               |size_t   ft_strlcat(char *dst, const char *src, size_t dstsizeV)              |
|ft_toupper        |Küçük harfleri büyük harf ile değiştirir. Return değeri harfin ASCII tablosundaki büyük harfin değeridir.                                                     |int	    ft_toupper(int c)                                                    |
|ft_tolower        |Büyük harfleri küçük harf ile değiştirir. Return değeri harfin ASCII tablosundaki küçük harfin değeridir.                                                     |int	    ft_tolower(int c)                                                    |
|ft_strchr         |Dizideki istenilen karakteri arayan bir fonksiyondur. Return değeri bulduğu karakterin adresinden başlayarak karakterleri döndürür.                           |char	    *ft_strchr(const char *s, int c)                                     |
|ft_strrchr        |Dizideki istenilen karakteri sondan başlayarak arayan bir fonksiyondur. Return değeri bulduğu karakterin adresinden başlayarak karakterleri döndürür.         |char	    *ft_strrchr(const char *s, int c)                                    |
|ft_strncmp        |Girilen dizilerdeki karakter farklılıklarını kontrol eder. Return değeri harf arasındaki farkı döndürür.                                                      |int	    ft_strncmp(const char *s1, const char *s2, size_t n)                 |
|ft_memchr         |Bellekteki adreste bulunan verinin içerisinde girilen karakteri arayan bir fonksiyondur. Return değeri yoktur.                                                |void	    *ft_memchr(const void *s, int c, size_t n)                           |
|ft_memcmp         |Bellekteki adreste bulunan verilerin içerisindeki karakterleri karşılaştıran bir fonksiyondur. Return değeri harf arasındaki farkı döndürür.                  |int	    ft_memcmp(const void *s1, const void *s2, size_t n)                  |
|ft_strnstr        |Girilen dizi içerisinde, alt dizi veya harf arayan bir fonksiyondur. Return değeri bulduğu yerden itibaren döndürür.                                          |char	    *ft_strnstr(const char *haystack, const char *needle, size_t len)    |
|ft_atoi           |Girilen karakter dizi içerinde ilk bulduğu rakamdan başlayarak sayıyı çevirir. Return değeri bu tamsayı değeridir.                                            |int	    ft_atoi(const char *str)                                             |
|ft_calloc         |Girilen değerlerin çarpımı kadar bellekte yer ayırırır ve içerisini sıfırlar. Return değeri yoktur.                                                           |void	    *ft_calloc(size_t count, size_t size)                                |
|ft_strdup         |Girilen dizinin kopyasını başka bir adreste yer ayırarak kopyalar. Return değeri kopyalanan dizidir.                                                          |char	    *ft_strdup(const char *s1)                                           |
|ft_substr         |Girilen S dizisindeki içeriği, girilen start verisinden başlayarak girilen len kadar başka bir adrese kopyalar. Return değeri bu adrestir.                    |char	    *ft_substr(const char *s, unsigned int start, size_t len)            |
|ft_strjoin        |Girilen S1 ve S2 verisini birleştirerek başka bir adrese kopyalar. Return değeri bu adrestir.                                                                 |char	    *ft_strjoin(char const *s1, char const *s2)                          |
|ft_strtrim        |Girilen S1 verisi içerisinde girilen set verisini kırpar ve kırpılmış veriyi başka bir adrese kopyalar. Return değeri bu adrestir.                            |char	    *ft_strtrim(char const *s1, char const *set)                         |
|ft_split          |Girilen S dizisini girilen karakter ile ayırarak farklı bir adreste çift boyutlu bir dizi oluşturur. Return değeri bu adrestir.                               |char	    **ft_split(char const *s, char c)                                    |
|ft_itoa           |Girilen tamsayı değerini karakter dizisine dönüştürür. Return değeri bu tamsayıdır.                                                                           |char	    *ft_itoa(int n)                                                      |
|ft_strmapi        |Girilen S dizisinin indislerine girilen fonksiyonu uygular. Return değeri ise yeni dizidir.                                                                   |char	    *ft_strmapi(char const *s, char (*f)(unsigned int, char))            |
|ft_striteri       |Girilen S dizisinin indislerini tek tek girilen fonksiyona gönderir. Return değeri yoktur.                                                                    |void	    ft_striteri(char *s, void (*f)(unsigned int, char *))                |
|ft_putchar_fd     |Girilen C karakterini oluşturulan fd (file descriptor/dosya tanımlayıcısı) içerisine yazar. Return değeri yoktur.                                             |void	    ft_putchar_fd(char c, int fd)                                        |
|ft_putstr_fd      |Girilen S dizisini oluşturulan fd (file descriptor/dosya tanımlayıcısı) içerisine yazar. Return değeri yoktur.                                                |void	    ft_putstr_fd(char *s, int fd)                                        |
|ft_putendl_fd     |Girilen S dizisini oluşturulan fd (file descriptor/dosya tanımlayıcısı) içerisine yazar ve alt satıra geçer. Return değeri yoktur.                            |void	    ft_putendl_fd(char *s, int fd)                                       |
|ft_putnbr_fd      |Girilen N tamsayısını oluşturulan fd (file descriptor/dosya tanımlayıcısı) içerisine yazar. Return değeri yoktur.                                             |void	    ft_putnbr_fd(int n, int fd)                                          |

<br></br>
<tr><h1 align="center"> BONUS FONKSİYONLAR VE AÇIKLAMALARI</h1> </h1></tr>
 <td>

|Fonksiyon Adı     |Fonksiyon Açıklaması                                                                                                                                          |Fonksiyonun Yazımı                                                            |
|:---              |:---                                                                                                                                                          |:---                                                                          |
|ft_lstnew         |Girilen content (içerik) ile yeni bir düğüm oluşturur. Return değeri düğüm adresidir.                                                                         |t_list   *ft_lstnew(void *content)                                            |
|ft_lstadd_front   |Girilen new listesini, girilen list parametresine ekler. Return değeri yoktur.                                                                                |void	    ft_lstadd_front(t_list **lst, t_list *new)                           |
|ft_lstsize        |Girilen lst listesinin uzunluğunu bulan bir fonksiyondur. Return değeri lst listesinin uzunluğudur.                                                           |int	    ft_lstsize(t_list *lst)                                              |
|ft_lstlast        |Girilen lst listesinin son düğümünü bulan bir fonksiyondur. Return değeri lst listesinin son düğümüdür.                                                       |t_list   *ft_lstlast(t_list *lst)                                             |
|ft_lstadd_back    |Girilen new listesini girilen lst parametresinin sonuna ekler. Return değeri yoktur.                                                                          |void	    ft_lstadd_back(t_list **lst, t_list *new)                            |
|ft_lstdelone      |Girilen lst listesinin contentini girilen del fonksiyonuna gönderir ve gönderilen contenti lst'de freeler (serbest bırakmak). Return değeri yoktur.           |void	    ft_lstdelone(t_list *lst, void (*del)(void *))                       |
|ft_lstclear       |Girilen lst listesinin içerisindeki tüm düğümleri del fonksiyonuna gönderir ve düğümleri freeler (serbest bırakmak). Return değeri yoktur.                    |void	    ft_lstclear(t_list **lst, void (*del)(void *))                       |
|ft_lstiter        |Girilen lst listesinin içerisindeki content değerlerini f fonksiyonuna gönderir. Return değeri yoktur.                                                        |void	    ft_lstiter(t_list *lst, void (*f)(void *))                           |
|ft_lstmap         |Girilen lst listesinin içerisinde dolaşır ve contentleri f fonksiyonuna gönderir ve yeni liste oluşturur. Return değeri listenin kendisidir.                  |t_list   *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))     |

</td>
<br></br>
