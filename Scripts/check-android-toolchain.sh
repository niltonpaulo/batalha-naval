#!/usr/bin/env bash
set -euo pipefail

required=(
  "${ANDROID_HOME:-/opt/android-sdk}/platform-tools/adb"
  "${ANDROID_HOME:-/opt/android-sdk}/cmdline-tools/latest/bin/sdkmanager"
  "${ANDROID_HOME:-/opt/android-sdk}/build-tools/${UE_ANDROID_BUILD_TOOLS:-35.0.0}/aapt"
  "${ANDROID_HOME:-/opt/android-sdk}/ndk/${UE_ANDROID_NDK_VERSION:-26.3.11579264}/ndk-build"
  "${JAVA_HOME:-/usr/lib/jvm/java-17-openjdk-amd64}/bin/java"
)

missing=0
for item in "${required[@]}"; do
  if [[ ! -x "$item" ]]; then
    echo "MISSING: $item" >&2
    missing=1
  else
    echo "OK: $item"
  fi
done

if (( missing )); then
  echo "Android toolchain incompleto. Execute: sdkmanager \"platform-tools\" \"platforms;android-${UE_ANDROID_API_LEVEL:-35}\" \"build-tools;${UE_ANDROID_BUILD_TOOLS:-35.0.0}\" \"ndk;${UE_ANDROID_NDK_VERSION:-26.3.11579264}\"" >&2
  exit 1
fi

"${ANDROID_HOME:-/opt/android-sdk}/cmdline-tools/latest/bin/sdkmanager" --list_installed
"${JAVA_HOME:-/usr/lib/jvm/java-17-openjdk-amd64}/bin/java" -version
