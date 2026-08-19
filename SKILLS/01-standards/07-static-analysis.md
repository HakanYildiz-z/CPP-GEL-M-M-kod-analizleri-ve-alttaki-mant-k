# Statik Analiz / Static Analysis

**Versiyon / Version:** 1.0

---

## English

### Mandatory Tools & Thresholds

| Tool | Purpose | Gate |
|------|---------|------|
| PC-lint Plus / Flexelint | MISRA C/C++ rule checking | **0 violations** (critical); deviations only via tracker |
| Cppcheck | C++ defect detection | **0 errors**; 0 critical |
| Clang-Tidy | Modern C++ / style | **0 critical findings** |
| SonarQube | Code quality & security | Grade **A** |
| CodeQL | Security (CWE Top 25) | **0 critical/high** |
| Semgrep | Custom security rules | 0 rule hits |

### Static Analysis Workflow

1. **Run locally** before submitting (`make lint`).
2. **In CI** after build — mandatory gate, not advisory.
3. **Triage:** every finding classified CRITICAL / HIGH / MEDIUM / LOW.
4. **Zero-tolerance gate:** CRITICAL + HIGH → merge blocked.
5. **Deviations** require the MISRA deviation form (`04-checklists/06`).

### Config Essentials

- PC-lint: rule set per MISRA C:2012 + C++:2008/2023 + CERT. Enable `-w3`, treat MISRA Mandatory as errors.
- Suppress only justified patterns with a ticket ID, never globally.
- CI uploads SARIF → GitHub Security tab / SonarQube.

### Record

Every merge stores: tool, version, rule profile hash, finding list, deviation IDs. (See `05-traceability`.)

---

## Türkçe

### Zorunlu Araçlar ve Eşikler

| Araç | Amaç | Kapı |
|------|---------|------|
| PC-lint Plus / Flexelint | MISRA C/C++ kural kontrolü | **0 ihlal** (kritik); sapmalar yalnızca takipçi ile |
| Cppcheck | C++ hata tespiti | **0 hata**; 0 kritik |
| Clang-Tidy | Modern C++ / stil | **0 kritik bulgu** |
| SonarQube | Kod kalitesi ve güvenlik | A **notu** |
| CodeQL | Güvenlik (CWE Top 25) | **0 kritik/yüksek** |
| Semgrep | Özel güvenlik kuralları | 0 kural isabeti |

### Statik Analiz İş Akışı

1. **Yerelde çalıştır** göndermeden önce (`make lint`).
2. **CI'da** derleme sonrası — zorunlu kapı, tavsiye değil.
3. **Triyaj:** her bulgu CRITICAL / HIGH / MEDIUM / LOW olarak sınıflandırılır.
4. **Sıfır tolerans kapısı:** CRITICAL + HIGH → merge engellenir.
5. **Sapmalar** MISRA sapma formunu gerektirir (`04-checklists/06`).

### Konfigürasyon Esasları

- PC-lint: MISRA C:2012 + C++:2008/2023 + CERT kural seti. `-w3` etkinleştir, MISRA Mandatory'yi hata say.
- Yalnızca gerekçeli desenleri bilet ID'si ile bastır, asla global.
- CI SARIF yükler → GitHub Security sekmesi / SonarQube.

### Kayıt

Her merge şunları saklar: araç, sürüm, kural profili hash'i, bulgu listesi, sapma ID'leri. (Bkz. `05-traceability`.)

---

**Sahip / Owner:** DevOps / CI Mühendisliği