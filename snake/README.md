# Snake Game (C++ with SDL2)

Este é um jogo clássico da cobrinha desenvolvido em C++ usando a biblioteca SDL2.

## Requisitos

Antes de compilar e executar o jogo, certifique-se de ter a biblioteca SDL2 instalada. No Linux, você pode instalá-la com:

```sh
sudo apt-get install libsdl2-dev
```

No macOS, usando Homebrew:

```sh
brew install sdl2
```

## Compilação e Execução

Para compilar o jogo, utilize o `Makefile` fornecido:

```sh
make
```

Para executar o jogo:

```sh
./snake
```

Para limpar os arquivos gerados:

```sh
make clean
```

## Como Jogar

- Use as setas do teclado para mover a cobra.
- O objetivo é comer a comida vermelha sem bater nas paredes ou em si mesma.
- O jogo termina se a cobra colidir com as bordas ou com seu próprio corpo.

## Controles

- **Seta para cima**: Move a cobra para cima.
- **Seta para baixo**: Move a cobra para baixo.
- **Seta para esquerda**: Move a cobra para a esquerda.
- **Seta para direita**: Move a cobra para a direita.
- **ESC ou Fechar Janela**: Encerra o jogo.

## Licença

Este projeto é open-source e está disponível sob a licença MIT.

---

Divirta-se jogando a cobrinha! 🐍🎮
