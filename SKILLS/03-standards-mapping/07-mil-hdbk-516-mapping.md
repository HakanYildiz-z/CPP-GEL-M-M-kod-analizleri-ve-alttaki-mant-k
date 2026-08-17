# MIL-HDBK-516 Haritalaması / MIL-HDBK-516 Mapping

**Versiyon / Version:** 1.0

---

## English

### Scope

MIL-HDBK-516 (Airworthiness Certification Criteria) defines certification criteria for military aircraft. Software contributes via airworthiness criteria linked to performance/safety; MIL-STD-882E provides the safety process, DO-178C the software assurance.

### Airworthiness ↔ Software Review

| Criterion area | Code review action |
|----------------|--------------------|
| Flight-critical software | DO-178C compatibility per item (deviation with documented equivalence) |
| System safety | Hazard mitigation in code + verification (per MIL-STD-882E) |
| Human-systems integration | Cautions/warnings logic verified; no silent override |
| Structural/system performance | Timing/WCET evidence on flight-critical paths |
| Software airworthiness criteria | Certification evidence = review records + analyses + tests |

### Integration Practice (SafeCode guidance)

The gap: hazard analysis lives on the system side, SW requirements on the software side. Code review is where the boundary is verified:

1. For each software safety requirement → cite its hazard origin.
2. For each hazard mitigation in code → confirm the mitigation test exists.
3. Any change → re-run the boundary check (per change analysis).

### Review Activity Mappings

| MIL-HDBK-516 element | Code review action |
|----------------------|--------------------|
| Airworthiness criteria → SW items | Map each item's DAL; evidence per DO-178C objectives |
| Performance/criticality interface | Review timing analysis; identify WCET-affecting changes |
| Civil airspace interoperability (DO-278A) | Where applicable, add CNS/ATM-specific review items |
| Safety case linkage | Each review record referenced by the safety case |

### Enforcement in Review

- SW item without an assigned DAL/airworthiness criterion → `[Question]` then `[BLOCKING]`.
- Flight-critical timing change without WCET evidence → `[BLOCKING]`.
- Mitigation verified only by inspection (no test) on flight-critical path → `[CRITICAL]`.

---

## Türkçe

### Kapsam

MIL-HDBK-516 (Uçuşa Elverişlilik Sertifikasyon Kriterleri), askeri uçaklar için sertifikasyon kriterlerini tanımlar. Yazılım, performans/güvenlikle bağlantılı uçuşa elverişlilik kriterleriyle katkıda bulunur; MIL-STD-882E güvenlik sürecini, DO-178C yazılım güvencesini sağlar.

### Uçuşa Elverişlilik ↔ Kod İnceleme

| Kriter alanı | Kod inceleme aksiyonu |
|----------------|--------------------|
| Uçuş-kritik yazılım | Öğe başına DO-178C uyumu (dokümante eşdeğerlik ile sapma) |
| Sistem güvenliği | Kodda tehlike azaltımı + doğrulama (MIL-STD-882E'ye göre) |
| İnsan-sistem entegrasyonu | Uyarı/ikaz mantığı doğrulanır; sessiz geçersiz kılma yok |
| Yapısal/sistem performansı | Uçuş-kritik yollarda zamanlama/WCET kanıtı |
| Yazılım uçuşa elverişlilik kriterleri | Sertifikasyon kanıtı = inceleme kayıtları + analizler + testler |

### Entegrasyon Pratiği (SafeCode yönlendirmesi)

Boşluk: tehlike analizi sistem tarafında, yazılım gereksinimleri yazılım tarafında yaşar. Kod incelemesi sınırın doğrulandığı yerdir:

1. Her yazılım güvenlik gereksinimi → tehlike kaynağını belirt.
2. Kodda her tehlike azaltımı → azaltım testinin var olduğunu onayla.
3. Her değişiklik → sınır kontrolünü yeniden çalıştır (değişiklik analizi uyarınca).

### İnceleme Aktivitesi Haritalaması

| MIL-HDBK-516 öğesi | Kod inceleme aksiyonu |
|----------------------|--------------------|
| Uçuşa elverişlilik kriterleri → YZ öğeleri | Her öğenin DAL'ını eşle; her DO-178C amacı için kanıt |
| Performans/kritiklik arayüzü | Zamanlama analizini gözden geçir; WCET etkileyen değişiklikleri belirle |
| Sivil hava sahası birlikte çalışabilirlik (DO-278A) | Uygulanabilirse CNS/ATM-özel inceleme öğeleri ekle |
| Güvenlik vakası bağlantısı | Her inceleme kaydı güvenlik vakası tarafından referanslanır |

### İncelemede Uygulama

- DAL/uçuşa elverişlilik kriteri atanmamış YZ öğesi → `[Question]` sonra `[BLOCKING]`.
- WCET kanıtı olmadan uçuş-kritik zamanlama değişikliği → `[BLOCKING]`.
- Uçuş-kritik yolda yalnızca incelemeyle doğrulanan (testsiz) azaltım → `[CRITICAL]`.

---

**Sahip / Owner:** Uçuşa Elverişlilik Mühendisliği / Airworthiness Engineering