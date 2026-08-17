# Standart Çapraz Referans Matrisi / Standards Cross-Reference Matrix

**Versiyon / Version:** 1.0

---

## English

This matrix maps the six defense/aerospace safety standards to concrete review activities. It answers: *"Which review activity satisfies which objectives of which standard?"*

### Legend / Anahtar

`M` = Mandatory · `R` = Required/Recommended · `T` = Tailored/discretionary · `—` = Not applicable

| Review activity | DO-178C | MIL-STD-882E | IEC 61508 | ISO 26262 | DEF-STAN 00-55/56 | MIL-HDBK-516 |
|-----------------|---------|--------------|-----------|-----------|-------------------|--------------|
| Requirements ↔ design review | M (§6.3.1) | M (hazard→req) | M (7.2) | M (Part 6, 6.4.1) | M | R |
| Architecture review | M (§6.3.2/6.3.3) | R | M (7.4.3) | M (Part 6, 7.4.1) | M | R |
| Source code ↔ architecture review | M (§6.3.4) | M (FTA/FMEA linkage) | M (7.4.4) | R (Part 6, 8.4.1) | M | R |
| Source code standards compliance | M (§6.3.3c) | R | M (Table A.1 – coding std) | M (Part 6, 8.4.4) | M | R |
| Static analysis | R (§6.3.4c, DAL-dependent) | R | M (Tables A.2/A.4/A.5) | R–M (Part 6, 8/9/11) | M | R |
| Unit test review | M (§6.4.5, tests of code) | R | M (7.4.7) | M (Part 6, 9.4) | M | R |
| Integration test review | M (§6.4.5) | R | M (7.4.8) | M (Part 6, 10) | M | R |
| Requirements-based test coverage | M (§6.4.4) | R | M (7.9) | M (Part 6, 11.4) | M | R |
| Structural coverage (MC/DC etc.) | M (A§; DAL A MC/DC) | R | R (Table B.6) | M (ASIL D MC/DC) | M | R |
| Independence of verification | M (DAL A: 16/31 objectives) | T | R (SIL 3–4 formal) | R (ASIL C–D) | M | T |
| Tool qualification evidence | M (DO-330) | T | M (7.4.4 tools) | M (Part 8, 11) | M | T |
| Configuration management | M (§7) | R | M (7.4.9) | M (Part 8, 7) | M | R |
| Traceability (req↔code↔test) | M (§6.4) | R | M (Annex A) | M (Part 6, Annexe A) | M | R |
| Problem/defect tracking | M (§11.14) | R | M (7.4.10) | M (Part 8, 9) | M | R |
| Security review (CWE/STRIDE) | T (DO-326A covers) | R | M (security reqs) | M (Part 6, security-relevant) | M | R |
| Coding standard (MISRA) | R (§6.3.3c) | R | M (Table A.1/a) | M (Part 6, 8.4.4) | M | R |

### How to use

1. Identify the governing standards from the contract (see `01-standards/01`).
2. Find your criticality cell: DAL A/B, SIL 3/4, ASIL C/D.
3. Apply the `M` activities unconditionally; plan `R`/`T` activities in the program's V&V plan.
4. Record satisfaction evidence per activity in traceability (`05-traceability/`).

---

## Türkçe

Bu matris altı savunma/havacılık güvenlik standardını somut inceleme aktivitelerine eşler. Şu soruyu yanıtlar: *"Hangi inceleme aktivitesi hangi standardın hangi amacını karşılar?"*

### Anahtar

`M` = Zorunlu · `R` = Gerekli/Önerilen · `T` = Uyarlanmış/takdire · `—` = Uygulanmaz

| İnceleme aktivitesi | DO-178C | MIL-STD-882E | IEC 61508 | ISO 26262 | DEF-STAN 00-55/56 | MIL-HDBK-516 |
|-----------------|---------|--------------|-----------|-----------|-------------------|--------------|
| Gereksinim ↔ tasarım incelemesi | M (§6.3.1) | M (tehlike→req) | M (7.2) | M (Bölüm 6, 6.4.1) | M | R |
| Mimari inceleme | M (§6.3.2/6.3.3) | R | M (7.4.3) | M (Bölüm 6, 7.4.1) | M | R |
| Kaynak kod ↔ mimari incelemesi | M (§6.3.4) | M (FTA/FMEA bağlantısı) | M (7.4.4) | R (Bölüm 6, 8.4.1) | M | R |
| Kaynak kod standartları uyumu | M (§6.3.3c) | R | M (Tablo A.1 – kod std) | M (Bölüm 6, 8.4.4) | M | R |
| Statik analiz | R (§6.3.4c, DAL'a göre) | R | M (Tablolar A.2/A.4/A.5) | R–M (Bölüm 6, 8/9/11) | M | R |
| Birim test incelemesi | M (§6.4.5, kod testleri) | R | M (7.4.7) | M (Bölüm 6, 9.4) | M | R |
| Entegrasyon test incelemesi | M (§6.4.5) | R | M (7.4.8) | M (Bölüm 6, 10) | M | R |
| Gereksinim tabanlı test kapsamı | M (§6.4.4) | R | M (7.9) | M (Bölüm 6, 11.4) | M | R |
| Yapısal kapsam (MC/DC vb.) | M (A§; DAL A MC/DC) | R | R (Tablo B.6) | M (ASIL D MC/DC) | M | R |
| Doğrulamanın bağımsızlığı | M (DAL A: 31 amacın 16'sı) | T | R (SIL 3–4 resmi) | R (ASIL C–D) | M | T |
| Araç yeterlilik kanıtı | M (DO-330) | T | M (7.4.4 araçlar) | M (Bölüm 8, 11) | M | T |
| Konfigürasyon yönetimi | M (§7) | R | M (7.4.9) | M (Bölüm 8, 7) | M | R |
| İzlenebilirlik (req↔kod↔test) | M (§6.4) | R | M (Ek A) | M (Bölüm 6, Ek A) | M | R |
| Sorun/kusur takibi | M (§11.14) | R | M (7.4.10) | M (Bölüm 8, 9) | M | R |
| Güvenlik incelemesi (CWE/STRIDE) | T (DO-326A kapsar) | R | M (güvenlik req) | M (Bölüm 6, güvenlik-ilgili) | M | R |
| Kodlama standardı (MISRA) | R (§6.3.3c) | R | M (Tablo A.1/a) | M (Bölüm 6, 8.4.4) | M | R |

### Nasıl kullanılır

1. Sözleşmeden geçerli standartları belirle (bkz. `01-standards/01`).
2. Kritiklik hücreni bul: DAL A/B, SIL 3/4, ASIL C/D.
3. `M` aktivitelerini koşulsuz uygula; `R`/`T` aktivitelerini programın V&V planında planla.
4. Her aktivite için karşılama kanıtını izlenebilirlikte kaydet (`05-traceability/`).

---

**Sahip / Owner:** Uyumluluk Mühendisliği / Compliance Engineering