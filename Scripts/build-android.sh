#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
PROJECT_NAME="AaaAndroidGame"
UE_BUILD="${UE_ROOT}/Engine/Build/BatchFiles/Linux/Build.sh"

if [[ ! -x "$UE_BUILD" ]]; then
  echo "Unreal build script não encontrado em \$UE_ROOT/Engine/Build/BatchFiles/Linux/Build.sh" >&2
  exit 1
fi

exec "$UE_BUILD" "$PROJECT_NAME" Android Development "${ROOT_DIR}/${PROJECT_NAME}.uproject" -waitmutex -NoHotReload
