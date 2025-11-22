#  Calculadora Científica em C

##  Descrição Geral
Este programa implementa uma **calculadora científica completa em linguagem C**, com suporte para operações matemáticas básicas e avançadas.  
Ele inclui um **sistema de histórico persistente**, armazenando os cálculos realizados em um arquivo de texto (`historico.txt`).

---

##  Funcionalidades

###  Operações Básicas
- Soma  
- Subtração  
- Multiplicação  
- Divisão  

###  Funções Matemáticas
- Porcentagem  
- Potência e Potência reversa  
- Raiz quadrada e cúbica  
- Fatorial  
- Logaritmo base N e Logaritmo natural  
- Módulo (valor absoluto)  

###  Funções Trigonométricas
- Seno  
- Cosseno  
- Tangente  
- Secante  
- Cossecante  
- Cotangente  

###  Constantes e Funções Especiais
- 10^X  
- e * X  
- e^X  

###  Estatísticas e Álgebra Linear
- Média  
- Máximo  
- Determinante 2x2  
- Determinante 3x3  

###  Histórico
- Visualizar histórico de cálculos  
- Limpar histórico  

---

##  Como Compilar

No terminal, use o comando:

```bash
gcc calculadora.c -o calculadora -lm
```

> O parâmetro `-lm` é necessário para incluir a biblioteca matemática (`math.h`).

---

##  Como Executar

Após a compilação, execute o programa com:

```bash
./calculadora
```

O menu principal será exibido no terminal, e você poderá selecionar a operação desejada digitando o número correspondente.

---

##  Histórico Persistente

Cada operação é registrada no arquivo `historico.txt` no formato:

```
Operacao: Soma
Entrada: 5 + 7 + 2
Resultado: 14.0000
------------------------------
```

As opções **27** e **28** do menu permitem **visualizar** e **limpar** o histórico, respectivamente.

---
## Exemplos de uso:
[Vídeo demonstração 1](https://github.com/user-attachments/assets/c2c55ee6-e0b0-4b3e-b126-0b00d2896cb8)
[Vídeo demonstração 2](https://github.com/user-attachments/assets/2236a2d2-30fe-4817-b056-349b28325691)
[Vídeo demonstração 3](https://github.com/user-attachments/assets/a8169bfa-2d54-4855-b876-63cdeb3640df)
---

##  Autor
Desenvolvido por **Davi Carvalho Boueres..**, **Henry Clark B. Silva**, **Davi Lucas**, **Gustavo Vasconcelos Ruas**
Versão: 2.0  
Linguagem: C  
Ano: 2025
