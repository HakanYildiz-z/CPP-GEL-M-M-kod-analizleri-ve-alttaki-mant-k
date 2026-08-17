# Yorum Kategorileri ve İşaretçiler / Comment Categories & Markers

**Versiyon / Version:** 1.0
**Kaynak:** Google (Nit: convention), Microsoft (clarity), Kimi (severity)

---

## English

Every review comment carries a mandatory prefix. This enables triage, dashboards, and audit evidence.

| Prefix | Meaning | Action required | Example |
|--------|---------|-----------------|---------|
| `[CRITICAL]` | Security vulnerability, functional error, standard violation | Resolve before LGTM | `[CRITICAL] buffer overflow risk; use sizeof().` |
| `[BLOCKING]` | Technical issue, gate failure | Resolve before LGTM | `[BLOCKING] coverage 60%, target 80%.` |
| `[Nit:]` | Style / naming / preference | Optional | `[Nit:] prefer 'temp_sensor' over 'tmp'.` |
| `[Question]` | Unclear point, request for explanation | Answer awaited | `[Question] does this loop satisfy REQ-1234?` |
| `[Praise]` | Well-done specific aspect | None (morale) | `[Praise] clean refactor.` |

### Writing Rules

1. **Polite but direct.** Not "I think maybe..." — "Here is a buffer overflow risk; fix it this way...".
2. **Give the "why"**: "change X because MISRA Dir 4.12 forbids it".
3. **Suggest, don't just flag**: include a concrete approach or code sample.
4. **Inline, not global**: comment on the exact line.
5. **Verifiable claims**: cite tool output, rule ID, or data. Never assert without evidence.
6. **No tone policing the person**: critique the code, never the author.
7. **Educational comments** are welcome but prefix `Nit:` so they are not blocking.

### Suggestion Quality

- When using "suggest changes", verify the suggestion compiles/tests when possible.
- Provide links (docs, commits, prior PRs) instead of relying on shared memory.
- Offer to pair on complex fixes.

### Review Enforcement

- Comment without prefix on a finding → author may `[Question]` it back; reviewer must fix.
- Ambiguous severity → default to `[Question]`, not `[BLOCKING]`.

---

## Türkçe

Her inceleme yorumu zorunlu bir önek taşır. Bu; triyajı, panoları ve denetim kanıtını mümkün kılar.

| Önek | Anlam | Gereken aksiyon | Örnek |
|--------|---------|-----------------|---------|
| `[CRITICAL]` | Güvenlik açığı, fonksiyonel hata, standart ihlali | LGTM öncesi çözülmeli | `[CRITICAL] buffer overflow riski; sizeof() kullan.` |
| `[BLOCKING]` | Teknik sorun, kapı başarısızlığı | LGTM öncesi çözülmeli | `[BLOCKING] kapsam %60, hedef %80.` |
| `[Nit:]` | Stil / isimlendirme / tercih | İsteğe bağlı | `[Nit:] 'tmp' yerine 'temp_sensor' tercih et.` |
| `[Question]` | Net olmayan nokta, açıklama talebi | Cevap beklenir | `[Question] bu döngü REQ-1234'ü sağlıyor mu?` |
| `[Praise]` | Özellikle iyi yapılmış kısım | Yok (moral) | `[Praise] temiz refactor.` |

### Yazım Kuralları

1. **Kibar ama net.** "Bence belki..." değil — "Burada buffer overflow riski var; şöyle düzeltin...".
2. **"Neden" ver**: "X'i değiştir çünkü MISRA Dir 4.12 yasaklıyor".
3. **Sadece işaretleme, öner**: somut yaklaşım veya kod örneği ekle.
4. **Satır içi, genel değil**: tam satıra yorum yap.
5. **Doğrulanabilir iddialar**: araç çıktısı, kural ID'si veya veri belirt. Kanıtsız asla iddia etme.
6. **Kişiyi yargılama**: kodu eleştir, asla yazarı.
7. **Eğitici yorumlar** memnuniyetle alınır ama engellememesi için `Nit:` öneki eklenir.

### Öneri Kalitesi

- "Değişiklik öner" kullanırken mümkünse önerinin derlenip test edildiğini doğrula.
- Ortak belleğe güvenme; link ver (dokümanlar, commit'ler, önceki PR'ler).
- Karmaşık düzeltmeler için pair çalışma teklif et.

### İncelemede Uygulama

- Öneksiz bulgu yorumu → yazar `[Question]` ile geri sorabilir; inceleyici düzeltmeli.
- Belirsiz şiddet → varsayılan `[Question]`, `[BLOCKING]` değil.

---

**Sahip / Owner:** Kod Kalite Komitesi / Code Quality Committee