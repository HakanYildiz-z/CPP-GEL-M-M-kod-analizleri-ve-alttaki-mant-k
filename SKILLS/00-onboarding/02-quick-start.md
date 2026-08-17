# Hızlı Başlangıç / Quick Start

**Versiyon / Version:** 1.0

---

## English

### For New Developers

1. Read `00-onboarding/01-terminology.md` — internalize the vocabulary.
2. Read `01-standards/01-standard-hierarchy.md` — understand which standard applies when.
3. Read `01-standards/02-cpp-language-rules.md` and `03-naming-conventions.md`.
4. Read `02-review-process/01-cl-methodology.md` — CL sizing and self-review.
5. Copy the PR template from `08-templates/01-pr-template.md` and submit your first CL.

**Self-review checklist before submitting:**
- [ ] I understand every line I wrote (can I explain it out loud?)
- [ ] No line exists without a reason
- [ ] Comments explain "why", not just "what"
- [ ] Tests pass (`make test`)
- [ ] Static analysis clean (`make lint`)
- [ ] `@requirement REQ-XXXX` tag present in headers
- [ ] No magic numbers — all constants defined
- [ ] All error codes checked; no error swallowing

### For New Reviewers

1. Read `02-review-process/02-review-phases.md` — the 4-phase methodology.
2. Memorize `02-review-process/03-comment-categories.md` — mandatory prefixes.
3. Check authority limits in `06-independence/02-reviewer-qualification.md`.
4. Perform your first review with a mentor.

**First-review cardinal rule:** When in doubt, **ask** (`[Question]`) rather than assume. Never guess intent.

### For Auditors / Assessors

1. Verify a review record exists for every merged CL (`05-traceability/02-review-records.md`).
2. Verify traceability tags REQ→SRC→TST (`05-traceability/01-bidirectional-traceability.md`).
3. Verify independence rules for DAL A/B (16/31 objectives) (`06-independence/01-independence-rules.md`).
4. Verify MISRA Compliance:2020 artifacts (GRP/GEP/Deviations) (`04-checklists/06`).

---

## Türkçe

### Yeni Geliştiriciler İçin

1. `00-onboarding/01-terminology.md` oku — sözlüğü içselleştir.
2. `01-standards/01-standard-hierarchy.md` oku — hangi standardın ne zaman geçerli olduğunu anla.
3. `01-standards/02-cpp-language-rules.md` ve `03-naming-conventions.md` oku.
4. `02-review-process/01-cl-methodology.md` oku — CL boyutlandırma ve öz-inceleme.
5. PR şablonunu `08-templates/01-pr-template.md`'den kopyala ve ilk CL'ini gönder.

**Göndermeden önce öz-inceleme kontrol listesi:**
- [ ] Yazdığım her satırı anlıyorum (sesli anlatabilir miyim?)
- [ ] Gerekçesiz hiçbir satır yok
- [ ] Yorumlar "ne" değil "neden" açıklıyor
- [ ] Testler geçiyor (`make test`)
- [ ] Statik analiz temiz (`make lint`)
- [ ] Başlıklarda `@requirement REQ-XXXX` etiketi var
- [ ] Büyülü sayı yok — tüm sabitler tanımlı
- [ ] Tüm hata kodları kontrol edilmiş; hata yutma yok

### Yeni İnceleyiciler İçin

1. `02-review-process/02-review-phases.md` oku — 4 fazlı metodoloji.
2. `02-review-process/03-comment-categories.md` ezberle — zorunlu önekler.
3. `06-independence/02-reviewer-qualification.md`'den yetki sınırlarını kontrol et.
4. İlk incelemeni bir mentor eşliğinde yap.

**İlk inceleme değişmez kuralı:** Şüphedeysen varsayma; sor (`[Question]`). Niyet asla tahmin edilmez.

### Denetçiler / Değerlendiriciler İçin

1. Merge edilen her CL için inceleme kaydı olduğunu doğrula (`05-traceability/02-review-records.md`).
2. REQ→SRC→TST izlenebilirlik etiketlerini doğrula (`05-traceability/01-bidirectional-traceability.md`).
3. DAL A/B için bağımsızlık kurallarını doğrula (31 amacın 16'sı) (`06-independence/01-independence-rules.md`).
4. MISRA Compliance:2020 belgelerini doğrula (GRP/GEP/Deviation) (`04-checklists/06`).

---

**Sahip / Owner:** Teknik Mimari Kurulu / Technical Architecture Board