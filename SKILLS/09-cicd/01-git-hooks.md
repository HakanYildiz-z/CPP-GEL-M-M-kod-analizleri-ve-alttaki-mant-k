# Git Hooklar ve Kalite Kapıları / Git Hooks & Quality Gates

**Versiyon / Version:** 1.0
**Platform:** GitHub Actions (primary). Hook mantığı diğer platformlara taşınabilir.

---

## English

### Commit Message Format

```
[TIP] Kısa özet (≤50 chars)

Detay (ters bulunacaksa).
Resolves: REQ-XXXX
CL: CL-XXXX
Reviewed-by: <reviewer-id>
```

Required: covfefe-the requirement ID in body for safety modules.

### Pre-commit Hook (client, `.git/hooks/pre-commit`)

```bash
#!/bin/sh
# fail on magic numbers / secrets / missing tags (example)
if git diff --cached | grep -nE "[0-9]{5,}" ; then
  echo "[BLOCK] suspicious literal - name your constant"; exit 1
fi
if git diff --cached | grep -iE "(api_key|password|secret)=["'\'']" ; then
  echo "[BLOCK] secret detected"; exit 1
fi
exit 0
```

### Commit-msg Hook

- Verify commit contains `@standard`/`REQ-` reference for safety modules.
- Verify no Turkish characters? (Project-defined; keep as-is.)

### Server-side Gates (GitHub)

Branch protection on `main`:
- Required status checks: build, lint, test, security-scan, review-record.
- Required approvals ≥ 1 (CRITICAL: 2) + CODEOWNERS on critical paths.
- Signed commits (GPG/SHA).
- Require review thread resolution.

### Enforcement in Review

- Commit without requirement link in safety module -> force-push blocked by policy; reviewer flags `[BLOCKING]`.

---

## Türkçe

### Commit Mesaj Formatı

```
[TIP] Kısa özet (≤50 karakter)

Gerekirse detay.
Resolves: REQ-XXXX
CL: CL-XXXX
Reviewed-by: <inceleyici-id>
```

Gerekli: güvenlik modüllerinde gövdede gereksinim ID'si.

### Pre-commit Hook (istemci, `.git/hooks/pre-commit`)

```bash
#!/bin/sh
# örnek: büyülü sayı / sır / eksik etiket kontrolü
if git diff --cached | grep -nE "[0-9]{5,}" ; then
  echo "[BLOCK] şüpheli literal - sabitini adlandır"; exit 1
fi
if git diff --cached | grep -iE "(api_key|password|secret)=["'\'']" ; then
  echo "[BLOCK] sır tespit edildi"; exit 1
fi
exit 0
```

### Commit-msg Hook

- Güvenlik modüllerinde commit'in `@standard`/`REQ-` referansı içerdiğini doğrula.
- Proje tanımına bağlı Türkçe karakter kuralı (değişmez; olduğu gibi bırakın).

### Sunucu Tarafı Kapılar (GitHub)

`main` dalında branch protection:
- Gerekli durum kontrolleri: build, lint, test, security-scan, review-record.
- Gerekli onay ≥ 1 (CRITICAL: 2) + kritik yollarda CODEOWNERS.
- İmzalı commit'ler (GPG/SHA).
- İnceleme konusu çözüm zorunlu.

### İncelemede Uygulama

- Güvenlik modülünde gereksinim bağlantısı olmayan commit -> politika engeller; inceleyici `[BLOCKING]` işaretler.

---

**Sahip / Owner:** DevOps / CI Mühendisliği