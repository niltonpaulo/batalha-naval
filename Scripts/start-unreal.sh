#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
PROJECT_NAME="AaaAndroidGame"
UE_EDITOR="${UE_ROOT}/Engine/Binaries/Linux/UnrealEditor"

if [[ ! -x "$UE_EDITOR" ]]; then
  echo "Unreal Engine não encontrado em \$UE_ROOT/Engine/Binaries/Linux/UnrealEditor" >&2
  exit 1
fi

exec "$UE_EDITOR" "$ROOT_DIR/${PROJECT_NAME}.uproject" -game
