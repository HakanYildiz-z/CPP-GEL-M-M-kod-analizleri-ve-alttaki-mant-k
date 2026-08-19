# Güvenlik Kontrol Listesi / Security Checklist (STRIDE)

**Versiyon / Version:** 1.0
**Kaynak:** STRIDE + CERT C/C++ + OWASP Embedded + CMMC/NIST SP 800-171

---

## English

### Input Validation (Girdi Doğrulama)

- [ ] All external input treated as hostile; validated before use.
- [ ] Length bounds checked; no unbounded copy (STR31-C).
- [ ] Numeric ranges validated (INT04-C); no implicit type widening on security paths.
- [ ] Failure of validation → fail secure; log SECURITY event.

### Memory & Pointer Safety

- [ ] No buffer overflow/underflow (ARR30-C).
- [ ] No use-after-free; RAII/smart pointers on heap paths (MEM30/31-C).
- [ ] NULL checked before dereference.
- [ ] No VLA; no unbounded recursion in security-critical code.

### Cryptography & Keys

- [ ] Keys stored in HSM/secure storage — **never** in source.
- [ ] Approved algorithms only (per contract: AES-256-GCM, SHA-3, etc.).
- [ ] Crypto RNG used; `rand()` forbidden (MSC30-C).
- [ ] No hardcoded IVs/secrets; no keylogging.

### Communication

- [ ] TLS 1.3 or contract-defined secure protocol.
- [ ] Mutual authentication; X.509v3 certs validated.
- [ ] Replay protection (nonce/sequence numbers); integrity (MAC) on messages.

### Concurrency & Timing

- [ ] No race conditions on shared state; atomics/mutexes correct.
- [ ] No deadlock/livelock paths in changed code.
- [ ] Timing-attack resistant branches on secrets.
- [ ] Side-channel (power/cache) considered per system threat model.

### Logging & Secrets

- [ ] No PII/EUII, credentials, or keys in logs or error messages (NIST 800-171).
- [ ] Logs tamper-resistant; WORM where required.
- [ ] Error messages reveal no internal paths/secrets.

### Dependency & Supply Chain

- [ ] Third-party deps scanned for CVEs (0 critical/high).
- [ ] SBOM generated (CycloneDX/SPDX).
- [ ] No untracked/vendored suspicious code.

### Review Enforcement

| Finding | Severity |
|---------|----------|
| Secret in source/log | `[CRITICAL]` |
| Unvalidated input on security path | `[CRITICAL]` |
| CVE critical in new dependency | `[BLOCKING]` |
| Timing attack on secret compare | `[CRITICAL]` |
| Missing replay protection | `[BLOCKING]` |

---

## Türkçe

### Girdi Doğrulama

- [ ] Tüm dış girdi düşmanca kabul edilir; kullanımdan önce doğrulanır.
- [ ] Uzunluk sınırları kontrol edildi; sınırsız kopya yok (STR31-C).
- [ ] Sayısal aralıklar doğrulandı (INT04-C); güvenlik yollarında örtük tip genişletme yok.
- [ ] Doğrulama başarısızlığı → fail secure; SECURITY olayı logla.

### Bellek & Pointer Güvenliği

- [ ] Buffer overflow/underflow yok (ARR30-C).
- [ ] Use-after-free yok; heap yollarında RAII/akıllı işaretçi (MEM30/31-C).
- [ ] Dereference öncesi NULL kontrolü.
- [ ] VLA yok; güvenlik-kritik kodda sınırsız özyineleme yok.

### Kripto & Anahtarlar

- [ ] Anahtarlar HSM/güvenli depolamada — **asla** kaynakta değil.
- [ ] Yalnızca onaylı algoritmalar (sözleşmeye göre: AES-256-GCM, SHA-3 vb.).
- [ ] Kriptografik RNG kullanılır; `rand()` yasak (MSC30-C).
- [ ] Sabit IV/sır yok; keylogging yok.

### İletişim

- [ ] TLS 1.3 veya sözleşme tanımlı güvenli protokol.
- [ ] Karşılıklı kimlik doğrulama; X.509v3 sertifikalar doğrulanıyor.
- [ ] Replay koruması (nonce/sıra numarası); mesajlarda bütünlük (MAC).

### Eşzamanlılık & Zamanlama

- [ ] Paylaşılan durumda race condition yok; atomikler/mutex'ler doğru.
- [ ] Değiştirilen kodda deadlock/livelock yolu yok.
- [ ] Sırlar üzerinde zamanlama-saldırısına dayanıklı dallar.
- [ ] Yan kanal (güç/önbellek) sistem tehdit modeline göre ele alındı.

### Loglama & Sırlar

- [ ] Loglarda veya hata mesajlarında PII/EUII, kimlik veya anahtar yok (NIST 800-171).
- [ ] Loglar kurcalamaya dayanıklı; gerekirse WORM.
- [ ] Hata mesajları iç yolları/sırları açığa çıkarmıyor.

### Bağımlılık & Tedarik Zinciri

- [ ] Üçüncü taraf bağımlılıklar CVE tarandı (0 kritik/yüksek).
- [ ] SBOM üretildi (CycloneDX/SPDX).
- [ ] İzlenmeyen/şüpheli satılan kod yok.

### İncelemede Uygulama

| Bulgu | Şiddet |
|---------|----------|
| Kaynakta/logda sır | `[CRITICAL]` |
| Güvenlik yolunda doğrulanmamış girdi | `[CRITICAL]` |
| Yeni bağımlılıkta kritik CVE | `[BLOCKING]` |
| Sır karşılaştırmasında zamanlama saldırısı | `[CRITICAL]` |
| Eksik replay koruması | `[BLOCKING]` |

---

**Sahip:** Bilgi Güvenliği Ofisörü / CISO