#!/usr/bin/env python3
"""Validate relative Markdown links inside the repository."""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path


LINK_RE = re.compile(r"!?(?<!\\)\[[^\]]*\]\(([^)]+)\)")
HEADING_RE = re.compile(r"^(#{1,6})\s+(.*)$")
SKIP_DIRS = {".git", ".pio", "__pycache__"}


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=Path("."))
    return parser.parse_args()


def slugify(text: str) -> str:
    text = text.strip().lower()
    text = re.sub(r"\s+", "-", text)
    text = re.sub(r"[^a-z0-9\-_]", "", text)
    return text


def collect_markdown_files(root: Path) -> list[Path]:
    result: list[Path] = []
    for path in root.rglob("*.md"):
        if any(part in SKIP_DIRS for part in path.parts):
            continue
        result.append(path)
    return sorted(result)


def collect_anchors(path: Path) -> set[str]:
    counts: dict[str, int] = {}
    anchors: set[str] = set()
    for line in path.read_text(encoding="utf-8").splitlines():
        match = HEADING_RE.match(line)
        if not match:
            continue
        slug = slugify(match.group(2))
        if not slug:
            continue
        count = counts.get(slug, 0)
        counts[slug] = count + 1
        anchors.add(slug if count == 0 else f"{slug}-{count}")
    return anchors


def main() -> int:
    args = parse_args()
    root = args.root.resolve()
    markdown_files = collect_markdown_files(root)
    anchor_map = {path.resolve(): collect_anchors(path) for path in markdown_files}

    issues: list[str] = []

    for path in markdown_files:
        text = path.read_text(encoding="utf-8")
        for match in LINK_RE.finditer(text):
            target = match.group(1).strip()
            if target.startswith(("http://", "https://", "mailto:")):
                continue
            if target.startswith("<") and target.endswith(">"):
                target = target[1:-1]

            if target.startswith("#"):
                anchor = target[1:]
                if anchor not in anchor_map.get(path.resolve(), set()):
                    issues.append(f"{path}: missing anchor {target}")
                continue

            if "#" in target:
                file_part, anchor = target.split("#", 1)
            else:
                file_part, anchor = target, ""

            target_path = (path.parent / file_part).resolve()
            if not target_path.exists():
                issues.append(f"{path}: missing file {target}")
                continue

            if anchor and target_path.suffix.lower() == ".md":
                if anchor not in anchor_map.get(target_path, set()):
                    issues.append(f"{path}: missing anchor {target}")

    if issues:
        for issue in issues:
            print(issue, file=sys.stderr)
        return 1

    print("markdown links: ok")
    return 0


if __name__ == "__main__":
    sys.exit(main())
