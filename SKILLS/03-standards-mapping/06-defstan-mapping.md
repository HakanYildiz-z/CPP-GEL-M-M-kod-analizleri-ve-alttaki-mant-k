# DEF-STAN 00-55/56 Haritalaması / DEF-STAN 00-55/56 Mapping

**Versiyon / Version:** 1.0

---

## English

### Scope

UK MoD treats DO-178C as the primary means for safety-critical (programmable element, PE) software via DEF-STAN 00-55/56, permitting tailored application when the civil standard is at least as effective.

### Structure

- **DEF-STAN 00-56:** safety management requirements; defines Hazard Log, risk classification (frequency/severity), and safety case.
- **DEF-STAN 00-55:** requirements for safety-related software per the PES concept — underpins 00-56 with development rigor.

### Tailoring Rules

1. The PSAC (DO-178C) may partially satisfy the PE Safety Management Plan.
2. Tailoring must be documented and agreed — never silent deviation.
3. Multicore processors: AMC 20-193 is incorporated into Def Stan 00-970; review must check interference channels, non-determinism, cache partitioning.

### Review Activity Mappings

| DEF-STAN element | Code review action |
|------------------|--------------------|
| Hazard Log (00-56) | Each safety requirement traceable from hazard log to code/test |
| Safety case evidence | Review records as evidence items; arguments backed by analysis/tests |
| Formal process (00-55) | Formal inspections at higher risk; structured methods |
| Tool confidence | Tool qualification evidence (DO-330) |
| Multicore timing | Interference-channel review; WCET analysis evidence |

### Enforcement in Review

- Safety-related code with no hazard-log link → `[BLOCKING]`.
- MC safety arguments with no supporting analysis/test → `[CRITICAL]`.
- Dev vs. review independence not evidenced for SIL 4-equivalent → `[BLOCKING]`.

---

## Türkçe

### Kapsam

İngiltere MoD, sivil standardın en az eşdeğer etkili olduğu durumda uyarlanmış uygulamaya izin vererek, güvenlik-kritik (programlanabilir eleman, PE) yazılım için DO-178C'yi DEF-STAN 00-55/56 üzerinden birincil araç olarak ele alır.

### Yapı

- **DEF-STAN 00-56:** güvenlik yönetimi gereksinimleri; Tehlike Günlüğü'nü, risk sınıflandırmasını (sıklık/şiddet) ve güvenlik vakasını tanımlar.
- **DEF-STAN 00-55:** PES kavramına göre güvenlik-ilgili yazılım gereksinimleri — 00-56'yı geliştirme titizliğiyle destekler.

### Uyarlama Kuralları

1. PSAC (DO-178C), PE Güvenlik Yönetim Planı'nı kısmen karşılayabilir.
2. Uyarlama dokümante edilmeli ve üzerinde anlaşılmalı — asla sessiz sapma değil.
3. Çok çekirdekli işlemciler: AMC 20-193, Def Stan 00-970'ye dahildir; inceleme çakışma kanallarını, deterministik olmamayı, önbellek bölümlemeyi kontrol etmeli.

### İnceleme Aktivitesi Haritalaması

| DEF-STAN öğesi | Kod inceleme aksiyonu |
|------------------|--------------------|
| Tehlike Günlüğü (00-56) | Her güvenlik gereksinimi tehlike günlüğünden koda/teste izlenebilir |
| Güvenlik vakası kanıtı | İnceleme kayıtları kanıt öğesi olarak; argümanlar analiz/testle desteklenmeli |
| Resmi süreç (00-55) | Yüksek riskte resmi muayeneler; yapılandırılmış yöntemler |
| Araç güveni | Araç yeterlilik kanıtı (DO-330) |
| Çok çekirdekli zamanlama | Çakışma-kanalı incelemesi; WCET analizi kanıtı |

### İncelemede Uygulama

- Tehlike günlüğü bağlantısı olmayan güvenlik-ilgili kod → `[BLOCKING]`.
- Destekleyici analiz/test olmayan MC güvenlik argümanları → `[CRITICAL]`.
- SIL 4 eşdeğeri için geliştirme/inceleme bağımsızlığı kanıtlanmamış → `[BLOCKING]`.

---

**Sahip / Owner:** Uyumluluk Mühendisliği / Compliance Engineering