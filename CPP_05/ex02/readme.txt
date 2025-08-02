## 🧩 **Exercise 02 – “No, you need form 28B, not 28C...”**

## 📝 **Resumo da Atividade**

Este exercício evolui a estrutura criada no ex01. A classe `Form` passa a ser uma **classe abstrata**,
renomeada para **`AForm`**, e você deve criar **três subclasses concretas** que implementam 
comportamentos diferentes ao serem executadas:

### 📄 Classes a serem implementadas:

* **Classe abstrata `AForm`**
* **Subclasses concretas:**

  * `ShrubberyCreationForm` – Cria um arquivo com árvores ASCII.
  * `RobotomyRequestForm` – Tenta robotizar o alvo com 50% de sucesso.
  * `PresidentialPardonForm` – Diz que o alvo foi perdoado.

### 📌 Cada formulário:

* Tem um **nome** (herdado de `AForm`)
* Tem um **alvo** (target)
* Tem **graus mínimos para assinar e executar**
* Só pode ser **executado se estiver assinado** e se o `Bureaucrat` tiver **grau suficiente**.

---

## 📦 Novos Elementos Introduzidos

### 🧪 Métodos obrigatórios:

* `execute(Bureaucrat const & executor) const` – deve ser **virtual puro em `AForm`** e **implementado em cada subclasse**.
* `Bureaucrat::executeForm(AForm const & form)` – tenta executar o formulário e mostra sucesso ou erro.

---

## 🎯 **Objetivos e Competências Desenvolvidas**

| Objetivo                              | Descrição                                                                                                                             |
| ------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------- |
| 🧱 **Herança**                        | Você cria uma hierarquia de classes onde `ShrubberyCreationForm`, `RobotomyRequestForm` e `PresidentialPardonForm` herdam de `AForm`. |
| 🔁 **Polimorfismo**                   | Permite trabalhar com **ponteiros ou referências para `AForm`**, e ainda assim chamar `execute()` de cada subclasse.                  |
| 📄 **Classe abstrata**                | Introduz o conceito de **métodos virtuais puros**, e ensina a tornar uma classe **não instanciável diretamente**.                     |
| ⚙️ **Separação de responsabilidades** | `AForm` lida com validação (grau, assinatura), e as subclasses lidam com **a ação concreta**.                                         |
| 🧨 **Tratamento de exceções**         | Você reforça o uso de `try/catch` para lidar com situações como "formulário não assinado" ou "grau insuficiente".                     |

---

## 🧠 **Pontos de Importância**

| Ponto                                                | Explicação                                                                                                                 |
| ---------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------- |
| `AForm` é **abstrata**                               | Deve ter ao menos um método virtual puro (ex: `execute`) e **não pode ser instanciada diretamente**.                       |
| `execute()` exige que o form esteja assinado         | A execução só é possível após validação dupla: assinatura e grau suficiente.                                               |
| Validação no lugar certo                             | A checagem pode ser feita no `AForm::execute()` antes de delegar para `action()` em cada subclasse — isso evita repetição. |
| **Randomização controlada** no `RobotomyRequestForm` | Deve usar `rand()` ou `std::srand()` para gerar 50% de chance — testando conhecimento básico de aleatoriedade.             |
| Criação de **arquivos**                              | `ShrubberyCreationForm` testa manipulação de arquivos com `ofstream`.                                                      |


## 📚 **Competências Desenvolvidas**

* 📐 **Design orientado a objetos avançado**

  * Classe base abstrata (`AForm`)
  * Subclasses com implementação específica de `execute()`

* 💡 **Polimorfismo**
  * Chamada dinâmica de métodos usando ponteiros/referências
* 🔐 **Encapsulamento e validação**
  * Validação centralizada na base (grau, assinatura)
* 🧪 **Tratamento de exceções robusto**
  * Controle de falhas por assinatura inválida ou execução não permitida
* 📁 **Manipulação de arquivos**
  * Gravar arquivos em `ShrubberyCreationForm`
