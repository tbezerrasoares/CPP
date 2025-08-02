## 🧩 **Resumo da atividade ex01 — `iter`**

### 🎯 **Objetivo**

Criar uma função template chamada `iter` que:

* Receba **um array de qualquer tipo**,
* Receba o **tamanho** desse array,
* E aplique uma **função** (passada como argumento) a **cada elemento** do array.

---

## 📄 **Especificação técnica**

* A função `iter` deve ser um **template** de função.
* Os parâmetros são:

  ```cpp
  template <typename T>
  void iter(T* array, int length, void (*func)(T const &));
  ```
* Mas pode (e deve) funcionar com **referência não-const** também quando necessário.

### 💡 A função passada pode:

* Receber o elemento como **referência constante** → para **somente leitura**.
* Ou como **referência não-constante** → se quiser **modificar** os valores do array.

## 🧠 **Competências desenvolvidas**

| Habilidade                  | Como é praticada                       |
| --------------------------- | -------------------------------------- |
| Templates                   | Função que aceita **qualquer tipo**.   |
| Funções como parâmetros     | Ponteiros para funções.                |
| Arrays e ponteiros          | Manipulação direta de elementos.       |
| Const e não-const           | Entender quando usar `const &` ou `&`. |
| Modularização e organização | Funções templates sempre no `.hpp`.    |

## ⚠️ Cuidados importantes

| Erro comum                     | Como evitar                                   |
| ------------------------------ | --------------------------------------------- |
| Esquecer de usar `std::size_t` | Use `size_t` para evitar warnings com índices |
| Tentar modificar const         | Certifique-se de usar sobrecarga de `iter`    |
| Escrever templates em `.cpp`   | Templates devem estar **100% no `.hpp`**      |

