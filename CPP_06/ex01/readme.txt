## 🎯 **Objetivo da atividade**

Implementar uma **classe `Serializer`** que permita **converter um ponteiro para inteiro** e depois **recuperar 
esse ponteiro a partir do inteiro**. Ou seja:

> Você vai simular **serialização manual de ponteiros** — útil em contextos como redes ou arquivos binários.

## 📦 **O que é `uintptr_t`?**

* Um tipo de inteiro definido em `<cstdint>` (ou `<stdint.h>`) que é **garantido para armazenar qualquer ponteiro
sem perda de dados**.
* É uma forma segura de converter ponteiros para inteiros e vice-versa.

## 📐 **Estrutura `Data`**

Você precisa criar uma struct `Data` com pelo menos um ou mais membros (ex: `int`, `std::string`, etc.). Exemplo:

struct Data {
    int number;
    std::string name;
};

## 🔐 **Regras obrigatórias**

* A classe `Serializer` deve ser **não instanciável** (construtor privado ou deletado).
* Funções devem ser **estáticas**.
* **Não há funções proibidas.**
* Teste deve comparar se o ponteiro original e o recuperado são iguais.

## 🧠 **Competências desenvolvidas com essa atividade**

* Uso de **conversão segura de ponteiros** (com `reinterpret_cast`)
* Compreensão de como ponteiros podem ser representados como valores "puros" (inteiros)
* Base para **serialização binária e sistemas de persistência**
* Organização de código com **métodos estáticos utilitários**
