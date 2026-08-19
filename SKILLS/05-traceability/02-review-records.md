# İnceleme Kayıtları / Review Records

**Versiyon / Version:** 1.0
**Kaynak:** DO-178C §11, ISO 26262 (verification records), AC 20-189 OPR

---

## English

Review records are certification evidence. Every merge (except documented LOW/telemetry-only) must have a record.

### Review Record Template

```md
## Review Record
- Review ID        : RV-XXXX
- CL / PR link     : PR-#  | commit-hash
- Reviewer         : name / ID        (independent: YES/NO)
- Author           : name / ID
- Config item      : version / hash of reviewed item
- Date / duration  : YYYY-MM-DD / minutes

### Scope
- Files reviewed, lines, criticality class.

### Findings
| ID | Location | Severity | Rule ref | Resolution |
|----|----------|----------|----------|------------|
| F1 | file.cpp:42 | CRITICAL | MISRA C:2012 R.2.2 | Fixed in new commit |
| F2 | file.cpp:90 | Nit: | — | Won't fix (justified) |

### Decisions
- LGTM : YES/NO
- BLOCKED until : ...
- Sign-offs : Security Officer / Tech Lead
- Independence claim : reviewer not author (evidence)

### Evidence links
- Static analysis report, test summary, coverage report, deviation IDs.
```

### Retention & Audit

- Store in the repo tree or CM tool; immutable once merged (GPG-signed tags).
- Retrievable during SOI audits and functional safety assessments.
- Records survive personnel changes.

### Independence Tagging

For DAL A/B (16/31, 7/31) and ASIL C/D confirmation, the record must state **who** performed verification and **why** they are independent.

### CI Enforcement

- Merge blocked unless PR carries review record artifacts (check job).
- Metrics harvested from records (`02-review-process/05-review-metrics.md`).

---

## Türkçe

İnceleme kayıtları sertifikasyon kanıtıdır. Her merge (dokümante edilmiş LOW/yalnız-telemetri hariç) bir kayda sahip olmalıdır.

### İnceleme Kaydı Şablonu

```md
## İnceleme Kaydı
- İnceleme ID      : RV-XXXX
- CL / PR bağlantısı : PR-#  | commit-hash
- İnceleyici        : ad / ID        (bağımsız: EVET/HAYIR)
- Yazar             : ad / ID
- Konfigürasyon öğesi : incelenen öğenin versiyon / hash'i
- Tarih / süre      : YYYY-MM-DD / dakika

### Kapsam
- İncelenen dosyalar, satırlar, kritiklik sınıfı.

### Bulgular
| ID | Konum | Şiddet | Kural ref. | Çözüm |
|----|----------|----------|------------|------------|
| F1 | dosya.cpp:42 | CRITICAL | MISRA C:2012 R.2.2 | Yeni commit'te düzeltildi |
| F2 | dosya.cpp:90 | Nit: | — | Düzeltilmeyecek (gerekçeli) |

### Kararlar
- LGTM : EVET/HAYIR
- Şunlara kadar engelli: ...
- Onaylar : Güvenlik Ofisörü / Teknik Lider
- Bağımsızlık iddiası : inceleyici yazar değil (kanıt)

### Kanıt bağlantıları
- Statik analiz raporu, test özeti, kapsam raporu, sapma ID'leri.
```

### Saklama ve Denetim

- Depo ağacında veya CM aracında sakla; merge sonrası değişmez (GPG-imzalı tag'ler).
- SOI denetimlerinde ve fonksiyonel güvenlik değerlendirmelerinde erişilebilir.
- Kayıtlar personel değişiminden etkilenmez.

### Bağımsızlık Etiketleme

DAL A/B (31/16, 31/7) ve ASIL C/D onayı için kayıt, doğrulamayı **kimin** yaptığını ve **neden** bağımsız olduğunu belirtmelidir.

### CI Uygulaması

- PR inceleme kaydı artefaktı taşımıyorsa merge engellenir (check işi).
- Metrikler kayıtlardan toplanır (`02-review-process/05-review-metrics.md`).

---

**Sahip:** CM Mühendisliği / Configuration Management