## 📘 **Ex02 – Identify real type**

## 🎯 **Objetivo**

Você deve:
1. Criar uma **classe base `Base` com destrutor virtual**
2. Criar 3 classes vazias `A`, `B` e `C` que **herdam publicamente de `Base`**
3. Criar 2 funções:
   * `void identify(Base* p);` → identifica o tipo real do objeto apontado
   * `void identify(Base& p);` → identifica o tipo real do objeto referenciado (**sem usar ponteiro**)
4. Criar a função:
   * `Base* generate();` → retorna uma instância aleatória de `A`, `B` ou `C` como `Base*`

## 🚫 **O que é proibido**

* **Não usar `typeid` nem `<typeinfo>`**
* Apenas `dynamic_cast` é permitido
* **Não precisa** implementar forma canônica ortodoxa (sem construtores/copias/etc.)
* Use apenas recursos compatíveis com C++98

## 🧠 **Por que isso é importante?**

Essa atividade testa:

* Compreensão de **herança**, **polimorfismo** e **casting dinâmico**
* Uso seguro de `dynamic_cast` com ponteiros e referências
* Capacidade de **identificar o tipo real de um objeto via RTTI** (Run-Time Type Information)

## ✅ **Competências desenvolvidas**

* Aplicação de **polimorfismo real**
* Conhecimento de **RTTI** sem `typeid`
* Prática com `dynamic_cast` e **tratamento de exceções**
* Design limpo e uso de classes base e derivadas
