📘 Resumo geral: Módulo 03 — Herança

O foco aqui é aprender a criar hierarquias de classes, entender construtores e destrutores em herança, 
e lidar com múltipla herança em C++.

✅ Atividades e objetivos
### 🧪 ex00 — "Aaaaand... OPEN!"

Objetivo:
Criar uma classe base chamada ClapTrap.
Você aprende:

    Criação de uma classe base.
    Implementação de métodos simples.
    Gestão de estado (vida, energia).
    Uso de mensagens nos construtores, destrutores e ações.

### 🤖 ex01 — "Serena, my love!"

Objetivo:
Criar uma subclasse chamada ScavTrap, que herda de ClapTrap.
Você aprende:

    Como funciona herança simples.
    Como construtores e destrutores são chamados em uma hierarquia.
    Como sobrescrever funções (e diferenciar as mensagens).
    Organização e reutilização de código com : public ClapTrap.

### 🔁 ex02 — "Repetitive work"

Objetivo:
Criar outra subclasse chamada FragTrap, que também herda de ClapTrap.
Você aprende:

    Repetição de herança com pequenas variações.
    Como sobrescrever construtores, destrutores e comportamentos com polimorfismo básico.
    Diferenças de especialização em subclasses.

🧠 Principais competências desenvolvidas no Módulo 03
Competência	Aprendizado na prática
👪 Herança	class ScavTrap : public ClapTrap
🔄 Reutilização de código	Compartilhamento de atributos e métodos base
🧱 Construtores/Destrutores	Ordem de chamada e encadeamento
🧬 Múltipla herança	class DiamondTrap : public FragTrap, public ScavTrap
🧠 Polimorfismo (inicial)	Sobrescrita de métodos com mensagens diferentes
☢️ Ambiguidade e shadowing	Lidar com nomes duplicados entre classes-pai