# 📊 **Exercício 01 - Span**

## 🎯 **Objetivo da Atividade**

O **Ex01 - Span** é um exercício intermediário do módulo CPP08 que visa consolidar conhecimentos sobre **STL containers**, **algoritmos**, **iteradores** e **tratamento de exceções**. O objetivo é criar uma classe `Span` que funciona como um **container inteligente com capacidade limitada** para armazenar inteiros e calcular estatísticas sobre as diferenças entre eles.

### **Funcionalidades Principais:**
1. **Armazenamento controlado**: Armazena no máximo **N inteiros**, onde N é definido no construtor
2. **Cálculo de spans**: 
   - `shortestSpan()` → menor diferença entre quaisquer dois números
   - `longestSpan()` → maior diferença entre quaisquer dois números
3. **Inserção eficiente**: Permite inserir ranges completos usando iteradores
4. **Tratamento robusto de erros**: Lança exceções específicas para cada tipo de erro

---

## 🧠 **Pontos de Aprendizado Fundamentais**

### ✅ **1. Controle de Capacidade e Gestão de Memória**
- **Objetivo**: Aprender a criar containers com limite fixo de elementos
- **Conceitos**: Verificação de bounds, prevenção de overflow, uso eficiente de `std::vector`
- **Aplicação prática**: Sistemas com recursos limitados, buffers de tamanho fixo

### ✅ **2. Algoritmos STL Avançados**
- **`std::sort`**: Para ordenação eficiente antes de calcular shortest span
- **`std::min_element` e `std::max_element`**: Para encontrar extremos em O(n)
- **`std::distance`**: Para calcular tamanho de ranges de iteradores
- **Vantagem**: Usar algoritmos otimizados em vez de loops manuais

### ✅ **3. Template Methods e Iteradores Genéricos**
- **Conceito**: Criar métodos que funcionam com qualquer tipo de iterador
- **Implementação**: `addRange(Iterator begin, Iterator end)`
- **Flexibilidade**: Funciona com `std::vector`, `std::list`, arrays C++, etc.
- **Aprendizado**: Como criar APIs genéricas e reutilizáveis

### ✅ **4. Sistema de Exceções Customizadas**
- **Hierarquia**: Três tipos específicos de exceções
  - `SpanFullException`: Container cheio
  - `NotEnoughElementsException`: Poucos elementos para cálculo
  - `RangeTooBigException`: Range maior que capacidade
- **Benefício**: Tratamento granular de erros e debugging facilitado

### ✅ **5. Orthodox Canonical Form**
- **Implementação completa**: Todos os construtores, destrutor e operadores
- **Gestão de recursos**: Cópia profunda vs shallow copy
- **Boas práticas**: RAII (Resource Acquisition Is Initialization)

### ✅ **6. Análise de Complexidade Algorítmica**
- **shortestSpan()**: O(n log n) devido à ordenação
- **longestSpan()**: O(n) usando min/max
- **addRange()**: O(k) onde k é o tamanho do range
- **Otimização**: Escolha do algoritmo correto para cada operação

---

## 🧪 **Explicação dos Testes Implementados**

### **Teste 1: Funcionalidade Básica**
```cpp
void testBasicFunctionality()
```
- **Objetivo**: Verificar operações fundamentais da classe
- **Cenário**: Adiciona 5 números (6, 3, 17, 9, 11) em um Span de capacidade 5
- **Verificações**:
  - Adição bem-sucedida de números
  - Cálculo correto do shortest span (diferença mínima = 2)
  - Cálculo correto do longest span (diferença máxima = 14)
- **Aprendizado**: Funcionamento básico da classe e cálculos corretos

### **Teste 2: Teste de Exceções**
```cpp
void testExceptions()
```
- **Cenários testados**:
  1. **Container cheio**: Tenta adicionar além da capacidade
  2. **Elementos insuficientes**: Calcula span com apenas 1 elemento
  3. **Container vazio**: Calcula span sem elementos
- **Objetivo**: Verificar se todas as exceções são lançadas corretamente
- **Aprendizado**: Importância do tratamento robusto de casos extremos

### **Teste 3: Inserção de Range**
```cpp
void testRangeInsertion()
```
- **Cenário 1**: Adiciona range de vector com 10 elementos (10, 20, 30...100)
- **Cenário 2**: Tenta adicionar range maior que a capacidade restante
- **Verificações**:
  - Inserção eficiente de múltiplos elementos
  - Cálculos corretos após inserção em massa
  - Exceção para range muito grande
- **Aprendizado**: Uso de iteradores e templates para operações em lote

### **Teste 4: Dataset Grande (Performance)**
```cpp
void testLargeDataset()
```
- **Escala**: 20.000 números aleatórios
- **Objetivo**: Verificar performance com grandes volumes de dados
- **Verificações**:
  - Inserção rápida usando `addRange()`
  - Cálculos eficientes mesmo com muitos elementos
  - Estabilidade da aplicação com big data
- **Aprendizado**: Importância da escolha de algoritmos eficientes

### **Teste 5: Cópia e Atribuição**
```cpp
void testCopyAndAssignment()
```
- **Cenários**:
  - Construtor de cópia: `Span copy(original)`
  - Operador de atribuição: `assigned = original`
- **Verificações**:
  - Cópia correta de dados
  - Independência entre objetos originais e copiados
  - Funcionamento idêntico após cópia
- **Aprendizado**: Implementação correta do Orthodox Canonical Form

### **Teste 6: Casos Extremos**
```cpp
void testEdgeCases()
```
- **Cenários especiais**:
  1. **Números negativos e positivos**: Mistura valores negativos, zero e positivos
  2. **Números duplicados**: Todos os elementos iguais (span = 0)
- **Verificações**:
  - Funcionamento correto com valores negativos
  - Cálculo correto quando não há diferença (span = 0)
  - Robustez em situações não convencionais
- **Aprendizado**: Importância de testar edge cases para garantir robustez

---

## 📋 **Arquivos do Projeto**

- **`Span.hpp`**: Declaração da classe, templates e exceções
- **`Span.cpp`**: Implementação de todos os métodos
- **`main.cpp`**: Suite completa de testes cobrindo todos os cenários
- **`Makefile`**: Compilação com flags apropriadas (-std=c++98)

---

## 🎯 **Resultado Esperado**

Após completar este exercício, você terá:
1. ✅ Domínio completo de containers STL e algoritmos
2. ✅ Experiência prática com templates e iteradores genéricos
3. ✅ Conhecimento sólido sobre tratamento de exceções
4. ✅ Habilidade de criar classes robustas seguindo boas práticas
5. ✅ Compreensão de análise de complexidade algorítmica
6. ✅ Experiência com testes abrangentes e edge cases

Este exercício prepara você para trabalhar com estruturas de dados mais complexas e sistemas que requerem alta performance e confiabilidade.


