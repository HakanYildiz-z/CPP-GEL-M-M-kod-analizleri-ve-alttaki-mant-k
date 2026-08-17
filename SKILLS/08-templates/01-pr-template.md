# PR Şablonu / PR Template

**Versiyon / Version:** 1.0
**Kullanım:** GitHub/GitLab merge request açıklamasına yapıştırın. Tüm bölümler zorunludur.

---

## Özet / Summary

> [2–3 cümle: ne yapıldı, neden yapıldı] / [2-3 sentences: what and why]

## Gereksinim / Requirement

| REQ ID | DSN ID | Açıklama / Description |
|--------|--------|------------------------|
| REQ-XXXX | DSN-XXXX | ... |
| − | − | **Davranış değişikliği yok / No behavior change** (dokümantasyon için) |

## Güvenlik Seviyesi / Safety Level

- [ ] CRITICAL   - [ ] HIGH   - [x] MEDIUM   - [ ] LOW

## Değişiklik Tipi / Change Type

- [x] Yeni özellik / New feature   - [ ] Hata düzeltmesi / Bugfix
- [ ] Refactor   - [ ] Dokümantasyon / Documentation
- [ ] Yapılandırma / Configuration

## Kodlama Standardı Uygunluğu / Standards Compliance

- [ ] MISRA Mandatory: 0 ihlal / 0 violations
- [ ] MISRA Required sapma: DEV-XXXX (veya yok / or none)
- [ ] CERT kuralları değerlendirildi / CERT rules assessed
- [ ] Büyülü sayı yok / No magic numbers
- [ ] `@requirement` etiketi mevcut / tag present  - [ ] `@verifies` testlerde / in tests

## Test / Test Results

- [ ] Birim testleri eklendi/güncellendi / Unit tests added/updated
- [ ] Statik analiz: 0 kritik / Static analysis: 0 critical
- [ ] Kapsam: `XX%` (hedef: `YY%`) / Coverage
- [ ] Entegrasyon testleri çalıştı / Integration tests ran
- [ ] MC/DC sonuçları eklendi (CRITICAL ise) / MC/DC results attached (if CRITICAL)

## Etki Analizi / Impact Analysis

- [ ] Tehlike etkisi değerlendirildi / Hazard impact assessed (MIL-STD-882E)
- [ ] Zamanlama/WCET etkisi değerlendirildi / Timing/WCET assessed (flight-critical)
- [ ] Bağımlılık/CVE taraması yapıldı / Dependency/CVE scan run
- [ ] Sır/PII sızıntısı yok / No secrets/PII

## İnceleme İhtiyacı / Review Needs

- [ ] Teknik Lider / Tech Lead
- [ ] Güvenlik Ofisörü / Security Officer
- [x] Standart / Standard

## İnceleyici Notları / Reviewer Notes

_(İnceleyiciler LGTM için aşağıyı işaretler / Reviewers mark here for LGTM)_
- [ ] LGTM — Reviewer 1 (ID):
- [ ] LGTM — Reviewer 2 (ID): *(CRITICAL için gerekli / required for CRITICAL)*
- [ ] Bağımsızlık beyanı / Independence statement: `inceleyici ≠ yazar`

---

## English (standalone copy for non-Turkish repos)

- Summary (what/why)
- Requirement link (REQ/DSN)
- Safety level (CRITICAL/HIGH/MEDIUM/LOW)
- Change type (feature/bugfix/refactor/docs/config)
- Standards compliance (MISRA/CERT/magic numbers/tags)
- Test results (unit/static/coverage/integration/MC-DC)
- Impact analysis (hazard/timing/deps/secrets)
- Review needs (Tech Lead / Security Officer / standard)
- Reviewer sign-off block with independence statement

---

**Sahip / Owner:** Kod Kalite Komitesi / Code Quality Committee