🎯 Objetivo da Atividade ex01

Você vai evoluir a classe Fixed que criou no exercício anterior (ex00) para torná-la útil de verdade, 
permitindo representar valores reais com precisão, convertendo de/para int e float.

✅ Novos recursos a implementar

Na classe Fixed, você deve adicionar:
🏗️ Novos construtores:

    Construtor com int como parâmetro:

        Converte o valor inteiro para ponto fixo.

        Ex: se Fixed f(5) → armazena 5 * 256 = 1280.

    Construtor com float como parâmetro:

        Converte o valor float para ponto fixo com arredondamento.

        Ex: se Fixed f(5.25f) → armazena roundf(5.25 * 256) = 1344.

    O número de bits fracionários continua fixo em 8.

🔁 Conversores:

    float toFloat(void) const → converte _rawBits de volta para float.

    int toInt(void) const → converte _rawBits de volta para int.

🖨️ Sobrecarga do operador <<

    Para imprimir um objeto Fixed usando std::cout.

    Ex: std::cout << fixed; deve mostrar o número como float.

🧠 Por que isso é importante?

Este exercício introduz conceitos avançados de conversão de tipos e sobrecarga de operadores:
Conceito	Importância
🧾 Construtores personalizados	Permitem construir objetos com base em diferentes tipos.
🔄 Conversão de tipos (toInt, toFloat)	Essencial para interoperabilidade com outros códigos.
📤 Sobrecarga de <<	Permite que sua classe se comporte como tipos nativos (int, float) com cout.