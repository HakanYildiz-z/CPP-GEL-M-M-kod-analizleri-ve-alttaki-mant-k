# Terminoloji / Terminology

**Versiyon / Version:** 1.0

---

## English

This glossary defines the core terms used across the entire SKILLS package. Consistent use of these terms reduces ambiguity in reviews and is required for audit evidence.

| Term | Definition / Usage |
|------|--------------------|
| **CL** | Changelist — a single, self-contained, testable change (PR/patch). One CL = one feature OR one bugfix OR one refactor. |
| **LGTM** | "Looks Good To Me" — the reviewer's final approval expression. Conditional on all CRITICAL/BLOCKING items being resolved. |
| **Nit** | A non-blocking, optional style/preference comment. MUST be prefixed with `Nit:`. Purely educational comments are also prefixed `Nit:`. |
| **CRITICAL** | A finding that must be resolved before merge: security vulnerability, functional error, standard violation. |
| **BLOCKING** | A finding that must be resolved before merge: technical issue, coverage below threshold, broken CI. |
| **Readability** | Degree to which code is understandable by humans. Established via reviews, not personal opinion. |
| **Traceability** | The link between requirement → design → code → test at every level of the lifecycle. |
| **CM** | Configuration Management — version control, change control, baseline management. |
| **CCB** | Change Control Board — the formal body that approves changes to baselines. |
| **DAL** | Development Assurance Level (DO-178C): A (catastrophic) → E (no safety effect). |
| **SIL** | Safety Integrity Level (IEC 61508): SIL 1 (low) → SIL 4 (highest). |
| **ASIL** | Automotive Safety Integrity Level (ISO 26262): A (lowest) → D (highest), plus QM. |
| **MC/DC** | Modified Condition/Decision Coverage — required at DAL A and ASIL D for critical logic. |
| **STRIDE** | Threat modeling acronym: Spoofing, Tampering, Repudiation, Information disclosure, Denial of service, Elevation of privilege. |
| **MISRA GRP** | Guideline Re-categorization Plan — re-categorizes MISRA rules for a project. |
| **MISRA GEP** | Guideline Enforcement Plan — defines how each rule is enforced (tool, review, etc.). |
| **SARIF** | Static Analysis Results Interchange Format — standardized static analysis output. |
| **Deviation** | A formally justified, documented, time-limited and approved non-compliance with a rule. |
| **Independence** | Verification performed by personnel/tools other than the developer. Mandatory for DAL A/B objectives. |

### Key Principles

1. A CL with any unresolved `CRITICAL` or `BLOCKING` finding **shall not** receive LGTM.
2. A `Nit:` comment is never a merge blocker.
3. Pure style points follow the standards; otherwise accept the author's style.

---

## Türkçe

Bu sözlük, SKILLS paketinin tamamında kullanılan temel terimleri tanımlar. Terimlerde tutarlılık, incelemelerde belirsizliği azaltır ve denetim kanıtı için zorunludur.

| Terim | Tanım / Kullanım |
|------|--------------------|
| **CL** | Changelist — tek, bağımsız, test edilebilir değişiklik (PR/patch). Bir CL = bir özellik VEYA bir hata düzeltmesi VEYA bir refactor. |
| **LGTM** | "Looks Good To Me" — inceleyicinin nihai onay ifadesi. Tüm CRITICAL/BLOCKING bulguların çözülmesine bağlıdır. |
| **Nit** | Engelleyici olmayan, isteğe bağlı stil/tercih yorumu. `Nit:` öneki ile yazılmalıdır. Tamamen eğitici yorumlar da `Nit:` ile ön eklenir. |
| **CRITICAL** | Merge öncesi çözülmesi zorunlu bulgu: güvenlik açığı, fonksiyonel hata, standart ihlali. |
| **BLOCKING** | Merge öncesi çözülmesi zorunlu bulgu: teknik sorun, eşik altı kapsam, bozuk CI. |
| **Readability** | Kodun insan tarafından anlaşılabilirlik düzeyi. İncelemelerle sağlanır, kişisel görüşle değil. |
| **Traceability** | Yaşam döngüsünün her aşamasında gereksinim → tasarım → kod → test bağlantısı. |
| **CM** | Konfigürasyon Yönetimi — versiyon kontrolü, değişiklik kontrolü, baseline yönetimi. |
| **CCB** | Change Control Board — baselinlere yapılan değişiklikleri onaylayan resmi kurul. |
| **DAL** | Development Assurance Level (DO-178C): A (katastrofik) → E (güvenlik etkisi yok). |
| **SIL** | Safety Integrity Level (IEC 61508): SIL 1 (düşük) → SIL 4 (en yüksek). |
| **ASIL** | Automotive Safety Integrity Level (ISO 26262): A (en düşük) → D (en yüksek), artı QM. |
| **MC/DC** | Modified Condition/Decision Coverage — DAL A ve ASIL D kritik mantık için zorunlu. |
| **STRIDE** | Tehdit modelleme kısaltması: Spoofing (kimlik taklidi), Tampering (kurcalama), Repudiation (inkar), Information disclosure (bilgi sızıntısı), Denial of service (hizmet reddi), Elevation of privilege (yetki yükseltme). |
| **MISRA GRP** | Guideline Re-categorization Plan — MISRA kurallarının proje için yeniden kategorilendirilmesi. |
| **MISRA GEP** | Guideline Enforcement Plan — her kuralın nasıl uygulanacağını tanımlar (araç, inceleme vb.). |
| **SARIF** | Static Analysis Results Interchange Format — standart statik analiz çıktı formatı. |
| **Deviation** | Bir kural ihlaline resmi gerekçeli, dokümante, süre sınırlı ve onaylı istisna. |
| **Independence** | Deneyimin, geliştiriciden başka personel/araçlarla yapılması. DAL A/B amaçları için zorunludur. |

### Temel İlkeler

1. Çözülmemiş `CRITICAL` veya `BLOCKING` bulgu içeren bir CL **LGTM alamaz**.
2. `Nit:` yorumu asla merge engelleyicisi değildir.
3. Saf stil noktaları standartlara uyar; aksi halde yazarın stili kabul edilir.

---

**Sahip / Owner:** Teknik Mimari Kurulu / Technical Architecture Board