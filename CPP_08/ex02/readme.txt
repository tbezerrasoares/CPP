# 🔥 **Exercício 02 - Mutated Abomination**

## 🎯 **Objetivo da Atividade**

O **Ex02 - Mutated Abomination** é o exercício mais desafiador do módulo CPP08. O objetivo é criar uma classe `MutantStack` que herda de `std::stack` mas adiciona funcionalidade de **iteração**, algo que a stack original não possui. Este exercício combina herança, adaptadores de containers e implementação de iteradores customizados.

### **Problema a Resolver:**
- `std::stack` é um **container adapter** que não fornece iteradores
- Precisamos manter toda a funcionalidade de stack (LIFO - Last In, First Out)
- Mas também permitir iteração pelos elementos armazenados
- A solução deve ser **template** para funcionar com qualquer tipo de dados

---

## 🧠 **Pontos de Aprendizado Fundamentais**

### ✅ **1. Container Adapters e Herança**
- **Conceito**: Como `std::stack` funciona como wrapper sobre outros containers
- **Implementação**: Herdar de `std::stack` mantendo toda sua funcionalidade
- **Desafio**: Adicionar recursos sem quebrar a interface original

### ✅ **2. Implementação de Iteradores**
- **Iterator**: Implementar `begin()` e `end()` para percorrer elementos
- **Const Iterator**: Versões const dos iteradores para containers imutáveis
- **Compatibilidade STL**: Iteradores compatíveis com algoritmos da STL

### ✅ **3. Template Classes**
- **Genericidade**: Classe template que funciona com qualquer tipo `T`
- **Container Subjacente**: Permitir escolha do container base (vector, deque, list)
- **Type Traits**: Uso correto de tipos derivados do container base

### ✅ **4. Orthodox Canonical Form para Templates**
- **Construtores**: Padrão, cópia, e parametrizados
- **Operadores**: Atribuição funcionando corretamente com templates
- **Destrutor**: Gestão automática via herança

### ✅ **5. Acesso ao Container Subjacente**
- **Problema**: `std::stack` não expõe seu container interno
- **Solução**: Usar `protected` member `c` ou criar acesso customizado
- **Segurança**: Manter encapsulamento enquanto permite iteração

---

## 🏗️ **Arquitetura da Implementação**

### **Estrutura da Classe:**
```cpp
template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
    // Tipos de iterador
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    // Orthodox Canonical Form
    MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack &operator=(const MutantStack &other);
    ~MutantStack();

    // Métodos de iteração
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    
    // Iteração reversa (opcional)
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};
```

### **Desafios Técnicos:**
1. **Acesso ao Container**: `std::stack` protege seu container interno
2. **Herança de Template**: Sintaxe correta para herdar de template especializado
3. **Type Definitions**: Definir tipos de iterador corretamente
4. **Compatibilidade**: Manter 100% compatibilidade com `std::stack`

---

## 🧪 **Testes Implementados**

### **Teste 1: Funcionalidade Stack Básica**
```cpp
void testBasicStackFunctionality()
```
- **Objetivo**: Verificar que todas as operações de stack funcionam
- **Operações testadas**:
  - `push()`: Adicionar elementos
  - `pop()`: Remover elementos (sem retorno)
  - `top()`: Acessar topo
  - `empty()`: Verificar se está vazia
  - `size()`: Obter tamanho
- **Verificação**: Comportamento LIFO mantido
- **Aprendizado**: Herança preserva funcionalidade da classe base

### **Teste 2: Iteração Forward**
```cpp
void testForwardIteration()
```
- **Cenário**: Stack com elementos [1, 2, 3, 4, 5] (5 no topo)
- **Iteração**: De `begin()` até `end()`
- **Ordem esperada**: [1, 2, 3, 4, 5] (bottom to top)
- **Verificações**:
  - Iteradores `begin()` e `end()` funcionam
  - Ordem de iteração correta
  - Compatibilidade com range-based for
- **Aprendizado**: Como iteradores expõem estrutura interna

### **Teste 3: Iteração Const**
```cpp
void testConstIteration()
```
- **Cenário**: MutantStack const
- **Verificações**:
  - `const_iterator` funciona corretamente
  - Não permite modificação via iterador
  - Métodos const retornam const_iterator
- **Aprendizado**: Importância de const-correctness

### **Teste 4: Iteração Reversa**
```cpp
void testReverseIteration()
```
- **Cenário**: Mesma stack do teste 2
- **Iteração**: De `rbegin()` até `rend()`
- **Ordem esperada**: [5, 4, 3, 2, 1] (top to bottom)
- **Verificações**:
  - Reverse iterators funcionam
  - Ordem reversa correta
  - Useful para algoritmos que precisam de ordem LIFO
- **Aprendizado**: Flexibilidade de diferentes tipos de iteração

### **Teste 5: Algoritmos STL**
```cpp
void testSTLAlgorithms()
```
- **Algoritmos testados**:
  - `std::find()`: Buscar elemento específico
  - `std::count()`: Contar ocorrências
  - `std::for_each()`: Aplicar função a todos elementos
  - `std::accumulate()`: Somar todos elementos
- **Objetivo**: Verificar compatibilidade total com STL
- **Aprendizado**: Poder dos iteradores para integração com STL

### **Teste 6: Diferentes Container Types**
```cpp
void testDifferentContainers()
```
- **Containers testados**:
  - `MutantStack<int, std::vector<int>>`
  - `MutantStack<int, std::deque<int>>` (padrão)
  - `MutantStack<int, std::list<int>>`
- **Verificações**:
  - Template funciona com diferentes containers base
  - Performance e comportamento adequados
  - Flexibilidade da implementação
- **Aprendizado**: Poder dos templates para genericidade

### **Teste 7: Copy e Assignment**
```cpp
void testCopyAndAssignment()
```
- **Cenários**:
  - Construtor de cópia: `MutantStack<int> copy(original)`
  - Operador de atribuição: `assigned = original`
- **Verificações**:
  - Cópia profunda de todos elementos
  - Independência entre objetos
  - Iteradores funcionam em cópias
- **Aprendizado**: Orthodox Canonical Form em templates

### **Teste 8: Large Dataset e Performance**
```cpp
void testPerformance()
```
- **Escala**: 100.000 elementos
- **Operações**:
  - Push massivo
  - Iteração completa
  - Algoritmos STL em grande escala
- **Verificações**:
  - Performance adequada
  - Sem vazamentos de memória
  - Estabilidade com big data
- **Aprendizado**: Importância de testes de escala

### **Teste 9: Edge Cases**
```cpp
void testEdgeCases()
```
- **Casos testados**:
  - Stack vazia: iteradores `begin() == end()`
  - Stack com um elemento
  - Push/pop durante iteração (undefined behavior)
  - Diferentes tipos de dados (string, custom objects)
- **Objetivo**: Garantir robustez em situações extremas
- **Aprendizado**: Importância de considerar todos os cenários

---

## 🔧 **Detalhes de Implementação**

### **Acesso ao Container Subjacente:**
```cpp
// std::stack tem um membro protected 'c' que é o container
// Podemos acessá-lo via herança:
iterator begin() { return this->c.begin(); }
iterator end() { return this->c.end(); }
```

### **Template Specialization:**
```cpp
// Container padrão é std::deque (mesmo que std::stack)
template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
```

### **Type Safety:**
```cpp
// Garantir que Container suporta operações necessárias
static_assert(std::is_same<T, typename Container::value_type>::value,
              "Container value_type must match T");
```

---

## 📋 **Arquivos do Projeto**

- **`MutantStack.hpp`**: Declaração da classe template e implementação inline
- **`main.cpp`**: Suite completa de testes cobrindo todos os cenários
- **`Makefile`**: Compilação com flags apropriadas (-std=c++98)

---

## 🎯 **Resultado Esperado**

Após completar este exercício, você terá:
1. ✅ Domínio completo de herança com templates
2. ✅ Experiência prática implementando iteradores
3. ✅ Conhecimento profundo sobre container adapters
4. ✅ Habilidade de estender funcionalidade de classes STL
5. ✅ Compreensão de design patterns (Adapter/Wrapper)
6. ✅ Experiência com compatibilidade total STL

Este é o exercício mais avançado do módulo e prepara você para trabalhar com bibliotecas complexas e implementar estruturas de dados customizadas mantendo compatibilidade com padrões existentes.

---

## ⚠️ **Considerações Importantes**

- **C++98 Compliance**: Usar sintaxe compatível (sem auto, range-based for em implementação)
- **Container Requirements**: Nem todos containers funcionam com stack (ex: std::forward_list)
- **Iterator Invalidation**: Modificar stack durante iteração pode invalidar iteradores
- **Performance**: Iteração em stack quebra o conceito de acesso apenas ao topo
- **Thread Safety**: Não implementado - usar com cuidado em ambientes multi-thread