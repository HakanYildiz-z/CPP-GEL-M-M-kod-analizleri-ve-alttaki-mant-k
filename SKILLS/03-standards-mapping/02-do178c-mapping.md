# DO-178C Haritalaması / DO-178C Mapping

**Versiyon / Version:** 1.0

---

## English

### Scope

DO-178C ("Software Considerations in Airborne Systems and Equipment Certification") governs airborne software. It is a process standard: correctness is shown through objectives, not just tests. Reviews are a mandated integral process (Section 6.3) and provide certification evidence.

### Criticality Levels

| Level | Failure condition | Review formality |
|-------|-------------------|------------------|
| DAL A | Catastrophic | Highest; independent review (16/31 objectives with independence) |
| DAL B | Hazardous | Independent review (7/31) |
| DAL C | Major | Planned review; no independence required |
| DAL D | Minor | Review targeted at affected items |
| DAL E | No effect | Agreed with authority |

### Review Objectives (Section 6.3 highlights)

- High-level requirements: correctness, accuracy, verifiability, consistency, compatibility with target (6.3.1).
- Low-level requirements: compliance with high-level; accuracy; verifiability (6.3.2).
- Architecture: compatibility with requirements, consistency of data/control flow (6.3.3).
- Source code: compliance with low-level requirements; compliance with architecture (data/control flow); compliance with coding standards; verifiability (6.3.4).
- Test cases/procedures/results: compliance with requirements and assumptions (6.4.5).

### Review Activity Mappings

| Code review artifact | DO-178C objective |
|----------------------|-------------------|
| `01-standards/*` (coding rules) | 6.3.4(b)(c) compliance |
| `02-review-process/02-review-phases.md` (design/line review) | 6.3.1–6.3.4 objectives |
| `04-checklists/01-dal-a-checklist.md` | Operationalized 6.3 + 6.4.5 |
| `05-traceability/01` (req↔code↔test) | Traceability across objectives |
| `06-independence/01` (independence) | Objective independence (DAL A/B) |
| `05-traceability/02` (review records) | Evidence (§11.14 problem reporting) |

### Review Record Requirements

- Configuration item reviewed must be identified (version / hash).
- Discrepancies tracked as problem reports with severity, disposition (AC 20-189 OPR concept).
- Reviewer independent from developer for DAL A/B objectives.
- Records retained and retrievable for certification audits.

### Enforcement in Review

- DAL A source tree: independence MUST be recorded on every review record.
- Deviations from coding standard require a problem report, not a silent `Nit:`.
- Any requirement with no test and no review analysis = open finding → `[BLOCKING]`.

---

## Türkçe

### Kapsam

DO-178C ("Software Considerations in Airborne Systems and Equipment Certification") hava aracı yazılımını yönetir. Bir süreç standardıdır: doğruluk yalnızca testlerle değil amaçlarla gösterilir. İncelemeler zorunlu bir bütünleşik süreçtir (Kısım 6.3) ve sertifikasyon kanıtı sağlar.

### Kritiklik Seviyeleri

| Seviye | Arıza durumu | İnceleme formalitesi |
|-------|-------------------|------------------|
| DAL A | Katastrofik | En yüksek; bağımsız inceleme (31 amacın 16'sı bağımsız) |
| DAL B | Tehlikeli | Bağımsız inceleme (31'den 7'si) |
| DAL C | Önemli | Planlı inceleme; bağımsızlık gerekmez |
| DAL D | Küçük | İnceleme etkilenen öğelere odaklı |
| DAL E | Etkisiz | Otorite ile kararlaştırılır |

### İnceleme Amaçları (Kısım 6.3 öne çıkanlar)

- Üst düzey gereksinimler: doğruluk, isabet, doğrulanabilirlik, tutarlılık, hedefle uyum (6.3.1).
- Alt düzey gereksinimler: üst düzeye uyum; isabet; doğrulanabilirlik (6.3.2).
- Mimari: gereksinimlerle uyum, veri/kontrol akışı tutarlılığı (6.3.3).
- Kaynak kod: alt düzey gereksinimlere uyum; mimariye uyum (veri/kontrol akışı); kodlama standartlarına uyum; doğrulanabilirlik (6.3.4).
- Test vakaları/prosedürleri/sonuçları: gereksinimlere ve varsayımlara uyum (6.4.5).

### İnceleme Aktivitesi Haritalaması

| Kod inceleme belgesi | DO-178C amacı |
|----------------------|-------------------|
| `01-standards/*` (kodlama kuralları) | 6.3.4(b)(c) uyumu |
| `02-review-process/02-review-phases.md` (tasarım/satır incelemesi) | 6.3.1–6.3.4 amaçları |
| `04-checklists/01-dal-a-checklist.md` | İşletileştirilmiş 6.3 + 6.4.5 |
| `05-traceability/01` (req↔kod↔test) | Amaçlar arası izlenebilirlik |
| `06-independence/01` (bağımsızlık) | Amaç bağımsızlığı (DAL A/B) |
| `05-traceability/02` (inceleme kayıtları) | Kanıt (§11.14 sorun raporlama) |

### İnceleme Kaydı Gereklilikleri

- İncelenen konfigürasyon öğesi tanımlanmalı (versiyon / hash).
- Tutarsızlıklar, şiddet ve sonuçla sorun raporu olarak izlenir (AC 20-189 OPR kavramı).
- İnceleyici, DAL A/B amaçları için geliştiriciden bağımsız olmalı.
- Kayıtlar sertifikasyon denetimleri için saklanır ve erişilebilir olur.

### İncelemede Uygulama

- DAL A kaynak ağacı: bağımsızlık HER inceleme kaydında belgelenmeli.
- Kodlama standardından sapma, sessiz `Nit:` değil sorun raporu gerektirir.
- Testi ve inceleme analizi olmayan gereksinim = açık bulgu → `[BLOCKING]`.

---

**Sahip / Owner:** Uyumluluk Mühendisliği / Compliance Engineering