# IEC 61508 Haritalaması / IEC 61508 Mapping

**Versiyon / Version:** 1.0

---

## English

### Scope

IEC 61508 (Functional safety of E/E/PE systems) covers sector-agnostic functional safety. Reviews are required throughout the lifecycle; reviewer competence and independence scale with SIL.

### SIL → Review Rigor

| SIL | Review technique (Table B.1 / A of Part 3) | Independence |
|-----|--------------------------------------------|--------------|
| SIL 1 | Peer review adequate | Not required |
| SIL 2 | Peer review + checklist-based inspection | Not required |
| SIL 3 | Formal inspection (Fagan-style) | Recommended |
| SIL 4 | Formal inspection + analysis methods | Required (independent) |

Highly recommended for SIL 3/4: formal inspections with specific criteria, control-flow and data-flow analysis, boundary value analysis.

### Review Activity Mappings

| IEC 61508 activity | Code review action |
|--------------------|--------------------|
| Software safety requirements review (7.2) | Traceability, ambiguity, verifiability, mode coverage |
| Architecture design review (7.4.3) | Fault detection, error detection, failure assertion patterns |
| Coding standard selection & enforcement (7.4.4) | MISRA + language subset; deviation process |
| Code verification (dynamic + static, 7.4.6/7.4.7) | Unit + integration test review; static analysis gates |
| Verification records (7.9) | Evidence files; repeatability, defined config |
| Tool qualification (7.4.4 tools / Annex A.2) | Tool selected per impact; relevance documented |
| Functional safety assessment (8.2) | Independent assessment; confirmation review |

### Coding Standard Requirements (Table A.1 Direction)

- Use of language subset (MISRA), no unrestricted pointers/recursion, structured programming.
- Design for testability and understandability.
- Complexity limits enforced (see `01-standards/04`).

### Enforcement in Review

- `[Question]`: which technique applies at this SIL? Cite table.
- Missing verification record → `[BLOCKING]`.
- Tool with SIL impact but no qualification record → `[BLOCKING]`.

---

## Türkçe

### Kapsam

IEC 61508 (E/E/PE sistemlerin fonksiyonel güvenliği) sektör-bağımsız fonksiyonel güvenliği kapsar. İncelemeler yaşam döngüsü boyunca gereklidir; inceleyici yeterliliği ve bağımsızlığı SIL ile ölçeklenir.

### SIL → İnceleme Titizliği

| SIL | İnceleme tekniği (Bölüm 3 Tablo B.1 / A) | Bağımsızlık |
|-----|--------------------------------------------|--------------|
| SIL 1 | Akran incelemesi yeterli | Gerekmez |
| SIL 2 | Akran incelemesi + kontrol listesi tabanlı muayene | Gerekmez |
| SIL 3 | Resmi muayene (Fagan tarzı) | Önerilir |
| SIL 4 | Resmi muayene + analiz yöntemleri | Gerekir (bağımsız) |

SIL 3/4 için yüksek önerilenler: spesifik kriterli resmi muayeneler, kontrol-akışı ve veri-akışı analizi, sınır değer analizi.

### İnceleme Aktivitesi Haritalaması

| IEC 61508 aktivitesi | Kod inceleme aksiyonu |
|--------------------|--------------------|
| YZ güvenlik gereksinimleri incelemesi (7.2) | İzlenebilirlik, belirsizlik, doğrulanabilirlik, mod kapsamı |
| Mimari tasarım incelemesi (7.4.3) | Arıza tespiti, hata tespiti, başarısızlık iddiası desenleri |
| Kodlama standardı seçimi ve uygulaması (7.4.4) | MISRA + dil alt kümesi; sapma süreci |
| Kod doğrulama (dinamik + statik, 7.4.6/7.4.7) | Birim + entegrasyon test incelemesi; statik analiz kapıları |
| Doğrulama kayıtları (7.9) | Kanıt dosyaları; tekrarlanabilirlik, tanımlı konfigürasyon |
| Araç yeterliliği (7.4.4 araçlar / Ek A.2) | Araç etkisine göre seçildi; ilgi dokümante edildi |
| Fonksiyonel güvenlik değerlendirmesi (8.2) | Bağımsız değerlendirme; onay incelemesi |

### Kodlama Standardı Gereklilikleri (Tablo A.1 Yönü)

- Dil alt kümesi (MISRA) kullanımı, kontrolsüz pointer/özyineleme yok, yapılandırılmış programlama.
- Test edilebilirlik ve anlaşılabilirlik için tasarım.
- Karmaşıklık limitleri uygulanır (bkz. `01-standards/04`).

### İncelemede Uygulama

- `[Question]`: bu SIL'de hangi teknik geçerli? Tablodan belirt.
- Eksik doğrulama kaydı → `[BLOCKING]`.
- SIL etkili ama yeterlilik kaydı olmayan araç → `[BLOCKING]`.

---

**Sahip / Owner:** Fonksiyonel Güvenlik Yönetimi / Functional Safety Management