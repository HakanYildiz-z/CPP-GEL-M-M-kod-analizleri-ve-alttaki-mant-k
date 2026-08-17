# Standart Hiyerarşisi / Standard Hierarchy

**Versiyon / Version:** 1.0

---

## English

When a conflict exists between standards, the hierarchy below decides. The contract always governs; the most restrictive applicable standard wins at the same level.

```
1.  Müşteri Sözleşmesi / SOW (Customer Contract / Statement of Work)   ← Highest authority
2.  DO-178C (Avionics) | ISO 26262 (Automotive) | IEC 61508 (Industrial)
3.  MIL-STD-882E (System Safety) | DEF-STAN-00-55/56 | MIL-HDBK-516 (Airworthiness)
4.  CMMC / NIST SP 800-171 (Cybersecurity)
5.  MISRA C:2012 | MISRA C++:2008/2023
6.  CERT C / CERT C++ (SEI secure coding)
7.  Company Coding Standard (this package)                             ← Lowest, most specific
```

### Resolution Rules

| # | Situation | Decision |
|---|-----------|----------|
| 1 | Contract specifies a standard | Contract wins. Always. |
| 2 | Two standards conflict at same level | The **more restrictive** applies. Document the conflict. |
| 3 | Safety standard vs. security standard | Safety wins for safety-critical paths; security wins for security-critical paths. Document the boundary. |
| 4 | MISRA Rule vs. CERT Rule | Both apply. Satisfy the union, not the intersection. |
| 5 | Standard silent on a topic | Company standard (`01-standards/`) fills the gap. |

### Apply on Review

- State the governing standard in each CL: `// @standard DO-178C DAL A + MISRA C:2012`
- When rejecting a change, cite the exact rule ID (e.g., `MISRA Dir 4.12`).
- When in conflict, escalate per `02-review-process/` conflict procedure.

---

## Türkçe

Standartlar arasında çakışma olduğunda aşağıdaki hiyerarşi karar verir. Sözleşme her zaman üstündür; aynı seviyede uygulanabilir en kısıtlayıcı standart geçerlidir.

```
1.  Müşteri Sözleşmesi / SOW                                       ← En yüksek yetki
2.  DO-178C (Havacılık) | ISO 26262 (Otomotiv) | IEC 61508 (Endüstriyel)
3.  MIL-STD-882E (Sistem Güvenliği) | DEF-STAN-00-55/56 | MIL-HDBK-516 (Uçuşa Elverişlilik)
4.  CMMC / NIST SP 800-171 (Siber Güvenlik)
5.  MISRA C:2012 | MISRA C++:2008/2023
6.  CERT C / CERT C++ (SEI güvenli kodlama)
7.  Şirket Kodlama Standardı (bu paket)                            ← En alt, en spesifik
```

### Çözüm Kuralları

| # | Durum | Karar |
|---|-------|-------|
| 1 | Sözleşme bir standart belirtir | Sözleşme kazanır. Her zaman. |
| 2 | Aynı seviyede iki standart çakışır | **Daha kısıtlayıcı** olan uygulanır. Çakışmayı dokümante et. |
| 3 | Güvenlik standardı vs. siber güvenlik standardı | Güvenlik kritik yollarda güvenlik; güvenlik kritik yollarda siber güvenlik. Sınırı dokümante et. |
| 4 | MISRA Kuralı vs. CERT Kuralı | İkisi de uygulanır. Kesişimi değil birleşimi karşıla. |
| 5 | Standart konuda sessiz | Şirket standardı (`01-standards/`) boşluğu doldurur. |

### İncelemede Uygulama

- Her CL'de geçerli standardı belirt: `// @standard DO-178C DAL A + MISRA C:2012`
- Değişikliği reddederken tam kural ID'sini belirt (ör. `MISRA Dir 4.12`).
- Çakışmada `02-review-process/` anlaşmazlık prosedürünü uygula.

---

**Sahip / Owner:** Teknik Mimari Kurulu / Technical Architecture Board