# AaaAndroidGame

Protótipo base de jogo AAA para Android com Unreal Engine 5.8+.

## Estrutura

- `.devcontainer/` - ambiente reproduzível com Android SDK/NDK/JDK.
- `Source/AaaAndroidGame/` - código C++ do jogo.
- `Config/` - configurações do projeto.
- `Content/` - conteúdo do jogo.
- `Scripts/` - scripts de inicialização e build.

## Rodar

```bash
./Scripts/start-unreal.sh
```

## Build Android

```bash
./Scripts/build-android.sh
```

## Observações

- Este é um protótipo base, não o jogo completo.
- O jogo web existente em `index.html` foi preservado.
