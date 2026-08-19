# Sözlük / Glossary

**Versiyon / Version:** 1.0

---

## English

### Review Terms / İnceleme Terimleri

| Term | EN definition | TR tanım |
|------|---------------|----------|
| CL | Changelist — a single self-contained testable change | Tek, bağımsız, test edilebilir değişiklik |
| LGTM | Looks Good To Me — reviewer approval | İnceleyici onayı |
| Nit: | Non-blocking optional comment | Engelleyici olmayan isteğe bağlı yorum |
| CRITICAL | Must fix before merge (security/functional/std) | Merge öncesi çözülmesi zorunlu |
| BLOCKING | Must fix before merge (technical/gate) | Merge öncesi çözülmesi zorunlu (teknik) |
| CB | Change Board / CCB | Değişiklik onay kurulu |
| CM | Configuration Management | Konfigürasyon yönetimi |
| Traceability | Req↔design↔code↔test links | İzlenebilirlik bağları |
| Review record | Certification evidence of a review | İncelemenin sertifikasyon kanıtı |

### Standardization Terms / Standart Terimleri

| Term | Meaning | TR |
|------|---------|----|
| DAL | Development Assurance Level (DO-178C): A–E | Geliştirme güvence seviyesi |
| DAL A | Catastrophic failure condition; highest rigor | Katastrofik; en yüksek titizlik |
| DAL B | Hazardous; independent verification (7/31) | Tehlikeli; bağımsız doğrulama |
| SIL | Safety Integrity Level (IEC 61508): 1–4 | Güvenlik bütünlüğü seviyesi |
| ASIL | Automotive SIL (ISO 26262): A–D, QM | Otomotiv SIL |
| MC/DC | Modified Condition/Decision Coverage | Değiştirilmiş koşul/karar kapsamı |
| WCET | Worst-case execution time | En kötü durum çalışma süresi |
| FTTI/FTI | Fault-tolerant time interval / fault-tolerant interval | Hata toleranslı zaman aralığı |
| PSSA/SSA | Preliminary/system safety assessment | Ön/sistem güvenlik değerlendirmesi |

### Security Terms / Güvenlik Terimleri

| Term | Meaning | TR |
|------|---------|----|
| STRIDE | Spoofing/Tampering/Repudiation/Info disclosure/DoS/Elevation | Tehdit modeli akronimi |
| CWE | Common Weakness Enumeration | Ortak zayıflık numaralandırması |
| SBOM | Software Bill of Materials | Yazılım malzeme listesi |
| SARIF | Static Analysis Results Interchange Format | Statik analiz sonuç değişim formatı |
| PII/EUII | Personally identifiable info / End-user identifiable info | Kişisel tanımlayıcı bilgi |

### MISRA Terms / MISRA Terimleri

| Term | Meaning | TR |
|------|---------|----|
| GRP | Guideline Re-categorization Plan | Kural yeniden kategorizasyon planı |
| GEP | Guideline Enforcement Plan | Kural uygulama planı |
| Deviation | Approved, time-limited non-compliance | Onaylı, süre sınırlı sapma |
| Mandatory | Cannot be deviated from | Sapma yapılamaz |

### Process Terms / Süreç Terimleri

| Term | Meaning | TR |
|------|---------|----|
| Self-review | Author checks own CL before submit | Yazarın kendi CL'sini göndermeden kontrolü |
| Round-trip | One author↔reviewer iteration | Bir yazar↔inceleyici turu |
| Independence | Verification by non-developer (or qualified tool) | Yazar dışı doğrulama |
| Tailoring | Documented adaptation of a standard | Standardın dokümante uyarlaması |

---

**Sahip / Owner:** Teknik Mimari Kurulu / Technical Architecture Board