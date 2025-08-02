## 🧩 **Ex00 – “Mommy, when I grow up, I want to be a bureaucrat!”**

### 📝 **Resumo da Atividade**

Você deve implementar uma classe chamada **`Bureaucrat`** com os seguintes requisitos:

* Um **nome constante** (não pode ser modificado após a criação).
* Um **grau (grade)** que vai de **1 (melhor possível)** até **150 (pior possível)**.
* O construtor deve **lançar exceções** se o grau for inválido (fora do intervalo).
* Métodos para **incrementar** e **decrementar** o grau, também com tratamento de exceções.
* Sobrecarga do operador `<<` para imprimir o burocrata no formato:

  ```
  <name>, bureaucrat grade <grade>.
  ```

---

## 🎯 **Objetivos e Competências Desenvolvidas**

### ✅ 1. **Criação de Classes com Atributos Constantes**

* Desenvolver o entendimento de **constantes em C++** (ex: `const std::string name;`).
* Saber como **inicializar constantes no construtor** usando lista de inicialização.

### ✅ 2. **Controle e Validação de Atributos**

* Desenvolver lógica para **verificar validade de dados** (neste caso, o `grade`).
* Praticar a **proteção da integridade dos objetos** contra estados inválidos.

### ✅ 3. **Exceções Personalizadas**

* Criar e lançar exceções do tipo:

  * `GradeTooHighException`
  * `GradeTooLowException`
* Compreender como usar `try/catch` e como **tratar exceções adequadamente**.
* Implementar exceções como **subclasses de `std::exception`** com `what()`.

### ✅ 4. **Sobrecarga de Operadores**

* Aprender a sobrescrever `operator<<` para permitir **impressão legível de objetos**, prática comum em C++ para debugging e logging.

### ✅ 5. **Uso da Orthodox Canonical Form (OCF)**

* Aplicar as boas práticas da **forma canônica**:

  * Construtor padrão
  * Construtor por cópia
  * Operador de atribuição
  * Destrutor

---

## 🧠 **Pontos Importantes na Implementação**

| Ponto                                   | Importância                                                |
| --------------------------------------- | ---------------------------------------------------------- |
| `const std::string name;`               | Obriga a inicialização via lista no construtor.            |
| Validação de `grade` no construtor      | Impede a criação de objetos inválidos.                     |
| `incrementGrade()` e `decrementGrade()` | Invertido! Grade menor é melhor (1 é o topo).              |
| Exceções específicas                    | Fornecem **feedback claro** e permitem tratamento isolado. |
| `std::ostream& operator<<`              | Exibe objetos de forma elegante e informativa.             |

## 📚 **Resumo das Competências Desenvolvidas**

* 📌 **Encapsulamento** com atributos `private` e `const`.
* 📌 **Lançamento e tratamento de exceções personalizadas**.
* 📌 **Manipulação de fluxo de saída (operator overloading)**.
* 📌 **Lógica de controle de valores com limites**.
* 📌 **Formação sólida em práticas de design de classes em C++98**.
