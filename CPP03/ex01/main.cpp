#include "ScavTrap.hpp"

int main()
{
	ClapTrap a("Remzi");
	ScavTrap b("Emir");
	std::cout << std::endl;
	b.attack("Remzi");
	b.takeDamage(20);
	b.beRepaired(20);
	b.guardGate();
	std::cout << std::endl;
	a.attack("Burulay");
	a.takeDamage(9);
	a.beRepaired(8);
	std::cout << std::endl;
}