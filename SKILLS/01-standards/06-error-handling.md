# Hata Yönetimi / Error Handling

**Versiyon / Version:** 1.0

---

## English

### Core Rules

1. **Every error code checked.** No error swallowing. (MISRA Rule 5.3 directive culture; CERT `ERR00-C`.)
2. **Error codes propagated** up the call chain; never transformed to `void` silently.
3. **Early return** on error; keep happy path dominant.
4. **Log with context** on every handled error: value of the failing parameter, error code, function.
5. **Fail secure:** on error, transition to a safe state; never continue with partial data.
6. **One error handling mechanism** per module — exceptions XOR error codes (embedded: error codes).

### Pattern

```cpp
// DO: check + early return + context log
int32_t result = sensor_read(&data);
if (result != ERR_NONE) {
    LOG_ERROR("sensor_read failed: code=%d sensor_id=%d", result, cfg.id);
    return result;
}

// DON'T: swallow
sensor_read(&data);                       // return value ignored — FORBIDDEN

// DON'T: ambiguity
if (sensor_read(&data)) { /* what does non-zero mean? */ }
```

### Error Taxonomy (recommended code ranges)

| Range | Meaning |
|-------|---------|
| `0` | Success |
| `-1` | Generic failure |
| `ERR_NULL_POINTER` | NULL passed despite precondition |
| `ERR_OUT_OF_RANGE` | Value outside contract |
| `ERR_TIMEOUT` | Resource did not respond |
| `ERR_BUSY` | Resource locked/in use |
| `ERR_SECURITY_VIOLATION` | Access/input validation failure |
| `ERR_NO_MEMORY` | Allocation failure (config-only paths) |

### Boundary Conditions

- Check array bounds before indexing (CERT `ARR30-C`).
- Check integer overflow before arithmetic (CERT `INT30-C`).
- Validate ALL external input (CERT `INT04-C`, `STR04-C`).
- NULL-check pointers before dereference.

### Concurrency & Errors

- Never return to an inconsistent state after a failed lock/unlock.
- Keep critical sections minimal; no allocation inside locks.
- Logging must be reentrant-safe in interrupt contexts.

### Review Enforcement

- Ignored return value on safety-relevant call → `[CRITICAL]`.
- Error swallowed with `(void)` or empty block → `[BLOCKING]`.
- Missing bounds/NULL check on external input → `[CRITICAL]`.
- Unclear error mapping (magic negative numbers) → `[BLOCKING]`.

---

## Türkçe

### Temel Kurallar

1. **Her hata kodu kontrol edilir.** Hata yutma yok. (MISRA Rule 5.3 kültürü; CERT `ERR00-C`.)
2. **Hata kodları** çağrı zincirinde yukarı taşınır; sessizce `void`'e çevrilmez.
3. Hatalarda **erken return**; mutlu yol baskın kalır.
4. Ele alınan her hatada **bağlamla logla**: başarısız parametre değeri, hata kodu, fonksiyon.
5. **Fail secure:** hata durumunda güvenli duruma geç; kısmi veriyle asla devam etme.
6. Modül başına **tek hata mekanizması** — istisna XOR hata kodu (gömülü: hata kodu).

### Desen

```cpp
// DO: kontrol + erken return + bağlamlı log
int32_t result = sensor_read(&data);
if (result != ERR_NONE) {
    LOG_ERROR("sensor_read failed: code=%d sensor_id=%d", result, cfg.id);
    return result;
}

// DON'T: yutma
sensor_read(&data);                       // dönüş değeri yok sayıldı — YASAK

// DON'T: belirsizlik
if (sensor_read(&data)) { /* sıfır olmaması ne demek? */ }
```

### Hata Taksonomisi (önerilen kod aralıkları)

| Aralık | Anlam |
|-------|---------|
| `0` | Başarı |
| `-1` | Genel arıza |
| `ERR_NULL_POINTER` | Ön koşula rağmen NULL geçildi |
| `ERR_OUT_OF_RANGE` | Değer sözleşme dışında |
| `ERR_TIMEOUT` | Kaynak yanıt vermedi |
| `ERR_BUSY` | Kaynak kilitli/kullanımda |
| `ERR_SECURITY_VIOLATION` | Erişim/girdi doğrulama başarısızlığı |
| `ERR_NO_MEMORY` | Tahsis başarısızlığı (yalnızca config yolları) |

### Sınır Koşulları

- Dizi indekslemeden önce sınır kontrolü (CERT `ARR30-C`).
- Aritmetikten önce tamsayı taşması kontrolü (CERT `INT30-C`).
- TÜM dış girdiyi doğrula (CERT `INT04-C`, `STR04-C`).
- Dereference öncesi pointer NULL kontrolü.

### Eşzamanlılık ve Hatalar

- Başarısız kilit/kilitleme açmadan sonra tutarsız duruma asla dönme.
- Kritik bölümleri minimumda tut; kilit içinde tahsis yok.
- Kesme bağlamlarında loglama reentrant-güvenli olmalı.

### İncelemede Uygulama

- Güvenlik-ilgili çağrıda yok sayılan dönüş değeri → `[CRITICAL]`.
- `(void)` veya boş blok ile yutulan hata → `[BLOCKING]`.
- Dış girdide eksik sınır/NULL kontrolü → `[CRITICAL]`.
- Belirsiz hata eşlemesi (büyülü negatif sayılar) → `[BLOCKING]`.

---

**Sahip / Owner:** Teknik Mimari Kurulu / Technical Architecture Board