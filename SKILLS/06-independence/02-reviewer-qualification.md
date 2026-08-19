# İnceleyici Yeterliliği / Reviewer Qualification

**Versiyon / Version:** 1.0
**Kaynak:** IEC 61508 (competence), ISO 26262-8 (competence management), DO-178C (SQA)

---

## English

A reviewer's finding is only as credible as their competence. Defense programs must evidence competence per reviewer role.

### Competence Matrix

| Domain | Required knowledge | Evidence |
|--------|--------------------|----------|
| C/C++ language mastery | Modern C++, undefined behavior, memory model | Certification/training + sample reviews |
| MISRA C/C++ | Rule sets, project GRP/GEP | MISRA training + audit-approved reviews |
| CERT C/C++ | Memory/integer/string rules | Training + reviewed findings |
| Target platform | Embedded RTOS, memory map, interrupts | Project experience |
| Domain safety | Avionics/defense domain hazards | Domain qualification |
| Review method | 4-phase method, prefixes, records | Onboarding + mentor sign-off |

### Roles & Progression

| Level | Capability | Can review |
|-------|-----------|------------|
| Reviewer (R1) | Method + standards | LOW/MEDIUM |
| Senior Reviewer (R2) | + architecture, security | HIGH |
| Lead Reviewer (R3) | + independence, evidence, DAL A/B | CRITICAL (with confirmation) |
| Subject Matter Expert (SME) | + niche domain | Specific items |

### Rules

1. **CRITICAL paths** are only signed off by R3 (Lead); SME if applicable.
2. **Retraining** after standard changes (e.g., MISRA 2012 -> 2023).
3. **Mentored reviews** count toward qualification; new reviewer's first reviews are jointly signed.
4. **Competence evidence** retained in HR/training files and referenced on records.

### Training Required

- New author: 4h onboarding + standards reading.
- New reviewer: 8h method + 3 mentored reviews.
- Lead reviewer: + independence, evidence, audit simulation.
- All: annual refresher + update on standards/tool changes.

### Review Enforcement

- Review by a not-yet-qualified person on HIGH/CRITICAL -> process violation; record + requalify.

---

## Türkçe

Bir inceleyicinin bulgusu ancak yeterliliği kadar güvenilirdir. Savunma programları rol başına yeterliliği kanıtlamalıdır.

### Yeterlilik Matrisi

| Alan | Gerekli bilgi | Kanıt |
|--------|--------------------|----------|
| C/C++ dil hakimiyeti | Modern C++, tanımsız davranış, bellek modeli | Sertifika/eğitim + örnek incelemeler |
| MISRA C/C++ | Kural setleri, projenin GRP/GEP'i | MISRA eğitimi + denetim-onaylı incelemeler |
| CERT C/C++ | Bellek/tamsayı/string kuralları | Eğitim + incelenen bulgular |
| Hedef platform | Gömülü RTOS, bellek haritası, kesmeler | Proje deneyimi |
| Alan güvenliği | Havacılık/savunma alanı tehlikeleri | Alan yeterliliği |
| İnceleme yöntemi | 4 fazlı yöntem, önekler, kayıtlar | Onboarding + mentor onayı |

### Roller ve İlerleme

| Seviye | Yetenek | İnceleyebilir |
|-------|-----------|------------|
| İnceleyici (R1) | Yöntem + standartlar | LOW/MEDIUM |
| Kıdemli İnceleyici (R2) | + mimari, güvenlik | HIGH |
| Lider İnceleyici (R3) | + bağımsızlık, kanıt, DAL A/B | CRITICAL (onay ile) |
| Uzman (SME) | + niş alan | Belirli öğeler |

### Kurallar

1. **CRITICAL yollar** yalnızca R3 (Lider) tarafından onaylanır; uygunsa SME.
2. Standart değişikliklerinden sonra **yeniden eğitim** (ör. MISRA 2012 -> 2023).
3. **Mentorlu incelemeler** yeterliliğe sayılır; yeni inceleyicinin ilk incelemeleri ortak imzalanır.
4. **Yeterlilik kanıtı** İK/eğitim dosyalarında saklanır ve kayıtlarda referanslanır.

### Gerekli Eğitim

- Yeni yazar: 4s onboarding + standart okuma.
- Yeni inceleyici: 8s yöntem + 3 mentorlu inceleme.
- Lider inceleyici: + bağımsızlık, kanıt, denetim simülasyonu.
- Hepsi: yıllık tazeleme + standart/araç değişiklik güncellemesi.

### İncelemede Uygulama

- HIGH/CRITICAL'de henüz nitelikli olmayan kişinin incelemesi -> süreç ihlali; kayıt + yeniden yeterlendirme.

---

**Sahip:** Kalite Güvence / Quality Assurance