# Savunma Sanayisi Kod İnceleme SKILLS Paketi / Defense Industry Code Review SKILLS Package

**Versiyon / Version:** 1.0
**Tarih / Date:** 2026-08-18
**Standartlar / Standards:** DO-178C · MIL-STD-882E · IEC 61508 · ISO 26262 · DEF-STAN-00-55/56 · MIL-HDBK-516 · MISRA C/C++ · CERT C/C++ · CMMC · NIST SP 800-171

---

## English

This SKILLS package provides a professional, defense-industry-grade code review framework. It synthesizes best practices from Google Engineering Practices (`google/eng-practices`), Microsoft Code-with-Engineering-Playbook (`microsoft/code-with-engineering-playbook`), thoughtbot Guides (`thoughtbot/guides`), and the open source code review ecosystem (`joho/awesome-code-review`).

### Purpose

Establish a zero-compromise, fully professional, defense-compliant code review system. Every review produces auditable evidence suitable for certification authorities (FAA, EASA, MoD, national authorities).

### How to Use This Package

1. **New developers** → `00-onboarding/02-quick-start.md`
2. **Reviewers** → `02-review-process/` (phases, comment categories, LGTM criteria)
3. **Standards references** → `01-standards/` + `03-standards-mapping/`
4. **Checklists** → `04-checklists/`
5. **Traceability & records** → `05-traceability/`
6. **Templates** → `08-templates/`
7. **Automation** → `09-cicd/`
8. **AI-assisted review** → `10-ai-review/`
9. **Glossary & references** → `12-appendix/`

---

## Türkçe

Bu SKILLS paketi, savunma sanayisi seviyesinde profesyonel bir kod inceleme çerçevesi sunar. Google Engineering Practices (`google/eng-practices`), Microsoft Code-with-Engineering-Playbook (`microsoft/code-with-engineering-playbook`), thoughtbot Guides (`thoughtbot/guides`) ve açık kaynak kod inceleme ekosisteminden (`joho/awesome-code-review`) sentezlenen en iyi uygulamaları içerir.

### Amaç

Tavizsiz, %100 profesyonel ve savunma mevzuatına uyumlu bir kod inceleme sistemi kurmak. Her inceleme, sertifikasyon otoriteleri (FAA, EASA, MoD, ulusal otoriteler) için denetlenebilir kanıt üretir.

### Paket Nasıl Kullanılır

1. **Yeni geliştiriciler** → `00-onboarding/02-quick-start.md`
2. **İnceleyiciler** → `02-review-process/` (fazlar, yorum kategorileri, LGTM kriterleri)
3. **Standart referansları** → `01-standards/` + `03-standards-mapping/`
4. **Kontrol listeleri** → `04-checklists/`
5. **İzlenebilirlik ve kayıtlar** → `05-traceability/`
6. **Şablonlar** → `08-templates/`
7. **Otomasyon** → `09-cicd/`
8. **AI destekli inceleme** → `10-ai-review/`
9. **Sözlük ve kaynaklar** → `12-appendix/`

---

## Module Map / Modül Haritası

| Module | Purpose / Amaç | Audience / Hedef Kitle |
|--------|----------------|------------------------|
| `00-onboarding` | Terminology, quick-start / Terminoloji, hızlı başlangıç | All / Tüm ekip |
| `01-standards` | Coding standards, style, security / Kodlama standartları, stil, güvenlik | Developers / Geliştiriciler |
| `02-review-process` | Review methodology, LGTM, SLAs / İnceleme metodolojisi, onay, süreler | Reviewers, authors / İnceleyiciler, yazarlar |
| `03-standards-mapping` | 6 safety standards ↔ review matrix / 6 güvenlik standardı ↔ inceleme matrisi | Tech leads, auditors / Teknik liderler, denetçiler |
| `04-checklists` | DAL/SIL/ASIL/Security checklists / Kritiklik seviye kontrol listeleri | Reviewers / İnceleyiciler |
| `05-traceability` | REQ→DSN→SRC→TST, evidence, records / İzlenebilirlik, kanıt, kayıtlar | CM, tech leads / CM, teknik liderler |
| `06-independence` | Independence rules, reviewer qualification / Bağımsızlık kuralları, yeterlilik | QA, compliance / Kalite, uyumluluk |
| `07-tools` | Open source tool ecosystem / Açık kaynak araç ekosistemi | DevOps, developers |
| `08-templates` | PR, review record, deviation / PR, inceleme kaydı, sapma formları | All / Tüm ekip |
| `09-cicd` | Git hooks & quality gates / Kalite kapıları | DevOps |
| `10-ai-review` | AI-assisted review agents / AI destekli inceleme ajanları | Tech leads |
| `11-metrics` | KPIs & dashboards / Metrikler & panolar | Management / Yönetim |
| `12-appendix` | Glossary, references / Sözlük, kaynaklar | All / Tüm ekip |

---

## Ground Rules / Temel Kurallar

### English
1. This document is **not** a style guide—it is a decision framework.
2. Technical facts and data **overrule** opinions and personal preferences.
3. Style questions are settled by the standards in `01-standards/`; unresolved questions follow existing code.
4. Every review must produce a **review record** (`05-traceability/02-review-records.md`).
5. AI review output is **advisory**; final sign-off is always human.

### Türkçe
1. Bu doküman bir stil rehberi değil—bir karar çerçevesidir.
2. Teknik gerçekler ve veriler, görüşlere ve kişisel tercihlere **üstün gelir**.
3. Stil sorunları `01-standards/` içindeki standartlarla çözülür; çözülmezse mevcut kod takip edilir.
4. Her inceleme bir **inceleme kaydı** üretmelidir (`05-traceability/02-review-records.md`).
5. AI inceleme çıktısı **tavsiye niteliğindedir**; nihai onay her zaman insan tarafından verilir.

---

## Audit Trail / Denetim İzi

| Requirement | Where / Nerede |
|-------------|----------------|
| Traceability REQ→SRC→TST | `01-standards/05-comment-documentation.md`, `05-traceability/` |
| Review independence (DAL A/B) | `06-independence/01-independence-rules.md` |
| MISRA Compliance:2020 | `01-standards/09-misra-compliance-2020.md`, `04-checklists/06` |
| Evidence packages | `05-traceability/` |
| Record retention | `05-traceability/02-review-records.md` |

---

**Sahip / Owner:** Teknik Mimari Kurulu / Technical Architecture Board
**Son İnceleme / Last Reviewed:** 2026-08-18