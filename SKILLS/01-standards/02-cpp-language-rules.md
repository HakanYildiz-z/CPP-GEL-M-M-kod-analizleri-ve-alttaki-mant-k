# C++ Dil Kuralları / C++ Language Rules

**Versiyon / Version:** 1.0

---

## English

### Forbidden Features (Embedded / Safety-Critical)

| Feature | Rule | Reason |
|---------|------|--------|
| RTTI (`dynamic_cast`, `typeid`) | **Forbidden** | Non-deterministic, bloats binary, unsafe with allocator-free environments. |
| Exceptions (`try`/`catch`/`throw`) | **Forbidden** (embedded) | Non-deterministic control flow, unbounded stack growth on fault. |
| `new` / `delete` | **Forbidden** (embedded) | Requires heap & allocation failure handling. Use static allocation or memory pools. |
| `goto` | **Forbidden** | Unstructured control flow (MISRA Dir 4.14). |
| Function pointers to non-static members | **Restricted** | Prefer `std::function` or virtual dispatch (MISRA Rule 17.2 in critical modules). |
| Standard I/O (`printf`, `scanf`, `cout`) | **Forbidden** in modules | Use project logging abstraction. `cout`/`cerr` only in host-side tools. (MISRA Rule 21.6) |
| C-style variable-length arrays (VLA) | **Forbidden** | Non-deterministic stack usage (MISRA Dir 4.12, Rule 21.12). |
| Multiple `return` in a single function path | **Restricted** | Single exit is recommended for critical modules (MISRA Rule 15.5 guidance). |

### Smart Pointer Rules

| Situation | Required Pattern |
|-----------|------------------|
| Exclusive ownership of heap object | `std::unique_ptr` (+ custom deleter for resources) |
| Shared ownership required | `std::shared_ptr` — justify; cycles require `std::weak_ptr` |
| Read-only access, no ownership | Raw reference / `std::weak_ptr::lock()` + `expired()` check |
| Resource (FILE, socket, mutex) | RAII wrapper or `std::unique_ptr<T, Deleter>` |

**Mandatory:** Prefer `std::make_unique` / `std::make_shared` over raw `new`. Never mix owned raw pointers with smart pointers.

### Type & Cast Rules

- Use `std::uint8_t/16_t/32_t/64_t` for explicit-width integers.
- `bool` for predicates; never store booleans as `int`.
- Casts: prefer `static_cast` (well-defined), then `const_cast`; use C-style casts **never** (MISRA Rule 2.5, Rule 11.5).
- Integer arithmetic: check overflow per CERT `INT30-C`, `INT32-C` (see `08-cert-c-security.md`).

### Concurrency

- Shared state → `std::atomic` or mutex + `std::lock_guard`/`std::scoped_lock`.
- Never use `volatile` for synchronization.
- Interrupt handlers must not allocate, lock, or call non-reentrant logging.

### Review Enforcement

Add finding with exact reference:
- `[CRITICAL] MISRA C++ Rule 15.0 ...` (control flow)
- `[BLOCKING] RTTI usage forbidden per MISRA Dir 4.12`
- `[BLOCKING] raw new in safety path; use make_shared`

---

## Türkçe

### Yasaklı Özellikler (Gömülü / Güvenlik-Kritik)

| Özellik | Kural | Gerekçe |
|---------|------|--------|
| RTTI (`dynamic_cast`, `typeid`) | **Yasak** | Deterministik değil, binary şişirir, allocator'sız ortamda güvensiz. |
| İstisnalar (`try`/`catch`/`throw`) | **Yasak** (gömülü) | Deterministik olmayan kontrol akışı, arızada sınırsız yığın büyümesi. |
| `new` / `delete` | **Yasak** (gömülü) | Heap ve tahsis hatası yönetimi gerektirir. Statik tahsis veya bellek havuzu kullan. |
| `goto` | **Yasak** | Yapısal olmayan kontrol akışı (MISRA Dir 4.14). |
| Statik olmayan üyeye fonksiyon pointer'ı | **Kısıtlı** | `std::function` veya sanal dağıtım tercih et (kritik modüllerde MISRA Rule 17.2). |
| Standart I/O (`printf`, `scanf`, `cout`) | **Modüllerde yasak** | Proje loglama soyutlaması kullan. `cout`/`cerr` yalnızca host tarafı araçlarda. (MISRA Rule 21.6) |
| C-tarzı değişken uzunluklu diziler (VLA) | **Yasak** | Deterministik olmayan yığın kullanımı (MISRA Dir 4.12, Rule 21.12). |
| Tek fonksiyonda çoklu `return` | **Kısıtlı** | Kritik modüller için tek çıkış önerilir (MISRA Rule 15.5 yönlendirmesi). |

### Akıllı İşaretçi Kuralları

| Durum | Gerekli Desen |
|-----------|------------------|
| Heap nesnesinde münhasır sahiplik | `std::unique_ptr` (+ kaynaklar için özel deleter) |
| Paylaşımlı sahiplik gerekli | `std::shared_ptr` — gerekçelendir; çevrimler `std::weak_ptr` gerektirir |
| Salt okunur erişim, sahiplik yok | Çıplak referans / `std::weak_ptr::lock()` + `expired()` kontrolü |
| Kaynak (FILE, soket, mutex) | RAII sarmalayıcı veya `std::unique_ptr<T, Deleter>` |

**Zorunlu:** Çıplak `new` yerine `std::make_unique` / `std::make_shared` tercih et. Sahipli çıplak pointer'ları akıllı işaretçilerle asla karıştırma.

### Tip ve Dönüşüm Kuralları

- Açık genişlikli tamsayılar için `std::uint8_t/16_t/32_t/64_t` kullan.
- Yüklemler için `bool`; boole'ları `int` olarak saklama.
- Dönüşümler: `static_cast` (iyi tanımlı) sonra `const_cast` tercih et; C-tarzı dönüşüm **asla** (MISRA Rule 2.5, Rule 11.5).
- Tamsayı aritmetiği: CERT `INT30-C`, `INT32-C`'ye göre taşma kontrolü (`08-cert-c-security.md`).

### Eşzamanlılık

- Paylaşılan durum → `std::atomic` veya mutex + `std::lock_guard`/`std::scoped_lock`.
- Senkronizasyon için `volatile` asla kullanma.
- Kesme işleyicileri bellek ayıramaz, kilit alamaz veya reentrant olmayan loglama çağıramaz.

### İncelemede Uygulama

Bulguya tam referans ekle:
- `[CRITICAL] MISRA C++ Rule 15.0 ...` (kontrol akışı)
- `[BLOCKING] RTTI usage forbidden per MISRA Dir 4.12`
- `[BLOCKING] raw new in safety path; use make_shared`

---

**Sahip / Owner:** Teknik Mimari Kurulu / Technical Architecture Board