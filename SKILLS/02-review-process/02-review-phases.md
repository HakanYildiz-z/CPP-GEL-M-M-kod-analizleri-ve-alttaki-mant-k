# İnceleme Fazları / Review Phases

**Versiyon / Version:** 1.0
**Kaynak:** Google eng-practices + Microsoft playbook + Kimi adaptasyon

---

## English

Review every CL in four phases. Budget total 40–50 minutes for a ≤200-line CL.

### Phase 1: Overview (5 min)

1. Read the PR description. Is there a requirement ID? Does scope match?
2. Is the change type sensible (feature/bugfix/refactor)?
3. Scan the file list. Unexpected files? (Fixes unrelated to scope → `[BLOCKING]`.)
4. CI status. **Red CI → immediate reject** (except known-infra with evidence).

**Decision:** red CI or out-of-scope files → conditional rejection; no line review yet.

### Phase 2: Design Review (10 min)

- Is this change in the right place (module/library/subsystem)?
- Does it integrate with the existing architecture? Recognizes existing patterns?
- Traceability: does it map to the requirement? (REQ ↔ design ↔ code.)
- Is there a simpler, more maintainable approach?

**Decision:** broken design → reject immediately. Do not descend to line level.

### Phase 3: Line-by-Line (20–30 min)

For each file:
1. **Logical correctness** — algorithm, boundary conditions, off-by-one.
2. **Error handling** — every return checked, codes propagated (`01-standards/06`).
3. **Security** — bounds, input validation, race conditions, secrets (`04-checklists/04`).
4. **Tests** — do they catch real failures? Valid assumptions? Edge cases?
5. **Readability** — names clear? Comments explain "why"?
6. **Standards** — MISRA/CERT hits (with rule IDs).

### Phase 4: Final Assessment (5 min)

- All findings categorized `[CRITICAL]` / `[BLOCKING]` / `[Nit:]` / `[Question]` / `[Praise]`.
- Clear action list for the author.
- **Approve:** summarise, list unresolved `Nit:` items, give LGTM.
- **Reject:** state exactly what blocks and why; propose an approach.

### Discipline Rules

- Do not review > 400 lines in one sitting; pause and recover.
- Do not gate on `Nit:` items.
- If the design is wrong, do NOT polish lines.
- Record time, findings, decision in review record (`05-traceability/02`).

---

## Türkçe

Her CL dört fazda incelenir. ≤200 satırlık bir CL için toplam 40–50 dk bütçeleyin.

### Faz 1: Genel Bakış (5 dk)

1. PR açıklamasını oku. Gereksinim ID var mı? Kapsam uyuyor mu?
2. Değişiklik tipi mantıklı mı (özellik/hata düzeltmesi/refactor)?
3. Dosya listesini tara. Beklenmeyen dosya? (Kapsam dışı düzeltme → `[BLOCKING]`.)
4. CI durumu. **Kırmızı CI → derhal red** (kanıtla desteklenen bilinen altyapı dışında).

**Karar:** kırmızı CI veya kapsam dışı dosya → koşullu red; henüz satır incelemesi yok.

### Faz 2: Tasarım İncelemesi (10 dk)

- Değişiklik doğru yerde mi (modül/kütüphane/alt sistem)?
- Mevcut mimariye entegre oluyor mu? Mevcut desenleri tanıyor mu?
- İzlenebilirlik: gereksinimle örtüşüyor mu? (REQ ↔ tasarım ↔ kod.)
- Daha basit, bakımı kolay bir yaklaşım var mı?

**Karar:** bozuk tasarım → derhal red. Satır seviyesine inme.

### Faz 3: Satır Satır (20–30 dk)

Her dosya için:
1. **Mantıksal doğruluk** — algoritma, sınır koşulları, off-by-one.
2. **Hata yönetimi** — her return kontrol edildi, kodlar taşındı (`01-standards/06`).
3. **Güvenlik** — sınırlar, girdi doğrulama, race condition, sırlar (`04-checklists/04`).
4. **Testler** — gerçek hataları yakalıyor mu? Geçerli varsayımlar? Kenar durumlar?
5. **Okunurluk** — isimler net? Yorumlar "neden" açıklıyor?
6. **Standartlar** — MISRA/CERT isabetleri (kural ID'leriyle).

### Faz 4: Son Değerlendirme (5 dk)

- Tüm bulgular `[CRITICAL]` / `[BLOCKING]` / `[Nit:]` / `[Question]` / `[Praise]` olarak kategorize edildi.
- Yazar için net aksiyon listesi.
- **Onay:** özetle, çözülmemiş `Nit:` öğelerini listele, LGTM ver.
- **Red:** tam olarak neyi engellediğini ve nedenini söyle; yaklaşım öner.

### Disiplin Kuralları

- Tek oturuşta > 400 satır incelemeyin; ara verin ve kendinizi toplayın.
- `Nit:` öğelerinde kapı koymayın.
- Tasarım bozuksa satır cilalama.
- Süreyi, bulguları, kararı inceleme kaydına işle (`05-traceability/02`).

---

**Sahip / Owner:** Kod Kalite Komitesi / Code Quality Committee