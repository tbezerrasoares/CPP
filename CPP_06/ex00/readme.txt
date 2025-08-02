## 🧩 **Título:** ex00 – Conversion of Scalar Types

**Pasta:** `ex00/`
**Arquivos:** `Makefile`, `.cpp`, `.hpp`
**Funções permitidas:** conversões de string para `int`, `float`, `double` 
(como `std::stoi`, `std::stof`, `std::stod`)
**Proibido:** Usar a classe como instanciável (ela deve ser puramente estática)

---

## 🎯 **Objetivo**

Criar uma **classe estática** chamada `ScalarConverter` com um método:

Esse método:

* Recebe um **literal como string** (ex: `"42"`, `"a"`, `"4.2f"`, `"nan"`)
* Detecta **qual é o tipo real** do literal
* Converte o valor para os outros tipos:

  * `char`
  * `int`
  * `float`
  * `double`
* Exibe os valores convertidos no terminal

## 🧠 **Competências desenvolvidas**

* Dominar **C++ casts** (`static_cast`, `reinterpret_cast`, etc.)
* Trabalhar com **detecção de tipos a partir de strings**
* Tratar **casos limites e pseudo-literals** (`nan`, `+inf`, `-inf`, etc.)
* Lidar com **conversões que podem falhar** (ex: `char` não exibível, overflow de `int`)
* Escrever código limpo, organizado e seguro

## 📌 **Requisitos**

### 1. A classe `ScalarConverter`

* Não pode ser instanciável (construtor privado ou deletado)
* Deve conter **apenas métodos estáticos**

### 2. O método `convert()`

* Detecta o tipo original do valor (com base em formato da string)
* Usa castings para converter para os demais tipos
* Imprime o resultado em todos os formatos:

#### Exemplo 1:

```bash
./convert 42
char: '*'
int: 42
float: 42.0f
double: 42.0
```

## 🧮 **Tipos que você deve suportar**

| Tipo            | Exemplo de entrada                              | Observações                                            |
| --------------- | ----------------------------------------------- | ------------------------------------------------------ |
| char            | `'a'`, `'c'`                                    | Mostrar como char, mas também como int, float e double |
| int             | `0`, `-42`, `123`                               | Conversão direta                                       |
| float           | `4.2f`, `-inff`                                 | Necessário remover o `f` ao exibir como double         |
| double          | `4.2`, `nan`                                    | Similar ao float, sem `f`                              |
| pseudo-literals | `nan`, `+inf`, `-inf`, `nanf`, `+inff`, `-inff` | Devem ser tratados corretamente                        |

## 🛠️ **Resumo das etapas para implementar**

1. Criar `ScalarConverter.hpp` com método estático `convert()`
2. Criar `ScalarConverter.cpp` com a lógica de:
   * Detectar o tipo
   * Converter usando castings corretos
   * Imprimir com tratamento de erros
3. Criar `main.cpp` para receber input
4. Criar `Makefile`

## ✅ **Exemplo de saída esperada**

```bash
$ ./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
```

```bash
$ ./convert nan
char: impossible
int: impossible
float: nanf
double: nan
```

```bash
$ ./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

