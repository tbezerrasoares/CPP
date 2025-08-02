O módulo CPP06 trata principalmente de type casting, um conceito central e delicado em C++.
A seguir, listo os principais pontos de aprendizagem que você deve prestar atenção ao 
longo do PDF:
🔑 **1. Entendimento profundo dos C++ casts:
Aprender a diferença e o uso adequado de:
    static_cast
    reinterpret_cast
    const_cast
    dynamic_cast
    💡 Importância: Esses castings substituem os C-style casts e são mais seguros e 
	explícitos. A escolha correta entre eles é avaliada na defesa do exercício.

🔍 2. Detecção e conversão de tipos escalares (ex00)
    Detectar o tipo de uma string literal (ex: "42", "4.2f", "a", "nan") e converter entre:
        char, int, float, double
    Tratar pseudo-literais (nan, +inf, -inf) corretamente.
    Exibir mensagens apropriadas em conversões impossíveis.
    🎯 Aprendizado: Conversões entre tipos primitivos usando castings corretos e tratamento 
	de casos limites.

📦 3. Serialização e desserialização de ponteiros (ex01)
    Transformar ponteiros em inteiros (uintptr_t) e de volta.
    Usar reinterpret_cast para esse processo.
    Compreender o conceito de serialização em baixo nível (sem bibliotecas externas).
    🎯 Aprendizado: Manipulação de ponteiros e conversões entre tipos de dados "brutos" 
	(low-level programming).

🧬 4. RTTI e identificação de tipos em tempo de execução sem typeid (ex02)
    Uso de dynamic_cast para identificar o tipo real de um objeto.
    Compreender como a herança e o polimorfismo funcionam na prática.
    Criar sistemas com classes base e derivadas e testar comportamento dinâmico.
    🎯 Aprendizado: Trabalhar com hierarquias de classes, casting entre ponteiros de base 
	e derivada e uso seguro de dynamic_cast.

📚 5. Regras de projeto e boas práticas
    Ortodox Canonical Form: Implementar construtores padrão, de cópia, operador de atribuição
	 e destrutor.
    Evitar vazamentos de memória: Sempre que usar new, garantir o uso de delete.
    Usar include guards nos headers.
    Manter código legível e bem organizado (sem Norminette, mas com clareza).
    Entregar arquivos corretamente nomeados (segundo as instruções).

✅ Em resumo, este módulo desenvolve:
    Domínio dos castings seguros e explícitos do C++
    Capacidade de trabalhar com conversão de tipos e RTTI
    Entendimento de ponteiros e manipulação de memória
    Rigor no uso de boas práticas de design e estruturação de classes

📘 Exercício 00 – Conversão de tipos escalares
    Objetivo: Criar uma classe ScalarConverter com um método estático convert(string literal) 
	que converte o valor dado em:
        char
        int
        float
        double
    Requisitos:
        A classe não pode ser instanciada.
        Detectar o tipo do literal (ex: 'a', 42, 4.2f, nanf, etc.).
        Realizar as conversões apropriadas e imprimir os resultados.
        Tratar casos de conversões impossíveis ou valores fora dos limites.
        Lidar com pseudo-literais como nan, +inf, -inf, nanf, etc.
        Usar castings apropriados (C++ casts) conforme o tipo de conversão.

📘 Exercício 01 – Serialização
    Objetivo: Criar uma classe Serializer com dois métodos estáticos:
        uintptr_t serialize(Data* ptr): converte um ponteiro para um inteiro.
        Data* deserialize(uintptr_t raw): converte o inteiro de volta para ponteiro.
    Requisitos:
        A estrutura Data deve conter membros de dados (não ser vazia).
        Verificar se o ponteiro original e o resultado da desserialização são equivalentes.
        Não há funções proibidas.
        A classe não pode ser instanciada.

📘 Exercício 02 – Identificação de tipo real
    Objetivo: Identificar dinamicamente o tipo real de um objeto em tempo de execução, sem 
	usar typeid.
    Classes a implementar:
        Base: classe com destrutor virtual.
        A, B, C: herdam publicamente de Base.
    Funções a implementar:
        Base* generate(void): retorna aleatoriamente uma instância de A, B ou C.
        void identify(Base* p): imprime o tipo real do objeto apontado por p.
        void identify(Base& p): imprime o tipo real do objeto referenciado por p, sem usar 
		ponteiros.
    Requisitos:
        Não usar typeinfo.
        Permite usar dynamic_cast.