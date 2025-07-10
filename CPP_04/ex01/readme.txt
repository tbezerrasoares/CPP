🧠 Resumo da atividade ex01 – “I don’t want to set the world on fire”
🎯 Objetivo:

Você vai:
    Adicionar um novo atributo chamado Brain às classes Dog e Cat.
    Garantir que cada Dog e Cat tenha seu próprio objeto Brain, alocado com new.
    Implementar cópia profunda para evitar problemas de ponteiros duplicados.
    Gerenciar corretamente a alocação e liberação de memória, evitando memory leaks.

📋 Tarefas principais
1. Criar a classe Brain
    A classe deve conter um array com 100 strings (std::string ideas[100]).
    Esta classe será usada como atributo de Dog e Cat.

2. Alterar as classes Dog e Cat
    Adicionar um ponteiro Brain* brain como membro privado.
    Criar o brain com new Brain() no construtor.
    Destruir o brain com delete no destrutor.
    Implementar o construtor de cópia e o operador de atribuição para garantir cópia profunda.

3. Testar o comportamento com polimorfismo e cópia
No main.cpp:
    Criar um array de Animal* com metade Dog e metade Cat.
    Liberar todos os objetos usando delete no final.
    Garantir que os destrutores corretos sejam chamados.
    Testar cópia de Dog e Cat e confirmar que é deep copy, não shallow.

❗ Pontos importantes
Ponto	Explicação
✅ Deep copy	Quando você copia um Dog, o novo Dog deve ter seu próprio Brain, com dados copiados.
🚫 Shallow copy	Copiar apenas o ponteiro leva a bugs e vazamentos de memória.
🔁 Regra dos três	Implementar: construtor de cópia, operador de atribuição, destrutor.
🧹 Memory leaks	Use valgrind ou similar para garantir que nenhuma memória é vazada.
🔄 Polimorfismo	Mesmo deletando um Dog* como Animal*, o destrutor de Dog deve ser chamado 
corretamente (graças a destrutores virtuais).

✅ O que você vai aprender com este exercício
    A aplicar composição entre classes (Dog contém um Brain).
    A usar alocação dinâmica com new e delete.
    A aplicar corretamente a Regra dos Três em C++.
    A garantir deep copies de objetos com ponteiros.
    A entender o impacto de polimorfismo com destrutores virtuais.

| Conceito          | Descrição curta                                                                 |
| ----------------- | --------------------------------------------------------------------------------|
| `new` / `delete`  | Alocação e liberação dinâmica de memória na heap                                |
| Regra dos Três    | Implementar: destrutor, construtor de cópia e operador de atribuição quando usar|
|					| ponteiros                                                                       |
| Deep copy         | Cópia real do conteúdo, não só dos ponteiros                                    |
| Destrutor virtual | Permite liberar corretamente memória em polimorfismo                            |
