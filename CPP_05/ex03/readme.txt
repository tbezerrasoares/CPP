## 🧩 **Exercise 03 – “At least this beats coffee-making”**

### 📝 **Resumo da Atividade**

Neste exercício, você deve implementar a classe **`Intern`**. O papel do `Intern` (estagiário) é **criar 
formulários automaticamente** com base no nome da requisição. Ou seja, **você implementará um tipo de 
FÁBRICA DE FORMULÁRIOS** — o famoso **Factory Pattern**.

### 📦 **Requisitos da Classe `Intern`**

* Deve ter uma função chamada:

  ```cpp
  AForm* makeForm(std::string const& formName, std::string const& target);
  ```
* Essa função deve **retornar um ponteiro para um novo formulário** (`AForm*`) baseado no nome (`formName`) 
recebido.
* Ela deve aceitar os seguintes nomes:

  * `"shrubbery creation"` → retorna `new ShrubberyCreationForm(target)`
  * `"robotomy request"` → retorna `new RobotomyRequestForm(target)`
  * `"presidential pardon"` → retorna `new PresidentialPardonForm(target)`
* Se o nome não corresponder a nenhum conhecido, o intern **deve imprimir uma mensagem de erro**.

### 🧠 **Regras importantes**

* **Evite `if/else if/else` excessivo!**
  A correção do exercício **não aceita soluções com muitas condicionais**. Isso é uma dica clara de que você 
  deve **usar arrays de strings + ponteiros para funções/funções lambda**, ou outra solução limpa e escalável.

## 🎯 **Objetivos e Competências Desenvolvidas**

| Competência                             | Aprendizado                                                                      |
| --------------------------------------- | -------------------------------------------------------------------------------- |
| 🧰 **Factory Pattern**                  | Como criar objetos dinamicamente com base em strings.                            |
| 🧠 **Mapeamento de strings para ações** | Aprender a associar nomes a classes via arrays, structs ou ponteiros de função.  |
| 🧼 **Código limpo e escalável**         | Evitar estruturas rígidas e difíceis de manter como grandes blocos de `if/else`. |
| 🧾 **Integração com herança**           | Reforço do uso de `AForm*` como tipo polimórfico.                                |
| 📣 **Mensagens de log claras**          | Prática de mensagens úteis ao usuário ou ao avaliador.                           |

