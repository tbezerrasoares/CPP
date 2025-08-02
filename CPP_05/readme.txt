# CPP_05 - Exceções e Hierarquia de Classes em C++
### ✅ **Objetivos Gerais do Módulo CPP05**

* Praticar o uso de **exceções em C++** (`try/catch`, `throw`, classes de exceção personalizadas).
* Entender e aplicar **encapsulamento**, **herança**, **classes abstratas**, e **polimorfismo**.
* Aprender a estruturar classes usando a **Orthodox Canonical Form**.
* Exercitar a **sobrecarga de operadores** (`<<`).
* Trabalhar com **herança múltipla indireta** e **fábricas de objetos (Factory Pattern)**.
* Criar código **robusto, reutilizável e testável**.

---

## 🧩 **Resumo das Atividades**

### 📌 **Exercise 00 – “Mommy, when I grow up, I want to be a bureaucrat!”**

**Objetivo:** Criar uma classe `Bureaucrat`.

**Aprendizados:**

* Definir atributos constantes e validá-los.
* Lançar exceções (`GradeTooHighException` e `GradeTooLowException`) ao criar ou alterar objetos com 
	valores inválidos.
* Criar métodos `incrementGrade()` e `decrementGrade()` com verificação de limites.
* Implementar `<<` para impressão com formato customizado.

---

### 📌 **Exercise 01 – “Form up, maggots!”**

**Objetivo:** Criar a classe `Form` que interage com `Bureaucrat`.

**Aprendizados:**

* Trabalhar com **dependência entre classes**.
* Verificar permissões de acordo com o grau do burocrata.
* Criar o método `beSigned()` com tratamento de exceção caso o grau seja insuficiente.
* Implementar lógica de `Bureaucrat::signForm()` com feedback de sucesso ou erro.

---

### 📌 **Exercise 02 – “No, you need form 28B, not 28C...”**

**Objetivo:** Criar uma **classe base abstrata** `AForm` e classes concretas que herdam dela.

**Aprendizados:**

* Introdução ao **polimorfismo e classes abstratas** com métodos virtuais puros.
* Criação de três subclasses com ações específicas:

  * `ShrubberyCreationForm`: escreve árvores ASCII em um arquivo.
  * `RobotomyRequestForm`: faz operação com 50% de chance de sucesso.
  * `PresidentialPardonForm`: imprime uma mensagem de perdão.
* Implementar método `execute()` e validar se o formulário está assinado e autorizado.
* Estender a classe `Bureaucrat` com `executeForm()`.

---

### 📌 **Exercise 03 – “At least this beats coffee-making”**

**Objetivo:** Criar a classe `Intern`, que gera formulários a partir de strings.

**Aprendizados:**

* **Factory Pattern (padrão de projeto)**: criação de objetos com base em strings de entrada.
* Evitar estruturas longas de `if/else` — buscar soluções mais elegantes (como arrays de ponteiros 
	para funções, mapeamento, etc.).
* Testar a função `makeForm()` que retorna ponteiros para diferentes tipos de `AForm`.

---

## 🎯 **Conclusão: Competências Desenvolvidas**

* Entendimento sólido do uso de **exceções** em C++.
* Criação de **hierarquias de classes com herança**.
* Compreensão de **classe abstrata e polimorfismo**.
* Uso prático de **boas práticas de encapsulamento** e **organização de código**.
* Introdução a **padrões de projeto**, como **Factory Method**.

Se quiser, posso montar um *esqueleto* básico das classes ou diagramas de herança para te ajudar a 
começar. Deseja isso?
