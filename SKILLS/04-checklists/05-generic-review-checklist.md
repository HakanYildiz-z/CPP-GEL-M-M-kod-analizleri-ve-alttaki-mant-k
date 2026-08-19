# Genel İnceleme Kontrol Listesi / Generic Review Checklist

**Versiyon / Version:** 1.0
**Kaynak:** Google eng-practices (areas), Microsoft reviewer guidance, thoughtbot

---

## English

Use for every CL at MEDIUM/HIGH until criticality-specific checklists replace it.

### Design / Tasarım

- [ ] Change belongs in this module/place (not ad-hoc location).
- [ ] Integrates with existing architecture/patterns.
- [ ] Scope matches PR description; no unrelated changes.
- [ ] Simplest approach that satisfies the requirement.

### Logical Correctness / Mantıksal Doğruluk

- [ ] Algorithm correct; boundary conditions handled; off-by-one checked.
- [ ] State transitions valid; no partial writes on error.
- [ ] Floating point: no exact equality on computed values.

### Error Handling / Hata Yönetimi

- [ ] Every return value checked (no swallowing).
- [ ] Errors propagated with context; fail-secure on safety items.
- [ ] NULL, bounds, overflow checked.

### Security / Güvenlik

- [ ] Input validated; no secrets in code/logs.
- [ ] No race conditions on shared state.
- [ ] No `rand()` on security paths.

### Tests / Testler

- [ ] Tests accompany code in the SAME CL ("tests later" is unacceptable).
- [ ] Tests catch real failures; assumptions sensical.
- [ ] Edge cases covered; test data tracked.
- [ ] Tests deterministic (no order/global-state dependence).

### Readability & Naming / Okunurluk & İsimlendirme

- [ ] Names clear; no misleading abbreviations.
- [ ] Comments explain "why"; no obvious comments.
- [ ] Functions ≤ 60 lines, CC ≤ 10, nesting ≤ 4.

### Standards / Standartlar

- [ ] No magic numbers; constants named.
- [ ] No forbidden patterns (goto, RTTI, exceptions on host too if embedded-style).
- [ ] Header/Doxygen complete where required.

### Review discipline / İnceleme disiplini

- [ ] Findings carry prefixes `[CRITICAL]`/`[BLOCKING]`/`[Nit:]`/`[Question]`/`[Praise]`.
- [ ] Decision recorded (LGTM / Reject) in review record.

---

## Türkçe

Her MEDIUM/HIGH CL için, kritiklik-özel kontrol listeleri yerini alana kadar kullanılır.

### Tasarım

- [ ] Değişiklik bu modüle/konuma ait (ad-hoc konum değil).
- [ ] Mevcut mimari/desenlere entegre.
- [ ] Kapsam PR açıklamasıyla uyumlu; ilgisiz değişiklik yok.
- [ ] Gereksinimi karşılayan en basit yaklaşım.

### Mantıksal Doğruluk

- [ ] Algoritma doğru; sınır koşulları ele alındı; off-by-one kontrol edildi.
- [ ] Durum geçişleri geçerli; hatada kısmi yazma yok.
- [ ] Kayan nokta: hesaplanan değerlerde tam eşitlik yok.

### Hata Yönetimi

- [ ] Her dönüş değeri kontrol edildi (yutma yok).
- [ ] Hatalar bağlamla taşınıyor; güvenlik öğelerinde fail-secure.
- [ ] NULL, sınır, taşma kontrol edildi.

### Güvenlik

- [ ] Girdi doğrulandı; kodda/logda sır yok.
- [ ] Paylaşılan durumda race condition yok.
- [ ] Güvenlik yollarında `rand()` yok.

### Testler

- [ ] Testler kodla AYNI CL'de ("testler sonra" kabul edilemez).
- [ ] Testler gerçek hataları yakalıyor; varsayımlar mantıklı.
- [ ] Kenar durumlar ele alındı; test verisi takip edildi.
- [ ] Testler deterministik (sıra/global durum bağımlılığı yok).

### Okunurluk & İsimlendirme

- [ ] İsimler net; yanıltıcı kısaltma yok.
- [ ] Yorumlar "neden" açıklıyor; bariz yorum yok.
- [ ] Fonksiyon ≤ 60 satır, CC ≤ 10, iç içe ≤ 4.

### Standartlar

- [ ] Büyülü sayı yok; sabitler adlandırıldı.
- [ ] Yasak desenler yok (goto, RTTI, istisnalar).
- [ ] Gerekli yerlerde başlık/Doxygen eksiksiz.

### İnceleme disiplini

- [ ] Bulgular `[CRITICAL]`/`[BLOCKING]`/`[Nit:]`/`[Question]`/`[Praise]` önek taşıyor.
- [ ] Karar (LGTM / Red) inceleme kaydına işlendi.

---

**Sahip:** Kod Kalite Komitesi / Code Quality Committee