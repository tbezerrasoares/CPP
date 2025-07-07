O **Módulo 04 de C++** que estás a estudar é focado principalmente em **polimorfismo**, 
**classes abstratas** e **interfaces**, três conceitos fundamentais da **Programação Orientada a 
Objetos (POO)**. Aqui vai um resumo do que cada exercício propõe e o que irás aprender com ele:

---

### ✅ **Exercício 00: Polimorfismo**

**Objetivo:**
Entender o conceito de **polimorfismo em tempo de execução** usando herança e funções virtuais.

**Atividades:**

* Criar uma classe base `Animal` com um atributo `type` e um método virtual `makeSound()`.
* Criar classes derivadas `Dog` e `Cat` que implementam `makeSound()` de forma específica.
* Criar uma classe `WrongAnimal` e `WrongCat` para mostrar o que acontece quando *não* usamos 
funções virtuais corretamente.

**O que você aprende:**

* Como o polimorfismo funciona em C++ com ponteiros para classes base.
* A importância de funções virtuais.
* O risco de omitir `virtual` e as consequências disso.

---

### ✅ **Exercício 01: I don’t want to set the world on fire**

**Objetivo:**
Aplicar **alocação dinâmica de memória** e **regra dos três** (construtor de cópia, operador de 
atribuição, destrutor).

**Atividades:**

* Criar uma classe `Brain` com 100 ideias (`std::string ideas[100]`).
* Adicionar um `Brain*` como atributo em `Dog` e `Cat`.
* Implementar cópias profundas em `Dog` e `Cat`.
* Testar o gerenciamento correto da memória e evitar *memory leaks*.

**O que você aprende:**

* A importância do **gerenciamento de memória manual** em C++.
* Como implementar **cópia profunda**.
* Utilizar `delete` corretamente e evitar vazamentos de memória.
* Princípios do **Ortodoxy Canonical Form** em C++.

---

### ✅ **Exercício 02: Classe Abstrata**

**Objetivo:**
Forçar o uso de **classes abstratas** com métodos puramente virtuais.

**Atividades:**

* Transformar `Animal` em uma classe abstrata, impedindo sua instanciação direta.

**O que você aprende:**

* Como declarar **métodos virtuais puros** (`= 0`).
* Por que usar classes abstratas para evitar instanciar objetos genéricos.
* Design de hierarquias mais seguras e claras.

---

### 🎯 **O que você vai dominar ao final do módulo:**

* O uso correto de **polimorfismo com funções virtuais**.
* A criação e uso de **classes abstratas e interfaces**.
* Implementação correta de **construtores, destrutores e cópias profundas**.
* Conceitos de **encapsulamento e separação de responsabilidades**.
* **Gerenciamento de memória manual**, evitando *memory leaks*.
* **Design orientado a objetos**, com foco na reutilização e extensibilidade do código.

Se quiser, posso te ajudar a começar o esqueleto de cada exercício! Deseja isso?
