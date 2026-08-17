# LGTM Kriterleri ve Kritiklik Matrisi / LGTM Criteria & Criticality Matrix

**Versiyon / Version:** 1.0
**Kaynak:** Google (areas of review), Kimi (criticality matrix), Microsoft (evidence)

---

## English

### LGTM Grant Conditions (ALL must hold)

- [ ] Change improves the codebase vs. its current state.
- [ ] All `[CRITICAL]` and `[BLOCKING]` findings resolved.
- [ ] CI pipeline green.
- [ ] Static analysis clean (0 critical/high).
- [ ] Tests pass; coverage at/above threshold for its criticality.
- [ ] Traceability complete (REQ tag present; tests verified).
- [ ] Required sign-offs obtained (Security Officer for critical code; Tech Lead per matrix).

### LGTM Refusal Reasons

Reject when ANY of:
1. Compile error or test failure.
2. Static analysis critical finding.
3. Unresolved `[CRITICAL]`/`[BLOCKING]`.
4. Missing traceability in a safety module.
5. Evidence of unverified behavior in critical logic.
6. Author ignored an agreed process (missing PR template data).

### Review Depth by Criticality

| Category | Example | Review depth | LGTM count | Extra sign-offs |
|----------|---------|--------------|------------|-----------------|
| **CRITICAL** | Flight control, fire control, crypto, interceptor guidance | Line-by-line + test + security + architecture + independence (DAL A/B) | **2** | Security Officer |
| **HIGH** | Sensor fusion, communications, navigation | Line-by-line + tests | **1** | — |
| **MEDIUM** | Logging, configuration | Overview + critical functions | **1** | — |
| **LOW** | UI text, report templates | Overview | **1** | — |

### Velocity / Quality SLA

| CL type | Target response | Depth | Notes |
|---------|-----------------|-------|-------|
| Emergency hotfix | ≤ 2 hours | Full | Parallel dual review |
| CRITICAL | ≤ 4 hours | Full + security | Security review mandatory |
| HIGH | ≤ 1 workday | Full | Standard flow |
| MEDIUM/LOW | ≤ 2 workdays | Overview + key functions | Standard flow |

### Review Enforcement

- Single LGTM on CRITICAL path with no Security Officer sign-off → process violation; record in review log.

---

## Türkçe

### LGTM Verme Koşulları (hepsi sağlanmalı)

- [ ] Değişiklik, kod tabanını mevcut durumuna göre iyileştiriyor.
- [ ] Tüm `[CRITICAL]` ve `[BLOCKING]` bulgular çözüldü.
- [ ] CI pipeline yeşil.
- [ ] Statik analiz temiz (0 kritik/yüksek).
- [ ] Testler geçiyor; kapsam kritikliği için eşiğin üstünde.
- [ ] İzlenebilirlik eksiksiz (REQ etiketi var; testler doğrulandı).
- [ ] Gerekli onaylar alındı (kritik kod için Güvenlik Ofisörü; matrise göre Teknik Lider).

### LGTM Yönessme Nedenleri

Aşağıdakilerden HERHANGİ biri varken reddet:
1. Derleme hatası veya test başarısızlığı.
2. Statik analiz kritik bulgusu.
3. Çözülmemiş `[CRITICAL]`/`[BLOCKING]`.
4. Güvenlik modülünde eksik izlenebilirlik.
5. Kritik mantıkta doğrulanmamış davranış kanıtı.
6. Yazar, üzerinde anlaşılan süreci atladı (eksik PR şablon verisi).

### Kritikliğe Göre İnceleme Derinliği

| Kategori | Örnek | İnceleme derinliği | LGTM sayısı | Ek onaylar |
|----------|---------|--------------|------------|-----------------|
| **CRITICAL** | Uçuş kontrolü, ateş kontrolü, kripto, önleme mühimmatı yönlendirme | Satır satır + test + güvenlik + mimari + bağımsızlık (DAL A/B) | **2** | Güvenlik Ofisörü |
| **HIGH** | Sensör füzyonu, haberleşme, seyrüsefer | Satır satır + testler | **1** | — |
| **MEDIUM** | Loglama, yapılandırma | Genel bakış + kritik fonksiyonlar | **1** | — |
| **LOW** | UI metni, rapor şablonları | Genel bakış | **1** | — |

### Hız / Kalite SLA

| CL tipi | Hedef yanıt | Derinlik | Notlar |
|---------|-----------------|-------|-------|
| Acil hotfix | ≤ 2 saat | Tam | Paralel çift inceleme |
| CRITICAL | ≤ 4 saat | Tam + güvenlik | Güvenlik incelemesi zorunlu |
| HIGH | ≤ 1 iş günü | Tam | Standart akış |
| MEDIUM/LOW | ≤ 2 iş günü | Genel + anahtar fonksiyonlar | Standart akış |

### İncelemede Uygulama

- Güvenlik Ofisörü onayı olmadan CRITICAL yolda tek LGTM → süreç ihlali; inceleme günlüğüne kaydet.

---

**Sahip / Owner:** Kod Kalite Komitesi / Code Quality Committee