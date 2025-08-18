A atividade **Ex00 – Easy find** do módulo CPP08 é um exercício introdutório para trabalhar com **templates**, **iteradores** e 
**algoritmos da STL**.

## **Objetivo**
Criar uma função **template** chamada `easyfind` que:
* Aceite um tipo genérico `T` (desde que seja **um container de inteiros**).
* Receba dois parâmetros:

  1. O container (`T`).
  2. Um número inteiro a procurar.
* Procure **a primeira ocorrência** do inteiro no container.
* Se encontrar, retorne o **iterador** para o elemento.
* Se não encontrar, **lance uma exceção** ou retorne um valor de erro definido por você.

## **Restrições e Regras**
* Não precisa lidar com **containers associativos** (`map`, `set`, etc.).
* Pode usar livremente funções e containers da STL, especialmente `<algorithm>` e `std::find`.
* Arquivos obrigatórios:
  `Makefile`, `main.cpp`, `easyfind.hpp` (ou `.h`), e opcionalmente `easyfind.tpp`.
* Nenhuma função padrão está proibida.

## **Pontos Importantes que Você Vai Aprender**
1. **Funções template**
   * Criar código genérico que funciona com diferentes tipos de containers.
2. **Iteradores na prática**
   * Entender como percorrer containers sem depender de índices (pois nem todos têm).
3. **Algoritmos STL**
   * Uso de `std::find` para buscar valores de forma simples e eficiente.
4. **Tratamento de erros**
   * Definir como lidar quando o valor não for encontrado (exceções, valores especiais, etc.).


