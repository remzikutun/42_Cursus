#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap Default Constructor Called" << std::endl;
	_hit = 100;
	_damage = 30;
	_energy = 100;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Name Constructor Called" << std::endl;
	_hit = 100;
	_damage = 30;
	_energy = 100;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor Called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap &opt)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (&opt == this)
		return (*this);
	ClapTrap::operator=(opt);
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name <<  " requests a high five!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_energy > 0 && _hit > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target << " causing "
		<< _damage << " points of damage!" << std::endl;
		_energy--;
	}
	else if (_hit == 0)
	{
		std::cout << "FragTrap " << _name << " is not able to attack " << target
		<< " because he has not enough hit points." << std::endl;
	}
	else if (_energy == 0)
	{
		std::cout << "FragTrap " << _name << " is not able to attack " << target
		<< " because he has no energy points left." << std::endl;
	}
}