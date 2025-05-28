🎯 Objetivo da atividade ex00

O principal objetivo é:

	Criar uma classe chamada ClapTrap que simula um robô com atributos de combate simples e métodos 
	para atacar, sofrer dano e se reparar.

Essa classe será a classe base das próximas atividades com herança (ScavTrap, FragTrap, etc).

🧠 O que você vai aprender
Conceito	Descrição
🧱 Criação de classe	Como declarar atributos privados e métodos públicos.
🧰 Encapsulamento	Ocultar os dados internos (vida, energia, dano) e expor métodos públicos.
⚙️ Construtor/Destrutor	Criar objetos com valores iniciais e saber quando eles são destruídos.
📉 Gestão de estado interno	Atualizar vida, energia e dano corretamente conforme ações são realizadas.
🖨️ Impressão de ações	Mostrar claramente o que acontece com mensagens em std::cout.
🧪 Escrita de testes simples	Testar cada comportamento em main() (ataque, dano, reparo).

🔎 Pontos de atenção importantes

✅ Mensagens de log obrigatórias

	Toda ação (ataque, dano, reparo) deve imprimir uma mensagem específica.

	Construtores e destrutores também devem mostrar que foram chamados.

🔁 Não fazer interações entre objetos

	Os target passados para attack() são apenas std::string, não outros objetos ClapTrap.

🚫 Ações só se o robô estiver vivo e com energia

	Antes de atacar ou se reparar, o robô deve ter hitPoints > 0 e energyPoints > 0.