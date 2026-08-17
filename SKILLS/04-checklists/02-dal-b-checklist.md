# DAL B Kontrol Listesi / DAL B Checklist

**Versiyon / Version:** 1.0
**Uygulama:** DO-178C Seviye B (tehlikeli) — bağımsız doğrulama 31 amacın 7'sinde. DAL A'dan titizlik çıkarılır; kalan kontroller geçerlidir.

---

## English

### 1. Traceability & Requirements

- [ ] `@requirement REQ-XXXX` on public functions; `@verifies` in tests.
- [ ] Low-level requirements consistent with high-level; no orphans.
- [ ] Hazard-relevant items marked `@safety_level` (HIGH/CRITICAL).

### 2. Coding Standards (MISRA Mandatory + Required)

- [ ] **0** Mandatory violations; Required deviations approved via tracker.
- [ ] No RTTI/exceptions on safety paths; no `goto`; bounded pointers.
- [ ] No magic numbers; complexity limits held (≤60 lines, CC ≤ 10).
- [ ] CERT: bounds, NULL, integer overflow checks present.

### 3. Verification & Tests

- [ ] Requirement-based tests per executable requirement.
- [ ] **Branch/condition coverage** on DAL B paths (MC/DC not mandatory, but recommended for logic-heavy items).
- [ ] Static analysis: **0** critical/high.
- [ ] Fault-injection for guard/interlock paths.

### 4. Independence & Records

- [ ] Independent verification for the (7/31) objectives — evidence recorded.
- [ ] Reviewer ≠ author; review record complete.

### 5. Security (STRIDE) & CM

- [ ] No secrets/PII in code or logs; input validated.
- [ ] Config item identified; CCB path acknowledged.

---

## Türkçe

### 1. İzlenebilirlik & Gereksinimler

- [ ] Genel fonksiyonlarda `@requirement REQ-XXXX`; testlerde `@verifies`.
- [ ] Alt düzey gereksinimler üst düzeyle tutarlı; yetim yok.
- [ ] Tehlike-ilgili öğeler `@safety_level` ile işaretli (HIGH/CRITICAL).

### 2. Kodlama Standartları (MISRA Mandatory + Required)

- [ ] **0** Mandatory ihlali; Required sapmaları takipçi aracılığıyla onaylı.
- [ ] Güvenlik yollarında RTTI/istisna yok; `goto` yok; sınırlı pointer'lar.
- [ ] Büyülü sayı yok; karmaşıklık limitleri korunuyor (≤60 satır, CC ≤ 10).
- [ ] CERT: sınır, NULL, tamsayı taşması kontrolleri mevcut.

### 3. Doğrulama & Testler

- [ ] Her çalıştırılabilir gereksinim için gereksinim tabanlı test.
- [ ] DAL B yollarında **branch/condition kapsamı** (MC/DC zorunlu değil ama mantık-ağır öğelerde önerilir).
- [ ] Statik analiz: **0** kritik/yüksek.
- [ ] Guard/interlock yollarında hata enjeksiyonu.

### 4. Bağımsızlık & Kayıtlar

- [ ] (7/31) amaç için bağımsız doğrulama — kanıt kayıtlı.
- [ ] İnceleyici ≠ yazar; inceleme kaydı eksiksiz.

### 5. Güvenlik (STRIDE) & CM

- [ ] Kodda/logda sır veya PII yok; girdi doğrulanıyor.
- [ ] Konfigürasyon öğesi tanımlı; CCB yolu onaylı.

---

**Sahip:** Uyumluluk Mühendisliği / Compliance Engineering