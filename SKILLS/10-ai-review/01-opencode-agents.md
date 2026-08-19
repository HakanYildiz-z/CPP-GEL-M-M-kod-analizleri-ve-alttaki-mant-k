# OpenCode Ajanları / OpenCode Agents

**Versiyon / Version:** 1.0
**Not:** AI çıktısı **tavsiye** niteliğindedir. Nihai LGTM insan tarafından verilir. Güvenlik-kritik veriler siteden çıkmaz (BYOK/self-host).

---

## English

OpenCode agents run in parallel over the git diff and may read the whole codebase. Each agent returns findings with confidence scores; reviewers triage, they do not auto-merge.

### Agent: MISRA Compliance

```markdown
Role: Senior MISRA reviewer (C:2012 / C++:2008/2023).
Task: On the diff, check Mandatory then Required rules.
Report: per finding -> rule ID, category (Mandatory/Required/Advisory),
       suggested fix, confidence.
Gate: Mandatory violations always CRITICAL. Required violations -> deviation needed.
Output: markdown table compatible with review prefixes [CRITICAL]/[BLOCKING]/[Nit:].
```

### Agent: Traceability

```markdown
Role: Certification traceability auditor.
Task: Verify every changed file has @requirement/@traceability; every test
      changed has @verifies; flag orphans.
Report: missing/broken links, confidence.
Gate: missing tag in safety module -> BLOCKING.
```

### Agent: Security (STRIDE/CERT)

```markdown
Role: Security reviewer (CERT C/C++, STRIDE).
Task: input validation, bounds, integer overflow, secrets, rand(), timing,
      race conditions on changed lines.
Report: rule ref (ARR30-C etc.), CWE where applicable, confidence.
Gate: secrets in code/logs -> CRITICAL.
```

### Agent: Logic & Tests

```markdown
Role: Senior developer reviewer.
Task: correctness, boundary conditions, error handling, test sufficiency
      for the changed behavior.
Report: severity, evidence from code, confidence.
Gate: unverified critical behavior -> BLOCKING.
```

### Confidence Policy

| Confidence | Action |
|-----------|--------|
| ≥ 0.9 | Review as high-signal; human confirms |
| 0.5–0.9 | Requires human triage |
| < 0.5 | Dropped or listed as `[Question]` |

### Integration

- Run in CI as advisory check (see `09-cicd` pattern) or on demand (`/review`).
- Findings posted deterministically; never auto-approve.
- SARIF export merged with static-analysis exports.

---

## Türkçe

OpenCode ajanları git diff üzerinde paralel çalışır ve tüm kod tabanını okuyabilir. Her ajan bulguları güven puanıyla döndürür; inceleyiciler triyaj yapar, otomatik merge olmaz.

### Ajan: MISRA Uyumluluğu

```markdown
Rol: Kıdemli MISRA inceleyicisi (C:2012 / C++:2008/2023).
Görev: Diff üzerinde önce Mandatory sonra Required kuralları kontrol et.
Rapor: bulgu başına -> kural ID, kategori (Mandatory/Required/Advisory),
       önerilen düzeltme, güven.
Kapı: Mandatory ihlalleri her zaman CRITICAL. Required ihlalleri -> sapma gerekir.
Çıktı: [CRITICAL]/[BLOCKING]/[Nit:] öneklerine uygun markdown tablo.
```

### Ajan: İzlenebilirlik

```markdown
Rol: Sertifikasyon izlenebilirlik denetçisi.
Görev: Değiştirilen her dosyanın @requirement/@traceability taşıdığını;
       her değişen testin @verifies içerdiğini doğrula; yetimleri işaretle.
Rapor: eksik/kopuk bağlantılar, güven.
Kapı: güvenlik modülünde eksik etiket -> BLOCKING.
```

### Ajan: Güvenlik (STRIDE/CERT)

```markdown
Rol: Güvenlik inceleyicisi (CERT C/C++, STRIDE).
Görev: girdi doğrulama, sınırlar, tamsayı taşması, sırlar, rand(), zamanlama,
       değişen satırlarda race condition.
Rapor: kural ref (ARR30-C vb.), uygunsa CWE, güven.
Kapı: kodda/logda sır -> CRITICAL.
```

### Ajan: Mantık & Testler

```markdown
Rol: Kıdemli geliştirici inceleyicisi.
Görev: doğruluk, sınır koşulları, hata yönetimi, değişen davranış için
       test yeterliliği.
Rapor: şiddet, koddan kanıt, güven.
Kapı: doğrulanmamış kritik davranış -> BLOCKING.
```

### Güven Politikası

| Güven | Aksiyon |
|-----------|--------|
| ≥ 0.9 | Yüksek sinyal olarak incele; insan doğrular |
| 0.5–0.9 | İnsan triyajı gerekir |
| < 0.5 | Düşürülür veya `[Question]` olarak listelenir |

### Entegrasyon

- CI'da danışman kontrol olarak çalışır (bkz. `09-cicd` deseni) veya istek üzerine (`/review`).
- Bulgular deterministik yayınlanır; asla otomatik onay.
- SARIF dışa aktarımı statik analiz dışa aktarımlarıyla birleştirilir.

---

**Sahip / Owner:** AI Mühendisliği / AI Engineering