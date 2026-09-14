FROM mcr.microsoft.com/devcontainers/base:ubuntu-22.04

ARG ANDROID_SDK_VERSION=11076708
ARG ANDROID_NDK_VERSION=26.3.11579264
ARG ANDROID_API_LEVEL=35
ARG ANDROID_BUILD_TOOLS=35.0.0
ARG UE_VERSION=5.8.2-hotfix

ENV DEBIAN_FRONTEND=noninteractive \
    ANDROID_HOME=/opt/android-sdk \
    ANDROID_SDK_ROOT=/opt/android-sdk \
    ANDROID_NDK_HOME=/opt/android-sdk/ndk/${ANDROID_NDK_VERSION} \
    ANDROID_NDK_ROOT=/opt/android-sdk/ndk/${ANDROID_NDK_VERSION} \
    JAVA_HOME=/usr/lib/jvm/java-17-openjdk-amd64 \
    UE_ROOT=/workspace/ue \
    UE_VERSION=${UE_VERSION} \
    UE_ANDROID_SDK_ROOT=/opt/android-sdk \
    UE_ANDROID_NDK_VERSION=${ANDROID_NDK_VERSION} \
    UE_ANDROID_API_LEVEL=${ANDROID_API_LEVEL}

RUN apt-get update && apt-get install -y --no-install-recommends \
    bash \
    ca-certificates \
    clang \
    cmake \
    curl \
    git \
    gnupg \
    libfontconfig1 \
    libgl1 \
    libglu1-mesa \
    libgtk-3-0 \
    libnss3 \
    libx11-xcb1 \
    libxcb1 \
    libxcomposite1 \
    libxcursor1 \
    libxdamage1 \
    libxi6 \
    libxrandr2 \
    libxrender1 \
    libxss1 \
    libxtst6 \
    lsb-release \
    ninja-build \
    openjdk-17-jdk \
    python3 \
    python3-pip \
    rsync \
    sudo \
    unzip \
    wget \
    zip \
    zsh \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p ${ANDROID_HOME}/cmdline-tools /tmp/android-cmdline-tools \
    && curl -fsSL -o /tmp/android-commandlinetools.zip https://dl.google.com/android/repository/commandlinetools-linux-${ANDROID_SDK_VERSION}_latest.zip \
    && unzip -q /tmp/android-commandlinetools.zip -d /tmp/android-cmdline-tools \
    && mv /tmp/android-cmdline-tools/cmdline-tools ${ANDROID_HOME}/cmdline-tools/latest \
    && rm -rf /tmp/android-cmdline-tools /tmp/android-commandlinetools.zip

ENV PATH=${ANDROID_HOME}/cmdline-tools/latest/bin:${ANDROID_HOME}/platform-tools:${ANDROID_HOME}/build-tools/${ANDROID_BUILD_TOOLS}:${PATH}

RUN yes | sdkmanager --licenses >/dev/null \
    && sdkmanager \
      "platform-tools" \
      "platforms;android-${ANDROID_API_LEVEL}" \
      "build-tools;${ANDROID_BUILD_TOOLS}" \
      "ndk;${ANDROID_NDK_VERSION}" \
      "cmake;3.22.1" \
      "ndk-side-by-side" \
    && chmod -R a+rwX ${ANDROID_HOME}

RUN groupadd -r androiddev -g 9000 \
    && useradd -m -s /bin/zsh -u 1000 -g 9000 -G sudo androiddev \
    && echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

USER androiddev
WORKDIR /workspace
