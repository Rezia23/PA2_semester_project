#!/bin/bash

set -eu

USERNAME="hrubate1"
PROJECT_DIR="semestralka"

mkdir "$USERNAME"
cp -r "$PROJECT_DIR/examples/" "$PROJECT_DIR/src" "$USERNAME";
cp "$PROJECT_DIR/zadani.txt" "$PROJECT_DIR/prohlaseni.txt" "$PROJECT_DIR/Makefile"  "$PROJECT_DIR/Doxyfile" "$USERNAME";
zip -r "$USERNAME.zip" "$USERNAME"
