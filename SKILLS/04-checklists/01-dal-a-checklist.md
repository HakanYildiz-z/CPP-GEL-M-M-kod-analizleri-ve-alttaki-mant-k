# DAL A Kontrol Listesi / DAL A Checklist

**Versiyon / Version:** 1.0
**Uygulama:** DO-178C Sevviye A (katastrofik) — en yüksek titizlik. Her öğe incelenmeli; bağımsızlık 31 amacın 16'sında zorunlu.

---

## English

### 1. Traceability & Requirements / İzlenebilirlik & Gereksinimler

- [ ] Every function references `@requirement REQ-XXXX` (low-level requirement).
- [ ] High-level ↔ low-level requirement trace complete.
- [ ] No orphan requirement; no orphan code.
- [ ] `@safety_level CRITICAL` marked on all flight-critical items.
- [ ] Change impact analysis recorded in the review record.

### 2. Architecture & Design / Mimari & Tasarım

- [ ] Code data/control flow matches architecture diagram (DO-178C 6.3.3/6.3.4).
- [ ] No concealed dependencies (e.g., hidden global state).
- [ ] FTTI/FTI protections present at DAL A boundaries.
- [ ] Partitioning/independence between DAL A and lower-level items preserved.

### 3. Coding Standards / Kodlama Standartları (MISRA Mandatory + Required)

- [ ] **0** MISRA Mandatory violations (no deviation permitted).
- [ ] Required violations carry approved deviation forms (`04-checklists/06`).
- [ ] No dynamic memory, RTTI, exceptions, `goto` in DAL A code.
- [ ] No magic numbers; all constants named (`constexpr`/`#define`).
- [ ] Function ≤ 60 lines, ≤ 5 params, CC ≤ 10, nesting ≤ 4.
- [ ] CERT checks pass: ARR30, MEM30, STR31, INT30, INT32 (auto + review).

### 4. Verification & Tests / Doğrulama & Testler

- [ ] Unit test present for every executable requirement.
- [ ] **MC/DC 100%** on DAL A code (per aggregation rules).
- [ ] Requirement-based tests approved by reviewer.
- [ ] Tests are **pure** (no dependence on execution order/global state).
- [ ] Fault-injection tests exist for D/A converters, guards, failsafe paths.
- [ ] Static analysis: **0** critical/high findings.

### 5. Independence & Review Records / Bağımsızlık & İnceleme Kayıtları

- [ ] Reviewer is **not** the author (independence recorded).
- [ ] Independent verification for the (16/31) objectives — evidence in record.
- [ ] Review record contains: reviewer, CL ID, time, findings, decision.
- [ ] Problem reports dispositioned (AC 20-189 OPR management).

### 6. Configuration Management / Konfigürasyon Yönetimi

- [ ] Configuration item identified (version/hash) in the review record.
- [ ] Baseline + change control (CCB) path acknowledged.
- [ ] Build reproducible from the reviewed source (evidence).

### 7. Security (STRIDE) / Güvenlik (STRIDE)

- [ ] No secrets, keys, or PII in code or logs.
- [ ] External input validated at all boundaries.
- [ ] No `rand()`; crypto RNG/TRNG only.
- [ ] Timing attacks considered on security-critical paths.

---

## Türkçe

### 1. İzlenebilirlik & Gereksinimler

- [ ] Her fonksiyon `@requirement REQ-XXXX` referansı taşır (alt düzey gereksinim).
- [ ] Üst ↔ alt düzey gereksinim izi tamam.
- [ ] Yetim gereksinim yok; yetim kod yok.
- [ ] Tüm uçuş-kritik öğelerde `@safety_level CRITICAL` işaretli.
- [ ] Değişiklik etki analizi inceleme kaydına işlendi.

### 2. Mimari & Tasarım

- [ ] Kod veri/kontrol akışı mimari diyagramla eşleşiyor (DO-178C 6.3.3/6.3.4).
- [ ] Gizli bağımlılık yok (ör. gizli global durum).
- [ ] DAL A sınırlarında FTTI/FTI korumaları mevcut.
- [ ] DAL A ile düşük seviyeli öğeler arasındaki bölümleme/bağımsızlık korundu.

### 3. Kodlama Standartları (MISRA Mandatory + Required)

- [ ] **0** MISRA Mandatory ihlali (sapma mümkün değil).
- [ ] Required ihlalleri onaylı sapma formu taşır (`04-checklists/06`).
- [ ] DAL A kodunda dinamik bellek, RTTI, istisna, `goto` yok.
- [ ] Büyülü sayı yok; tüm sabitler adlandırıldı (`constexpr`/`#define`).
- [ ] Fonksiyon ≤ 60 satır, ≤ 5 parametre, CC ≤ 10, iç içe ≤ 4.
- [ ] CERT kontrolleri geçiyor: ARR30, MEM30, STR31, INT30, INT32 (oto + inceleme).

### 4. Doğrulama & Testler

- [ ] Her çalıştırılabilir gereksinim için birim test mevcut.
- [ ] DAL A kodunda **MC/DC %100** (toplama kurallarına göre).
- [ ] Gereksinim tabanlı testler inceleyici onaylı.
- [ ] Testler **saf** (çalıştırma sırasına/global duruma bağımlı değil).
- [ ] D/A dönüştürücüler, guard'lar, failsafe yollar için hata enjeksiyon testleri var.
- [ ] Statik analiz: **0** kritik/yüksek bulgu.

### 5. Bağımsızlık & İnceleme Kayıtları

- [ ] İnceleyici, yazar **değil** (bağımsızlık kayıtlı).
- [ ] (16/31) amaç için bağımsız doğrulama — kanıt kayıtta.
- [ ] İnceleme kaydı: inceleyici, CL ID, süre, bulgular, karar.
- [ ] Sorun raporları sonuçlandırıldı (AC 20-189 OPR yönetimi).

### 6. Konfigürasyon Yönetimi

- [ ] Konfigürasyon öğesi inceleme kaydında tanımlandı (versiyon/hash).
- [ ] Baseline + değişiklik kontrolü (CCB) yolu onaylandı.
- [ ] İncelenen kaynaktan derleme yeniden üretilebilir (kanıt).

### 7. Güvenlik (STRIDE)

- [ ] Kodda veya loglarda sır, anahtar veya PII yok.
- [ ] Dış girdi tüm sınırlarda doğrulanıyor.
- [ ] `rand()` yok; kriptografik RNG/TRNG yalnızca.
- [ ] Güvenlik-kritik yollarda zamanlama saldırıları göz önünde.

---

**Sahip:** Uyumluluk Mühendisliği / Compliance Engineering