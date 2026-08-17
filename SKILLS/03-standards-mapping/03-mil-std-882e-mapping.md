# MIL-STD-882E Haritalaması / MIL-STD-882E Mapping

**Versiyon / Version:** 1.0

---

## English

### Scope

MIL-STD-882E (System Safety) requires hazards to be identified and risk reduced to acceptable levels. Software review must demonstrate that the code cannot invalidate the hazard mitigation claim.

### Hazard → Software Review Chain

```
Hazard Analysis (HARA) ──► Safety Requirements ──► Software Requirements
        │                                                   │
        ▼                                                   ▼
  Mitigation (eliminate/control)                  Code review checks the
        │                                    safety requirements actually encoded
        ▼
  Verification (M_T, SAL)                 + hazard-relevant paths identified
```

### MIL-STD-882E → Review Activity

| Standard element | Code review action |
|------------------|--------------------|
| Hazard identification/tracking | Trace each safety requirement to code + test; no orphan requirements |
| Risk assessment (severity/probability) | Classify each CL by resulting risk change; trigger depth per `04-lgtm-criteria` |
| Risk mitigation (elimination > reduction > control) | Verify mitigation implemented; e.g., guards, interlocks, failsafe default |
| Safety measure traceability | `@safety_level` + `@requirement` tags on mitigation code |
| Verification tasks (M_T/M_P) | Test evidence that mitigation behaves under fault injection |
| Change analysis | Re-assess hazard impact on EVERY change (incl. refactor) |

### Itertailored Review Rules

1. **Hazard-adjacent code** reviews at CRITICAL depth, regardless of LOC.
2. **Mitigation code** must have fault-injection tests (see `04-checklists/05`), reviewed for sufficiency.
3. **Risk-reduction claim** in PR description: "how does this change affect identified hazards?"
4. **No golden plating:** mitigation must be minimal and verifiable, not speculative.

### Enforcement in Review

- Code changing hazard-relevant behavior without a traceability note → `[BLOCKING]`.
- Mitigation that cannot be verified by test → `[CRITICAL]` open finding.
- Refactor silently altering timing on a hazard-relevant path → `[CRITICAL]`.

---

## Türkçe

### Kapsam

MIL-STD-882E (Sistem Güvenliği), tehlikelerin tanımlanmasını ve riskin kabul edilebilir seviyeye indirilmesini gerektirir. Kod incelemesi, kodun tehlike azaltım iddiasını geçersiz kılamayacağını göstermelidir.

### Tehlike → Kod İnceleme Zinciri

```
Tehlike Analizi (HARA) ──► Güvenlik Gereksinimleri ──► Yazılım Gereksinimleri
        │                                                   │
        ▼                                                   ▼
  Azaltım (eliminasyon/kontrol)                   Kod incelemesi güvenlik
        │                                    gereksinimlerinin gerçekten
        ▼                                    kodlandığını kontrol eder
  Doğrulama (M_T, SAL)                 + tehlike-ilgili yollar tanımlanır
```

### MIL-STD-882E → İnceleme Aktivitesi

| Standart öğesi | Kod inceleme aksiyonu |
|------------------|--------------------|
| Tehlike tanımlama/takip | Her güvenlik gereksinimini koda + teste izle; yetim gereksinim olmasın |
| Risk değerlendirmesi (şiddet/olasılık) | Her CL'yi sonuç risk değişimine göre sınıflandır; derinliği `04-lgtm-criteria`'ya göre tetikle |
| Risk azaltımı (eliminasyon > azaltma > kontrol) | Azaltımın uygulandığını doğrula; ör. guard, interlock, failsafe varsayılan |
| Güvenlik önlemi izlenebilirliği | Azaltım kodunda `@safety_level` + `@requirement` etiketleri |
| Doğrulama görevleri (M_T/M_P) | Hata enjeksiyonu altında azaltımın davrandığına dair test kanıtı |
| Değişiklik analizi | HER değişiklikte (refactor dahil) tehlike etkisini yeniden değerlendir |

### Uyarlanmış İnceleme Kuralları

1. **Tehlike-ilişik kod**, satır sayısından bağımsız olarak CRITICAL derinlikte incelenir.
2. **Azaltım kodu** hata enjeksiyon testine sahip olmalı (bkz. `04-checklists/05`); yeterliliği incelenmeli.
3. PR açıklamasında **risk azaltım iddiası**: "bu değişiklik tanımlı tehlikeleri nasıl etkiler?"
4. **Altın kaplama yok:** azaltım minimal ve doğrulanabilir olmalı, spekülatif değil.

### İncelemede Uygulama

- Tehlike-ilgili davranışı izlenebilirlik notu olmadan değiştiren kod → `[BLOCKING]`.
- Testle doğrulanamayan azaltım → `[CRITICAL]` açık bulgu.
- Tehlike-ilgili yolda zamanlamayı sessizce değiştiren refactor → `[CRITICAL]`.

---

**Sahip / Owner:** Güvenlik Mühendisliği / Safety Engineering