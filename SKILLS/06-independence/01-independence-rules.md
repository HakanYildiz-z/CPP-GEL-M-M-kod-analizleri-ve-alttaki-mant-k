# Bağımsızlık Kuralları / Independence Rules

**Versiyon / Version:** 1.0
**Kaynak:** DO-178C §6.2, DO-248C, IEC 61508-3 (Sil 3/4), ISO 26262-6 (confirmation measures)

---

## English

Independence prevents the author's blind spots from propagating. It is achieved via personnel (different people) or qualified tools (DO-330) with equivalence.

### Where Independence is Required

| Standard | Requirement |
|----------|-------------|
| DO-178C | DAL A: 16/31 verification objectives with independence; DAL B: 7/31. Reviewer ≠ developer. |
| IEC 61508 | SIL 3–4: formal inspection recommended/required; independent assessment; tools with SIL impact qualified. |
| ISO 26262 | Confirmation measures for ASIL C/D require an independent reviewer (competence + independence). |
| DEF-STAN 00-55 | Independence evidence for higher risk; separate personnel. |

### Rules

1. **Reviewer ≠ author**, always, for any criticality (at minimum a different human when independence is required).
2. **End-to-end independence** for DAL A objectives: the verifying person is not the developer and not the author of the verification plan they execute.
3. **Tool independence:** a DO-330-qualified tool may substitute for human independence with documented equivalence (DO-178C §6.2e).
4. **Chain independence:** a reviewer who approved the design of an item must normally be a different person from the one verifying its implementation.
5. **No self-approval** at any level: an author never approves their own CRITICAL-path code.

### Practical Implementation

- Two-reviewer flow for CRITICAL: author → reviewer 1 (design/semantics) → reviewer 2 (verification/evidence, independent of author).
- Rotate reviewer pairs per module.
- Document independence on the review record (`05-traceability/02`): names + roles.
- Conflict-of-interest declaration when a reviewer has stake in the result.

### Review Enforcement

- Missing independence statement on DAL A record → `[BLOCKING]`.
- Same person authored + verified DAL A code without tool evidence → `[CRITICAL]` process violation.
- COI undeclared → `[BLOCKING]`.

---

## Türkçe

Bağımsızlık, yazarın kör noktalarının yayılmasını önler. Personel (farklı kişiler) veya nitelikli araçlarla (DO-330) eşdeğerlik yoluyla sağlanır.

### Bağımsızlığın Gerektiği Yerler

| Standart | Gereklilik |
|----------|-------------|
| DO-178C | DAL A: 31 doğrulama amacının 16'sı bağımsız; DAL B: 31/7. İnceleyici ≠ geliştirici. |
| IEC 61508 | SIL 3–4: resmi muayene önerilir/gerekir; bağımsız değerlendirme; SIL etkili araçlar nitelikli. |
| ISO 26262 | ASIL C/D onay önlemleri bağımsız inceleyici gerektirir (yeterlilik + bağımsızlık). |
| DEF-STAN 00-55 | Yüksek risk için bağımsızlık kanıtı; ayrı personel. |

### Kurallar

1. **İnceleyici ≠ yazar**, her kritiklik için her zaman (bağımsızlık gerektiğinde asgari farklı insan).
2. DAL A amaçları için **uçtan uca bağımsızlık**: doğrulayan, geliştirici değil ve uyguladığı doğrulama planının yazarı değil.
3. **Araç bağımsızlığı:** DO-330 nitelikli araç, dokümante eşdeğerlikle insan bağımsızlığının yerine geçebilir (DO-178C §6.2e).
4. **Zincir bağımsızlığı:** bir öğenin tasarımını onaylayan inceleyici, genellikle uygulamasını doğrulayan kişiden farklı olmalıdır.
5. **Kendi kendine onay yok** her seviyede: yazar, CRITICAL yol kodunu asla kendisi onaylamaz.

### Pratik Uygulama

- CRITICAL için iki inceleyici akışı: yazar → inceleyici 1 (tasarım/anlambilim) → inceleyici 2 (doğrulama/kanıt, yazardan bağımsız).
- Modül başına inceleyici çiftlerini döndür.
- İnceleme kaydına bağımsızlığı işle (`05-traceability/02`): isimler + roller.
- İnceleyicinin sonuçta çıkarı varsa çıkar çatışması beyanı.

### İncelemede Uygulama

- DAL A kaydında eksik bağımsızlık beyanı → `[BLOCKING]`.
- Aynı kişinin DAL A kodunu araç kanıtı olmadan yazıp doğrulaması → `[CRITICAL]` süreç ihlali.
- Beyan edilmemiş çıkar çatışması → `[BLOCKING]`.

---

**Sahip:** Kalite Güvence / Quality Assurance