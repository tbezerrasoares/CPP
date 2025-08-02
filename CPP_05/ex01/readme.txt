## 🧩 **Exercise 01 – “Form up, maggots!”**

## 📝 **Resumo da Atividade**

Neste exercício, você irá **criar a classe `Form`** e fazê-la interagir com a classe `Bureaucrat` 
(implementada no ex00). A ideia é simular uma **burocracia real**, onde formulários têm que ser 
**assinados por burocratas com níveis adequados**.

### 📦 **Requisitos da Classe `Form`**

* Atributos privados:

  * `const std::string name;` (nome do formulário)
  * `bool isSigned;` (se está assinado ou não — começa como `false`)
  * `const int gradeToSign;` (grau necessário para assinar)
  * `const int gradeToExecute;` (grau necessário para executar)

* Regras:

  * Grades inválidos (< 1 ou > 150) devem lançar:

    * `Form::GradeTooHighException`
    * `Form::GradeTooLowException`

* Métodos:

  * Getters para todos os atributos.
  * `beSigned(Bureaucrat const & b)` → só assina se `b.getGrade() <= gradeToSign`; caso contrário, 
	lança `GradeTooLowException`.
  * Sobrecarga do operador `<<` para imprimir informações do formulário.

---

## 🎯 **Objetivos e Competências Desenvolvidas**

### ✅ 1. **Interação entre classes**

Você vai **relacionar duas classes diferentes**, usando métodos de uma (`Bureaucrat`) para 
modificar o estado da outra (`Form`). Isso é um passo importante rumo ao **design orientado a 
objetos** real.

### ✅ 2. **Encapsulamento e validação de dados**

Todos os atributos são `private`, e o acesso/modificação é feito com **métodos controlados**.

### ✅ 3. **Tratamento de exceções**

Mais uma vez você aplicará `try/catch`, mas agora em **interação entre objetos**.

### ✅ 4. **Reforço da Canonical Form**

`Form` também deve seguir a **Orthodox Canonical Form** (construtor, cópia, atribuição e destrutor).

### ✅ 5. **Impressão personalizada**

Reforço da sobrecarga do `<<`, agora para um novo tipo (`Form`), o que melhora a **observação e 
debug** dos objetos.

### ✅ 6. **Lógica condicional orientada a objetos**

A lógica de permissão para assinar é **distribuída entre os métodos**, não é feita em um único lugar 
fixo. Isso simula o **comportamento real de objetos interdependentes**.

---

## 🧠 **Pontos de Importância**

| Ponto                                        | Importância                                          |
| -------------------------------------------- | -----------------------------------------------------|
| `gradeToSign` e `gradeToExecute` são `const` | Imutabilidade ajuda a garantir integridade da lógica |
|                                              | do sistema.                                          |
| Método `beSigned()`                          | Mostra como encapsular a lógica de permissão.        |
| Classe lança exceções personalizadas         | Mostra como isolar falhas e evitar estados inválidos.|
| Integração com `Bureaucrat`                  | Reforça a reutilização de código e a coesão entre    |
|                                              | classes.                                             |

---

## 🔍 **Exemplo de Interação**

```cpp
Bureaucrat bob("Bob", 50);
Form formA("FormA", 30, 20);

bob.signForm(formA); // Bob não tem grade suficiente → mensagem de erro
// Resultado: Bob couldn't sign FormA because grade too low.

Bureaucrat alice("Alice", 20);
alice.signForm(formA); // Sucesso
// Resultado: Alice signed FormA
```

---

## 📚 **Competências Desenvolvidas**

* 🧱 **Modelagem de classes com regras de negócio internas.**
* 📡 **Relacionamento entre objetos de diferentes classes.**
* ⚠️ **Tratamento e lançamento de exceções no contexto de regras de permissão.**
* 🔄 **Sobrecarga de operadores para objetos personalizados.**
* 🧼 **Separação entre interface (headers) e implementação (cpp).**

---

## 💡 Dica

Você pode fazer com que `signForm()` da classe `Bureaucrat` chame `form.beSigned(*this)` internamente, 
e dentro de `try/catch` mostrar uma mensagem diferente para sucesso ou falha — simulando a vida real: 
o burocrata **tenta assinar** o formulário, e o formulário decide se **aceita ou não** com base na 
autoridade.
