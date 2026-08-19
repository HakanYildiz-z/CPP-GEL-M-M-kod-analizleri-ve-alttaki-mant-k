# MISRA Sapma Takipçisi / MISRA Deviation Tracker

**Versiyon / Version:** 1.0
**Kaynak:** MISRA Compliance:2020 framework

---

## English

Each deviation MUST be visible in the review, approved before merge, and re-verified at expiry. Copy this record per deviation (or keep the columns in your tracker).

### Deviation Form

| Field | Value |
|-------|-------|
| Deviation ID | `DEV-XXXX` |
| CL / PR link | `PR-#` |
| Guideline ID | `MISRA C:2012 Rule 2.2` |
| Category | `Required` (Mandatory deviations **never** permitted) |
| Location | `module/file.cpp:line` |
| Severity of affected path | CRITICAL / HIGH / MEDIUM / LOW |
| Justification (technical) | ... |
| Compensation / risk mitigation | ... |
| Expiry date | YYYY-MM-DD |
| Re-review required at expiry | YES |
| Approver 1 (reviewer) | |
| Approver 2 (domain lead) | |
| Safety representative (CRITICAL paths) | |
| Review evidence link | `05-traceability/02` |

### Rules

1. Mandatory guidelines: **no deviation**. Fix.
2. Advisory deviations: discouraged; require a GRP-approved reason.
3. A deviation without expiry is invalid.
4. At expiry the code is re-reviewed against the guideline and either fixed or the deviation renewed with new evidence.
5. Deviations are reported in the compliance report (count, cause, per-DAL distribution).

---

## Türkçe

Her sapma, merge öncesinde onaylanmış ve bitişte yeniden doğrulanmış olarak incelemede GÖRÜNÜR olmalıdır. Sapma başına bu kaydı kopyalayın (veya sütunları takipçinizde tutun).

### Sapma Formu

| Alan | Değer |
|-------|-------|
| Sapma ID | `DEV-XXXX` |
| CL / PR bağlantısı | `PR-#` |
| Kural ID | `MISRA C:2012 Rule 2.2` |
| Kategori | `Required` (Mandatory sapmalara **asla** izin verilmez) |
| Konum | `modul/dosya.cpp:satır` |
| Etkilenen yolun şiddeti | CRITICAL / HIGH / MEDIUM / LOW |
| Gerekçe (teknik) | ... |
| Telafi / risk azaltımı | ... |
| Bitiş tarihi | YYYY-MM-DD |
| Bitişte yeniden inceleme | EVET |
| Onaylayan 1 (inceleyici) | |
| Onaylayan 2 (alan lideri) | |
| Güvenlik temsilcisi (CRITICAL yollar) | |
| İnceleme kanıtı bağlantısı | `05-traceability/02` |

### Kurallar

1. Mandatory kurallar: **sapma yok**. Düzelt.
2. Advisory sapmalar: teşvik edilmez; GRP-onaylı gerekçe gerektirir.
3. Bitişi olmayan sapma geçersizdir.
4. Bitişte kod kurala karşı yeniden incelenir; ya düzeltilir ya da sapma yeni kanıtla yenilenir.
5. Sapmalar uyumluluk raporunda raporlanır (sayı, neden, DAL başına dağılım).

---

**Sahip:** Kalite Mühendisliği / Quality Engineering