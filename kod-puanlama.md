# Kod Puanlama ve Eleştiri Raporu / Code Assessment & Critique Report

**İncelenen kapsam / Scope:** `shared_ptr.cpp`, `unique_ptr.cpp`, `unique_ptr&shared_ptr.md`
**Standart / Standard:** SKILLS paketi `01-standards/` + `04-checklists/` (savunma sanayisi üretim kodu seviyesi)
**Tarih / Date:** 2026-08-18
**İnceleyici / Reviewer:** SKILLS paketi otomasyonu ile `[Puanlama: 41/100 — LGTM REDDİ / REJECTED]`

> **Önemli not / Important note:** İncelenen dosyalar **eğitim amaçlı demo kodlardır** (C++ akıllı işaretçi öğrenimi). Bu rapor, bu dosyaları savunma üretim kodu standardına göre değerlendirir; amaç "kötü kod" damgası vurmak değil, SKILLS metodolojisinin somut bir uygulama örneği olarak öğrenme değeri sağlamaktır.

---

## 1. Kapsam / Scope

| Dosya / File | Satır / Lines | Sınıflandırma / Class | Kritiklik varsayımı / Assumed criticality |
|--------------|----------------|-----------------------|-------------------------------------------|
| `shared_ptr.cpp` | 210 | Demo — hava savunma simülasyonu (akıllı işaretçi örneği) | HIGH (tehdit takibi senaryosu) |
| `unique_ptr.cpp` | 107 | Demo — RAII dosya yöneticisi (sensör benzetimi) | MEDIUM (telemetri toplama) |
| `unique_ptr&shared_ptr.md` | 17 | Ders notu / lecture notes | — (dokümantasyon dışında puanlanmadı) |

---

## 2. Puanlama Metodolojisi / Scoring Methodology

100 üzerinden ağırlıklı puanlama. Her kategori 0–100 puanlanır, ağırlıkla çarpılır.

| Kategori / Category | Ağırlık / Weight | Açıklama / Basis |
|---------------------|------------------|------------------|
| Güvenlik / Security | %20 | CERT, STRIDE, sır, girdi doğrulama |
| Kod Kalitesi / Code Quality | %20 | Karmaşıklık, büyülü sayı, DRY, temizlik |
| İsimlendirme / Naming | %10 | `g_/s_/k_`, PascalCase_t, tutarlılık, yazım |
| Dökümantasyon / Documentation | %15 | Doxygen, `@requirement`, "neden" yorumları |
| Hata Yönetimi / Error Handling | %15 | Dönüş değeri kontrolü, fail-secure |
| Stil / Style | %10 | Biçim, tutarlılık, dili profesyonel |
| İzlenebilirlik / Traceability | %10 | REQ→SRC→TST bağları |

---

## 3. Bulgu Özeti Tablosu / Findings Summary

| ID | Konum / Location | Kategori | Öncelik / Priority | Kural / Rule ref |
|----|------------------|----------|--------------------|------------------|
| F01 | `shared_ptr.cpp:18,22` | İsimlendirme | `[Nit:]` | `classication` → `classification` |
| F02 | `shared_ptr.cpp:31-35` | Stil | `[CRITICAL]` | Resmi olmayan, alaycı ton — savunma profesyonelliği ihlali |
| F03 | `shared_ptr.cpp:38-39` | Stil/Dökümantasyon | `[BLOCKING]` | Yıkıcıda resmi olmayan çıktı; davranış şaşırtıcı |
| F04 | `shared_ptr.cpp:45` | Kod Kalitesi | `[BLOCKING]` | Büyülü sayı `0.343` (Mach→km/s) — `constexpr` gerek |
| F05 | `shared_ptr.cpp:166` | Kod Kalitesi | `[BLOCKING]` | Büyülü değerler `500.0, 7.2, "Hipersonik fuze"` |
| F06 | `shared_ptr.cpp:166` | İsimlendirme | `[BLOCKING]` | `Target` PascalCase yerine `target`/`s_` kuralı |
| F07 | `shared_ptr.cpp:47` | Hata Yönetimi | `[Nit:]` | Negatif clamp iyi ama üst sınır yok (`ERR_OUT_OF_RANGE` yok) |
| F08 | `shared_ptr.cpp:78` | İsimlendirme | `[Nit:]` | Parametre `Target` PascalCase |
| F09 | `shared_ptr.cpp:175` | Kod Kalitesi | `[BLOCKING]` | Büyülü sayaç `3` |
| F10 | `shared_ptr.cpp:186-189` | Hata Yönetimi | `[BLOCKING]` | `fprintf`/`fflush` dönüş değerleri kontrolsüz |
| F11 | `shared_ptr.cpp:191` | Kod Kalitesi | `[Nit:]` | Büyülü uyku `1` saniye |
| F12 | `shared_ptr.cpp:194` | Stil | `[BLOCKING]` | Resmi olmayan çıktı "tehdit tehdit..." |
| F13 | `shared_ptr.cpp` (genel) | Dökümantasyon | `[BLOCKING]` | Doxygen yok; `@requirement`, `@safety_level` yok |
| F14 | `shared_ptr.cpp` (genel) | İzlenebilirlik | `[BLOCKING]` | REQ→SRC→TST bağı yok; hiçbir test yapısı yok |
| F15 | `shared_ptr.cpp:31-35` | Dökümantasyon | `[BLOCKING]` | Kurucuda yan-etki (çıktı) — loglama soyutlaması yok |
| F16 | `unique_ptr.cpp:17` | İsimlendirme | `[BLOCKING]` | Global `systemRunning` — `g_` öneki eksik |
| F17 | `unique_ptr.cpp:99` | Kod Kalitesi | `[BLOCKING]` | Büyülü `10` (döngü sayacı) |
| F18 | `unique_ptr.cpp:90-94` | Hata Yönetimi | `[BLOCKING]` | `fprintf`/`fflush` dönüş değeri kontrolsüz |
| F19 | `unique_ptr.cpp:31` | Hata Yönetimi | `[Nit:]` | Yalnızca `SIGINT` — `SIGTERM` de ele alınmalı |
| F20 | `unique_ptr.cpp` (genel) | Dökümantasyon | `[BLOCKING]` | Doxygen + traceability etiketleri yok |
| F21 | `unique_ptr.cpp:43` | Stil | `[Praise]` | RAII + özel deleter doğru desen — tebrik |
| F22 | `unique_ptr.cpp:64-71` | Güvenlik | `[Praise]` | `random_device`+`mt19937` — güvenli RNG deseni |

---

## 4. Detaylı İnceleme / Detailed Review

### 4.1 `shared_ptr.cpp`

**İyi yönler / Good:**
- `virtual ~AirDefenseSystem() = default;` (satır 73) — doğru sanal yıkıcı.
- `if (!Target) return;` (satır 79) — NULL kontrolü bilinci.
- `weak_ptr::lock()` + kapsam kontrollü erişim (satır 86-91) — çevrim kırma doğru kullanım.
- `distance_km` negatif kümelenmesi (satır 47) — sınır bilinci.

**Eleştiriler / Findings:**
- **[CRITICAL] F02 (satır 33-34):** Çıktı metni savunma ortamına kesinlikle uygun değil: *"iran yine israili iskaladi adamlar bize ... atmislar"*. Bu; profesyonellik, dil bütünlüğü ve kültürel güvenlik ihlalidir. Üretim kodu, kimlik belirten/devletlerarası ifadeler içeremez. Düzeltme: `LOG_INFO("Target acquired: %s, distance %.1f km, speed %.1f mach", ...)`.
- **[BLOCKING] F04 (satır 45):** `0.343` sabiti isimlendirilmemiştir. Öneri: `static constexpr double kMachToKmPerSec = 0.343;` (MISRA C++ kural: büyülü sayı yasağı).
- **[BLOCKING] F05/F06 (satır 166):** `target` değişkeni PascalCase ve büyülü değerlerle kuruluyor. `make_shared<TargetData>` doğru desen, ancak değerler `kInitialDistanceKm`, `kInitialSpeedMach` gibi adlandırılmalı; `target` küçük harfle.
- **[BLOCKING] F08 (satır 78):** Parametre adı `Target` → `target`.
- **[BLOCKING] F10 (satır 186-189):** `fprintf` ve `fflush` dönüşleri kontrolsüz; telemetri yazma başarısızlığı sessizce geçiyor. `[BLOCKING]` hata yutma.
- **[BLOCKING] F13/F14:** Hiçbir dosyada Doxygen, `@requirement REQ-XXXX`, `@safety_level`, `@standard` yok; test dosyası yok; izlenebilirlik matrisi boş.
- **[BLOCKING] F15 (satır 31-39):** Kurucu ve yıkıcı ekrana basar (yan etki). Gömülü koddan çıktı, loglama soyutlamasına taşınmalı.

### 4.2 `unique_ptr.cpp`

**İyi yönler / Good:**
- **[Praise] F21 (satır 43):** `std::unique_ptr<FILE, decltype(fileCloser)>` kusursuz RAII; kaynak yaşam döngüsü garantili.
- **[Praise] F22 (satır 64-71):** `random_device` + `mt19937` + `uniform_int_distribution` — `rand()` yerine doğru RNG.
- **[Satır 17]:** `std::atomic<bool>` sinyal güvenli — iyi.
- **[Satır 51-54]:** Dosya açılamazsa `return 1` — hata yolu farkında.

**Eleştiriler / Findings:**
- **[BLOCKING] F16 (satır 17):** `systemRunning` global — `g_systemRunning` olmalı (naming kuralı).
- **[BLOCKING] F17 (satır 99):** `i < 10` büyülü; `kTelemetryPeriodIterations = 10` tanımla. Kısaca: `1s` uyku süresi de `constexpr auto kTelemetryInterval = 1s;`.
- **[BLOCKING] F18 (satır 90-94):** `fprintf`/`fflush` kontrolsüz. Disk tam / yazma hatası senaryosunda veri sessizce kaybolur. Telemetri için bu `[CRITICAL]`'e yakın bir kanıt kaybıdır.
- **[Nit:] F19 (satır 31):** Sadece `SIGINT` yakalanıyor; `SIGTERM` de ele alınmalı.
- **[BLOCKING] F20:** Doxygen/izlenebilirlik yok.

### 4.3 `unique_ptr&shared_ptr.md`

Ders notu; eğitim değeri yüksek ancak **kod değildir**. Not: "fanhyedma farkları", "kararsız" gibi ifadeler okuyucuya göre net olsa da, ticari dokümanda terimler standartlaştırılmalı (bkz. `base fee terminology`, `02-review-process`). Puanlama dışı tutulmuştur.

---

## 5. Puan Kartı / Score Card

| Kategori / Category | Puan / Raw | Ağırlık / Weight | Katkı / Contribution |
|---------------------|-----------|------------------|----------------------|
| Güvenlik / Security | 55 | 0.20 | 11.0 |
| Kod Kalitesi / Code Quality | 45 | 0.20 | 9.0 |
| İsimlendirme / Naming | 35 | 0.10 | 3.5 |
| Dökümantasyon / Documentation | 40 | 0.15 | 6.0 |
| Hata Yönetimi / Error Handling | 45 | 0.15 | 6.75 |
| Stil / Style | 50 | 0.10 | 5.0 |
| İzlenebilirlik / Traceability | 0 | 0.10 | 0.0 |
| **Toplam / Total** | | | **41.25 → 41/100** |

**Not / Grade:** **FAIL / Yetersiz** (üretim koduna kabul edilmez)

---

## 6. Sonuç ve Karar / Conclusion & Decision

**LGTM: Verilmez / NOT GRANTED.**

**Engelleyen CRITICAL/BLOCKING bulgular / Blocking items:**
1. **F02** — profesyonellik ihlali (resmi olmayan ton, siyasi-öznel ifade).
2. **F04, F05, F09, F11, F17** — isimlendirilmemiş sabitler (büyülü sayılar).
3. **F10, F18** — yazma hatalarının sessizce yutulması (kanıt kaybı riski).
4. **F13, F14, F20** — Doxygen + izlenebilirlik + test yapısının tamamen yokluğu.
5. **F16** — isimlendirme konvansiyonu ihlali.

**Düzeltme önceliği / Fix priority (öncelik):**
1. **P0:** F02 (dil/profesyonellik), F10/F18 (hata yutma).
2. **P1:** F04/F05/F09/F11/F17 (sabitler), F06/F08/F16 (isimlendirme).
3. **P2:** F13/F14/F20 (Doxygen, REQ etiketleri, test + matris), F15 (loglama soyutlama).

---

## 7. Örnek Düzeltmeler / Example Corrections

### 7.1 `shared_ptr.cpp` satır 33-35 → loglama soyutlaması

```cpp
// DOĞRU / CORRECT
#include "log_api.h"   // proje loglama soyutlaması

TargetData(std::string classification, double distanceKm, double speedMach)
    : classification_(std::move(classification)),
      distanceKm_(distanceKm),
      speedMach_(speedMach),
      telemetryCycle_(1) {
    LOG_INFO("Target acquired: %s, distance %.1f km, speed %.1f mach",
             classification_.c_str(), distanceKm_, speedMach_);
}
```

### 7.2 Büyülü sayıların adlandırılması (satır 45, 166, 175, 191)

```cpp
// DOĞRU / CORRECT
static constexpr double kMachToKmPerSec  = 0.343;   // 1 mach = 343 m/s = 0.343 km/s
static constexpr double kInitialDistanceKm = 500.0;
static constexpr double kInitialSpeedMach  = 7.2;
static constexpr int    kTelemetryCycles   = 3;
static constexpr std::chrono::seconds kTelemetryInterval{1};

// ...
distanceKm_ -= speedMach_ * kMachToKmPerSec * deltaTimeSeconds;

auto target = std::make_shared<TargetData>("Hypersonic", kInitialDistanceKm, kInitialSpeedMach);
for (int cycle = 0; cycle < kTelemetryCycles && target; ++cycle) {
    // ...
    std::this_thread::sleep_for(kTelemetryInterval);
}
```

### 7.3 Yazma hatalarının ele alınması (satır 186-189)

```cpp
// DOĞRU / CORRECT
int written = std::fprintf(logFile.get(), "cycle=%d dist=%.2f speed=%.1f\n",
                           target->getCycle(), target->getDistance(), target->getSpeed());
if (written < 0 || std::fflush(logFile.get()) != 0) {
    LOG_ERROR("telemetry write failed");           // veya fail-safe davranış
}
```

### 7.4 Başlık/etiket ekleme (izlenebilirlik)

```cpp
/**
 * @file target_tracker.cpp
 * @brief Hipersonik hedef takip ve imha simülasyonu
 * @version 1.0
 * @author <ad / ID>
 * @requirement REQ-0001 (hedef takibi)
 * @safety_level HIGH
 * @standard MISRA C++:2008 + CERT C++
 */
```

---

## 8. Sonraki Adım / Next Step

Bu rapor, `SKILLS/` paketinin nasıl uygulanacağının **canlı bir örneğidir**. Dosyaları üretim seviyesine taşımak için:
1. `02-review-process/01-cl-methodology.md` — CL boyutu ve öz-inceleme.
2. `01-standards/02-cpp-language-rules.md` — akıllı işaretçi ve yasaklar.
3. `05-traceability/01-bidirectional-traceability.md` — matris oluştur.
4. `04-checklists/03-dal-c-d-checklist.md` — MEDIUM/HIGH kontrol listesi.

---

**Sahip / Owner:** SKILLS Değerlendirme Aracı / SKILLS Assessment Tool
**Son İnceleme / Last Reviewed:** 2026-08-18