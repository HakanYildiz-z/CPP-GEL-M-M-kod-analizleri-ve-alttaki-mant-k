# DAL C / D Kontrol Listesi / DAL C/D Checklist

**Versiyon / Version:** 1.0
**Uygulama:** DO-178C Seviye C (önemli) ve D (küçük). Bağımsızlık zorunlu değil; planlı inceleme yeterli. DAL C, DAL D'den daha titiz olsun.

---

## English

### DAL C (additional rigor on top of D items)

- [ ] Requirement trace present (`@requirement`) for changed modules.
- [ ] MISRA Mandatory: **0** violations; Required: deviations approved.
- [ ] Requirement-based tests; **statement coverage** measured and ≥ threshold.
- [ ] Static analysis: 0 critical; ≤ small HIGH backlog with plan.
- [ ] Review record complete; reviewer ≠ author standard.

### DAL D (common baseline)

- [ ] Change is scoped and documented; required files only.
- [ ] No error swallowing on changed behavior.
- [ ] No new magic numbers in modified lines.
- [ ] No secrets/PII exposure.
- [ ] Compile + existing tests green.

### Deviation policy

- Deviations for Required rules are permitted with form (`04-checklists/06`).

---

## Türkçe

### DAL C (D maddelerinin üzerine ek titizlik)

- [ ] Değiştirilen modüllerde gereksinim izi mevcut (`@requirement`).
- [ ] MISRA Mandatory: **0** ihlal; Required: sapmalar onaylı.
- [ ] Gereksinim tabanlı testler; **statement kapsamı** ölçüldü ve ≥ eşik.
- [ ] Statik analiz: 0 kritik; planla ≤ küçük HIGH backlog.
- [ ] İnceleme kaydı eksiksiz; inceleyici ≠ yazar standart.

### DAL D (ortak taban)

- [ ] Değişiklik kapsamlandı ve dokümante edildi; yalnızca gerekli dosyalar.
- [ ] Değiştirilen davranışta hata yutma yok.
- [ ] Değiştirilen satırlarda yeni büyülü sayı yok.
- [ ] Sır/PII sızıntısı yok.
- [ ] Derleme + mevcut testler yeşil.

### Sapma politikası

- Required kuralları için sapmalara form ile izin verilir (`04-checklists/06`).

---

**Sahip:** Uyumluluk Mühendisliği / Compliance Engineering