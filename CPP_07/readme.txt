### 🎯 **Objetivos gerais do módulo**

* Introduzir o conceito de **templates em C++** (funções e classes).
* Desenvolver código **genérico e reutilizável**, independente do tipo.
* Reforçar conceitos como **tipagem forte, alocação de memória, exceções e boas práticas com operadores**.

## ✅ **Exercício 00: Funções template (swap, min, max)**
### 🔍 O que você vai fazer:
Implementar três **funções templates**:
* `swap`: troca os valores entre dois parâmetros.
* `min`: retorna o menor valor entre dois.
* `max`: retorna o maior valor entre dois.

### 🧠 Competências desenvolvidas:
* Criação de **funções genéricas** usando `template<typename T>`.
* **Comparações genéricas** usando operadores (`<`, `>`, `==`).
* Prática com **funções inline** em headers.

## ✅ **Exercício 01: `iter` (template de função com ponteiros e funções)**
### 🔍 O que você vai fazer:
Criar a função `iter`, que:
* Recebe um **array de qualquer tipo**, seu tamanho, e uma função.
* Aplica essa função **a cada elemento do array**.
### 🧠 Competências desenvolvidas:
* Uso de **funções como parâmetros** (funções simples ou templates).
* Manipulação de arrays com **ponteiros e referência** (const e não-const).
* Pensar em **flexibilidade e generalização** do código.

## ✅ **Exercício 02: Template de classe `Array<T>`**
### 🔍 O que você vai fazer:
Criar uma **classe template `Array<T>`** que:
* Pode ser instanciada com qualquer tipo.
* Aloca memória dinamicamente com `new[]`.
* Implementa operadores como `[ ]` (com verificação de limites).
* Implementa cópia e atribuição sem efeitos colaterais.
* Tem um método `size()` que retorna o tamanho do array.
### 🧠 Competências desenvolvidas:
* Criação de **classes genéricas** com `template<class T>`.
* Implementação de **operadores personalizados** (`operator[]`).
* Gerenciamento manual de memória com **`new[]` e `delete[]`**.
* Tratamento de **exceções** com `std::exception`.
* Garantir **deep copy** e evitar memory leaks.

## 📚 **Regras e boas práticas exigidas**

* **C++98** (sem C++11+ ou STL containers).
* Sem `printf`, `malloc`, `free`, `namespace std`, `friend`.
* Código deve ser **modularizado** com headers bem definidos e guardas de inclusão.
* Classes em **Forma Canônica Ortodoxa** (construtor default, cópia, destrutor e operador de atribuição).

## 🧠 Conclusão: O que você aprenderá com esse módulo

| Conceito                      | Aplicação prática nos exercícios             |
| ----------------------------- | -------------------------------------------- |
| **Templates (função/classe)** | Generalizar operações e estruturas de dados. |
| **Operadores personalizados** | Implementar `[ ]` e copiar corretamente.     |
| **Tratamento de exceções**    | Lançar exceção ao acessar índice inválido.   |
| **Memória dinâmica**          | Gerenciar `new[]`/`delete[]` com segurança.  |
| **Const correctness**         | Garantir uso correto de const references.    |
