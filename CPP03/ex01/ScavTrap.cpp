#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	_hit = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hit = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "ScavTrap Name Constructor Called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &trap)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	if (&trap == this)
		return (*this);
	_name = trap._name;
	_damage = trap._damage;
	_hit = trap._hit;
	_energy = trap._energy;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energy > 0 && _hit > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing "
		<< _damage << " points of damage!" << std::endl;
		_energy--;
	}
	else if (_hit == 0)
	{
		std::cout << "ScavTrap " << _name << " is not able to attack " << target
		<< " because he has not enough hit points." << std::endl;
	}
	else if (_energy == 0)
	{
		std::cout << "ScavTrap " << _name << " is not able to attack " << target
		<< " because he has no energy points left." << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;

}