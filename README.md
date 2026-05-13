# 🎮 Sistema de Matchmaking

Este projeto simula um sistema de gerenciamento de fila e formação de partidas (*matchmaking*) para jogos online. O objetivo é agrupar jogadores com níveis de habilidade (score) semelhantes, utilizando algoritmos de ordenação para otimizar a busca.

## 🛠️ Funcionalidades Implementadas

- **Gestão de Fila:** Inserção e remoção de jogadores por ID.
- **Ordenação Dupla:** Implementação manual de dois algoritmos clássicos:
  - **Insertion Sort:** Eficiente para listas pequenas ou quase ordenadas.
  - **Merge Sort:** Algoritmo de divisão e conquista para alta performance em grandes volumes de dados.
- **Formação de Grupos:** Busca determinística de grupos baseada em um limite máximo de diferença de score (*delta*).
- **Estabilidade:** Em caso de empate no score, a prioridade é de quem chegou primeiro (menor *timestamp*).

## 🚀 Como Compilar e Rodar

1. Abra o terminal na pasta do projeto.
2. Compile todos os módulos:
   ```bash
   g++ main.cpp Matchmaking.cpp Player.cpp -o matchmaking