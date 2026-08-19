# İnceleme Kaydı Şablonu / Review Record Template

**Versiyon / Version:** 1.0
**Kaynak:** DO-178C §11, `05-traceability/02-review-records.md`

---

## İnceleme Kaydı / Review Record

| Alan / Field | Değer / Value |
|--------------|---------------|
| İnceleme ID / Review ID | RV-XXXX |
| CL / PR bağlantısı / CL / PR link | PR-# \| commit-hash |
| İnceleyici / Reviewer | ad / ID | bağımsız: EVET/HAYIR |
| Yazar / Author | ad / ID |
| Konfigürasyon öğesi / Config item | versiyon / hash |
| Tarih / süre / Date / duration | YYYY-MM-DD / dk |

### Kapsam / Scope
- İncelenen dosyalar / satırlar: ...
- Kritiklik sınıfı / Criticality class: CRITICAL/HIGH/MEDIUM/LOW

### Bulgular / Findings

| ID | Konum / Location | Şiddet / Severity | Kural ref. / Rule ref | Çözüm / Resolution |
|----|------------------|-------------------|-----------------------|--------------------|
| F1 | dosya.cpp:42 | CRITICAL | MISRA C:2012 R.2.2 | Yeni commit'te düzeltildi |
| F2 | dosya.cpp:90 | Nit: | — | Düzeltilmeyecek (gerekçeli) |
| F3 | dosya.cpp:120 | BLOCKING | CERT INT30-C | Açık / pending |

### Kararlar / Decisions
- **LGTM**: EVET / HAYIR
- **Şu sebeplerle engelli / Blocked until**: ...
- **Onaylar / Sign-offs**: Güvenlik Ofisörü / Teknik Lider
- **Bağımsızlık / Independence**: inceleyici ≠ yazar — kanıt: ...
- **Sapmalar / Deviations**: DEV-XXXX (uygulanmış / applied), DEV-YYYY (önceden / previous)

### Kanıt bağlantıları / Evidence links
- Statik analiz raporu / Static analysis report: ...
- Test özeti / Test summary: ...
- Kapsam raporu / Coverage report: ...
- SARIF çıktıları / SARIF outputs: ...

---

**Saklama / Retention:** merge sonrası immutable (GPG-imzalı tag). SOI/FSA denetimlerinde erişilebilir.
**Kaynak şablon:** `05-traceability/02-review-records.md`