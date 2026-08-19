# Pano Şablonu / Dashboard Template

**Versiyon / Version:** 1.0
**Amaç:** Aylık inceleme sağlığı; denetim izi için veri toplama.

---

## English

### SQL / Query (GitHub + CI exports example)

```sql
-- per-review aggregate (from review-record export)
SELECT month, COUNT(*) AS reviews,
       SUM(crit) AS critical_findings,
       SUM(blocking) AS blocking_findings,
       AVG(first_lgtm) AS first_pass_rate,
       AVG(roundtrips) AS roundtrips
FROM review_records GROUP BY month;
```

### Grafana Chart Ideas

| Panel | Metric | Threshold alert |
|-------|--------|-----------------|
| Review volume | % of merges with record | < 100% warn |
| First-pass rate | % LGTM first pass | < 40% or =100% |
| Round-trips | avg/CL | > 2 warn |
| Backlog | open > 2 workdays | CRITICAL ≠ 0 critical |
| Escape rate | post-merge defects | rising alert |
| Coverage | avg delta/CL | < 0 warn |

### Spreadsheet Columns (per CL)

`month, cl_id, criticality, reviewer_id, author_id, duration_min, crit, blocking, nit, first_lgtm (0/1), decision (lgtm/reject), roundtrips, coverage_delta`

### Reporting Cadence

- Weekly: automated extract → email/CI comment.
- Monthly: committee review → minutes (audit trail) → SLA adjustments.

---

## Türkçe

### SQL / Sorgu (GitHub + CI dışa aktarım örneği)

```sql
SELECT month, COUNT(*) AS reviews,
       SUM(crit) AS critical_findings,
       SUM(blocking) AS blocking_findings,
       AVG(first_lgtm) AS first_pass_rate,
       AVG(roundtrips) AS roundtrips
FROM review_records GROUP BY month;
```

### Grafana Pano Fikirleri

| Panel | Metrik | Eşik alarmı |
|-------|--------|-----------------|
| İnceleme hacmi | Kayıtlı merge %'si | < %100 uyarı |
| İlk geçiş oranı | % LGTM ilk geçiş | < %40 veya %100 |
| Gidiş-dönüş | ort/CL | > 2 uyarı |
| Birikim | > 2 iş günü açık | CRITICAL ≠ 0 kritik |
| Kaçış oranı | merge sonrası kusurlar | yükselme alarmı |
| Kapsam | ort delta/CL | < 0 uyarı |

### Pano Sütunları (CL başına)

`month, cl_id, criticality, reviewer_id, author_id, duration_min, crit, blocking, nit, first_lgtm (0/1), decision (lgtm/reject), roundtrips, coverage_delta`

### Raporlama Takvimi

- Haftalık: otomatik çıkarı → e-posta/CI yorumu.
- Aylık: komite incelemesi → tutanak (denetim izi) → SLA ayarlamaları.

---

**Sahip / Owner:** Kod Kalite Komitesi / Code Quality Committee