# İnceleme Metrikleri / Review Metrics

**Versiyon / Version:** 1.0

---

## English

Metrics are feedback, not targets to game. Trends are reviewed monthly by the committee.

### Core Metrics

| Metric | Formula | Health target |
|--------|---------|----------------|
| Review volume | Merged CLs with record / total merged | 100% |
| Discovery rate | CRITICAL findings / KLOC | trend → 0 |
| First-approval LGTM rate | LGTM on first pass / total | ≥ 40% |
| Round-trips / CL | author↔reviewer iterations | ≤ 2 |
| Review latency | time from PR to first comment | per `04-lgtm-criteria` SLA |
| Backlog | open reviews > 2 workdays | 0 for CRITICAL |
| Escape rate | post-merge defects / total | decreasing |
| Coverage delta | test coverage change per CL | ≥ 0 |

### Interpretation

- 100% first-approval → reviews are shallow; deepen or add independence.
- Round-trips > 4 → incomplete PR description; enforce template.
- Rising escape rate → re-audit approved reviews; check independence.
- Backlog > threshold → capacity; split CLs.

### Reporting

Monthly: table + trend lines. Update dashboard (`02-dashboard-template.md`). Decisions recorded in committee minutes (audit trail).

---

## Türkçe

Metrikler geri bildirimdir; oynanacak hedefler değil. Trendler komitede aylık gözden geçirilir.

### Çekirdek Metrikler

| Metrik | Formül | Sağlık hedefi |
|--------|---------|----------------|
| İnceleme hacmi | Kayıtlı merge / toplam merge | %100 |
| Bulma oranı | KLOC başına CRITICAL bulgu | trend → 0 |
| İlk onayda LGTM oranı | İlk geçişte LGTM / toplam | ≥ %40 |
| Gidiş-dönüş / CL | yazar↔inceleyici iterasyon | ≤ 2 |
| İnceleme gecikmesi | PR'den ilk yoruma süre | `04-lgtm-criteria` SLA'ya göre |
| Birikim | > 2 iş günü açık inceleme | CRITICAL için 0 |
| Kaçış oranı | merge sonrası kusur / toplam | azalan |
| Kapsam deltası | CL başına kapsam değişimi | ≥ 0 |

### Yorumlama

- %100 ilk onay → incelemeler yüzeysel; derinleştirin veya bağımsızlık ekleyin.
- Gidiş-dönüş > 4 → eksik PR açıklaması; şablonu zorla.
- Yükselen kaçış oranı → onaylı incelemeleri yeniden denetle; bağımsızlığı kontrol et.
- Birikim eşiği → kapasite; CL'leri böl.

### Raporlama

Aylık: tablo + trend çizgileri. Panoyu güncelle (`02-dashboard-template.md`). Kararlar komite tutanaklarında kaydedilir (denetim izi).

---

**Sahip / Owner:** Kod Kalite Komitesi / Code Quality Committee