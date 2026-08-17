# CL (Changelist) Metodolojisi / CL Methodology

**Versiyon / Version:** 1.0
**Kaynak:** Google eng-practices (CL structure), Kimi adaptasyon (savunma)

---

## English

### CL Definition

A CL is a single, self-contained, testable change. One CL = one feature **OR** one bugfix **OR** one refactor.

**Forbidden combinations:**
- Refactor + feature in one CL.
- Formatting + logic in one CL.
- Multiple unrelated bug fixes in one CL.

### CL Size

| Scope | Guideline |
|-------|-----------|
| Target | ≤ **200 lines** (excluding tests) |
| Rationale | Review quality degrades with size; small CLs are reviewed deeper. |
| Exception | Test data / generated artifacts; document in description. |

### Self-Review Before Submitting

```bash
git diff --cached | less
```

Checklist:
- [ ] I understand every line (can I explain it aloud?)
- [ ] Each line has a purpose; remove purposeless lines
- [ ] Comments explain "why" where non-obvious
- [ ] `make test` passed
- [ ] `make lint` clean (0 critical)
- [ ] `@requirement REQ-XXXX` tags present
- [ ] No magic numbers
- [ ] No error swallowing
- [ ] PR description complete (template: `08-templates/01-pr-template.md`)

### PR Description Essentials

1. **Summary** — 2–3 sentences on what & why.
2. **Requirement link** — `REQ-XXXX`.
3. **Safety level** — CRITICAL / HIGH / MEDIUM / LOW.
4. **Change type** — feature / bugfix / refactor / documentation.
5. **Tests** — what ran, coverage evidence.
6. **Review needs** — Tech Lead / Security Officer / standard.

### Review Enforcement

- > 200 lines (non-test) without justification → `[Question]` then `[BLOCKING]`.
- Refactor+feature combined → `[BLOCKING]` (split CL).
- Missing requirement link in safety module → `[BLOCKING]`.

---

## Türkçe

### CL Tanımı

CL tek, bağımsız, test edilebilir bir değişikliktir. Bir CL = bir özellik **VEYA** bir hata düzeltmesi **VEYA** bir refactor.

**Yasak kombinasyonlar:**
- Refactor + özellik aynı CL'de.
- Formatlama + mantık aynı CL'de.
- Birbiriyle ilgisiz birden fazla hata düzeltmesi aynı CL'de.

### CL Boyutu

| Kapsam | Yönlendirme |
|-------|-----------|
| Hedef | ≤ **200 satır** (testler hariç) |
| Gerekçe | İnceleme kalitesi boyutla düşer; küçük CL'ler daha derin incelenir. |
| İstisna | Test verisi / üretilmiş artefaktlar; açıklamada belirt. |

### Göndermeden Önce Öz-İnceleme

```bash
git diff --cached | less
```

Kontrol listesi:
- [ ] Her satırı anlıyorum (sesli anlatabilir miyim?)
- [ ] Her satırın amacı var; amaçsız satırları kaldırdım
- [ ] Yorumlar görünür olmayan yerlerde "neden" açıklıyor
- [ ] `make test` geçti
- [ ] `make lint` temiz (0 kritik)
- [ ] `@requirement REQ-XXXX` etiketleri var
- [ ] Büyülü sayı yok
- [ ] Hata yutma yok
- [ ] PR açıklaması eksiksiz (şablon: `08-templates/01-pr-template.md`)

### PR Açıklaması Esasları

1. **Özet** — nek & neden, 2–3 cümle.
2. **Gereksinim bağlantısı** — `REQ-XXXX`.
3. **Güvenlik seviyesi** — CRITICAL / HIGH / MEDIUM / LOW.
4. **Değişiklik tipi** — özellik / hata düzeltmesi / refactor / dokümantasyon.
5. **Testler** — neler çalıştı, kapsam kanıtı.
6. **İnceleme ihtiyacı** — Teknik Lider / Güvenlik Ofisörü / standart.

### İncelemede Uygulama

- Gerekçesiz > 200 satır (test dışı) → `[Question]` sonra `[BLOCKING]`.
- Refactor+özellik birleşik → `[BLOCKING]` (CL'yi böl).
- Güvenlik modülünde eksik gereksinim bağlantısı → `[BLOCKING]`.

---

**Sahip / Owner:** Kod Kalite Komitesi / Code Quality Committee