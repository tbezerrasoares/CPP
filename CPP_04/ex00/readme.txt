📘 Ex00 – Polymorphism (Polimorfismo)
🎯 Objetivo

A atividade tem como principal objetivo ensinar o uso do polimorfismo por herança em C++, por meio 
da criação de uma hierarquia de classes baseadas em animais.
🧱 O que você deve implementar

    Classe base Animal:
        Possui um atributo protegido: std::string type.
        Deve ter métodos:
            getType() para retornar o tipo do animal.
            makeSound() que imprime um som genérico (ou nenhum som específico, dependendo da 
			implementação).
        Essa classe não precisa ser abstrata ainda (isso será feito na ex02).

    Classe Dog que herda de Animal:
        No construtor, define type = "Dog".
        Implementa seu próprio makeSound() que imprime algo como "Woof!".

    Classe Cat que herda de Animal:

        No construtor, define type = "Cat".
        Implementa seu próprio makeSound() que imprime algo como "Meow!".

🐛 Desafio adicional: WrongAnimal e WrongCat

Você também deve implementar:

    WrongAnimal e WrongCat para mostrar o que acontece quando você NÃO usa funções virtuais.
    WrongCat herda de WrongAnimal, mas makeSound() não é virtual em WrongAnimal.

Ao usar ponteiros para WrongAnimal*, mesmo se apontando para WrongCat, o método de WrongAnimal 
será chamado, demonstrando o que não fazer.

🛠️ Detalhes técnicos

    Construtores e destrutores devem imprimir mensagens distintas para cada classe, para ajudar 
	nos testes.
    Use ponteiros e alocação dinâmica (new) para testar o comportamento real da hierarquia.

✅ Conceitos que você pratica aqui

    Herança em C++
    Polimorfismo por funções virtuais
    Métodos sobrescritos
    Uso de ponteiros para objetos base
    Diferença entre funções virtuais e não virtuais

✅ O que são funções virtuais em C++?

Uma função virtual é uma função membro declarada na classe base com a palavra-chave virtual, 
que permite que as classes derivadas possam sobrescrevê-la.
Quando você chama essa função através de um ponteiro para a classe base, o C++ irá executar a 
versão correta da classe derivada, se existir.