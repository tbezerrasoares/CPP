🧩 Exercício 02 – Abstract Class
🎯 Objetivo:

Transformar a classe Animal em uma classe abstrata, impedindo que ela seja instanciada diretamente.

🛠️ O que você precisa fazer
1. Tornar Animal uma classe abstrata

Você faz isso marcando pelo menos uma função como "virtual pura" (pure virtual), com = 0. Neste caso:

2. Garantir que as classes derivadas (Dog e Cat) implementem makeSound()

Elas já devem estar implementando isso desde o exercício anterior, então aqui basta manter como está:

💡 Por que isso é importante?

    Você está forçando o uso correto da hierarquia: apenas objetos "reais" (como Dog ou Cat) podem ser criados.

    Garante que todas as subclasses sejam obrigadas a fornecer sua própria implementação de makeSound().

    É um passo importante para projetar APIs seguras e coerentes.

✅ O que você aprende com o ex02
| Conceito                  | O que significa/prática                        |
| ------------------------- | ---------------------------------------------- |
| **Classe abstrata**       | Não pode ser instanciada                       |
| **Função virtual pura**   | Função que *deve* ser sobrescrita              |
| **Polimorfismo completo** | Agora garantido em tempo de compilação         |
| **Boas práticas de OOP**  | Obriga subclasses a implementar comportamentos |
