# MISRA Compliance:2020 Çerçevesi / MISRA Compliance:2020 Framework

**Versiyon / Version:** 1.0
**Uygulanan standartlar:** MISRA C:2012, MISRA C++:2008/2023, uniform MISRA Compliance:2020

---

## English

MISRA compliance is demonstrated through documented planning and enforcement, not by a green tool report alone. The framework has four artifacts.

### 1. Guideline Re-categorization Plan (GRP)

Maps every applicable MISRA guideline to a category for THIS project.

| Category | Meaning | Handling |
|----------|---------|----------|
| **Mandatory** | Cannot be deviated from. | Fix. Never deviate. |
| **Required** | Must be complied with; deviations require formal approval. | Fix or deviate with form. |
| **Advisory** | Optional; deviation discouraged. | Follow unless justified. |

Re-categorization MUST NOT lower Mandatory or weaken safety rules. Every change is itself reviewed.

### 2. Guideline Enforcement Plan (GEP)

Defines HOW each rule is enforced:

| Enforcement | Example |
|-------------|---------|
| Static analysis tool | PC-lint Plus rule set |
| Compiler messages | `-Werror` subset |
| Code review | Human check items in `04-checklists/` |
| Compile-time checks | `static_assert`, SFINAE barriers |

Every guideline has exactly one primary enforcement method with an owner.

### 3. Deviations

Each deviation record contains:

| Field | Requirement |
|-------|-------------|
| Deviation ID | Unique, linked to CL |
| Guideline ID | e.g., MISRA C:2012 Rule 2.2 |
| Category | Required (advisory deviations discouraged) |
| Justification | Technical rationale, not convenience |
| Risk mitigation | Compensating measures |
| Expiry | Time-bound; re-review required |
| Approvers | ≥2 qualified + safety representative for CRITICAL paths |
| Review evidence | Link to review record |

Rules: deviations are **never** carried silently; they are visible in the review; they require re-verification at expiry.

### 4. Compliance Report

Generated from GRP + GEP + deviation log + tool evidence. States per-SIL/DAL the percentage of guidelines enforced, pending deviations, and independence of checks.

---

## Türkçe

MISRA uyumluluğu dokümante planlama ve uygulama ile gösterilir; yalnızca yeşil araç raporuyla değil. Çerçevenin dört belgesi vardır.

### 1. Guideline Re-categorization Plan (GRP)

Her uygulanabilir MISRA kuralını BU proje için bir kategoriye eşler.

| Kategori | Anlam | İşleme |
|----------|---------|----------|
| **Mandatory** | Sapma yapılamaz. | Düzelt. Asla sapma. |
| **Required** | Uyulmalı; sapmalar resmi onay gerektirir. | Düzelt veya form ile sap. |
| **Advisory** | İsteğe bağlı; sapma teşvik edilmez. | Gerekçesizse uy. |

Yeniden kategorilendirme Mandatory'yi DÜŞÜREMEZ veya güvenlik kurallarını zayıflatamaz. Her değişiklik kendisi de incelenir.

### 2. Guideline Enforcement Plan (GEP)

Her kuralın NASIL uygulanacağını tanımlar:

| Uygulama | Örnek |
|-------------|---------|
| Statik analiz aracı | PC-lint Plus kural seti |
| Derleyici mesajları | `-Werror` alt kümesi |
| Kod incelemesi | `04-checklists/` içindeki insan kontrol maddeleri |
| Derleme zamanı kontrolleri | `static_assert`, SFINAE bariyerleri |

Her kuralın tam olarak birincil bir uygulama yöntemi ve sahibi vardır.

### 3. Sapmalar

Her sapma kaydı şunları içerir:

| Alan | Gereklilik |
|-------|-------------|
| Sapma ID'si | Benzersiz, CL'ye bağlı |
| Kural ID'si | ör., MISRA C:2012 Rule 2.2 |
| Kategori | Required (advisory sapma teşvik edilmez) |
| Gerekçe | Teknik rasyonel, kolaylık değil |
| Risk azaltımı | Telafi önlemleri |
| Bitiş tarihi | Zaman sınırlı; yeniden inceleme gerekir |
| Onaylayanlar | ≥2 nitelikli + CRITICAL yollarda güvenlik temsilcisi |
| İnceleme kanıtı | İnceleme kaydı bağlantısı |

Kurallar: sapmalar asla sessiz taşınmaz; incelemede görünür; bitişte yeniden doğrulama gerektirir.

### 4. Uyumluluk Raporu

GRP + GEP + sapma günlüğü + araç kanıtından üretilir. SIL/DAL başına uygulanan kural yüzdesini, bekleyen sapmaları ve kontrollerin bağımsızlığını belirtir.

---

**Sahip / Owner:** Kalite Mühendisliği / Quality Engineering