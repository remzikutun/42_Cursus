#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default Constructor Called" << std::endl;
	_name = "null";
	_hit = 10;
	_energy = 10;
	_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name Constructor Called" << std::endl;
	_name = name;
	_hit = 10;
	_energy = 10;
	_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &trap)
{
	std::cout << "Copy Constructor Called" << std::endl;
	*this = trap;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &trap)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;

	if (&trap == this)
		return (*this);
	_name = trap._name;
	_hit = trap._hit;
	_energy = trap._energy;
	_damage = trap._damage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy > 0 && _hit > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing "
		<< _damage << " points of damage!" << std::endl;
		_energy--;
	}
	else if (_hit <= 0)
	{
		std::cout << "ClapTrap " << _name << " is not able to attack " << target
		<< " because he has not enough hit points." << std::endl;
	}
	else if (_energy <= 0)
	{
		std::cout << "ClapTrap " << _name << " is not able to attack " << target
		<< " because he has no energy points left." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit > amount)
		_hit -= amount;
	else
		_hit = 0;
	std::cout << "ClapTrap " << _name << " was attacked and lost " << amount << " hit points, he now has " << _hit << " hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit > 0 && _energy > 0)
	{
		_hit += amount;
		std::cout << "ClapTrap " << _name << " repaired itself and gained " << amount << " of hit points, he now has " << _hit << " hit points." << std::endl;
		_energy--;
	}
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << "is not able to repair itself, because he doesn't have enough energy points." << std::endl;
	else if (_hit == 0)
		std::cout << "ClapTrap " << _name << " is not able to repair itself, because he doesn't have enough hit points." << std::endl;
}