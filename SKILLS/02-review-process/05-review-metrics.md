# İnceleme Metrikleri / Review Metrics

**Versiyon / Version:** 1.0
**Kaynak:** Coachable best practices (SmartBear), Kimi team metrics, ISO 26262 verification metrics principles

---

## English

### Per-Review Log (required)

For every review, capture:
- Reviewer ID
- CL ID
- Start / end time
- Findings count by category: `[CRITICAL]`, `[BLOCKING]`, `[Nit:]`
- Decision: LGTM / Reject
- Duration (minutes)

### Team Metrics (monthly)

| Metric | Definition | Health target |
|--------|-----------|----------------|
| Avg review time / CL | Mean duration | 30–50 min for ≤200-line CL |
| Avg round-trips / CL | Author↔reviewer iterations | ≤ 2 |
| `[CRITICAL]` discovery rate | Critical findings per KLOC | TBD per criticality |
| First-approval LGTM rate | % approved on first review | ≥ 40% (not 100%) |
| Review backlog | Open reviews > 2 workdays | Keep 0 for CRITICAL |
| Coverage delta per CL | Test coverage change per CL | Non-negative |
| Escape rate | Defects found post-merge / total | Decreasing trend |
| Review coverage | % of merges with a review record | 100% |

### Process Health Signals

- 100% first-approval → reviews too shallow; increase depth or independence.
- Round-trips > 4 → PR description incomplete or design-phase skipped.
- Backlog growth → capacity planning; split CLs.
- Escape rate rising → lookback on rejected vs. approved CLs.

### Dashboard

Implement `11-metrics/02-dashboard-template.md`. Monthly: plot trends, review at committee, adjust SLAs (NOT to game the metric).

---

## Türkçe

### İnceleme Başına Günlük (zorunlu)

Her inceleme için:
- İnceleyici ID
- CL ID
- Başlangıç / bitiş zamanı
- Bulgu adetleri: `[CRITICAL]`, `[BLOCKING]`, `[Nit:]`
- Karar: LGTM / Red
- Süre (dakika)

### Ekip Metrikleri (aylık)

| Metrik | Tanım | Sağlık hedefi |
|--------|-----------|----------------|
| Ort. inceleme süresi / CL | Ortalama süre | ≤200 satırlık CL için 30–50 dk |
| Ort. gidiş-dönüş / CL | Yazar↔inceleyici iterasyon | ≤ 2 |
| `[CRITICAL]` bulma oranı | KLOC başına kritik bulgu | Kritikliğe göre TBD |
| İlk onayda LGTM oranı | İlk incelemede onaylanan % | ≥ %40 (asla %100 değil) |
| İnceleme birikimi | > 2 iş günü açık inceleme | CRITICAL için 0 |
| CL başına kapsam deltası | CL başına test kapsamı değişimi | Negatif değil |
| Kaçış oranı | Merge sonrası bulunan kusur / toplam | Azalan trend |
| İnceleme kapsamı | İnceleme kayıtlı merge %'si | %100 |

### Süreç Sağlığı Sinyalleri

- %100 ilk onay → incelemeler çok yüzeysel; derinliği veya bağımsızlığı artır.
- Gidiş-dönüş > 4 → PR açıklaması eksik veya tasarım fazı atlanmış.
- Birikim artışı → kapasite planlaması; CL'leri böl.
- Kaçış oranı yükseliyor → reddedilen vs. onaylanan CL'lere geriye dönük bak.

### Pano

`11-metrics/02-dashboard-template.md` uygula. Aylık: trendleri çiz, komitede gözden geçir, SLA'ları ayarla (metriği oynatmak için DEĞİL).

---

**Sahip / Owner:** Kod Kalite Komitesi / Code Quality Committee