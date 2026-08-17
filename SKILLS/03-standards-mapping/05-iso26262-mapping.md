# ISO 26262 Haritalaması / ISO 26262 Mapping

**Versiyon / Version:** 1.0

---

## English

### Scope

ISO 26262-6 covers product development at the software level for road vehicles. It distinguishes **verification reviews** (work product correctness) from **confirmation measures** (process/independence assurance).

### ASIL → Rigor

| ASIL | Coding standard | Coverage | Independence |
|------|-----------------|----------|--------------|
| QM | MISRA advisory level valid¹ | Statement | Not required |
| A | MISRA | Statement/branch | Not required |
| B | MISRA | Branch/condition | Independence recommended |
| C | MISRA + enhanced rules | DC/condition determination | Independence required (confirmation) |
| D | MISRA (Mandatory subset) | **MC/DC** | Independence required |

¹Subject to the project's GRP re-categorization.

### Review Activity Mappings (Part 6)

| ISO 26262-6 clause | Code review action |
|--------------------|--------------------|
| Software safety requirement specification (6.6) | Correctness, completeness, mode coverage, traceability to safety goals |
| Architectural design (7.4) | FTTI/FTI in design; no concealed dependencies |
| Unit design & implementation (8.4) | Coding guidelines compliance; MISRA; complexity control |
| Unit verification (9.4) | Reviews + structural coverage per ASIL; MC/DC at D |
| Software integration (10.6) | Interface continuity; data/control flow; tests review |
| Verification of SW safety requirements (11.4) | Requirements-based tests at integrated level |
| Configurable software (12) | Parameter review; restrict variability |

### Verification vs Confirmation

- **Verification review:** "Did we build the product per requirements?" → technical review of work products.
- **Confirmation measure:** "Can we prove, independently, the process is acceptable?" → independent check of work products vs. requirements; tied to ASIL.
- In a CL review: verification applies to code/test; confirmation applies to evidence and independence of the reviewer.

### Enforcement in Review

- MISRA Mandatory violation at ASIL D without deviation → `[CRITICAL]`.
- Coverage evidence below ASIL C/D threshold → `[BLOCKING]`.
- Confirmation-measure independence not documented → `[BLOCKING]` for ASIL C/D.

---

## Türkçe

### Kapsam

ISO 26262-6, yol araçları için yazılım seviyesinde ürün geliştirmeyi kapsar. **Doğrulama incelemelerini** (iş ürünü doğruluğu) **onay önlemlerinden** (süreç/bağımsızlık güvencesi) ayırır.

### ASIL → Titizlik

| ASIL | Kodlama standardı | Kapsam | Bağımsızlık |
|------|-----------------|----------|--------------|
| QM | MISRA advisory seviyesi geçerli¹ | Statement | Gerekmez |
| A | MISRA | Statement/branch | Gerekmez |
| B | MISRA | Branch/condition | Önerilir |
| C | MISRA + gelişmiş kurallar | DC/condition determination | Gerekir (onay) |
| D | MISRA (Mandatory alt kümesi) | **MC/DC** | Gerekir |

¹Projenin GRP yeniden kategorilendirmesine tabidir.

### İnceleme Aktivitesi Haritalaması (Bölüm 6)

| ISO 26262-6 maddesi | Kod inceleme aksiyonu |
|--------------------|--------------------|
| Yazılım güvenlik gereksinimi özelliklemesi (6.6) | Doğruluk, eksiksizlik, mod kapsamı, güvenlik hedeflerine izlenebilirlik |
| Mimari tasarım (7.4) | Tasarımda FTTI/FTI; gizli bağımlılık yok |
| Birim tasarımı & uygulama (8.4) | Kodlama kural uyumu; MISRA; karmaşıklık kontrolü |
| Birim doğrulaması (9.4) | İncelemeler + ASIL'e göre yapısal kapsam; D'de MC/DC |
| Yazılım entegrasyonu (10.6) | Arayüz sürekliliği; veri/kontrol akışı; test incelemesi |
| YZ güvenlik gereksinimlerinin doğrulanması (11.4) | Entegre seviyede gereksinim tabanlı testler |
| Yapılandırılabilir yazılım (12) | Parametre incelemesi; değişkenliği sınırla |

### Doğrulama vs Onay

- **Doğrulama incelemesi:** "Ürünü gereksinimlere göre mi inşa ettik?" → iş ürünlerinin teknik incelemesi.
- **Onay önlemi:** "Sürecin kabul edilebilir olduğunu bağımsız kanıtlayabilir miyiz?" → iş ürününün gereksinimlere karşı bağımsız kontrol; ASIL'a bağlı.
- CL incelemesinde: doğrulama kod/teste; onay, kanıt ve inceleyicinin bağımsızlığına uygulanır.

### İncelemede Uygulama

- ASIL D'de sapmasız MISRA Mandatory ihlali → `[CRITICAL]`.
- Kapsam kanıtı ASIL C/D eşiği altında → `[BLOCKING]`.
- ASIL C/D için onay önlemi bağımsızlığı dokümante edilmemiş → `[BLOCKING]`.

---

**Sahip / Owner:** Fonksiyonel Güvenlik Yönetimi / Functional Safety Management