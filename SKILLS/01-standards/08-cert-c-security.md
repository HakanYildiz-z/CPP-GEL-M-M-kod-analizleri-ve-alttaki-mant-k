# CERT C / C++ Güvenlik Kuralları / CERT C/C++ Security Rules

**Versiyon / Version:** 1.0

---

## English

These rules are the minimum security baseline. Configuration applies MISRA + CERT jointly (union).

### Memory Safety

| Rule | Requirement |
|------|-------------|
| `ARR30-C` | Check array bounds before access; prefer range-checked access. |
| `MEM30-C` | Do not access freed memory; use RAII/smart pointers in C++. |
| `MEM31-C` | Free dynamically allocated memory exactly once. |
| `STR31-C` | Do not allow buffer overflow in string operations; use bounded functions. |
| `STR32-C` | Null-terminate strings; never rely on unspecified length. |

### Integer Safety

| Rule | Requirement |
|------|-------------|
| `INT30-C` | Check for integer overflow before arithmetic; use dedicated checked ops. |
| `INT32-C` | Do not mix signed/unsigned in a way that causes wrap-around. |
| `INT33-C` | Ensure that division and remainder do not divide by zero. |

### Input Validation

| Rule | Requirement |
|------|-------------|
| `INT04-C` | Sanitize all external input; assume hostile. |
| `MSC30-C` | Use a cryptographically secure RNG, never `rand()`. |
| `FLP32-C` | Do not compare floating-point values for exact equality. |
| `ERR00-C` | Adopt and consistently use an error strategy; no swallowed errors. |

### Secure Practices

- **Keys never in code**: use HSM/secure storage.
- **Approved algorithms only**: AES-256-GCM, SHA-3/256, Curve25519 (per contract).
- **Timing**: avoid data-dependent branches on secrets (timing attack).
- **Logging**: never log secrets, PII, or key material.

### Review Enforcement

| Finding | Severity |
|---------|----------|
| `rand()` in security-relevant code | `[CRITICAL]` |
| Unsanitized external input reaching `memcpy`/index | `[CRITICAL]` |
| Potential overflow in safety-critical math | `[CRITICAL]` |
| Signed/unsigned mix warning | `[BLOCKING]` |
| Exact float comparison in control logic | `[BLOCKING]` |

---

## Türkçe

Bu kurallar asgari güvenlik tabanıdır. Konfigürasyon MISRA + CERT'i birlikte (birleşim) uygular.

### Bellek Güvenliği

| Kural | Gereklilik |
|------|-------------|
| `ARR30-C` | Erişimden önce dizi sınırını kontrol et; sınır kontrollü erişim tercih et. |
| `MEM30-C` | Serbest bırakılmış belleğe erişme; C++'ta RAII/akıllı işaretçi kullan. |
| `MEM31-C` | Dinamik tahsisli belleği tam olarak bir kez serbest bırak. |
| `STR31-C` | String işlemlerinde buffer overflow'a izin verme; sınırlı fonksiyonlar kullan. |
| `STR32-C` | String'leri null sonlandır; belirsiz uzunluğa asla güvenme. |

### Tamsayı Güvenliği

| Kural | Gereklilik |
|------|-------------|
| `INT30-C` | Aritmetikten önce tamsayı taşmasını kontrol et; ayrı kontrollü işlemler kullan. |
| `INT32-C` | İşaretli/işaretsizi sarıp sarmaya yol açacak şekilde karıştırma. |
| `INT33-C` | Bölme ve kalan işlemlerinin sıfıra bölme yapmadığından emin ol. |

### Girdi Doğrulama

| Kural | Gereklilik |
|------|-------------|
| `INT04-C` | Tüm dış girdiyi temizle; düşmanca varsay. |
| `MSC30-C` | Kriptografik güvenli RNG kullan, asla `rand()`. |
| `FLP32-C` | Kayan nokta değerlerini tam eşitlik için karşılaştırma. |
| `ERR00-C` | Bir hata stratejisi benimse ve tutarlı uygula; yutulan hata yok. |

### Güvenli Uygulamalar

- **Anahtarlar asla kodda**: HSM/güvenli depolama kullan.
- **Yalnızca onaylı algoritmalar**: AES-256-GCM, SHA-3/256, Curve25519 (sözleşmeye göre).
- **Zamanlama**: sırlar üzerinde veri-bağımlı dallardan kaçın (timing attack).
- **Loglama**: asla sır, PII veya anahtar materyali loglama.

### İncelemede Uygulama

| Bulgu | Şiddet |
|---------|----------|
| Güvenlik-ilgili kodda `rand()` | `[CRITICAL]` |
| Temizlenmemiş dış girdinin `memcpy`/indekse ulaşması | `[CRITICAL]` |
| Güvenlik-kritik matematikte potansiyel taşma | `[CRITICAL]` |
| İşaretli/işaretsiz karışım uyarısı | `[BLOCKING]` |
| Kontrol mantığında tam float karşılaştırması | `[BLOCKING]` |

---

**Sahip / Owner:** Bilgi Güvenliği Ofisörü / CISO