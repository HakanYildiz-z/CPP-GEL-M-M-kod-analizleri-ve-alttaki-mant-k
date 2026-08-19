# Açık Kaynak Araç Ekosistemi / Open Source Tool Ecosystem

**Versiyon / Version:** 1.0
**Kaynak:** joho/awesome-code-review, kodustech/awesome-code-review-tools

---

## English

Human review is the source of truth; tools multiply its reach. All tools are **advisory** unless qualified (DO-330) for a certification objective.

### Review Platforms

| Tool | Type | Strength | Deployment |
|------|------|----------|------------|
| Gerrit | Web review for Git | Fine-grained, verified merges; Android/Chromium heritage | Self-host |
| Phabricator | Review + project suite | Integrations; large monorepos | Self-host |
| GitHub PRs / GitLab MRs | Built-in | Native CI + CODEOWNERS + branch protection | Cloud/self-host |
| Reviewdog | Lint-integrated comments | Language-agnostic; posts linter findings on diff | GitHub/GitLab actions |

### Static & Security Analysis

| Tool | Purpose | Notes |
|------|---------|-------|
| PC-lint Plus | MISRA C/C++ + CERT | Primary MISRA gate; text rule config → CI |
| Cppcheck | C++ defects | Free; 0-error gate |
| Clang-Tidy | Modern C++ | Style + correctness |
| SonarQube | Quality/security dashboard | Grade-A gate |
| CodeQL | Semantic security | CWE Top 25 scanning |
| Semgrep | Custom rules | Fast, BYO rulesets |

### AI-Assisted Review

| Tool | Strength | Deployment | Diff visibility |
|------|----------|------------|-----------------|
| OpenCode agents | Custom prompts + SARIF + full repo access | CLI/CI/plugin | Yes |
| Alibaba Open Code Review | Precision-focused, token-efficient, C/C++ rulesets | CLI/CI | Yes |
| LiveReview | Self-host, BYOK, git-native | Self-host | Yes |
| Gito | Stateless, BYOK, multi-language | CLI/CI | Yes |
| OpenLens | Parallel security/bug/perf/style agents | CLI/CI | Yes |

### Distributed / No-Server

| Tool | Strength |
|------|----------|
| google/git-appraise | Reviews stored as git objects; offline friendly; any host |

### Tool Selection Guidance

| Need | Select |
|------|--------|
| MISRA gate in CI | PC-lint Plus (or LDRA/QAC if contracted) |
| First-pass automated review on PRs | Reviewdog + linters; optionally AI agent |
| Security scan of deps | Dependency-check (OWASP) + SBOM |
| AI advisory pass without data leaving site | LiveReview/Gito BYOK, self-host |
| Certification evidence chain | Human records + tool SARIF exports |

### Governance

- Weakest tool gate is no gate: every tool's exit code is enforced in CI.
- SARIF from all tools → one place (GitHub Security / SonarQube).
- Tool versions pinned; rule profiles stored in repo.
- Tool qualification (DO-330) applied only where a tool substitutes human verification.

---

## Türkçe

İnsan incelemesi gerçeğin kaynağıdır; araçlar erişimini çoğaltır. Tüm araçlar, sertifikasyon amacı için (DO-330) niteliklendirilmedikçe **tavsiye** niteliğindedir.

### İnceleme Platformları

| Araç | Tip | Güçlü yön | Dağıtım |
|------|------|----------|------------|
| Gerrit | Git için web inceleme | İnce taneli, doğrulanmış merge'ler; Android/Chromium mirası | Self-host |
| Phabricator | İnceleme + proje paketi | Entegrasyonlar; büyük monorepo'lar | Self-host |
| GitHub PR / GitLab MR | Gömülü | Yerel CI + CODEOWNERS + branch protection | Bulut/self-host |
| Reviewdog | Lint entegreli yorumlar | Dil-bağımsız; linter bulgularını diff'e gönderir | GitHub/GitLab actions |

### Statik & Güvenlik Analizi

| Araç | Amaç | Notlar |
|------|---------|-------|
| PC-lint Plus | MISRA C/C++ + CERT | Birincil MISRA kapısı; metin kural konfigürasyonu → CI |
| Cppcheck | C++ hataları | Ücretsiz; 0-hata kapısı |
| Clang-Tidy | Modern C++ | Stil + doğruluk |
| SonarQube | Kalite/güvenlik panosu | A-notu kapısı |
| CodeQL | Anlamsal güvenlik | CWE Top 25 taraması |
| Semgrep | Özel kurallar | Hızlı, kendi kural setlerin | |

### AI Destekli İnceleme

| Araç | Güçlü yön | Dağıtım | Diff görünürlüğü |
|------|----------|------------|-----------------|
| OpenCode ajanları | Özel promptlar + SARIF + tam depo erişimi | CLI/CI/plugin | Evet |
| Alibaba Open Code Review | Hassasiyet-odaklı, token-verimli, C/C++ kural setleri | CLI/CI | Evet |
| LiveReview | Self-host, BYOK, git-nesil | Self-host | Evet |
| Gito | Durumsuz, BYOK, çok dilli | CLI/CI | Evet |
| OpenLens | Paralel güvenlik/bug/performans/stil ajanları | CLI/CI | Evet |

### Dağıtık / Sunucusuz

| Araç | Güçlü yön |
|------|----------|
| google/git-appraise | İncelemeler git nesneleri olarak saklanır; çevrimdışı uyumlu; her host |

### Araç Seçim Rehberi

| İhtiyaç | Seçim |
|------|--------|
| CI'da MISRA kapısı | PC-lint Plus (veya sözleşmeli LDRA/QAC) |
| PR'lerde ilk-geçiş otomatik inceleme | Reviewdog + linterler; opsiyonel AI ajanı |
| Bağımlılık güvenlik taraması | Dependency-check (OWASP) + SBOM |
| Site dışına veri çıkmadan AI tavsiye | LiveReview/Gito BYOK, self-host |
| Sertifikasyon kanıt zinciri | İnsan kayıtları + araç SARIF dışa aktarımları |

### Yönetim

- En zayıf araç kapısı kapı değildir: her aracın çıkış kodu CI'da uygulanır.
- Tüm araçlardan SARIF → tek yer (GitHub Security / SonarQube).
- Araç sürümleri sabitlenir; kural profilleri depoda saklanır.
- Araç yeterliliği (DO-330) yalnızca bir aracın insan doğrulamasının yerine geçtiği yerde uygulanır.

---

**Sahip:** DevOps / CI Mühendisliği