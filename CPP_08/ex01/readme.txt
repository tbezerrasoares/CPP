A **atividade Ex01 – Span** do módulo CPP08 é um passo além do Ex00: ela ainda envolve **STL**, 
mas agora o foco é **armazenar dados**, **controlar capacidade**, **usar algoritmos** e 
**trabalhar com intervalos usando iteradores**.

---

## **Objetivo**
Criar uma classe `Span` que:
1. Armazena **no máximo N inteiros**, onde `N` é definido no **construtor**.
2. Possui métodos para:
   * **`addNumber()`** → adiciona um número ao container (lança exceção se estiver cheio).
   * **`shortestSpan()`** → retorna a menor diferença entre quaisquer dois números armazenados.
   * **`longestSpan()`** → retorna a maior diferença entre quaisquer dois números armazenados.
3. Permite inserir **um range inteiro de números** de uma vez usando **iteradores** (para não precisar chamar `addNumber()` várias vezes).

## **Restrições**
* Arquivos obrigatórios:
  `Makefile`, `main.cpp`, `Span.hpp` (ou `.h`), `Span.cpp`.
* Nenhuma função proibida.
* Deve **lançar exceção** quando:

  * Tentar adicionar mais números do que a capacidade `N`.
  * Calcular spans com menos de **2 elementos** no container.

## **Pontos Importantes que Você Vai Aprender**
1. **Controle de capacidade** → evitar overflow de container.
2. **Uso de exceções** (`throw`, `try/catch`) para tratar erros.
3. **Iteradores** (`begin()`, `end()`) para inserir ranges e manipular dados.
4. **Algoritmos STL**:

   * `std::sort` → ordenar antes de calcular `shortestSpan`.
   * `std::min_element` e `std::max_element` → calcular `longestSpan`.
   * `std::distance` → verificar tamanho.
5. **Eficiência** → evitar loops desnecessários (usar funções da STL sempre que possível).


