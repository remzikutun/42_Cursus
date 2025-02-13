#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap a("Remzi");
	ScavTrap b("Recep");
	FragTrap c ("Emir");

	std::cout << std::endl;

	c.attack("Remzi");
	c.takeDamage(89);
	c.beRepaired(1);
	c.highFivesGuys();

	std::cout << std::endl;
	b.attack("Remzi");
	b.takeDamage(20);
	b.beRepaired(20);
	b.guardGate();

	std::cout << std::endl;

	a.attack("Selami");
	a.takeDamage(9);
	a.beRepaired(8);

	std::cout << std::endl;
}