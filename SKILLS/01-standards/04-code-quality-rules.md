# Kod Kalitesi Kuralları / Code Quality Rules

**Versiyon / Version:** 1.0

---

## English

### Function Rules

| Metric | Limit | Enforcement |
|--------|-------|-------------|
| Function length | ≤ **60 lines** (excluding blanks/comments) | Static analysis; review |
| Parameters | ≤ **5**; group excess into a struct | Review |
| Cyclomatic complexity (McCabe) | ≤ **10**; above → decompose | `ccenv`, SonarQube, review |
| Nesting depth | ≤ **4** levels | Static analysis; review |
| Magic numbers | **Forbidden** | `constexpr`/`#define` with `k` prefix |

### Rules

1. **Single Responsibility:** a function/class does one "thing". Split upon review request.
2. **No dead code:** every line has a purpose. Remove unused includes, variables, branches.
3. **YAGNI:** no speculative functionality. If unused → remove, do not comment out.
4. **DRY (bounded):** duplicating a subtle algorithm is a defect; abstract only when abstraction doesn't obscure.
5. **No output parameters** unless justified; prefer return values and small value-based structs.
6. **Early return** for error paths; keep the happy path dominant.

### Struct / Class Design

- Data + behavior together; getters must be `const`.
- Avoid god classes; enforce via complexity metrics.
- Prefer composition over inheritance; inheritance depth ≤ 3 for critical modules.

### Header Rules

- Every header: include guard (`#pragma once` or `#ifndef`), Doxygen block, `extern "C"` if needed.
- No implementation in headers except `inline`/`constexpr` with justification.

### Review Enforcement

| Finding | Severity |
|---------|----------|
| Function > 60 lines with duplicate logic | `[BLOCKING]` |
| Magic number in safety logic | `[BLOCKING]` |
| Dead/speculative code | `[BLOCKING]` (must remove) |
| Function > 60 lines, no complexity issue | `[Nit:]` |
| CC > 10 | `[BLOCKING]` |

---

## Türkçe

### Fonksiyon Kuralları

| Metrik | Sınır | Uygulama |
|--------|-------|-------------|
| Fonksiyon uzunluğu | ≤ **60 satır** (boşluk/yorum hariç) | Statik analiz; inceleme |
| Parametre | ≤ **5**; fazlasını struct ile grupla | İnceleme |
| Siklomatik karmaşıklık (McCabe) | ≤ **10**; üstü → ayrıştır | `ccenv`, SonarQube, inceleme |
| İç içe geçme derinliği | ≤ **4** seviye | Statik analiz; inceleme |
| Büyülü sayı | **Yasak** | `constexpr`/`#define` + `k` öneki |

### Kurallar

1. **Tek Sorumluluk:** bir fonksiyon/sınıf tek "iş" yapar. İnceleme talebiyle ayrıştırılır.
2. **Ölü kod yok:** her satırın amacı vardır. Kullanılmayan include, değişken ve dalı kaldır.
3. **YAGNI:** spekülatif işlevsellik yok. Kullanılmıyorsa → kaldır, yorum satırına alma.
4. **DRY (sınırlı):** ince bir algoritmayı tekrarlamak kusurdur; soyutlama anlamı gizlemiyorsa soyutla.
5. **Çıktı parametresi yok** gerekçelenmedikçe; dönüş değeri ve küçük değer tabanlı struct tercih et.
6. Hata yollarında **erken return**; mutlu yol baskın kalsın.

### Struct / Sınıf Tasarımı

- Veri + davranış birlikte; getter'lar `const` olmalı.
- God class'lardan kaçın; karmaşıklık metrikleriyle uygula.
- Kalıtım yerine kompozisyon tercih et; kritik modüllerde kalıtım derinliği ≤ 3.

### Başlık Kuralları

- Her başlık: include guard (`#pragma once` veya `#ifndef`), Doxygen bloğu, gerekirse `extern "C"`.
- Gerekçelenmedikçe başlıkta implementasyon yok — `inline`/`constexpr` hariç.

### İncelemede Uygulama

| Bulgu | Şiddet |
|---------|----------|
| Tekrarlayan mantıkla > 60 satır fonksiyon | `[BLOCKING]` |
| Güvenlik mantığında büyülü sayı | `[BLOCKING]` |
| Ölü/spekülatif kod | `[BLOCKING]` (kaldırılmalı) |
| > 60 satır fonksiyon, karmaşıklık sorunu yok | `[Nit:]` |
| CC > 10 | `[BLOCKING]` |

---

**Sahip / Owner:** Teknik Mimari Kurulu / Technical Architecture Board