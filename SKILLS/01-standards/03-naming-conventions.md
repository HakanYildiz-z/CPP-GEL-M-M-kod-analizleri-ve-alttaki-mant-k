# İsimlendirme Konvansiyonları / Naming Conventions

**Versiyon / Version:** 1.0

---

## English

### C / C++ Identifiers

| Type | Convention | Example |
|------|-----------|---------|
| Function | `snake_case` + module prefix | `nav_calc_route()`, `sns_read_temp()` |
| Macro | `SCREAMING_SNAKE_CASE` | `MAX_BUFFER_SIZE`, `PI_CONSTANT` |
| Type (typedef/struct) | `PascalCase` + `_t` suffix | `SensorData_t`, `NavConfig_t` |
| Global variable | `g_` prefix + `snake_case` | `g_system_status`, `g_sensor_count` |
| Static variable | `s_` prefix + `snake_case` | `s_last_error_code` |
| Constant | `k` prefix + `PascalCase` | `kMaxPacketSize` |
| Enum | `PascalCase` type + `SCREAMING_SNAKE_CASE` values | `enum ErrorCode { ERR_NONE, ERR_TIMEOUT };` |
| Class member | `snake_case` | `distance_km`, `telemetry_cycle` |

### Rules

1. **No Hungarian notation.** Type prefixes discouraged; semantic prefixes (`g_`, `s_`, `k_`) required.
2. **No abbreviations** unless defined in the module glossary and used consistently.
3. **No misspellings.** Verify with a spell-checker in reviews (`[Nit:] classification vs. classication`).
4. **Length:** descriptive over short; 20–30 chars acceptable for domain terms; avoid >50.
5. **Consistency:** a file uses ONE convention. Mixing `snake_case` and `PascalCase` for the same element type is a `[BLOCKING]` finding.
6. **Bools** read like predicates: `is_ready`, `has_error`, `target_locked`.

### File Naming

| File | Convention |
|------|-----------|
| Source | `modul_adi.c` / `modul_adi.cpp` |
| Header | `modul_adi.h` / `modul_adi.hpp` |
| Test | `test_modul_adi.c` / `test_modul_adi.py` |
| Mock | `mock_modul_adi.c` |

### Review Enforcement

- Inconsistent naming of the same element type → `[BLOCKING]`.
- Misspelling → `[Nit:]` (fix in same CL).
- Ambiguous abbreviation → `[Question]` or `[BLOCKING]` if it hides meaning.

---

## Türkçe

### C / C++ Tanımlayıcılar

| Tür | Konvansiyon | Örnek |
|------|-----------|---------|
| Fonksiyon | `snake_case` + modül öneki | `nav_calc_route()`, `sns_read_temp()` |
| Makro | `SCREAMING_SNAKE_CASE` | `MAX_BUFFER_SIZE`, `PI_CONSTANT` |
| Tip (typedef/struct) | `PascalCase` + `_t` soneki | `SensorData_t`, `NavConfig_t` |
| Global değişken | `g_` öneki + `snake_case` | `g_system_status`, `g_sensor_count` |
| Statik değişken | `s_` öneki + `snake_case` | `s_last_error_code` |
| Sabit | `k` öneki + `PascalCase` | `kMaxPacketSize` |
| Enum | `PascalCase` tip + `SCREAMING_SNAKE_CASE` değer | `enum ErrorCode { ERR_NONE, ERR_TIMEOUT };` |
| Sınıf üyesi | `snake_case` | `distance_km`, `telemetry_cycle` |

### Kurallar

1. **Hungarian notation yok.** Tip önekleri teşvik edilmez; anlamsal önekler (`g_`, `s_`, `k_`) zorunludur.
2. **Kısaltma yok** — modül sözlüğünde tanımlanmadıkça ve tutarlı kullanılmadıkça.
3. **Yazım hatası yok.** İncelemede yazım denetleyicisi ile doğrula (`[Nit:] classification vs. classication`).
4. **Uzunluk:** açıklayıcı > kısa; alan terimleri için 20–30 karakter kabul edilebilir; 50'den uzun olmasın.
5. **Tutarlılık:** bir dosya TEK konvansiyon kullanır. Aynı element tipi için karışık `snake_case` ve `PascalCase` kullanımı `[BLOCKING]` bulgudur.
6. **Bools** yüklem gibi okunur: `is_ready`, `has_error`, `target_locked`.

### Dosya İsimlendirme

| Dosya | Konvansiyon |
|------|-----------|
| Kaynak | `modul_adi.c` / `modul_adi.cpp` |
| Başlık | `modul_adi.h` / `modul_adi.hpp` |
| Test | `test_modul_adi.c` / `test_modul_adi.py` |
| Mock | `mock_modul_adi.c` |

### İncelemede Uygulama

- Aynı element tipi için tutarsız isimlendirme → `[BLOCKING]`.
- Yazım hatası → `[Nit:]` (aynı CL'de düzeltilir).
- Belirsiz kısaltma → `[Question]` veya anlamı gizliyorsa `[BLOCKING]`.

---

**Sahip / Owner:** Teknik Mimari Kurulu / Technical Architecture Board