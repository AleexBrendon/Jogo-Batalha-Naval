# Batalha Naval em C — Projeto Acadêmico

Este projeto consiste no desenvolvimento incremental de um jogo simplificado de **Batalha Naval em linguagem C**, dividido em três níveis de complexidade: **Básico, Intermediário e Avançado**.  
O foco do trabalho é o uso correto de **matrizes**, **estruturas de repetição**, **condicionais**, **organização de código** e **visualização em console**.

---

## Nível Básico — Tabuleiro e Navios Simples

### Objetivo
Criar a base do jogo com posicionamento fixo de navios.

### Funcionalidades
- Criação de um tabuleiro **10x10** (matriz bidimensional)
- Inicialização com `0` (água)
- Posicionamento de **2 navios** de tamanho fixo (3 posições)
  - 1 horizontal
  - 1 vertical
- Representação dos navios com o valor `3`
- Validação de limites e sobreposição
- Exibição do tabuleiro no console

---

## Nível Intermediário — Navios Diagonais

### Objetivo
Aumentar a complexidade do posicionamento dos navios.

### Funcionalidades
- Manutenção do tabuleiro **10x10**
- Posicionamento de **4 navios**:
  - 2 horizontais ou verticais
  - 2 diagonais
- Navios diagonais ocupam posições onde linha e coluna variam simultaneamente
- Validação de:
  - Limites do tabuleiro
  - Sobreposição entre navios (inclusive diagonais)
- Código modularizado com funções
- Exibição organizada do tabuleiro

---

## Nível Avançado — Habilidades Especiais

### Objetivo
Simular áreas de efeito de habilidades especiais sobre o tabuleiro.

### Funcionalidades
- Manutenção do tabuleiro **10x10**
- Criação de **3 matrizes de habilidade** (5x5):
  - **Cone** (expansão para baixo)
  - **Cruz** (linha e coluna centrais)
  - **Octaedro** (formato de losango)
- Matrizes de habilidade usam:
  - `0` → área não afetada
  - `1` → área afetada
- Sobreposição das habilidades no tabuleiro a partir de um ponto de origem
- Representação visual:
  - `0` → Água
  - `3` → Navio
  - `5` → Área afetada pela habilidade
- Uso obrigatório de loops aninhados e condicionais
- Validação simples de limites durante a aplicação das habilidades

---

## Tecnologias Utilizadas
- Linguagem C
- Compilador GCC
- Execução em terminal/console

---

## Objetivos de Aprendizagem
- Manipulação de matrizes bidimensionais
- Uso de estruturas de repetição e condicionais
- Organização e modularização de código em C
- Representação visual de dados no console
- Desenvolvimento incremental de software

---

## Execução

```powershell
gcc batalha_naval.c -o batalha
./batalha
