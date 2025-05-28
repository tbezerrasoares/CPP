🧮 O que é um número em ponto fixo (Fixed-Point)?

Um número em ponto fixo é uma forma de representar números reais (com parte fracionária) usando apenas inteiros, sem usar float ou double.

Imagine que você queira representar 1.5 em ponto fixo com 8 bits fracionários.

Você multiplica o número real por 2⁸ = 256:

1.5 × 256 = 384

Então, em vez de armazenar 1.5, você armazena o inteiro 384.
Quando quiser o número original de volta, basta dividir por 256:

384 / 256 = 1.5

Por que usar ponto fixo e não float/double?
Vantagens do ponto fixo	Explicação breve
🚀 Mais rápido que float	Em hardwares simples, inteiros são mais rápidos que floats.
💾 Determinístico	Sem "erro de arredondamento flutuante".
🎮 Usado em games, gráficos, DSPs, etc.	Ideal para sistemas embarcados e gráficos.
⚙️ Controla melhor precisão e range	Você define quantos bits para parte inteira e parte fracionária.

📌 Importância prática

Sistemas embarcados, processadores de áudio, gráficos antigos, jogos retrô e microcontroladores não possuem FPU (unidade de ponto flutuante).
Nestes casos, usar ponto fixo é mais eficiente e seguro.

💡 Como o exercício ex00 nos ajuda a entender isso?

Ele te leva a implementar uma classe Fixed personalizada, onde:

	Você armazena o número real como um inteiro bruto (_rawBits).

	Mas esse valor é entendido como tendo 8 bits de fração (multiplicado por 2⁸).

	Você não lida diretamente com floats, mas sim com o valor codificado.

Além disso, o exercício te ensina:
Aprendizado	Aplicação prática
📦 Encapsulamento	Armazena o valor como inteiro e oferece acesso controlado.
🧱 Forma Canônica Ortodoxa	Você aprende a escrever classes bem estruturadas.
🧠 Compreensão de representação numérica	Você percebe que o mesmo número pode ser representado de forma diferente.
🔧 get/set RawBits	Manipula diretamente o valor "codificado".