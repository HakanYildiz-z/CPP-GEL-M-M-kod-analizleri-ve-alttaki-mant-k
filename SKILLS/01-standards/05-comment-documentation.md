# Yorum ve Dokümantasyon / Comment & Documentation

**Versiyon / Version:** 1.0

---

## English

### Mandatory Documentation

1. **Every function** documented in Doxygen format: `@brief`, `@param[in/out]`, `@return`, `@pre`, `@post`.
2. **Header file** template (`modul_adi.h`):
   - `@file`, `@brief`, `@version`, `@date`, `@author`
   - `@requirement REQ-XXXX` (traceability link)
   - `@safety_level CRITICAL | HIGH | MEDIUM | LOW`
   - `@standard` (governing standard)
   - `@copyright <Company> — All rights reserved.`
3. **"Why" comments** required next to complex algorithms. "What" comments are noise.
4. **`/* SAFETY: ... */`** tag on any safety-critical line (guard, boundary check, atomic op).
5. **No magic numbers:** every constant named (`constexpr` / `#define`).
6. **TODO/FIXME** must carry an owner ID and a linked work item. Bare TODOs are `[BLOCKING]`.

### Comment Style Rules

| Rule | Example |
|------|---------|
| Use `//` for single-line, `/* ... */` for blocks. Never mix inside a function at random. | `// nominal path` |
| Keep comments ≤ 1 line where possible | — |
| Never state the obvious: `i++;  // increment i` → remove | — |
| Reference units in comments for domain data | `// distance in km` |
| Comments in the module's working language (defined per project) | — |

### Traceability Tags (required)

| Tag | Location | Links |
|-----|----------|-------|
| `@requirement REQ-XXXX` | Header + function | REQ → SRC |
| `@traceability <DSN-XXXX>` | Header | DSN → SRC |
| `@verifies REQ-XXXX` | Test file | SRC → TST |

### Review Enforcement

- Missing Doxygen on exported function → `[BLOCKING]`.
- No `@requirement` on a file → `[BLOCKING]` for safety-related modules, `[Question]` otherwise.
- Bare `TODO` without owner → `[BLOCKING]`.
- Obvious comments → `[Nit:]`.

---

## Türkçe

### Zorunlu Dokümantasyon

1. **Her fonksiyon** Doxygen formatında dokümante edilir: `@brief`, `@param[in/out]`, `@return`, `@pre`, `@post`.
2. **Başlık dosyası** şablonu (`modul_adi.h`):
   - `@file`, `@brief`, `@version`, `@date`, `@author`
   - `@requirement REQ-XXXX` (izlenebilirlik bağlantısı)
   - `@safety_level CRITICAL | HIGH | MEDIUM | LOW`
   - `@standard` (geçerli standart)
   - `@copyright <Şirket> — Tüm hakları saklıdır.`
3. Karmaşık algoritmaların yanında **"Neden" yorumu** zorunludur. "Ne" yorumları gürültüdür.
4. Güvenlik-kritik her satırda **`/* SAFETY: ... */`** etiketi (guard, sınır kontrolü, atomik işlem).
5. **Büyülü sayı yok:** her sabit isimlendirilir (`constexpr` / `#define`).
6. **TODO/FIXME** sahip ID'si ve bağlı iş kalemi taşımalıdır. Çıplak TODO'lar `[BLOCKING]`'dir.

### Yorum Stili Kuralları

| Kural | Örnek |
|------|---------|
| Tek satır için `//`, blok için `/* ... */`. Fonksiyon içinde rastgele karıştırma. | `// nominal path` |
| Mümkünse yorumlar ≤ 1 satır | — |
| Bariz olanı söyleme: `i++;  // i'yi artır` → kaldır | — |
| Alan verilerinde yorumlarda birim belirt | `// mesafe km cinsinden` |
| Yorumlar modülün çalışma dilinde (proje bazında tanımlı) | — |

### İzlenebilirlik Etiketleri (zorunlu)

| Etiket | Konum | Bağlantı |
|-----|----------|-------|
| `@requirement REQ-XXXX` | Başlık + fonksiyon | REQ → SRC |
| `@traceability <DSN-XXXX>` | Başlık | DSN → SRC |
| `@verifies REQ-XXXX` | Test dosyası | SRC → TST |

### İncelemede Uygulama

- Dışa açık fonksiyonda eksik Doxygen → `[BLOCKING]`.
- Dosyada `@requirement` yok → güvenlik-ilgili modüllerde `[BLOCKING]`, diğerlerinde `[Question]`.
- Sahipsiz çıplak `TODO` → `[BLOCKING]`.
- Bariz yorumlar → `[Nit:]`.

---

**Sahip / Owner:** Teknik Mimari Kurulu / Technical Architecture Board