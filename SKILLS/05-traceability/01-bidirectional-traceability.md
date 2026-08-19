# Çift Yönlü İzlenebilirlik / Bidirectional Traceability

**Versiyon / Version:** 1.0
**Kaynak:** DO-178C §6.4, ISO 26262 Part 6 Annex A, IEC 61508 Annex A, Kimi adaptasyon

---

## English

Traceability is the backbone of certification evidence. Every requirement must be linked forward (to design, code, test) and backward (to its origin).

### Chain

```
REQ (Requirement) → DSN (Design) → SRC (Code) → TST (Test) → [Results]
```

### Tags (mandatory)

| Tag | Location | Direction |
|-----|----------|-----------|
| `@requirement REQ-XXXX` | Header + function | REQ → SRC |
| `@traceability DSN-XXXX` | Header | DSN → SRC |
| `@verifies REQ-XXXX` | Test file | SRC → TST |
| `@safety_level` | Header | classification |

### Matrix Template

| REQ ID | DSN ID | SRC (file:line) | TST (file) | Test type | Result link |
|--------|--------|-----------------|-----------|-----------|-------------|
| REQ-0001 | DSN-0010 | `nav.c:45` | `test_nav.c` | Unit | `TR-0001` |
| REQ-0002 | DSN-0020 | `sns.c:120` | `test_sns.c` | Integration | `TR-0002` |

### Per-CL Checks

- [ ] At least one requirement reference exists (REQ).
- [ ] `@requirement` tag in code; `@verifies` in tests.
- [ ] No orphan requirements (requirement with no code/test).
- [ ] No orphan code (code with no requirement).
- [ ] Change impact analysis maps affected requirements.

### Tooling

- CM/ALM traces: DOORS, Jama, or traceability matrix (XLSX/CSV auto-generated from tags).
- CI gate: script fails on missing tag in safety modules.

### Review Enforcement

- Missing REQ tag in safety module → `[BLOCKING]`.
- Orphan code/req discovered → `[BLOCKING]` + problem report.
- Trace broken after refactor → `[BLOCKING]`.

---

## Türkçe

İzlenebilirlik, sertifikasyon kanıtının bel kemiğidir. Her gereksinim ileri (tasarıma, koda, teste) ve geri (kaynağına) bağlanmalıdır.

### Zincir

```
REQ (Gereksinim) → DSN (Tasarım) → SRC (Kod) → TST (Test) → [Sonuçlar]
```

### Etiketler (zorunlu)

| Etiket | Konum | Yön |
|-----|----------|-----------|
| `@requirement REQ-XXXX` | Başlık + fonksiyon | REQ → SRC |
| `@traceability DSN-XXXX` | Başlık | DSN → SRC |
| `@verifies REQ-XXXX` | Test dosyası | SRC → TST |
| `@safety_level` | Başlık | sınıflandırma |

### Matris Şablonu

| REQ ID | DSN ID | SRC (dosya:satır) | TST (dosya) | Test tipi | Sonuç bağlantısı |
|--------|--------|-----------------|-----------|-----------|-------------|
| REQ-0001 | DSN-0010 | `nav.c:45` | `test_nav.c` | Birim | `TR-0001` |
| REQ-0002 | DSN-0020 | `sns.c:120` | `test_sns.c` | Entegrasyon | `TR-0002` |

### CL Başına Kontroller

- [ ] En az bir gereksinim referansı var (REQ).
- [ ] Kodda `@requirement`; testte `@verifies` etiketi.
- [ ] Yetim gereksinim yok (kodu/testi olmayan gereksinim).
- [ ] Yetim kod yok (gereksinimi olmayan kod).
- [ ] Değişiklik etki analizi etkilenen gereksinimleri eşler.

### Araçlar

- CM/ALM izleri: DOORS, Jama veya etiketlerden otomatik üretilen izlenebilirlik matrisi (XLSX/CSV).
- CI kapısı: güvenlik modüllerinde eksik etikette script hatası.

### İncelemede Uygulama

- Güvenlik modülünde eksik REQ etiketi → `[BLOCKING]`.
- Yetim kod/req tespiti → `[BLOCKING]` + sorun raporu.
- Refactor sonrası kopan iz → `[BLOCKING]`.

---

**Sahip:** CM Mühendisliği / Configuration Management