#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Remzi");

	a.takeDamage(10);
	a.attack("Berkay");
	a.beRepaired(8);
}