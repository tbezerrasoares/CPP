## 🧩 **Resumo da atividade ex02 — `Array<T>`**
### 🎯 **Objetivo**
Criar uma **classe template `Array<T>`** com comportamento semelhante a um array:
* Genérica (funciona com qualquer tipo)
* Segura (verifica acesso fora dos limites)
* Copiável corretamente (deep copy)
* Gerencia memória dinamicamente

## 📄 **Especificações obrigatórias**
### A classe `Array<T>` deve:

1. **Ter um construtor padrão**
   * Cria um array vazio, sem elementos.
2. **Ter um construtor com parâmetro `unsigned int n`**
   * Cria um array com `n` elementos, **inicializados por default**.
   > 💡 Dica: `new T[n]()` inicializa todos os elementos com o construtor padrão de `T`.
3. **Implementar construtor de cópia e operador de atribuição**
   * Modificar uma cópia **não afeta** o original. (**deep copy**).
4. **Implementar o operador `[]`**
   * Permite acessar/modificar elementos por índice.
   * Se o índice for **inválido**, lançar uma exceção.
5. **Implementar `size()`**
   * Retorna o número de elementos.
   * Deve ser `const` e não modificar o objeto.
6. **Gerenciar a memória com `new[]` e `delete[]`**
   * **Sem leaks** e sem acessar memória não alocada.

## 🧠 **Competências desenvolvidas**

| Habilidade               | Aplicação na ex02                                   |
| ------------------------ | --------------------------------------------------- |
| Templates de classe      | `template <typename T> class Array`                 |
| Alocação dinâmica segura | `new[]`, `delete[]`, sem leaks                      |
| Operador `[]`            | Implementar com verificação de limites              |
| Exceções                 | Lançar `std::exception` ao acessar índice inválido  |
| Deep copy                | Cópia segura no construtor e operador de atribuição |
| Canonical Form           | Implementar forma canônica: ctor, copy, dtor, `=`   |

## ⚠️ Regras importantes

| Regra                                   | Significado                                                |
| --------------------------------------- | ---------------------------------------------------------- |
| Proibido `std::vector`, `std::list` etc | Nada de containers STL (somente no módulo 08+)             |
| `new[]` obrigatório                     | Não pode usar `malloc` nem `std::allocator`                |
| Proibido acessar memória não alocada    | Só use o que você mesmo alocou                             |
| Operações fora do `Array`               | Devem lançar `std::exception`                              |
| Templates no `.cpp` = erro              | Tudo precisa estar em `.hpp` (ou `.tpp` incluso no `.hpp`) |

