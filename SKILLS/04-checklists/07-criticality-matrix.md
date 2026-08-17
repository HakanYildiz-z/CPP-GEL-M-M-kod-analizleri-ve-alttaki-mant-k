# Kritiklik Matrisi / Criticality Matrix

**Versiyon / Version:** 1.0

---

## English

Use this matrix to decide review depth, LGTM count, and sign-offs for any CL based on its criticality.

| Class | Example | Review depth | LGTM | Sign-offs | Coverage gate | Independence |
|-------|---------|--------------|------|-----------|---------------|--------------|
| **CRITICAL** | Flight control, fire control, crypto, interceptor guidance, hazard mitigation | Line-by-line + test + security + architecture | **2** | Security Officer + Tech Lead | MC/DC 100% (where applicable) | Required (DAL A/B 16/31; ASIL C/D) |
| **HIGH** | Sensor fusion, comms, navigation, safety-relevant state machines | Line-by-line + tests | **1** | Tech Lead | Branch/condition ≥ 90% | Recommended |
| **MEDIUM** | Logging, config, diagnostics | Overview + critical functions | **1** | Team lead (option) | Statement ≥ 80% | Not required |
| **LOW** | UI text, report templates, build config | Overview | **1** | — | Statement ≥ 50% | Not required |

### Review Depth Definitions

| Depth | Meaning |
|-------|---------|
| **Line-by-line** | Every line above the trivial threshold reviewed; logic, errors, security, tests. |
| **Overview + critical functions** | Full-file skim; deep review of functions on hot/safety paths only. |
| **Overview** | Scope, design, gate checks; line-level review only on flagged patterns. |

### Gate Map (per standard)

| Criticality | Correct review record? | Independence? | Static analysis | Tests |
|-------------|------------------------|---------------|-----------------|-------|
| CRITICAL (DAL A / SIL 4 / ASIL D) | 2 records, independent | Yes | 0 critical/high | MC/DC 100% |
| HIGH (DAL B / SIL 3 / ASIL C) | 1 record | 7/31 (DO-178C), confirmation (ISO) | 0 critical | Branch/condition |
| MEDIUM (DAL C / SIL 2 / ASIL B) | 1 record | Not required | 0 critical, plan HIGH | Statement |
| LOW (DAL D / SIL 1 / ASIL A) | 1 record | Not required | 0 critical | Compile + existing |

### Escalation

- Ambiguous class → assign the higher criticality class.
- Class downgrade requires Tech Lead + Safety Representative sign-off.
- Every downgrade is recorded (audit trail).

---

## Türkçe

Bu matrisi, herhangi bir CL için inceleme derinliğine, LGTM sayısına ve onaylara kritikliğine göre karar vermek için kullanın.

| Sınıf | Örnek | İnceleme derinliği | LGTM | Onaylar | Kapsam kapısı | Bağımsızlık |
|-------|---------|--------------|------|-----------|---------------|--------------|
| **CRITICAL** | Uçuş kontrolü, ateş kontrolü, kripto, önleme mühimmatı yönlendirme, tehlike azaltımı | Satır satır + test + güvenlik + mimari | **2** | Güvenlik Ofisörü + Teknik Lider | MC/DC %100 (uygulanabildiğinde) | Gerekir (DAL A/B 31/16; ASIL C/D) |
| **HIGH** | Sensör füzyonu, haberleşme, seyrüsefer, güvenlik-ilgili durum makineleri | Satır satır + testler | **1** | Teknik Lider | Branch/condition ≥ %90 | Önerilir |
| **MEDIUM** | Loglama, yapılandırma, tanılama | Genel bakış + kritik fonksiyonlar | **1** | Ekip lideri (opsiyonel) | Statement ≥ %80 | Gerekmez |
| **LOW** | UI metni, rapor şablonları, derleme yapılandırması | Genel bakış | **1** | — | Statement ≥ %50 | Gerekmez |

### İnceleme Derinliği Tanımları

| Derinlik | Anlam |
|-------|---------|
| **Satır satır** | Önemsizlik eşiğinin üstündeki her satır; mantık, hatalar, güvenlik, testler. |
| **Genel bakış + kritik fonksiyonlar** | Dosya tümünde tarama; yalnızca sıcak/güvenlik yollarındaki fonksiyonların derin incelemesi. |
| **Genel bakış** | Kapsam, tasarım, kapı kontrolleri; işaretli desenlerde yalnızca satır seviyesi. |

### Kapı Haritası (standartlara göre)

| Kritiklik | Doğru inceleme kaydı? | Bağımsızlık? | Statik analiz | Testler |
|-------------|------------------------|---------------|-----------------|-------|
| CRITICAL (DAL A / SIL 4 / ASIL D) | 2 kayıt, bağımsız | Evet | 0 kritik/yüksek | MC/DC %100 |
| HIGH (DAL B / SIL 3 / ASIL C) | 1 kayıt | 31/7 (DO-178C), onay (ISO) | 0 kritik | Branch/condition |
| MEDIUM (DAL C / SIL 2 / ASIL B) | 1 kayıt | Gerekmez | 0 kritik, HIGH planı | Statement |
| LOW (DAL D / SIL 1 / ASIL A) | 1 kayıt | Gerekmez | 0 kritik | Derleme + mevcut |

### Yükseltme

- Belirsiz sınıf → daha yüksek kritiklik sınıfı atanır.
- Sınıf düşürme, Teknik Lider + Güvenlik Temsilcisi onayı gerektirir.
- Her düşürme kaydedilir (denetim izi).

---

**Sahip:** Kod Kalite Komitesi / Code Quality Committee