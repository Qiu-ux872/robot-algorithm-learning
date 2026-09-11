#!/usr/bin/env python3
"""Merge colcon per-package compile_commands.json into one at the workspace root."""
import glob
import json
import os

os.chdir(os.path.dirname(os.path.abspath(__file__)))

entries = {}
for path in glob.glob("build/**/compile_commands.json", recursive=True):
    with open(path) as f:
        for entry in json.load(f):
            entries.setdefault(entry["file"], entry)

with open("compile_commands.json", "w") as f:
    json.dump(list(entries.values()), f, indent=1)

print(f"compile_commands.json: {len(entries)} entries")
