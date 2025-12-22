#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import hashlib
from pathlib import Path

ROOT_DIR = Path(".").resolve()
OUTPUT_FILE = ROOT_DIR / "MEGA_SOURCE.md"

# ❌ Verzeichnisse komplett ausschließen
EXCLUDE_DIRS = {
    "build",
    ".git",
    ".vscode",
    "__pycache__",
}

# ❌ Dateien ausschließen
EXCLUDE_FILES = {
    "e2pat.all",
}

# ❌ Extensions ausschließen (binär / müll)
EXCLUDE_EXTENSIONS = {
    ".bin", ".elf", ".o", ".a", ".so", ".dll", ".exe",
    ".base64",
}

# ✔️ als Text erlaubte Extensions
TEXT_EXTENSIONS = {
    ".c", ".h", ".hpp", ".cpp",
    ".py", ".sh",
    ".S", ".ld",
    ".md", ".txt",
    ".json", ".yml", ".yaml", ".ini", ".cfg",
    ".mk", ".cmake",
}

SPECIAL_TEXT_FILES = {
    "Makefile",
    "Dockerfile",
}

def sha256_of_file(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(8192), b""):
            h.update(chunk)
    return h.hexdigest()

def is_text_file(path: Path) -> bool:
    if path.name in SPECIAL_TEXT_FILES:
        return True
    return path.suffix.lower() in TEXT_EXTENSIONS

def should_exclude(path: Path) -> bool:
    if path.name in EXCLUDE_FILES:
        return True
    if path.suffix.lower() in EXCLUDE_EXTENSIONS:
        return True
    for part in path.parts:
        if part in EXCLUDE_DIRS:
            return True
    return False

def chapter_of(path: Path) -> str:
    p = path.as_posix().lower()
    if p.startswith("docs/") or path.suffix.lower() in {".md", ".txt"}:
        return "DOCS"
    return "SRC"

def safe_read_text(path: Path) -> str:
    try:
        return path.read_text(encoding="utf-8")
    except UnicodeDecodeError:
        return path.read_text(encoding="utf-8", errors="replace")

def anchor_for(rel_path: str) -> str:
    # GitHub-kompatible Markdown-Anker
    return rel_path.lower().replace("/", "").replace(".", "").replace("_", "")

# ---------------- MAIN ----------------

files = []

for root, dirs, filenames in os.walk(ROOT_DIR):
    # prune excluded dirs
    dirs[:] = [d for d in dirs if d not in EXCLUDE_DIRS]

    for name in filenames:
        p = Path(root) / name
        rel = p.relative_to(ROOT_DIR)

        if should_exclude(rel):
            continue
        if not is_text_file(rel):
            continue

        files.append(rel)

files.sort(key=lambda p: p.as_posix().lower())

chapters = {
    "SRC": [],
    "DOCS": [],
}

for f in files:
    chapters[chapter_of(f)].append(f)

out = []

# Header
out.append("# Mega Source Export\n")
out.append(f"**Root:** `{ROOT_DIR}`  \n")
out.append(f"**Dateien:** {len(files)}  \n")
out.append("\n---\n")

# TOC
out.append("## Index\n")
for ch in ("SRC", "DOCS"):
    out.append(f"### {ch}")
    for f in chapters[ch]:
        anchor = anchor_for(f.as_posix())
        out.append(f"- [`{f.as_posix()}`](#{anchor})")
    out.append("")
out.append("\n---\n")

# Content
for ch in ("SRC", "DOCS"):
    out.append(f"## {ch}\n")
    for f in chapters[ch]:
        abs_path = ROOT_DIR / f
        sha = sha256_of_file(abs_path)
        anchor = anchor_for(f.as_posix())

        out.append(f"### {f.as_posix()}")
        out.append(f"<a name=\"{anchor}\"></a>\n")
        out.append(f"- **Name:** `{f.name}`")
        out.append(f"- **Pfad:** `{f.as_posix()}`")
        out.append(f"- **SHA256:** `{sha}`\n")

        out.append("```")
        out.append(safe_read_text(abs_path))
        out.append("```\n")

OUTPUT_FILE.write_text("\n".join(out), encoding="utf-8")
print(f"✔ MEGA_SOURCE.md erzeugt ({len(files)} Dateien)")
