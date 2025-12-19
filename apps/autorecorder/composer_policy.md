# composer_policy.md — WHY / Musical Rationale

## Ziel
`composer_policy.c` definiert **musikalische Makro-Entscheidungen** pro Genre / Section / Segment:
- Section: INTRO / MAIN / BREAK / PEAK / OUTRO
- Segment: A/B/C/D (0..3), bei BREAK/PEAK meist nur A/B
- Outputs sind **nicht-destruktiv**:
  - Randomizer-Parameter (Density / Variation)
  - Fill-State (für Live-FX / SongMode)
  - Decision-Flags (Bias, “musikalische Intention”)

Das Composer-Modul schreibt **keine Notes direkt** (außer wenn bewusst Generation gerufen wird).
Die Policy ist das “Regelwerk”, das später stabil bleibt.

---

## Begriffe

### Density (0–100)
Wie “voll” das Pattern ist (Wahrscheinlichkeit, dass Steps belegt werden).
- INTRO: eher niedrig (Platz schaffen)
- MAIN: mittel bis hoch (Groove)
- PEAK: hoch (Energie)
- OUTRO: zurückfahren

### Variation (0–127)
Wie stark Variation/Randomness wirkt (Pitch/Vel/Pattern-Varianz).
- Intro: gering bis moderat
- Main: moderat
- Peak: höher (Aggressivität/Bewegung)
- Outro: sinkend

### Fill-State (FILL_*)
Wird als “Performance-Layer”-Signal genutzt (Live-FX, Boosts, Fill-Triggers).
- FILL_GROOVE: subtiler Lift
- FILL_BUILD: Energie steigt (Riser/Fill erlaubt)
- FILL_PUNCTUATION: kurze Akzent-Fills
- FILL_NONE: neutral

### Decision-Flags (CP_FLAG_*)
Die Flags codieren **Intention** (nicht “Noten”):
- SPARSE / DENSE: Struktur-Dichte
- LOW_REGISTER / HIGH_REGISTER: Register-Tendenz
- STRAIGHT / SYNCOPATED: Groove-Fokus
- SUSTAINED / PERCUSSIVE: Artikulation
- BUILDING / RELEASE: Verlauf innerhalb des Segments

Composer setzt Flags → Randomizer interpretiert Flags als Bias.

---

## Designprinzipien

### 1) Intro ≠ Peak (Section-Spezifisch)
Die Sections sind bewusst verschieden:
- INTRO: Setup / “Teasing”, weniger Notes, eher low register, Aufbau möglich
- MAIN: stabiler Groove, “Tanzen”
- BREAK: Spannung lösen, Raum, Release/Sparse
- PEAK: Max Energy, DENSE + HIGH_REGISTER + BUILDING
- OUTRO: Abbau, Release, Sparse

### 2) Segment-Logik (A/B/C/D)
Segments stehen für Mikro-Entwicklung innerhalb einer Section:
- A: Einstieg (stabil/etwas leer)
- B: Aufbau (mehr Bewegung)
- C: Richtung Peak (wenn genutzt)
- D: Punch / Transition (wenn genutzt)

BREAK/PEAK sind kurz → oft nur A/B.

### 3) Flags sind “Meta”, nicht “Note-Commands”
Flags dürfen keine harten Regeln sein.
Sie sind Bias:
- beeinflussen Wahrscheinlichkeit (Density +-)
- beeinflussen Register (Pitch-Bereich)
- beeinflussen Groove-Verteilung (Downbeats vs Offbeats)
- beeinflussen Artikulation (Gate/Vel)

---

## Part-spezifische Bias-Matrix (aktuell)

### Rollenmodell (empfohlen)
Wir behandeln Parts grob als Rollen:
- Part 0: BASS (low register, eher stabil, etwas höhere Hit-Rate)
- Part 1: LEAD (höheres Register, etwas weniger Hits als Bass)
- Parts 2–7: MID/PAD/FX (kontextabhängig, meist sparsamer)
- Parts 8–15: DRUMS (feel stärker, kurze Gates, punchier vel)

### Einfluss der Flags pro Rolle (Beispiel)
| Flag | Bass | Lead | Mid/Pad | Drums |
|---|---:|---:|---:|---:|
| SPARSE | - | - | -- | - |
| DENSE | + | + | + | + |
| LOW_REGISTER | ++ | - | + | 0 |
| HIGH_REGISTER | - | ++ | + | 0 |
| STRAIGHT | + (Downbeat) | + | + | ++ |
| SYNCOPATED | + | ++ | ++ | ++ |
| SUSTAINED | + (länger) | + | ++ | 0/leicht |
| PERCUSSIVE | - | + | + | ++ |
| BUILDING | + | + | + | + (fill feel) |
| RELEASE | + | + | ++ | + |

*Hinweis:* Das ist eine Doku der Intention – die genaue Implementierung lebt in `randomizer.c`.

---

## Genre Review (musikalisch, Leitplanken)

### Acid Techno
- Charakter: hypnotisch, rolling, low register, klare Transitions.
- Intro: sparse/low, langsam building
- Main: dichter, syncopation optional
- Break: release, punctuations
- Peak: dense/high + building
- Outro: release, sparse

### Rave / Gabber / Frenchcore / HHC / Tech Trance / Tekkno
Hier definieren wir pro Genre:
- typische Dichte
- typische Register-Tendenz
- Groove-Charakter (straight vs syncopated)
- Peak-Overdrive

*(Wenn du willst, schreibe ich diese Genre-Blöcke als nächsten Step mit konkreten Empfehlungen pro Section.)*

---

## Pflege-Regeln (“Gold wert später”)
1) Werteänderung immer mit WHY-Kommentar (1 Satz).
2) Keine harten Sprünge ohne Übergang (A→B→C→D).
3) BREAK ist nicht “leise MAIN” – es ist **Raum**.
4) PEAK ist “max energy”, aber nicht “random chaos”: Variation kontrolliert.
